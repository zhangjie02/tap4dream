from sqlalchemy import *
from sqlalchemy.sql import column
import json
import sys
sys.path.append('..')

db=create_engine('mysql://droidhen:droidhen.hz@115.236.92.117/slotomania',echo=False)
metadata=MetaData(db)

table='user_bet'
t=Table(table, metadata, autoload=True)


info = {3:[], 4:[], 5:[]}
min_win_rate = {3:5, 4:5, 5:5}

for i in t.select().where(t.c.is_bonus==True).execute():
    #print i['id']

    win_lines = json.loads(i['win_lines'])
    #print win_lines

    n = 0
    for l in win_lines.values():
        if l.has_key('is_bonus') and l['is_bonus']:
            n = len(l['icons'])
            break

    win = i['bonus_win_amount'] * 100
    lines = i['bet_lines']
    bet = i['bet_value']

    if n >= 3:
        if win < bet * min_win_rate[n]:
            #print 'win too low'
            pass
        #elif win > bet * 10000:
        #    print 'too much :id:', i['id']
        else:
            info[n].append((win, lines * bet, win *1.0/ bet, win*1.0/(lines*bet), i['id']))
    else:
        #print 'skip:n=', n
        pass

for n, l in info.items():
    total_win = 0
    total_bet = 0

    rate_min = 10000000000
    rate_max = 0
    total_rate = 0
    count=0

    amount_min = 10000000000
    amount_max = 0
    total_amount = 0

    for v in l:

        #print v
        total_win += v[0]
        total_bet += v[1]

        rate_min = min(rate_min, v[2])
        rate_max = max(rate_max, v[2])
        total_rate += v[2]
        count += 1

        amount_min = min(amount_min, v[0])
        amount_max = max(amount_max, v[0])
        total_amount += v[0]

    print n, "\n"
    print 'count', count
    print 'total_win', total_win
    print 'total_bet', total_bet
    print 'rate', total_win*1.0 / total_bet
    print 'rate_range: ', rate_min, '-', rate_max
    print 'avg_rate:', total_rate / count

    print 'amount_range: ', amount_min, '-', amount_max
    print 'avg_amount:', total_amount / count




"""
s = select([t])
for i in db.execute(s):
    print i
"""
