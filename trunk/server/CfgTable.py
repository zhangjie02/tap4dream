#!/usr/bin/python

from Table import Table
import DB
import Version

class CfgTable(Table):
    FIELD_TYPE = {
                  'revision': int,
                  'validate': int,
                  'version_min': int,
                  'exp': int,
                  'total_exp': int,
                  'level': int,
                  'max_line': int,
                  'unlock_level': int,
                  'is_featured': int,
                  'featured_level': int,
                  'bet': int,
                  'special_bonus': int,
                  }
    SYS_TABLE = 'table:sys_table'
    CFG_MACHINE_INFO = 'cfg_machine_info'
    CFG_LEVEL_INFO = 'cfg_level_info'
    CFG_LEVEL_BET = 'cfg_level_bet'
    CFG_TOURNAMENT = 'cfg_tournament'
    CFG_STORE = 'cfg_store'

    def __init__(self, table, key):
        Table.__init__(self, key, table)

    @classmethod
    def genKSKey(cls, table, version=None):
        if version is None:
            return 'table:%s:key_set' % table
        else:
            return 'table:%s:key_set:%s' % (table, version)

    @classmethod
    def loadAll(cls, data_version, version):
        ret = {}
        for table, v in dict(DB.get_hash(cls.SYS_TABLE)).items():
            if int(v) > data_version:
                ret[table] = cls.load(table, data_version, version)

        return ret

    @classmethod
    def load(cls, table, data_version=None, version=None):
        ret = []
        key_list = []

        if data_version is None:
            key_set = cls.genKSKey(table)
            key_list = list(DB.get_set(key_set))
        else:
            cur_data_version = Version.loadCurDataVersion()

            for dv in range(data_version + 1, cur_data_version + 1):
                key_set = cls.genKSKey(table, dv)
                key_list.extend(list(DB.get_set(key_set)))

        data_list = cls(table, key_list).batchGet()

        for data in data_list:
            ret.append(data)

            # if version is None or version >= int(data['version_min']):
            #     ret.append(data)

        return ret

    @classmethod
    def save(cls, table, data):
        key_set = cls.genKSKey(table)

        for k, v in data.items():
            DB.get_set(key_set).add(k)
            cls(table, k).setAll(v)

            ver_key_set = cls.genKSKey(table, v['revision'])
            DB.get_set(ver_key_set).add(k)

    @classmethod
    def truncate(cls, table):
        key_set = cls.genKSKey(table)
        s = set(DB.get_set(key_set))

        for k in s:
            cls(k, table).remove()

        DB.Redis().delete(key_set)

        cur_data_version = Version.loadCurDataVersion()
        for v in xrange(1, cur_data_version + 1):
            key_set = cls.genKSKey(table, v)
            DB.Redis().delete(key_set)

if __name__ == '__main__':
    # data = {
    #         1: {'revision': 1, 'version_min': 1},
    #         2: {'revision': 2, 'version_min': 1},
    #         3: {'revision': 3, 'version_min': 1},
    #         }
    #CfgTable.save('test_cfg', data)
    #print CfgTable.load('test_cfg', 1)
    print CfgTable.loadAll(1, 1)
    # CfgTable.truncate('cfg_machine_info')
    # data = CfgTable.load(CfgTable.CFG_LEVEL_BET, fields=['level', 'bet'])
    # lv_bet = []
    # for d in data:
    #     lv_bet.append((d['level'], d['bet']))

    # print sorted(lv_bet, key=lambda x: (x[1], x[0]))
    pass
