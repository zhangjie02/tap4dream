from sqlalchemy import *
from sqlalchemy.sql import column
import json
import sys, time
sys.path.append('..')


db=create_engine('mysql://droidhen:droidhen.hz@115.236.92.117/slot',echo=False)
metadata=MetaData(db)

table='user'
t=Table(table, metadata, autoload=True)


if __name__ == '__main__':

        """
        ii = 1
        for i in t.select().where(t.c.max_level==10).execute():
            d = dict(i)
            del d['rid']
            d['max_level'] = 1000
            d['amount'] *= 6
            d['item_id'] = 'coin4_%d' % ii
            ii +=1

            t.insert().values(d).execute()
        """

        for i in range(563, 663):
            t.insert().values({'user_id': i}).execute()
