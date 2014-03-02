#include "CfgDataSource.h"
#include "TableName.h"
#include "Preferences.h"
#include "cocos2d.h"
#include "BaseTable.h"
#include "Global.h"


USING_NS_CC;

const char* CfgDataSource::SHADRED_KEY 		= "cfgdata";
const char* CfgDataSource::KEY_DATAVERSION	= "key_dataversion";
const char* CfgDataSource::KEY_CONTENT		= "key_content";

CfgDataSource::CfgDataSource(): _loaded(false), _dataVersion(0) {
    _tableMap = new map<string,BaseTable*>();
    init();
}

CfgDataSource::~CfgDataSource() {
    map<string,BaseTable*>::iterator iter = _tableMap->begin();
    while(iter != _tableMap->end()) {
        BaseTable* table = (*iter).second;
        delete table;
    }
    delete _tableMap;
}

void CfgDataSource::saveToLocal() {
    JSONNode node = JSONNode(JSON_NODE);
	node.push_back(JSONNode(CfgDataSource::KEY_DATAVERSION, _dataVersion));
	JSONNode content = JSONNode(JSON_NODE);
	content.set_name(CfgDataSource::KEY_CONTENT);
	dump(content);
	node.push_back(JSONNode(content));
	string info = node.write();
	Preferences::sharedPreferences()->setStringForKey(CfgDataSource::SHADRED_KEY, info);
}

void CfgDataSource::loadFromLocal() {
#if CLEAR_LOCAL_CFG_DATA
    clear();
#endif
    string cfgdata = Preferences::sharedPreferences()->getStringForKey(CfgDataSource::SHADRED_KEY);

	if(cfgdata == "") {
        CCLOG("[config] local data is empty");
        return;
    }
	JSONNode data = libjson::parse_unformatted(cfgdata.c_str());
	_dataVersion = JSONUtil::getInt(data,CfgDataSource::KEY_DATAVERSION);
	JSONNode content = JSONUtil::getNode(data,CfgDataSource::KEY_CONTENT);
	parse(content);
	_loaded = true;
    CCLOG("[config] load cfg from local, dataversion:%d",_dataVersion);
}

void CfgDataSource::parse(const JSONNode& node) {
	for(JSONNode::const_iterator iter = node.begin(); iter != node.end(); ++iter) {
		string name = iter->name();
		map<string, BaseTable*>::const_iterator mapiter = _tableMap->find(name);
		if(mapiter != _tableMap->end()) {
			BaseTable* table = mapiter->second;
			table->init(iter->as_array());
		}
	}
}

void CfgDataSource::dumpTables(JSONNode& node, list<string>& tableList) const {
    for(map<string, BaseTable*>::const_iterator iter = _tableMap->begin(); iter != _tableMap->end(); iter++){
        string tableName = iter->first;
        
        bool isInList = false;
        for(list<string>::iterator nameIter = tableList.begin(); nameIter != tableList.end(); nameIter++) {
            if(tableName ==  (*nameIter)) {
                isInList = true;
                break;
            }
        }
        
        if(isInList) {
            JSONNode tableNode(JSON_ARRAY);
            tableNode.set_name(tableName);
            iter->second->dump(tableNode);
            node.push_back(tableNode);
        }
	}
}

void CfgDataSource::dump(JSONNode& node) const {
	node.clear();
	for(map<string, BaseTable*>::const_iterator iter = _tableMap->begin(); iter != _tableMap->end(); iter++){
		JSONNode tableNode(JSON_ARRAY);
		tableNode.set_name(iter->first);
		iter->second->dump(tableNode);
		node.push_back(tableNode);
	}
}

void CfgDataSource::update(const JSONNode& node) {
    CCLOG("[config] update content: %s", node.write_formatted().c_str());
	for(JSONNode::const_iterator iter = node.begin(); iter != node.end(); ++iter) {
		string name = iter->name();
		map<string, BaseTable*>::const_iterator mapiter = _tableMap->find(name);
		if(mapiter != _tableMap->end()) {
			BaseTable* table = mapiter->second;
            CCLOG("[config]update table: %s, content:%s", name.c_str(),iter->write_formatted().c_str());
			table->update(iter->as_array());
		}
	}
}

void CfgDataSource::clear() {
    _dataVersion = 0;
    _loaded = false;
    Preferences::sharedPreferences()->setStringForKey(CfgDataSource::SHADRED_KEY, "");
}

int CfgDataSource::getDataVersion() {
    return _dataVersion;
}

void CfgDataSource::setDataVersion(int version) {
    _dataVersion = version;
}

bool CfgDataSource::isLoaded() {
    return _loaded;
}


void CfgDataSource::init() {
	
}