#!/usr/bin/env python

from DB import Redis
from User import User
from Logging import Log
#from Social import Social
from Utils import checkPara
from Error import Error
from Session import Session
import Config
from Social import Social
from django.contrib.gis.geoip import GeoIP
from Location import Location
import time


class Login:

    ID_CTR = 'id_ctr'
    DID2UID = 'did2uid'
    FBID2UID = 'fbid2uid'
    DID2FBID = 'did2fbid'

    DEVICE_TYPE = 0
    FB_TYPE = 1

    GEO = GeoIP()

    @classmethod
    def login(cls, para):
        if not checkPara(para, ['version', 'did', ('type', lambda x: x in [cls.DEVICE_TYPE, cls.FB_TYPE])]):
            return Error.INVALID_PARAM

        version = para['version']
        did = para['did']

        if para['type'] == cls.DEVICE_TYPE:
            (uid, is_new) = Login.device_login(did)
        else:
            if para['fb_id'] in para['frd_list']:
                return Error.INVALID_PARAM

            (uid, is_new) = Login.fb_login(did, para['fb_id'], para['fb_name'], para['frd_list'])

        sid = Session.gen_session(uid)
        ret = {'uid': uid, 'sid': sid}

        user_info = User(uid).get(['coin', 'level', 'exp', 'name'], True)
        user_info['exp'] /= 100

        ret.update(user_info)

        if version < Config.LATEST_VERSION:
            ret['update'] = Config.PKG_URL

        User(uid).login_time = int(time.time())

        if 'ip' in para:
            g = cls.GEO.city(para['ip'])
            Location.update(uid, g['country_code'], g['region'])

        return ret

    @classmethod
    def device_login(cls, did):
        uid = cls.did_to_uid(did)
        is_new = False

        if uid is None:
            uid = cls.create_user(did, cls.DID2UID)
            is_new = True
            Log.info("create user by did: uid=%d" % uid)

        return (uid, is_new)


    @classmethod
    def fb_login(cls, did, fbid, fb_name, frd_list):
        uid = cls.fbid_to_uid(fbid)
        is_new = False

        if uid is None:

            uid = cls.did_to_uid(did)

            # create new account if device already binded to a fb id
            if uid is None or cls.did_to_fbid(did) is not None:
                uid = cls.create_user(fbid, cls.FBID2UID)
                is_new = True
                Log.info("create user by fb: uid=%d" % uid)
            else:
                # clear device id map to enable new login by did?
                Redis().hset(cls.FBID2UID, fbid, uid)
                Redis().hset(cls.DID2FBID, did, fbid)
                Log.info("move user to fb map: uid=%d" % uid)


        #update info
        user = User(uid)
        user.setName(fb_name)

        if not user.fbid:
            #import friends for 1st time
            uid_list = []
            for f in frd_list:
                u = cls.fbid_to_uid(f)
                if u is not None:
                    uid_list.append(u)

            if len(uid_list) > 0:
                Social.importFriends(uid, uid_list)

            user.fbid = fbid

        return (uid, is_new)

    @classmethod
    def did_to_uid(cls, did):
        uid = Redis().hget(cls.DID2UID, did)

        return None if uid is None else int(uid)

    @classmethod
    def fbid_to_uid(cls, fbid):
        uid = Redis().hget(cls.FBID2UID, fbid)

        return None if uid is None else int(uid)

    @classmethod
    def did_to_fbid(cls, did):
        fbid = Redis().hget(cls.DID2FBID, did)

        return fbid

    @classmethod
    def create_user(cls, key_id, id_map):
        uid = Redis().incr(cls.ID_CTR)
        Redis().hset(id_map, key_id, uid)

        User.create(uid)

        return uid


if __name__ == '__main__':

    # n = 100
    # for i in range(n):
    #     did = 'robot:%d' % i
    #     para = {'version': 1, 'did': did, 'type':0}
    #     ret = Login.login(para)
    #     print ret
    #     print ret['uid']
    #print Login.device_login('zcfz')
    print Login.fb_login('abc', 'f1', 'fn', ['f2', 'f3'])
    print Login.fb_login('abcd', 'f2', 'fn', ['f1'])
