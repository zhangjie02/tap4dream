#!/usr/bin/python

import time

from IndexTable import IndexTable
from Table import Table
from Error import Error
from DB import Redis
from User import User
from Social import Social
import Utils
from Notice import Notice

class ShareGift(Table):

    FIELD_TYPE = {
        'counter': Utils.toInt,
        'type': int,
        'time': int,
    }


class UserShareGift(IndexTable):
    MAX_SIZE = 100

    TYPE_LEVELUP = 1
    TYPE_COMBO = 2
    TYPE_MEGA = 3
    TYPE_BONUS = 4

    SHARE_COIN = { TYPE_LEVELUP: 50000,
                    TYPE_COMBO: 20000,
                    TYPE_MEGA: 100000,
                    TYPE_BONUS: 20000,
                    }

    TTL = 7 * 86400

    SAMPLE_SIZE = 5
    RECLAIM_COUNTER = 5

    @classmethod
    def load(cls, para):
        uid = para['uid']
        user_gift = cls(uid)

        ret = []
        for (k, i) in user_gift.getAll():
            if not ShareGift(k).exists():
                user_gift.removeOne(k)
                continue

            coin = cls.SHARE_COIN[i.type]

            ret.append({'time': i.time,
                        'from_uid': i.uid,
                        'share_gift_id': k,
                        'coin': coin,
                        'name': User(i.uid).getName(),
                        'icon': User(i.uid).getIcon(),
                        'level': User(i.uid).level,
                        'type': i.type,
                        })

        # if len(ret) <= cls.SAMPLE_SIZE:
        #     random.shuffle(ret)
        # else:
        #     ret = random.sample(ret, cls.SAMPLE_SIZE)

        return {'share_gifts': ret}

    @classmethod
    def reclaim(cls, para):
        uid = para['uid']
        sid = para['share_gift_id']

        user_gift = cls(uid)
        if not user_gift.exists(sid):
            return Error.GIFT_NOT_EXIST

        item_type = cls.getIndexItemType()

        # expired
        if not ShareGift(sid).exists():
            user_gift.removeOne(sid)
            return {'result': 1}

        item = item_type(sid)

        if item.counter < cls.RECLAIM_COUNTER:
            coin = cls.SHARE_COIN[item.type]
            User(uid).coin += coin
            user_gift.removeOne(sid)
            return {'result': 0, 'gift_coin': coin, 'coin':User(uid).coin, 'share_gift_id':sid}
        else:
            return {'result': 2}


    @classmethod
    def getIndexItemType(cls):
        return ShareGift

    @classmethod
    def share(cls, para):
        uid = para['uid']
        share_type = int(para['type'])

        share_gift = cls(uid)

        if not share_gift.hasFlag(share_type):
            return Error.INVALID_PARAM

        now = int(time.time())

        key = '%s:%s' % (uid, now)

        data = {
                'uid': uid,
                'time': now,
                'type': share_type,
                }

        item_type = cls.getIndexItemType()
        item_type(key).setAll(data)
        Redis().expire(key, cls.TTL)

        frd_list = Social.getFriendsUID(uid)

        for f in frd_list:
            box = cls(f)
            box.addKey(key)

            Notice(f).push({'type':Notice.TYPE_SHAREGIFT})

            n = box.size()
            if n > cls.MAX_SIZE:
                box.remove(n - cls.MAX_SIZE)

        # clear
        share_gift.clearFlag(share_type)

        return {}

    def hasFlag(self, t):
        return int(Redis().getbit('share_type:%s' % self.key_, t))

    def setFlag(self, t):
        Redis().setbit('share_type:%s' % self.key_, t, 1)

    def clearFlag(self, t):
        Redis().setbit('share_type:%s' % self.key_, t, 0)


if __name__ == '__main__':
    uid = 1
    UserShareGift(uid).setFlag(1)
    print UserShareGift.share({'uid':uid, 'type':1})
    print UserShareGift.load({'uid':2})

    #print UserShareGift.reclaim({'uid':2, 'sid':'1:1392892831'})

    #gid = '4:500:1392801542'
    #print UserShareGift.reclaim({'uid': uid, 'gid':gid, 'machine_id':1})
