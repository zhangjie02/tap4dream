#!/usr/bin/python

import time

from Table import Table
import DB

class Stat(Table):
    FIELD_TYPE = {
                  'dau': int,
                  'bet': int,
                  'win': int,
                  'spin': int,
                  'trigger_free_spin': int,
                  'trigger_bonus': int,
                  'free_spin': int,
                  'bonus': int,
                  'buy_coin': int,
                  'free_coin': int,
                  'special_bonus': int,
                  'tournament_prize': int,
                  }

    def __init__(self, day=None):
      if day is None:
        day = time.strftime('%Y%m%d')

      Table.__init__(self, day)

    def incr(self, data):
      rkey = self.genRkey()
      pipe = DB.Redis().pipeline()
      for k, v in data.items():
        pipe.hincrby(rkey, k, v)
      pipe.execute()

if __name__ == '__main__':
  s = Stat()
  s.incr({'bet': 2})
