#ifndef __spacewar__CfgDataSource__
#define __spacewar__CfgDataSource__

#include <iostream>
#include <map>
#include "Table.h"
#include "libjson.h"
#include <list>

using namespace std;

class CfgDataSource {
public:
    CfgDataSource();
    ~CfgDataSource();
    
    void parse(const JSONNode& node);
	void update(const JSONNode& node);
    
    void saveToLocal();
	void loadFromLocal();
    
	void dump(JSONNode& node) const;
    
    void dumpTables(JSONNode& node, list<string>& tableList) const;
    
    void clear();
    
    int getDataVersion();
    void setDataVersion(int version);
    bool isLoaded();
    
    template<typename T>
	vector<T*>* getCfgVOList(string tablename) {
		map<string,BaseTable*>::iterator iter = _tableMap->find(tablename);
		if(iter != _tableMap->end()) {
			BaseTable* basetable = iter->second;
			Table<T>* table = static_cast<Table<T>*>(basetable);
			return table->getData();
		}
		return NULL;
	}
    
private:
    void init();
    
private:
	static const char* SHADRED_KEY;
	static const char* KEY_DATAVERSION;
	static const char* KEY_CONTENT;
    
private:
    int _dataVersion;
    bool _loaded;
    map<string,BaseTable*>* _tableMap;
};

#endif /* defined(__spacewar__CfgDataSource__) */
