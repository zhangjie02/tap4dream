//
//  AssetsVersionMgr.cpp
//  poker
//
//  Created by jayson on 13-12-12.
//
//

#include "AssetsVersionMgr.h"
#include "Preferences.h"
#include "libjson.h"
#include "cocos2d.h"
#include "Global.h"
string AssetsVersionMgr::KEY_VERSION = "key_version";

AssetsVersionMgr* AssetsVersionMgr::getInstance() {
    static AssetsVersionMgr instance;
    return &instance;
}

AssetsVersionMgr::AssetsVersionMgr() {
#if CLEAR_LOCAL_VERSION_DATA
    clear();
#endif
    
    init();
}

void AssetsVersionMgr::clear() {
    Preferences::sharedPreferences()->setStringForKey(KEY_VERSION.data(), "");
}

int AssetsVersionMgr::getVersion(string key) {
    if(versionMap.find(key) != versionMap.end()) {
        return versionMap[key];
    }
    return 0;
}

void AssetsVersionMgr::setVersion(string key, int value) {
    int nowVersion = getVersion(key);
    if(value < nowVersion) {
        CCLOG("[version]error set version, now: %d, new: %d, key: %s", nowVersion, value, key.data());
        return;
    }
    versionMap[key] = value;
    save();
}

void AssetsVersionMgr::init() {
    string versionInfo = Preferences::sharedPreferences()->getStringForKey(KEY_VERSION.data());
    //CCLOG("[version] init : %s", versionInfo.c_str());
    if(versionInfo.size() <= 0) return;
    JSONNode node = libjson::parse(versionInfo);
    JSONNode::iterator iter = node.begin();
    while (iter != node.end()) {
        string name = iter->name();
        int version = iter->as_int();
        versionMap[name] = version;
        
        iter++;
    }
}

string AssetsVersionMgr::dump() {
    JSONNode node;
    map<string,int>::iterator iter = versionMap.begin();
    while(iter != versionMap.end()) {
        string key = iter->first;
        int version = iter->second;
        
        node.push_back(JSONNode(key, version));
        iter++;
    }
    return node.write_formatted();
}

void AssetsVersionMgr::save() {
    string data = dump();
    //CCLOG("[version] save: %s", data.c_str());
    Preferences::sharedPreferences()->setStringForKey(KEY_VERSION.data(), data);
}