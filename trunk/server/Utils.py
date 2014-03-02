from Logging import Log
import random

def checkPara(para, in_list):
    for i in in_list:
        if isinstance(i, tuple):
            (k, func) = i
            if not (k in para and func(para[k])):
                Log.error('param error:' + k)
                return False

        elif i not in para:
            Log.error('param not exist:' + i )
            return False

    return True

def toInt(x):
    return int(x) if x else 0

def weightedRandom(s):
    sum = 0
    for t in s:
        sum += s[t]

    r = random.uniform(0,sum)
    for t in s:
        if r < s[t]:
            return t
        r -= s[t]