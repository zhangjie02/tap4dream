#ifndef CONFIGMGR_H_
#define CONFIGMGR_H_
#include <map>
#include <string>
#include <vector>
#include "libjson.h"
#include "BaseTable.h"
#include "Table.h"
#include "CfgDataSource.h"
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

enum CfgDataSourceType {
    CfgDataSourceType_Normal,
    CfgDataSourceType_Replay
};

class ConfigMgr {
public:
	static ConfigMgr* getInstance() {
		static ConfigMgr instance;
		return &instance;
	}
    
    /**
     * 获得某个类型数据源
     */
    CfgDataSource* getCfgDataSource(CfgDataSourceType type);

    /**
     * 解析normal数据
     */
	void parseFromServer(const JSONNode& node);
    
    /**
     * 解析replay数据, 并且切换数据源为replay
     */
    void parseReplayData(const JSONNode& node);
    
    /**
     * 切换数据源
     */
    void switchDataSource(CfgDataSourceType type);

	template<typename T>
	vector<T*>* getCfgVOList(string tablename) {
		if(_dataSource != NULL) return _dataSource->getCfgVOList<T>(tablename);
		return NULL;
	}

private:
	ConfigMgr();
    ~ConfigMgr();

private:
	CfgDataSource* _dataSource;

    // 数据源
    map<CfgDataSourceType, CfgDataSource* > _dataSourceMap;

};


#endif /* CONFIGMGR_H_ */
