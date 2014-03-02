#!/usr/bin/python
from Logging import Log
from Table import Table

class FreeSpin(Table):
    FIELD_TYPE = {
        'lines': int,
        'bet': int,
        'left': lambda x: int(x) if x else 0,
    }

    SCATTER_RATE = {1: {3:5, 4:10, 5:20},
                    2: {3:5, 4:10, 5:20},
                    3: {3:9, 4:15, 5:30},
                    }

    def __init__(self, uid, machine_id):
        Table.__init__(self, "%s:%s" % (uid, machine_id))

    @classmethod
    def getNum(cls, machine_id, n):
        if machine_id not in cls.SCATTER_RATE:
            Log.error('FreeSpin::getNum: machine_id=%s invalid'%machine_id)
            machine_id = 1
        return cls.SCATTER_RATE[machine_id][n]

    def add(self, n, lines, bet):
        self.left += n
        self.lines = lines
        self.bet = bet

    def consume(self):
        now = self.left - 1
        if now < 0:
            Log.error('not enough spin')
            return False

        ret = (self.lines, self.bet)

        if now == 0:
            self.remove()
        else:
            self.left = now

        return ret


if __name__ == '__main__':
    c = FreeSpin(1, 1)
    #c.add(5, 10, 100)
    print c.consume()
