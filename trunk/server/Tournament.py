#!/usr/bin/python

import time

from Table import Table
import Config
from CfgTable import CfgTable
from User import User
import DB
from Error import Error
from Logging import Log
from UserRewardLog import UserRewardLog
from Stat import Stat
from Notice import Notice

class Tournament(Table):
    LV_RANGE = [Config.MAX_LEVEL]
    #LV_RANGE = [10, 20, 30, 50, 100, 150, Config.MAX_LEVEL]
    PRIZE_RATE = 0.05 # % to go to prize pool


    FIELD_TYPE = {
                  'start_time': int,
                  }

    WIN_PER_POINT = 100

    @classmethod
    def load(cls, para):
        uid = para['uid']
        ret = []

        for data in CfgTable.load(CfgTable.CFG_TOURNAMENT):
            tid = int(data['tid'])
            base_prize = int(data['prize'])

            tour = Tournament(tid)

            if not tour.exists():
                continue

            info = tour.getRangeInfo(uid)
            info['prize'] += base_prize
            info['tid'] = tid
            info['name'] = data['name']

            total_time = int(data['time'])
            info['total_time'] = total_time

            left_time = tour.start_time + total_time - int(time.time())
            if left_time < 0:
                left_time = 0

            """
            print 'tid:', tid
            print 'start_time', tour.start_time
            print 'now:', int(time.time())
            print 'left_time', left_time
            print 'total_time', total_time
            """

            info['left_time'] = left_time

            ret.append(info)

        ret = sorted(ret, key = lambda x: x['tid'])

        return {'tournament_info':ret}

    @classmethod
    def getRank(cls, para):
        uid = para['uid']
        machine_id = para['machine_id']

        cfg = CfgTable(CfgTable.CFG_MACHINE_INFO, machine_id)
        tid = int(cfg.tid)

        if tid == 0:
            return Error.TOUR_NOT_OPEN

        tour = Tournament(tid)
        return tour.getRankInfo(uid)

    @classmethod
    def create(cls, tid):
        now = int(time.time())
        data = {
                'start_time': now,
                }
        cls(tid).setAll(data)

    def isEnd(self, total_time):
        now = int(time.time())

        if now < self.start_time:
            Log.error('tournament start time error(<now)')
            return True

        offset = 5

        if now - self.start_time >= total_time - offset:
            return True
        else:
            return False

    def getRangeId(self, uid):
        user = User(uid)
        tid = self.key_
        now = int(time.time())

        (entry_time, range_id) = user.getRangeInfo(tid)

        cfg = CfgTable(CfgTable.CFG_TOURNAMENT, tid)
        total_time = int(cfg.time)


        if self.start_time <= entry_time < self.start_time + total_time:
            return range_id
        else:
            # update
            lv = user.level
            range_id = 0
            for i, r in enumerate(self.LV_RANGE):
                if lv <= r:
                    range_id = i + 1
                    break

            user.setRangeInfo(tid, now, range_id)

            return range_id

        # lv = User(uid).level
        # lv = min(lv, Config.MAX_LEVEL)

        # range_id = lv / self.LV_RANGE

        # if lv > 1:
        #     # test if level up while competing
        #     old_range_id = (lv - 1) / self.LV_RANGE

        #     if range_id != old_range_id:
        #         if not self.inRankList(uid, range_id):
        #             if self.inRankList(uid, old_range_id):
        #                 return old_range_id

        # return range_id

    def getLevelRange(self, range_id):
        if range_id > len(self.LV_RANGE):
            Log.error('range_id exceeded')
            return False

        r = range_id - 1

        start = 1
        end = self.LV_RANGE[r]
        if r > 0:
            start = self.LV_RANGE[r-1] + 1

        return {'start':start, 'end':end}


    def getRankKey(self, range_id):
        return '%s:rank:%d' % (self.genRkey(), range_id)

    def getRangePrizeKey(self, range_id):
        return 'range_prize:%d' % range_id

    def inRankList(self, uid, range_id):
        k = self.getRankKey(range_id)
        return True if DB.Redis().zrank(k, uid) else False

    # main entry
    @classmethod
    def compete(cls, uid, machine_id, win):
        if win == 0:
            return

        cfg = CfgTable(CfgTable.CFG_MACHINE_INFO, machine_id)
        tid = int(cfg.tid)

        if tid == 0:
            return

        tour = cls(tid)
        range_id = tour.getRangeId(uid)
        k = tour.getRankKey(range_id)


        cli = DB.Redis()
        cli.zincrby(k, uid, win)

        prize = int(win * cls.PRIZE_RATE)
        prize_key = tour.getRangePrizeKey(range_id)
        cli.hincrby(tour.genRkey(), prize_key, prize)

    def getRangeInfo(self, uid):
        ret = {}
        range_id = self.getRangeId(uid)
        k = self.getRankKey(range_id)

        cli = DB.Redis()

        prize_key = self.getRangePrizeKey(range_id)
        prize = self.get(prize_key)
        ret['prize'] = int(prize) if prize else 0

        ret['player_num'] = cli.zcard(k)

        rank = cli.zrevrank(k, uid)
        ret['rank'] = 0 if rank is None else rank + 1

        return ret

    # top3 and surrouded 3
    def getRankInfo(self, uid):
        all_ret = {}
        range_id = self.getRangeId(uid)
        k = self.getRankKey(range_id)

        cli = DB.Redis()

        player_num = cli.zcard(k)
        all_ret['player_num'] = player_num

        rank = cli.zrevrank(k, uid)
        start = 0

        ret = []
        if rank is None:
            ret = cli.zrevrange(k, -2, -1, withscores=True)
            start = player_num - len(ret) + 1
        elif rank == 0:
            ret = cli.zrevrange(k, rank, rank + 2, withscores=True)
            start = 1
        elif rank == player_num - 1:
            ret = cli.zrevrange(k, -3, -1, withscores=True)
            start = player_num - len(ret) + 1
        else:
            ret = cli.zrevrange(k, rank-1, rank+1, withscores=True)
            start = rank

        result = []
        for idx, (u, score) in enumerate(ret):
            user = User(u)
            result.append({'uid': u, 'name': user.getName(), 'icon': user.getIcon(), 'pts': int(score) / 100 / self.WIN_PER_POINT, 'rank': start + idx})
        if rank is None:
            user = User(uid)
            result.append({'uid': uid, 'name': user.getName(), 'icon': user.getIcon(), 'pts': 0, 'rank': 0})

        all_ret['rank'] = result

        #top 3
        result = []
        ret = cli.zrevrange(k, 0, 2, withscores=True)
        for idx, (u, score) in enumerate(ret):
            user = User(u)
            result.append({'uid': u, 'name': user.getName(), 'icon': user.getIcon(), 'pts': int(score) / 100 / self.WIN_PER_POINT, 'rank': idx + 1})
        all_ret['top_rank'] = result

        info = self.getRangeInfo(uid)
        cfg = CfgTable(CfgTable.CFG_TOURNAMENT, self.key_)
        total_prize = int(cfg.prize) + info['prize']
        all_ret['prize'] = total_prize

        all_ret['reward_info'] = self.getRewardInfo(int(cfg.prize), range_id)

        total_time = int(cfg.time)
        left_time = self.start_time + total_time - int(time.time())
        if left_time < 0:
            left_time = 0
        all_ret['left_time'] = left_time

        all_ret['level_range'] = self.getLevelRange(range_id)

        return all_ret

    def getPlayerNum(self, range_id):
        k = self.getRankKey(range_id)
        cli = DB.Redis()

        return cli.zcard(k)

    def getTopPlayer(self, range_id, n):
        k = self.getRankKey(range_id)
        cli = DB.Redis()

        return cli.zrevrange(k, 0, n-1)

    def getRewardInfo(self, base_prize, range_id):
        k = self.getRangePrizeKey(range_id)
        prize = self.get(k)

        info = []
        pool = 0
        if prize:
            pool = base_prize + int(prize)
            player_num = self.getPlayerNum(range_id)

            max_win_player = max(1, int(player_num * Config.WIN_PRIZE_RATE))

            total_w = 0
            total_n = 0
            selected_prize = []
            for (n, w) in Config.PRIZE:
                if total_n >= max_win_player:
                    break

                total_n += n
                total_w += n * w
                selected_prize.append((n, w))


            start = 1
            for (n, w) in selected_prize:
                info.append({'start': start, 'end':start + n - 1, 'prize': int(w * 1.0 / total_w * pool)})
                start += n

        return info

    def reward(self, base_prize):
        self.is_rewarding = 1

        for range_id in range(1, len(self.LV_RANGE) + 1):
            k = self.getRangePrizeKey(range_id)
            prize = self.get(k)

            pool = 0
            if prize:
                pool = base_prize + int(prize)
                player_num = self.getPlayerNum(range_id)

                max_win_player = max(1, int(player_num * Config.WIN_PRIZE_RATE))

                total_w = 0
                total_n = 0
                for (n, w) in Config.PRIZE:
                    if total_n >= max_win_player:
                        break

                    total_n += n
                    total_w += n * w

                win_player_list = self.getTopPlayer(range_id, total_n)
                rank = 1
                for (n, w) in Config.PRIZE:
                    for i in range(n):
                        if win_player_list:
                            uid = win_player_list.pop(0)
                            prize = int((w * 1.0 / total_w) * pool)
                            tid = self.key_

                            #TODO: skip robots
                            if 563<= int(uid) <= 662:
                                continue

                            User(uid).coin += prize
                            Log.debug('reward uid=%s, rank=%d, prize=%d' % (uid, rank, prize))
                            UserRewardLog.create(uid, tid, rank, prize)

                            # notify
                            Notice(uid).push({'type':Notice.TYPE_TOURNAMENT,
                                'rank': rank,
                                'tid': tid,
                                'prize': prize,
                                'time': int(time.time())})

                            rank += 1

                            data = {'tournament_prize': prize}
                            Stat().incr(data)


    def reset(self):
        tid = self.key_

        cli = DB.Redis()
        for range_id in range(1, len(self.LV_RANGE) + 1):
            k = self.getRankKey(range_id)
            cli.delete(k)

        self.remove()
        Tournament.create(tid)


    #################
    # cron job to
    @classmethod
    def refresh(cls):
        for data in CfgTable.load(CfgTable.CFG_TOURNAMENT):
            tid = int(data['tid'])
            base_prize = int(data['prize'])
            total_time = int(data['time'])

            print 'tid:%s base_prize:%s, total_time=%s' % (tid, base_prize, total_time)

            tour = Tournament(tid)

            if not tour.exists():
                print 'create tour'
                tour.reset()
            elif tour.isEnd(total_time):
                print "rewarding tid=%d"%tid
                tour.reward(base_prize)

                print 'recreate tour'
                tour.reset()


if __name__ == '__main__':
    #Tournament.create(1)
    uid = 663
    t = Tournament(1)

    #Tournament.refresh()
    #t.reward(0)
    #t.compete(uid, 1, 10000)

    para = {'uid': uid, 'machine_id':4}
    print Tournament.load(para)

    #print t.getRewardInfo(0, 1)
    #print t.getRankInfo(uid)
    #print t.getRangeId(uid)
    #print t.getTopPlayer(0, 3)
    #print t.getRankInfo(uid)
    #print Tournament.getRank(para)

