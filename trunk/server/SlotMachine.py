#!/usr/bin/env python

import random, time
from Logging import Log
from PayTable import PayTable
from Error import Error
from User import User
import ConfMgr
from Utils import checkPara
from FreeSpin import FreeSpin
import BonusGameType
from Tournament import Tournament
from UserShareGift import UserShareGift
from Stat import Stat

class SlotMachine:
    # 3*5
    WIDTH= 5
    HEIGHT = 3

    @classmethod
    def load(cls, para):
        if not checkPara(para, ['uid', 'machine_id']):
            return Error.INVAILD_PARAM

        mid = para['machine_id']
        uid = para['uid']

        ret = {'machine_id': mid}
        machine = cls(mid)
        init = machine.genInitLayout()
        init_left = machine.genInitLayoutLeft(mid, init)

        ret['symbols'] = init_left + init

        free_spin = FreeSpin(uid, mid).getAll()
        if free_spin:
            ret['free_spin'] = free_spin

        game_type = BonusGameType.getBonusGameType(mid)
        bonus_game = game_type(uid, mid).load()
        if bonus_game is not None:
            ret['bonus'] = bonus_game

        # reset in case last spin is free
        User(uid).clearWinRec()

        return ret

    @classmethod
    def spin(cls, para):
        if not checkPara(para, ['uid', 'machine_id', 'lines', 'bet', 'is_free']):
            return Error.INVALID_PARAM

        uid = para['uid']
        game_id = para['machine_id']
        lines = para['lines']
        bet = para['bet']
        is_free = para['is_free']

        fake_flag = 0
        if 'fakeflag' in para:
            fake_flag = int(para['fakeflag'])

        lv = User(uid).level

        #check
        if not ConfMgr.isMachineLocked(game_id, lv):
            return Error.MACHINE_LOCKED

        if not ConfMgr.isLineValid(game_id, lines):
            return Error.LINE_EXCEEDED

        if not ConfMgr.isBetValid(lv, bet):
            return Error.BET_EXCEEDED

        pay_in = 0
        user = User(uid)
        cur_coin = user.coin

        # may change wild_tune for this user
        user.addSpin()

        if not is_free:
            user.clearWinRec()

        if not is_free:
            pay_in = lines * bet
            if cur_coin < pay_in:
                Log.error('no enough coin to spin')
                return Error.NO_COIN
        else:
            # pick saved bet and lines for free spin
            free_spin = FreeSpin(uid, game_id)
            ret = free_spin.consume()

            if ret is False:
                return Error.NO_FREE_SPIN

            # override
            (lines, bet) = ret

        machine = cls(game_id)

        # ignore bonus if skip playing it
        game_type = BonusGameType.getBonusGameType(game_id)
        bonus_game = game_type(uid, game_id)
        bonus_game.remove()

        (response, win, bonus_num, spin_num) = machine.doSpin(game_id, lv, lines, bet, is_free, fake_flag)

        if bonus_num > 0:
            game_type.create(uid, game_id, bonus_num, bet)
            Log.debug('created bonus games: bonus_num=%s'%bonus_num)

        if spin_num > 0:
            free_spin = FreeSpin(uid, game_id)
            free_spin.add(spin_num, lines, bet)
            response['is_new_freespin'] = True
            Log.debug('added free spin=%s'%spin_num)

        # save for big/mega win
        user.addWinRec(win / bet)

        # Tournament update
        Tournament.compete(uid, game_id, win)

        # compose reponse
        now_coin = cur_coin - pay_in + win
        user.coin = now_coin
        response['coin'] = now_coin

        (now_exp, lv_up) = user.addExp(lines*bet)
        response['exp'] = now_exp

        response['level'] = user.level

        free_spin = FreeSpin(uid, game_id).getAll()
        if free_spin:
            response['free_spin'] = free_spin

        win_info = user.checkWinRec()
        if win_info:
            response.update(win_info)

        rank_info = Tournament.getRank({'uid': uid, 'machine_id': game_id})
        if rank_info != Error.TOUR_NOT_OPEN:
            response['rank_info'] = rank_info

        # share gift flag
        share = UserShareGift(uid)
        if '5combo' in response:
            share.setFlag(UserShareGift.TYPE_COMBO)

        # bonus may also trigger it
        if 'is_mega' in response:
            share.setFlag(UserShareGift.TYPE_MEGA)

        if lv_up:
            share.setFlag(UserShareGift.TYPE_LEVELUP)

        #only for stat
        data = {'bet': pay_in,
                'win': win,
                'spin': 1,
                'trigger_freespin': 1 if spin_num > 0 else 0,
                'trigger_bonus': 1 if bonus_num > 0 else 0,
                'free_spin': 1 if is_free else 0,
                }
        Stat().incr(data)

        return response

    def __init__(self, game_id):
        self.game_id = game_id
        random.seed(time.time())

    def genInitLayout(self):
        """
        make sure each column has diff symbols.
        """
        symbols = PayTable.getInitSymbols(self.game_id)
        random.shuffle(symbols)

        symbols += symbols

        slot = [[-1]*self.WIDTH for i in range(self.HEIGHT)]
        for j in range(self.WIDTH):
            for i in range(self.HEIGHT):
                slot[i][j] = symbols.pop(0)

        scatter_pos = random.randint(0, 2)
        slot[scatter_pos][0] = PayTable.SCATTER

        bonus_pos = random.randint(0, 2)
        slot[bonus_pos][3] = PayTable.BONUS

        return slot

    def genInitLayoutLeft(self, machine_id, init_layout):
        all_symbols = PayTable.getAllSymbols(machine_id)

        ret = [[]for i in range(len(all_symbols) - len(init_layout))]

        for i in range(self.WIDTH):
            column = []
            for row in init_layout:
                column.append(row[i])

            left_column = [s for s in all_symbols if s not in column]
            random.shuffle(left_column)

            for idx, s in enumerate(left_column):
                ret[idx].append(s)

        return ret


    def choose(self, s, exclude):
        sum = 0
        for t in s:
            if not t in exclude:
                sum += s[t]
        r = random.uniform(0,sum)
        for t in s:
            if not t in exclude:
                if r < s[t]:
                    return t
                r -= s[t]

    def genLayout(self, game_id, weight):
        s = []

        for i in range(0, self.WIDTH):
            t = []
            for j in range(0, self.HEIGHT):
                t.append(self.choose(weight,t))

            # if game_id == 2 and i == 2:
            #     if PayTable.WILD in t:
            #         t = [PayTable.WILD] * 3

            s.append(t)

        slots = []
        for i in range(self.HEIGHT):
            slots.append([-1] * self.WIDTH)

        for (j, col) in enumerate(s):
            for (i, v) in enumerate(col):
                slots[i][j] = v

        return slots

    def doSpin(self, game_id, lv, lines, bet, is_free, fake_flag):
        weight = PayTable.getSymbolWeight(self.game_id, lv, is_free, bet, fake_flag)

        slots = self.genLayout(game_id, weight)

        #final result checking
        bonus_num = 0
        spin_num = 0
        response = {}

        pay_out, ret = self.recheck(game_id, lines, slots)
        if pay_out != 0:
            response['win_lines'] = ret

            combo = self.check5Combo(ret, slots)
            if combo:
                response["5combo"] = combo

        response['symbols'] = slots
        response['win'] = pay_out * bet

        bonus = self.check_bonus(slots, lines)
        if bonus:
            (bonus_num, line, pos) = bonus
            response['win_bonus'] = {'line': line, 'pos': pos}

        scatter = self.check_scatter(slots)
        if scatter:
            (pos, n) = scatter
            spin_num = FreeSpin.getNum(game_id, n)

            response['win_free_spin'] = {'pos': pos, 'num': spin_num}



        return (response, pay_out * bet, bonus_num, spin_num)

    def check_bonus(self, slots, lines):
        for line in range(lines):
            n = 0
            pos = []

            for (y, x) in enumerate(PayTable.LINES[line]):
                if slots[x][y] == PayTable.BONUS:
                    n += 1
                    pos.append((x, y))

            if n >= 3:
                return (n, line, pos)

        return None

    def check_scatter(self, slots):
        n = 0
        pos = []

        for i in range(0, self.HEIGHT):
            for j in range(0, self.WIDTH):
                if slots[i][j] == PayTable.SCATTER:
                    n += 1
                    pos.append((i, j))
        if n >= 3:
            return (pos, n)
        else:
            return None

    def recheck(self, game_id, line_num, slots):
        ret = []
        pay_out = 0

        for idx in xrange(line_num):
            n = 0
            wild_n = 0

            x = PayTable.LINES[idx][0]
            y = 0
            k = slots[x][y]

            # if multiple wild exist on the same line
            for (y, x) in enumerate(PayTable.LINES[idx]):
                if slots[x][y] == PayTable.WILD:
                    wild_n += 1
                else:
                    break

            is_triple_wild = False
            # checking for common symbol
            for (y, x) in enumerate(PayTable.LINES[idx]):
                if k == slots[x][y] or (PayTable.isWild(k) or PayTable.isWild(slots[x][y])):
                    n += 1
                    if PayTable.isWild(k):
                        k = slots[x][y]
                    if k == PayTable.TRIPLE_WILD or slots[x][y] == PayTable.TRIPLE_WILD:
                        is_triple_wild = True
                else:
                    break

            single_payout = 0

            win_line = {}
            # except BONUS and SCATTER checking
            pay_table = PayTable.getPayTable(game_id)
            if (k in pay_table) and (n in pay_table[k]):
                single_payout = pay_table[k][n]
                win_line = {'pos' : [(PayTable.LINES[idx][i], i) for i in xrange(n)],
                            'line' : idx}

                if is_triple_wild:
                    single_payout *= 3
                    win_line['triple_wild'] = True

                #Log.debug('detected:(%d, %d, %d)' % (idx, n, k))

            if PayTable.WILD in pay_table and wild_n in pay_table[PayTable.WILD]:
                if pay_table[PayTable.WILD][wild_n] > single_payout:
                    single_payout = pay_table[PayTable.WILD][wild_n]
                    win_line = {'pos': [(PayTable.LINES[idx][i], i) for i in xrange(wild_n)],
                                'line': idx}

                    #Log.debug('detected(override): (%d, %d, %d)' % (idx, wild_n, PayTable.WILD))

            if win_line:
                ret.append(win_line)

            pay_out += single_payout

        return (pay_out, ret)

    def check5Combo(self, win_lines, slots):
        symbol = []

        for l in win_lines:
            pos = l['pos']

            if len(pos) != 5:
                continue

            s = PayTable.WILD

            for x, y in pos:
                if slots[x][y] != PayTable.WILD:
                    s = slots[x][y]
                    break

            symbol.append(s)

        return symbol


if __name__ == "__main__":
    sm = SlotMachine(1)

    # i = sm.genInitLayout()
    # print i
    #print sm.genInitLayoutLeft(i)
    #print sm.doSpin(1, 2, 10, False, 0)

    #print sm.select_comb(1000)

    #sm.slots = [[100, 8, 100, 7, 2], [200, 100, 200, 1, 6], [100, 200, 200, 200, 1]]
    #sm.slots = [[7, 3, 8, 0, 200], [200, 200, 200, 200, 6], [6, 4, 2, 8, 200]]
    #print sm.recheck(1)

    #sm.spin(9, 1, False)

    #print sm.random_pick_symbol([sm.WILD])

    #for i in range(100):
        #sm.spin(9, 1, False)
    #sm.tease(sm.BONUS)
    #sm.stat()
    para = {'uid':413, 'machine_id':4}
    print SlotMachine.load(para)
    #print SlotMachine.spin(para)

