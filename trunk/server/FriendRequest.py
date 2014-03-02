#!/usr/bin/python

from DB import Redis
from Error import Error
from Social import Social
from User import User
import json, time

class FriendRequest(object):

    def __init__(self, uid):
        self.uid = uid
        self.key = 'friend_req:%s' % uid

    @classmethod
    def load(cls, para):
        uid = para['uid']
        data = [{'uid': u, 'name': User(u).getName(), 'icon': User(u).getIcon(), 'level': User(u).level, 'time': int(t)} for (u, t) in cls(uid).doLoad()]

        return {'requests': data}

    @classmethod
    def send(cls, para):
        uid = para['uid']
        fuid = para['fuid']

        if uid == fuid:
            return Error.INVALID_PARAM

        if not cls(fuid).add(uid):
            return Error.REQUEST_SENT

        return {}

    @classmethod
    def confirm(cls, para):
        uid = para['uid']
        fuid = para['fuid']

        req = cls(uid)

        if not req.exist(fuid):
            return Error.REQUEST_NOT_EXIST

        if Social.importFriends(uid, [fuid]) is False:
            return Error.FRIEND_FULL

        req.delete(fuid)

        return {}

    @classmethod
    def ignore(cls, para):
        uid = para['uid']
        fuid = para['fuid']

        req = cls(uid)
        req.delete(fuid)

        return {}

    def doLoad(self):
        return Redis().zrevrange(self.key, 0, -1, withscores=True)

    def add(self, fuid):
        if self.exist(fuid):
            return False

        now = int(time.time())
        Redis().zadd(self.key, fuid, now)
        return True

    def exist(self, fuid):
        return False if Redis().zrank(self.key, fuid) is None else True

    def delete(self, fuid):
        Redis().zrem(self.key, fuid)


if __name__ == '__main__':
    uid = 1
    fuid = 2

    para = {'uid':uid, 'fuid':fuid}
    print FriendRequest.send(para)
    print FriendRequest.confirm(para)
    print FriendRequest.load(para)
