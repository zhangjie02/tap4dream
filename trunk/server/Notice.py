#!/usr/bin/python

from DB import Redis
import DB
import json

class Notice(object):
    TYPE_TOURNAMENT = 1
    TYPE_SHAREGIFT = 2

    def __init__(self, uid):
        self.uid = uid

    def genKey(self, t):
        if t == self.TYPE_TOURNAMENT:
            return 'notice:queue:%s' % (self.uid)
        else:
            return 'notice:counter:%s' % (self.uid)

    def push(self, data):
        t = data['type']
        key = self.genKey(t)

        if t == self.TYPE_TOURNAMENT:
            DB.get_list(key).append(json.dumps(data))
        else:
            DB.Redis().hincrby(key, t)

    def get(self):
        key = self.genKey(self.TYPE_TOURNAMENT)
        data = [json.loads(i) for i in DB.get_list(key)]


        key = self.genKey(self.TYPE_SHAREGIFT)
        h = DB.get_hash(key)

        for k in h.keys():
            data.append({'type':k, 'counter':h[k]})

        self.clear()
        return data

    def clear(self):
        k1 = 'notice:queue:%s' % (self.uid)
        k2 = 'notice:counter:%s' % (self.uid)
        Redis().delete(k1)
        Redis().delete(k2)

if __name__ == '__main__':
    n = Notice(1)

    #n.push({'type':2})
    #n.push({'type':1})
    print Notice(1).get()
