#!/usr/bin/python
import time

import DB

class IndexTable:

    def __init__(self, key):
        self.key_ = key

    def getIndexKey(self):
        return 'table:%s:%s:key_set' % (self.__class__.__name__, self.key_)

    def addKey(self, key):
        cli = DB.Redis()
        cli.zadd(self.getIndexKey(), key, int(time.time()))

    """
    @classmethod
    def getIndexItemType():
        return Table
    """

    #time based(desc)
    def range(self, from_time, to_time=0):
        cli = DB.Redis()

        item_type = self.__class__.getIndexItemType()

        r = cli.zrevrangebyscore(self.getIndexKey(), from_time, to_time)
        return [item_type(key) for key in r]

    def getAll(self):
        cli = DB.Redis()

        item_type = self.__class__.getIndexItemType()

        r = cli.zrange(self.getIndexKey(), 0, -1)
        return [(key, item_type(key)) for key in r]


    # remove oldest n records
    def remove(self, n):
        cli = DB.Redis()

        item_type = self.__class__.getIndexItemType()

        r = cli.zrange(self.getIndexKey(), 0, n - 1)
        for key in r:
            cli.zrem(self.getIndexKey(), key)
            item_type(key).remove()

    def size(self):
        cli = DB.Redis()
        return cli.zcard(self.getIndexKey())

    def exists(self, k):
        cli = DB.Redis()
        return cli.zrank(self.getIndexKey(), k) is not None

    def removeOne(self, key):
        cli = DB.Redis()
        item_type = self.__class__.getIndexItemType()
        cli.zrem(self.getIndexKey(), key)
        item_type(key).remove()


if __name__ == '__main__':
    pass
