#!/usr/bin/python

import time
import random

from IndexTable import IndexTable
from Table import Table
import Config
import Utils

class RewardLogItem(Table):
    FIELD_TYPE = {
        'time': int,
        'tid': int,
        'rank': Utils.toInt,
        'prize': int,
    }


class UserRewardLog(IndexTable):
    MAX_SIZE = 50

    @classmethod
    def load(cls, para):
        uid = para['uid']
        log = cls(uid)

        ret = []
        now = int(time.time())
        for i in log.range(now):
            ret.append({'time': i.time,
                        'tid': i.tid,
                        'rank': i.rank,
                        'prize': i.prize / 100
                        })

        return {'reward_history': ret}

    @classmethod
    def getIndexItemType(cls):
        return RewardLogItem

    @classmethod
    def create(cls, uid, tid, rank, prize):
        now = int(time.time())
        data = {
                'tid': tid,
                'rank': rank,
                'prize': prize,
                'time': now
                }

        key = '%s:%s:%s' % (uid, tid, now)

        item_type = cls.getIndexItemType()
        item_type(key).setAll(data)

        log = cls(uid)
        log.addKey(key)

        n = log.size()
        if n > cls.MAX_SIZE:
            log.remove(n - cls.MAX_SIZE)

if __name__ == '__main__':
    uid = 546
    log = UserRewardLog(546)
    UserRewardLog.create(uid, 2, 1, 100)
    print UserRewardLog.load({'uid':uid})
    #print user.addExp(25000)
#    user.hehe = 'zcf'
#    user.coin = 50
#     print user.coin
#     print user.get(['a', 'coin'])
#    print user.getAll()
#    user.setAll({'a':1, 'b':2})
#    user.coin += 50