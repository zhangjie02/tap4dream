#!/usr/bin/python

import time
import random

from IndexTable import IndexTable
from Table import Table
from Logging import Log
from Error import Error
from DB import Redis
from User import User
from FreeSpin import FreeSpin
import ConfMgr
from CfgTable import CfgTable

class Gift(Table):
    TYPE_COIN = 1
    TYPE_FREESPIN = 2

    FIELD_TYPE = {
        'time': int,
        'from_uid': int,
        'type': int,
    }


class UserGift(IndexTable):
    MAX_SIZE = 100
    GIFT_CACHE_KEY = 'gift_cache'
    DAY_SEC = 86400

    @classmethod
    def load(cls, para):
        uid = para['uid']
        user_gift = cls(uid)

        ret = []
        now = int(time.time())
        for i in user_gift.range(now):
            ret.append({'time': i.time,
                        'gid': i.gid,
                        'from_uid': i.from_uid,
                        'name': User(i.from_uid).getName(),
                        'icon': User(i.from_uid).getIcon(),
                        'level': User(i.from_uid).level,
                        'type': i.type,
                        'is_sent': cls.isSent(uid, i.from_uid),
                        })

        return {'gifts': ret}

    @classmethod
    def reclaim(cls, para):
        uid = para['uid']
        gid = para['gid']

        user_gift = cls(uid)

        ret = user_gift.doReclaim(gid)

        if ret is False:
            return Error.GIFT_NOT_EXIST

        return ret

    @classmethod
    def getIndexItemType(cls):
        return Gift

    @classmethod
    def send(cls, para):
        from_uid = para['from_uid']
        to_uid = para['to_uid']

        #TODO
        # if cls.isSent(from_uid, to_uid):
        #     return Error.GIFT_SENT

        now = int(time.time())

        key = '%s:%s:%s' % (from_uid, to_uid, now)

        gift_type = random.randint(1, 2)

        data = {
                'from_uid': from_uid,
                'time': now,
                'gid': key,
                'type': gift_type,
                }

        item_type = cls.getIndexItemType()
        item_type(key).setAll(data)

        user_gift = cls(to_uid)
        if user_gift.size() < cls.MAX_SIZE:
            user_gift.addKey(key)

            cli = Redis()
            key = cls.genGiftCacheKey(from_uid, to_uid)
            cli.set(key, 1)
            cli.expire(key, cls.DAY_SEC)
        else:
            Log.error('user_gift full, unable to receive')

        return {}

    @classmethod
    def isSent(cls, from_uid, to_uid):
        key = cls.genGiftCacheKey(from_uid, to_uid)
        return Redis().exists(key)

    @classmethod
    def genGiftCacheKey(cls, from_uid, to_uid):
        day = (int(time.time()) - 7*3600) / cls.DAY_SEC
        return '%s:%s_%s_%d' % (cls.GIFT_CACHE_KEY, from_uid, to_uid, day)

    def doReclaim(self, gid):
        if not self.exists(gid):
            return False

        gift_type = Gift(gid).type

        uid = self.key_
        user = User(uid)
        lv = user.level

        ret = {'type':gift_type}
        if gift_type == Gift.TYPE_COIN:
            sb = CfgTable(CfgTable.CFG_LEVEL_INFO, lv).special_bonus
            coin =  sb / 2 * 100
            user.coin += coin
            ret['gift_coin'] = coin
            ret['coin'] = user.coin
        elif gift_type == Gift.TYPE_FREESPIN:
            machine_id = ConfMgr.getRandomMachineId(lv)
            free_spin = FreeSpin(uid, machine_id)
            spin_num = 5
            lines = ConfMgr.getMediumLineNum(machine_id)
            bet = ConfMgr.getMediumBet(lv)
            free_spin.add(spin_num, lines, bet)
            ret['spin_num'] = 5
            ret['machine_id'] = machine_id

        self.removeOne(gid)

        return ret

if __name__ == '__main__':
    uid = 500
    print UserGift.send({'from_uid':5, 'to_uid':uid})
    print UserGift.load({'uid':uid})

    #gid = '4:500:1392801542'
    #print UserGift.reclaim({'uid': uid, 'gid':gid, 'machine_id':1})
