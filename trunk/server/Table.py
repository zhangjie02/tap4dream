#!/usr/bin/python

import DB

class Table(object):

    def __init__(self, key, table=None):
        self.key_ = key
        self.table_ = table if table else self.__class__.__name__

    def genRkey(self, key=None):
        if key is None:
            key = self.key_

        rkey = 'table:%s:%s' % (self.table_, key)

        return rkey

    def __getattr__(self, attr):
        rkey = self.genRkey()
        val = DB.get_hash(rkey).get(attr, None)

        if attr in self.FIELD_TYPE:
            return self.FIELD_TYPE[attr](val)
        else:
            return val

    def __setattr__(self, attr, val):
        if attr.endswith('_'):
            object.__setattr__(self, attr, val)
        else:
            rkey = 'table:%s:%s' % (self.__class__.__name__, self.key_)
            DB.get_hash(rkey)[attr] = val

    def batchGet(self):
        if isinstance(self.key_, list):
            key_list = [self.genRkey(k) for k in self.key_]

            pipe = DB.Redis().pipeline()
            for k in key_list:
                pipe.hgetall(k)
            return pipe.execute()
        else:
            raise Exception('call batchGet with non-list key')

    def get(self, attr, is_dict=False):
        if isinstance(attr, list):
            if is_dict:
                return {a:self.__getattr__(a) for a in attr}
            else:
                return [self.__getattr__(a) for a in attr]
        else:
            return self.__getattr__(attr)

    def getAll(self):
        rkey = self.genRkey()
        return dict(DB.get_hash(rkey))

    def set(self, attr, value):
        rkey = self.genRkey()
        DB.get_hash(rkey)[attr] = value

    def setAll(self, data):
        rkey = self.genRkey()
        h = DB.get_hash(rkey)
        for k, v in data.items():
            h[k] = v

    def remove(self):
        rkey = self.genRkey()
        DB.Redis().delete(rkey)

    def exists(self):
        rkey = self.genRkey()
        return DB.Redis().exists(rkey)

if __name__ == '__main__':
    pass
