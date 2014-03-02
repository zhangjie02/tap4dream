from sqlalchemy import *
import sys
sys.path.append('..')

import DB
from CfgTable import CfgTable
import Version

def sync_sys_table():
    t=Table('sys_table', metadata, autoload=True)
    data = {}
    cur_data_version = 1

    for i in t.select().execute():
        item = dict(i)
        data[item['name']] = int(item['version'])

        if (int(item['version']) > cur_data_version):
            cur_data_version = int(item['version'])

    print 'Syncing sys table', data

    DB.Redis().delete(CfgTable.SYS_TABLE)

    for k, v in data.items():
        DB.get_hash(CfgTable.SYS_TABLE)[k] = v

    print 'current_data_version:', cur_data_version

    Version.saveCurDataVersion(cur_data_version)

def sync_table(table, id_column):
    print 'Syncing ', table

    CfgTable.truncate(table)

    data = {}

    t=Table(table, metadata, autoload=True)

    for i in t.select().execute():
        data[getattr(i, id_column)] = dict(i)

    CfgTable.save(table, data)


db=create_engine('mysql://droidhen:droidhen.hz@115.236.92.117/slot',echo=False)
metadata=MetaData(db)


sync_table('cfg_machine_info', 'id')
sync_table('cfg_level_info', 'level')
sync_table('cfg_machine_icon', 'id')
sync_table('cfg_machine_zip', 'id')
sync_table('cfg_level_bet', 'rid')
sync_table('cfg_tournament', 'tid')
sync_table('cfg_store', 'product_id')
sync_table('cfg_assets', 'id')
sync_sys_table()
