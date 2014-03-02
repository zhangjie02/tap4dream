#!/usr/bin/python
import time, random
from Logging import Log
from Table import Table
from CfgTable import CfgTable
from Utils import toInt, weightedRandom
from User import User
from Error import Error
from Stat import Stat

class SpecialBonus(Table):
    FIELD_TYPE = {
        'count': toInt,
        'reclaim_time': toInt,
    }

    INTERVAL = 4 * 3600
    ROUND = 5

    WHEEL = [(500,500), (760,760), (1100,1100), (300,300), (600,600), (800,800), (1200,1200),
             (350,350), (640,640), (840,840), (2000,2000), (400,400), (720,720), (920,920), (6000,6000)]

    @classmethod
    def load(cls, para):
        uid = para['uid']
        sp_bonus = cls(uid)

        count = sp_bonus.count
        idx = count % cls.ROUND

        ret = {'count': idx, 'time': sp_bonus.getCDTime()}

        if idx == cls.ROUND - 1:
            ret['all'] = [a*100 for (a, b) in cls.WHEEL] #cents

        return ret

    @classmethod
    def reclaim(cls, para):
        uid = para['uid']
        user = User(uid)
        sp_bonus = cls(uid)

        if sp_bonus.getCDTime() > 0:
            return Error.BONUS_NOT_EXIST

        count = sp_bonus.count
        idx = count % cls.ROUND

        ret = {}
        bonus = 0

        user = User(uid)
        lv = user.level

        if idx == cls.ROUND - 1:
            #big
            bonus = weightedRandom(dict(cls.WHEEL))
        else:
            bonus = CfgTable(CfgTable.CFG_LEVEL_INFO, lv).special_bonus

        sp_bonus.count = count + 1
        sp_bonus.reclaim_time = int(time.time())

        bonus *= 100
        user.coin += bonus
        ret['bonus'] = bonus
        ret['coin'] = user.coin

        data = {'special_bonus': bonus}
        Stat().incr(data)

        return ret

    def getCDTime(self):
        cd_time = 0
        now = int(time.time())
        eclipse_time = now - self.reclaim_time

        if  0 <= eclipse_time < self.INTERVAL:
            cd_time = self.INTERVAL - eclipse_time

        return cd_time


if __name__ == '__main__':
    print SpecialBonus.load({'uid': 377})
    print SpecialBonus.reclaim({'uid': 377})
