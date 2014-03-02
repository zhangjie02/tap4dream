#!/usr/bin/python

import time

from Table import Table
import Config
from CfgTable import CfgTable
import Utils
from DB import Redis

class User(Table):
    NAME_INDEX = 'name_idx'
    NAME_SEARCH_NUM = 20

    FIELD_TYPE = {
                  'coin': int,
                  'login_time': int,
                  'reg_time': int,
                  'level': int,
                  'exp': int,
                  #'name': lambda x: x if x else 'Guest',
                  'total_spin': lambda x: int(x) if x else 0,
                  'win_record': lambda x: int(x) if x else 0, # for big_win & mega_win check
                  }

    @classmethod
    def setNameAPI(cls, para):
        uid = para['uid']
        name = para['name']

        user = cls(uid)
        if user.fbid is None:
            user.setName(name)
        return {}

    # set default icon id
    @classmethod
    def setIcon(cls, para):
        uid = para['uid']
        icon = para['icon']
        user = cls(uid)
        if user.fbid is None:
            user.icon = icon
        return {}

    @classmethod
    def search(cls, para):
        name = para['name']
        cli = Redis()
        uid_list = cli.srandmember('%s:%s'%(cls.NAME_INDEX, name), cls.NAME_SEARCH_NUM)

        ret = [{'uid':uid, 'name': User(uid).getName(), 'icon': User(uid).getIcon(),'level':User(uid).level} for uid in uid_list]
        return {'users': ret}

    @classmethod
    def create(cls, uid):
        now = int(time.time())
        data = {
                'coin': Config.INIT_USER_COIN,
                'level': Config.INIT_USER_LEVEL,
                'exp': Config.INIT_USER_EXP,
                'login_time': now,
                'reg_time': now,
                'total_spin': 0,
                }
        cls(uid).setAll(data)

    def getName(self):
        name = self.name
        if not name:
            return 'Guest%s'%self.key_
        else:
            return name

    def setName(self, name):
        old_name = self.name
        self.name = name

        uid = self.key_
        cli = Redis()
        cli.srem('%s:%s'%(self.NAME_INDEX, old_name), uid)
        cli.sadd('%s:%s'%(self.NAME_INDEX, name), uid)

    def getIcon(self):
        fbid = self.fbid

        if fbid:
            return "http://graph.facebook.com/%s/picture?type=normal"%fbid

        #default user icon id(cfg_asserts)
        icon = self.icon
        if not icon:
            return '3'
        else:
            return icon

    # normalized exp
    def getExp(self):
        return self.exp / 100

    def addExp(self, exp):
        now_exp = self.exp
        lv_up = False

        #check lv up
        lv = self.level
        if lv < Config.MAX_LEVEL:
            now_exp += exp
            self.exp = now_exp

            next_exp = CfgTable(CfgTable.CFG_LEVEL_INFO, lv + 1).total_exp
            if now_exp >= next_exp * 100:
                self.level = lv + 1
                lv_up = True

        return (now_exp / 100, lv_up)

    def addSpin(self):
        self.total_spin += 1

    def clearWinRec(self):
        self.win_record = 0

    def addWinRec(self, n):
        if n > 0:
            self.win_record += n

    def checkWinRec(self):
        response = {}
        rate = self.win_record

        if rate >= Config.MEGA_WIN_RATE:
            response['is_mega'] = 1

        elif rate >= Config.BIG_WIN_RATE:
            response['is_big'] = 1

        return response

    def getRangeInfo(self, tid):
        entry_time = Utils.toInt(self.get('entry_time:%d'%tid))
        range_id = Utils.toInt(self.get('range_id:%d'%tid))
        return (entry_time, range_id)

    def setRangeInfo(self, tid, entry_time, range_id):
        self.set('entry_time:%d'%tid, entry_time)
        self.set('range_id:%d'%tid, range_id)


if __name__ == '__main__':
    user = User(500)
    #print user.addExp(25000)
    user.setName('haha')
    print user.getName()
    print User.search({'name':'haha'})
#    user.hehe = 'zcf'
#    user.coin = 50
#     print user.coin
#     print user.get(['a', 'coin'])
#    print user.getAll()
#    user.setAll({'a':1, 'b':2})
#    user.coin += 50
    # for i in range(563, 663):
    #     User(i).remove()
    #     User.create(i)
