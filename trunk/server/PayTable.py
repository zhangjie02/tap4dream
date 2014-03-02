#!/usr/bin/env python

import random
from Logging import Log

class PayTable:
    LINES = [[1, 1, 1, 1, 1],
            [0, 0, 0, 0, 0],
            [2, 2, 2, 2, 2],
            [0, 1, 2, 1, 0],
            [2, 1, 0, 1, 2],
            [1, 0, 0, 0, 1],
            [1, 2, 2, 2, 1],
            [0, 0, 1, 2, 2],
            [2, 2, 1, 0, 0],
            [1, 2, 1, 0, 1],
            [1, 0, 1, 2, 1],
            [0, 1, 1, 1, 0],
            [2, 1, 1, 1, 2],
            [0, 1, 0, 1, 0],
            [2, 1, 2, 1, 2],
            [1, 1, 0, 1, 1],
            [1, 1, 2, 1, 1],
            [0, 0, 2, 0, 0],
            [2, 2, 0, 2, 2],
            [0, 2, 2, 2, 0],
            [2, 0, 0, 0, 2],
            [1, 2, 0, 2, 1],
            [1, 0, 2, 0, 1],
            [0, 2, 0, 2, 0],
            [2, 0, 2, 0, 2],
            [2, 0, 1, 2, 0],
            [0, 2, 1, 0, 2],
            [0, 2, 1, 2, 0],
            [2, 0, 1, 0, 2],
            [2, 1, 0, 0, 1],
            [0, 1, 2, 2, 1],
            [0, 0, 2, 2, 2],
            [2, 2, 0, 0, 0],
            [1, 0, 2, 1, 2],
            [1, 2, 0, 1, 0],
            [0, 1, 0, 1, 2],
            [2, 1, 2, 1, 0],
            [1, 2, 2, 0, 0],
            [0, 0, 1, 1, 2],
            [2, 2, 1, 1, 0],
            [2, 0, 0, 0, 0],
            [0, 2, 2, 2, 2],
            [2, 2, 2, 2, 0],
            [0, 0, 0, 0, 2],
            [1, 0, 1, 0, 1],
            [1, 2, 1, 2, 1],
            [0, 1, 2, 2, 2],
            [2, 1, 0, 0, 0],
            [0, 1, 1, 1, 1],
            [2, 1, 1, 1, 1],
            ]

    WILD = 100
    SCATTER = 200 # for free spin
    BONUS = 300
    TRAP = 400 # hide in the bonus batch

    TRIPLE_WILD = 500

    PAYTABLE = {
            1: {0:{5:1000, 4:250, 3:50, 2:5},
                1:{5:500, 4:200, 3:40, 2:4},
                2:{5:300, 4:150, 3:30, 2:3},
                3:{5:200, 4:100, 3:25},
                4:{5:150, 4:75, 3:20},
                5:{5:100, 4:50, 3:15},
                6:{5:80, 4:30, 3:10},
                7:{5:60, 4:20, 3:5},
                8:{5:50, 4:15, 3:4},
                WILD:{5:10000, 4:1000, 3:100, 2:10},
                },

            2: {0:{5:1000, 4:250, 3:50, 2:5},
                1:{5:500, 4:200, 3:40, 2:4},
                2:{5:300, 4:150, 3:30, 2:3},
                3:{5:200, 4:100, 3:25, 2:2},
                4:{5:150, 4:75, 3:20},
                5:{5:100, 4:40, 3:15},
                6:{5:75, 4:25, 3:8},
                7:{5:60, 4:20, 3:6},
                8:{5:50, 4:15, 3:5},
                WILD:{5:8888, 4:888, 3:88, 2:8},
                },

            3: {0:{5:4000, 4:500, 3:50, 2:5},
                1:{5:500, 4:250, 3:40, 2:4},
                2:{5:300, 4:150, 3:30, 2:3},
                3:{5:250, 4:100, 3:25, 2:2},
                4:{5:200, 4:75, 3:20},
                5:{5:150, 4:50, 3:15},
                6:{5:100, 4:30, 3:10},
                7:{5:80, 4:20, 3:5},
                8:{5:60, 4:15, 3:4},
                },

            4: {0:{5:1000, 4:200, 3:50},
                1:{5:500, 4:100, 3:20},
                2:{5:250, 4:80, 3:15},
                3:{5:200, 4:50, 3:10},
                4:{5:150, 4:30, 3:8},
                5:{5:100, 4:20, 3:6},
                6:{5:75, 4:15, 3:4},
                7:{5:50, 4:12, 3:3},
                WILD:{5:10000, 4:1500, 3:150},
                },
            }

    SYMBOL_WEIGHT = {
                1:  {8: 2,
                     7:1.8,
                     6:1.6,
                     5:1.4,
                     4:1.2,
                     3:1,
                     2:0.9,
                     1:0.8,
                     0:0.7,
                     WILD: 0.4,#wild
                     BONUS: 0.6,#bonus
                     SCATTER: 0.6, #free
                     #TRIPLE_WILD: 0.2,
                     },
                4:  {7:1.8,
                     6:1.6,
                     5:1.4,
                     4:1.2,
                     3:1,
                     2:0.9,
                     1:0.8,
                     0:0.7,
                     WILD: 0.4,#wild
                     BONUS: 0.6,#bonus
                     SCATTER: 0.6, #free
                     #TRIPLE_WILD: 0.2,
                     },
                     }
    """
    SYMBOL_WEIGHT = {8: 2,
                     7:1.8,
                     6:1.6,
                     5:1.4,
                     4:1.2,
                     3:1,
                     2:0.9,
                     1:0.8,
                     0:0.7,
                     WILD: 0.47,#wild
                     BONUS: 0.43,#bonus
                     SCATTER: 0.88, #free
                     #TRIPLE_WILD: 0.2,
                     }
    """

    @classmethod
    def getPayTable(cls, game_id):
        if game_id not in cls.PAYTABLE:
            Log.error('getPayTable:game_id=%s invalid, using 1 instead'%game_id)
            game_id = 1
        return cls.PAYTABLE[game_id]

    @classmethod
    def getSymbolWeightById(cls, game_id):
        if game_id not in cls.SYMBOL_WEIGHT:
            Log.error('getSymbolWeightById:game_id=%s invalid, using 1 instead'%game_id)
            game_id = 1
        return cls.SYMBOL_WEIGHT[game_id]

    @classmethod
    def isWild(cls, s):
        return s == cls.WILD or s == cls.TRIPLE_WILD

    @classmethod
    def getInitSymbols(cls, game_id):
        excludes = [PayTable.TRIPLE_WILD, PayTable.WILD, PayTable.SCATTER, PayTable.BONUS]
        w = cls.getSymbolWeightById(game_id)
        #w = cls.getPayTable(game_id)
        return [s for s in w.keys() if s not in excludes]

    @classmethod
    def getAllSymbols(cls, game_id):
        w = cls.getSymbolWeightById(game_id)
        #w = cls.getPayTable(game_id)
        return [k for k in w.keys() if k != PayTable.TRIPLE_WILD]

    @classmethod
    def getSymbolWeight(cls, game_id, lv, is_free, bet, fake_flag):
        w = dict(cls.getSymbolWeightById(game_id))

        #if is_free:
        #    del(w[PayTable.SCATTER])

        # if game_id != 2:
        #     del(w[PayTable.TRIPLE_WILD])
        #del(w[PayTable.TRIPLE_WILD])

        if lv < 3:
            w[cls.WILD] += (3 - lv) * 0.1

        if bet <= 10:
            w[cls.WILD] += 0.15
        else:
            wave = 0.3
            w[cls.WILD] = random.uniform(w[cls.WILD] - wave, w[cls.WILD] + wave)

        if fake_flag == 1:
            w[PayTable.SCATTER] += 5
        elif fake_flag == 2:
            w[PayTable.BONUS] += 5
        elif fake_flag == 3:
            if PayTable.TRIPLE_WILD in w:
                w[PayTable.TRIPLE_WILD] += 5

        return w

if __name__ == '__main__':
    print PayTable.getAllSymbols(2)
    #print PayTable.getInitSymbols(2)
