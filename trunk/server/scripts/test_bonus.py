from sqlalchemy import *
from sqlalchemy.sql import column
from sqlalchemy.sql import and_, or_, not_
import json
import sys, time
sys.path.append('..')


db=create_engine('mysql://droidhen:droidhen.hz@115.236.92.117/slotomania',echo=False)
metadata=MetaData(db)

table='user_bet_bonus'
t=Table(table, metadata, autoload=True)

def set_bonus_num():
    for i in t.select().execute():
        l = i['win_lines']
        id = i['id']
        bonus_num = 0
        if l.count('[') == 1:
            bonus_num = len([i for i in l[1:-1].split(',')])

        print id, l, bonus_num

        if bonus_num > 0:
            t.update().where(t.c.id == id).values({'bonus_num':bonus_num}).execute()



def main():


    level_set = {i:set() for i in range(1, 6)}

    for i in t.select().where(and_(t.c.machine_id==8, t.c.bonus_num==3)).execute():
        bonus_level = i['bonus_level']
        l = i['icons']

        if bonus_level == 5:
            print i

        c = [int(j) for j in l[1:-1].split(',') if int(j) > 0]

        for k in c:
            level_set[bonus_level].add(k)

    for k, v in level_set.items():
        print 'lv:', k
        print min(list(v)), max(v)


    print level_set

if __name__ == '__main__':
    main()
