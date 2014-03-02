//
//  LoadInfoMgr.h
//  poker
//
//  Created by jayson on 13-12-26.
//
//

#ifndef __poker__LoadInfoMgr__
#define __poker__LoadInfoMgr__

#include <iostream>
#include <string>
#include "libjson.h"
#include <map>

using namespace std;

class LoadInfo {
public:
    LoadInfo():totalSize(0),version(0),url("") {}
    
    double totalSize;
    int version;
    string url;
    
public:
    void parse(const JSONNode& param);
    
    void dumpLoadInfo(JSONNode& node);
};

class LoadInfoMgr {
public:
    static LoadInfoMgr* getInstance() {
        static LoadInfoMgr instance;
        return &instance;
    }
    
    LoadInfoMgr();
    
    void setInfo(string url, double totalSize, int version);
    
    void remove(string url);
    
    LoadInfo getLoadInfo(string url);
    
    bool isExist(string url);
private:
    void init();
    
    string dump();
    
    void save();
    
    void clear();
    
private:

    static string KEY_LOAD_INFO;

    map<string, LoadInfo> _loadInfoMap;
};

#endif /* defined(__poker__LoadInfoMgr__) */
