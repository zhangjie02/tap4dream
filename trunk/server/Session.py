#!/usr/bin/env python

import DB
import hashlib, time

class Session:
    SESSION_KEY = 'session'
    TTL = 86400 # 1 day

    @classmethod
    def is_valid(cls, uid, sid):
        # extend it
        DB.Redis().expire(cls.gen_key(uid), cls.TTL)

        if sid != DB.Redis().get(cls.gen_key(uid)):
            return False

        return True

    @classmethod
    def gen_session(cls, uid):
        sid = hashlib.md5('%d:%.2f' % (uid, time.time())).hexdigest()
        #DB().client.setex(cls.gen_key(uid), cls.TTL, sid)
        DB.Redis().set(cls.gen_key(uid), sid)
        DB.Redis().expire(cls.gen_key(uid), cls.TTL)
        return sid

    @classmethod
    def gen_key(cls, uid):
        return "%s:%d" % (cls.SESSION_KEY, uid)

if __name__ == '__main__':
    Session.gen_session(1)
