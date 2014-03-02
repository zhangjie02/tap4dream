import random
import sys
#wild 0.57 -> 0.83 (+0.1=>0.95, +0.15=>1, +0.2=>1.07, +0.3=>1.19)
ALL =   [(1,2),
        (2,1.8),
        (3,1.6),
        (4,1.4),
        (5,1.2),
        (6,1),
        (7,0.9),
        (8,0.8),
        (9,0.7),
        (10,0.17),#wild
        (11,0.43),#bonus
        (12,0.65)]#free

WILD = 10
BONUS = 11
FREE = 12

reward = {1:(4,15,50),
    2:(5,20,60),
    3:(10,30,80),
    4:(15,50,100),
    5:(20,75,150),
    6:(25,100,200),
    7:(30,150,300),
    8:(40,200,500),
    9:(50,250,1000),
    10:(100,1000,10000),
    11:(66.5, 66.5*5, 66.5*20),
    12:(0,0,0)}

lines = [(1,1,1,1,1),
    (0,0,0,0,0),
    (2,2,2,2,2),
    (0,1,2,1,0),
    (2,1,0,1,2),
    (1,0,0,0,1),
    (1,2,2,2,1),
    (0,0,1,2,2),
    (2,2,1,0,0),
    (1,2,1,0,1),
    (1,0,1,2,1),
    (0,1,1,1,0),
    (2,1,1,1,2),
    (0,1,0,1,0),
    (2,1,2,1,2),
    (1,1,0,1,1),
    (1,1,2,1,1),
    (0,0,2,0,0),
    (2,2,0,2,2),
    (0,2,2,2,0),
    (2,0,0,0,2),
    (1,2,0,2,1),
    (1,0,2,0,1),
    (0,2,0,2,0),
    (2,0,2,0,2),
    (2,0,1,2,0),
    (0,2,1,0,2),
    (0,2,1,2,0),
    (2,0,1,0,2),
    (2,1,0,0,1),
    (0,1,2,2,1),
    (0,0,2,2,2),
    (2,2,0,0,0),
    (1,0,2,1,2),
    (1,2,0,1,0)]

def choose(s,exclude):
    sum = 0
    for t in s:
        if not t[0] in exclude:
            sum += t[1]
    r = random.uniform(0,sum)
    for t in s:
        if not t[0] in exclude:
            if r < t[1]:
                return t[0]
            r -= t[1]

def genTable(free = True):
    s = []
    if free:
        a = ALL
    else:
        a = ALL[0:11]

    for i in range(0,5):
        t = []
        for j in range(0,3):
            t.append(choose(a,t))
        s.append(t)
    return s


def judgeone(s,line):
    r = 0
    mark = WILD
    wild = 0
    index = 0
    free = 0
    flag = True
    for l in line:
        c = s[index][l]
        if mark == WILD and c != WILD:
            mark = c
        if c == WILD and wild >=0:
            wild +=1
        else:
            wild = -1
        if mark != WILD and (mark!=c and c!= WILD):
            flag = False
        if flag:
            r += 1
        if c == FREE:
            free += 1
        index += 1
    res = 0
    if r ==2:
        if mark in [7, 8, 9]:
            res = reward[mark][r-2]

    if r >= 3:
        res = reward[mark][r-3]
    if wild >= 2:
        temp = reward[WILD][wild-2]
        if temp > res:
            res = temp

    return (free,res)


def judge(s,lines):
    r = 0
    free = 0
    for l in lines:
        t = judgeone(s,l)
        r += t[1]
        if t[0] > free:
            free = t[0]
    return (free,r)



def judgebonus(s):
    bonus = 0
    for a in s:
        for l in a:
            if l == BONUS:
                bonus += 1
    if bonus < 3:
        return 0
    return reward[BONUS][bonus-3]
debug = True
debug = False
if debug:
    s = genTable()
    for t in s:
        print t
    print judge(s,lines)
    s = genTable()
    for t in s:
        print t
    print judge(s,lines)



if __name__ == "__main__" and not debug:
    total = 0
    rewards = 0
    maxline = len(lines)
    count = 0
    rcount = 0
    bcount = 0
    fcount = 0
    wild = ALL[9][1]
    while True:
        count += 1
        flag = False
        ALL[9] = (10,random.uniform(wild-0.1,wild+0.1))
        s = genTable(True)
        betline = random.randint(9,maxline)
        betline = maxline
        #betline = 1
        betlines = lines[0:betline]
        r = judge(s,betlines)
        total += betline
        rewards += r[1]
        bonus = judgebonus(s)
        rewards += bonus

        if bonus > 0:
            bcount += 1

        FREES = [5,10,15]
        free = r[0] - 3

        if free >=0:
            free = FREES[free]
        else:
            free = 0

        if free > 0:
            fcount += 1

        if r[1] > 0:
            flag = True
        for i in range(0,free):
            s = genTable(False)
            r = judge(s,betlines)
            rewards += r[1]
            if r[1] >0:
                flag = True
            t = judgebonus(s)
            rewards += t
            if t > 0:
                flag = True
        if flag:
            rcount += 1

        sys.stdout.write("\r")
        sys.stdout.write("Rate:%f Total bet:%d Reward:%d RewardRate:%f BonusRate:%f FreeSpinRate:%f"%(rewards*1.0/total,total,rewards,1.0*rcount/count, 1.0*bcount/count, 1.0*fcount/count))
        sys.stdout.flush()


