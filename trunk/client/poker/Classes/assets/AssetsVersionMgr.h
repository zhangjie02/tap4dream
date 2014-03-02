//
//  AssetsVersionMgr.h
//  poker
//
//  Created by jayson on 13-12-12.
//
//

#ifndef __poker__AssetsVersionMgr__
#define __poker__AssetsVersionMgr__

#include <iostream>
#include <map>
#include <string>

using namespace std;

class AssetsVersionMgr {
public:
    static AssetsVersionMgr* getInstance();
    
    int getVersion(string key);
    
    void setVersion(string key, int value);
    
    void clear();
    
public:
    static string KEY_VERSION;
    
private:
    AssetsVersionMgr();
    
    void init();
    
    string dump();
    
    void save();
    
private:
    map<string, int> versionMap;
};

#endif /* defined(__poker__AssetsVersionMgr__) */
