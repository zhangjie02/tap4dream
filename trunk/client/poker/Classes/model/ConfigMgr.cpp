#include "ConfigMgr.h"
#include "Table.h"
#include "TableName.h"
#include "BaseTable.h"
#include "JSONUtil.h"
#include <string>
#include "Preferences.h"

USING_NS_CC;

ConfigMgr::ConfigMgr() {
    for(int i=CfgDataSourceType_Normal; i <= CfgDataSourceType_Replay; i++) {
        CfgDataSource* dataSource = new CfgDataSource();
        CfgDataSourceType type = static_cast<CfgDataSourceType>(i);
        _dataSourceMap.insert(std::pair<CfgDataSourceType, CfgDataSource*>(type, dataSource));
    }
    
    // 默认normal
    switchDataSource(CfgDataSourceType_Normal);
}

ConfigMgr::~ConfigMgr() {
    for(int i=CfgDataSourceType_Normal; i <= CfgDataSourceType_Replay; i++) {
        CfgDataSourceType type = static_cast<CfgDataSourceType>(i);
        CfgDataSource* dataSource = _dataSourceMap.at(type);
        delete dataSource;
    }
}

CfgDataSource* ConfigMgr::getCfgDataSource(CfgDataSourceType type) {
    return _dataSourceMap.at(type);
}

void ConfigMgr::switchDataSource(CfgDataSourceType type) {
     _dataSource = _dataSourceMap.at(type);
}

void ConfigMgr::parseFromServer(const JSONNode& node) {
    CfgDataSource* dataSource = getCfgDataSource(CfgDataSourceType_Normal);
    JSONNode constantsNode = JSONUtil::getNode(node, "constants");
	int dataVersion = JSONUtil::getInt(constantsNode, "data_version");
	if(!dataSource->isLoaded()) {
		dataSource->loadFromLocal();
	}
	if(dataVersion > dataSource->getDataVersion()) {
        CCLOG("[config]update cfgdata and save , new version: %d, local version: %d", dataVersion, dataSource->getDataVersion());
		dataSource->setDataVersion(dataVersion);
		dataSource->update(JSONUtil::getNode(node,"data"));
		dataSource->saveToLocal();
	}
}

void ConfigMgr::parseReplayData(const JSONNode& node) {
    CfgDataSource* dataSource = getCfgDataSource(CfgDataSourceType_Replay);
    if(!dataSource->isLoaded()) {
        dataSource->loadFromLocal();
    }
    
    dataSource->update(JSONUtil::getNode(node,"data"));
    // 切换
    switchDataSource(CfgDataSourceType_Replay);
}

