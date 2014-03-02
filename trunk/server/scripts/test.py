from sqlalchemy import *
from sqlalchemy.sql import column
from sqlalchemy.sql import and_, expression
import json
import sys
sys.path.append('..')

db=create_engine('mysql://droidhen:droidhen.hz@115.236.92.117/slotomania',echo=False)
metadata=MetaData(db)

table='user_bet'
t=Table(table, metadata, autoload=True)


q = expression.select([t.c.user_id], limit=5)
for i in q.execute():
    print dict(i)
