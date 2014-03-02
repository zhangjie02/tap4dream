#!/usr/bin/env python

import time
from User import User
from DB import Redis

class Social:
    FRDS_KEY = 'frds'
    MAX_FRIEND_NUM = 100

    DAY_SEC = 86400

    @classmethod
    def getFriends(cls, para):
        uid = para['uid']
        frds = []

        l = Redis().smembers(cls.gen_frd_key(uid))
        #l.add(uid)

        from UserGift import UserGift

        for u in l:
            user = User(int(u))
            frds.append({'uid': int(u), 'level': user.level, 'name': user.getName(), 'icon': user.getIcon(),
                        'coin': user.coin, 'login_time': user.login_time,
                        'is_sent': UserGift.isSent(uid, u),})

        #sort by level
        return {'friends': sorted(frds, key = lambda x: x['level'])}

    @classmethod
    def deleteFriend(cls, para):
        uid = para['uid']
        fuid = para['fuid']

        Redis().srem(cls.gen_frd_key(uid), fuid)

        return {}

    @classmethod
    def gen_frd_key(cls, uid):
        return '%s:%s' % (cls.FRDS_KEY, uid)

    @classmethod
    def gen_gift_box_key(cls, uid):
        return '%s:%s' % (cls.GIFT_BOX_KEY, uid)

    @classmethod
    def gen_gift_key(cls, gid):
        return '%s:%s' % (cls.GIFT_KEY, gid)

    @classmethod
    def gen_gift_cache_key(cls, from_id, to_id):
        day = (int(time.time()) - 7*3600) / cls.DAY_SEC
        return '%s:%d_%s_%d' % (cls.GIFT_CACHE_KEY, from_id, to_id, day)

    @classmethod
    def importFriends(cls, uid, uid_list):
        friend_num = Redis().scard(cls.gen_frd_key(uid))
        if friend_num >= cls.MAX_FRIEND_NUM:
            return False

        #truncate for fb import
        if friend_num + len(uid_list) > cls.MAX_FRIEND_NUM:
            uid_list = uid_list[:cls.MAX_FRIEND_NUM - friend_num]

        pipe = Redis().pipeline()
        for i in uid_list:
            pipe.sadd(cls.gen_frd_key(uid), i)
            pipe.sadd(cls.gen_frd_key(i), uid)
        pipe.execute()


    @classmethod
    def isFriend(cls, uid, fuid):
        return Redis().sismember(cls.gen_frd_key(uid), fuid)

    @classmethod
    def getFriendsUID(cls, uid):
        return [u for u in Redis().smembers(cls.gen_frd_key(uid))]

if __name__ == '__main__':
    #print Social.importFriends(1, [2, 3])
    print Social.getFriends({'uid':663})
