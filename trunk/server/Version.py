import DB

CUR_DATA_VERSION = 'cfg:cur_data_version'

def loadCurDataVersion():
    return int(DB.Redis().get(CUR_DATA_VERSION))

def saveCurDataVersion(version):
    return DB.Redis().set(CUR_DATA_VERSION, version)


if __name__ == '__main__':
	#print load({'data_version':0, 'version':1})
	#print isBetValid(1,  10)
	#saveCurDataVersion(2)
	print loadCurDataVersion()
