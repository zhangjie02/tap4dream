//
//  LuaManager.cpp
//  poker
//
//  Created by xiaoxiangzi on 13-12-26.
//
//

#include "LuaManager.h"
#include "Lua_extensions_CCB.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "Lua_web_socket.h"
#endif
#include "CCLuaEngine.h"
#include "cocos2d.h"
#include "StringConverter.h"
#include <algorithm>
#include "Global.h"
#include "LuaCocoStudio.h"
using namespace cocos2d;

LuaManager* LuaManager::getInstance() {
    static LuaManager manager;
    return &manager;
}

LuaManager::LuaManager() {}

void LuaManager::init() {
    // register lua engine
    CCLuaEngine* pEngine = CCLuaEngine::defaultEngine();
    CCScriptEngineManager::sharedManager()->setScriptEngine(pEngine);
    
    CCLuaStack *pStack = pEngine->getLuaStack();
    lua_State *tolua_s = pStack->getLuaState();
    tolua_extensions_ccb_open(tolua_s);
    tolua_CocoStudio_open(tolua_s);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
    pStack = pEngine->getLuaStack();
    tolua_s = pStack->getLuaState();
    //tolua_web_socket_open(tolua_s);
#endif
}

string LuaManager::getDirPath(const string &fileFullpath) const {
    size_t index = fileFullpath.rfind("/");
    if (index == fileFullpath.npos) {
        CCLOG("wrong file path %s", fileFullpath.c_str());
        return "";
    }
    
    string dirPath = fileFullpath.substr(0, index);
    return dirPath;
}

void LuaManager::runLua(const string &path) {
    if (path.size() == 0) {
        CCLOG("empty lua path %s", path.c_str());
        return;
    }
    
    string fullpath = CCFileUtils::sharedFileUtils()->fullPathForFilename(path.c_str());
    string dirPath = getDirPath(fullpath);
    addSearchPath(dirPath);
    CCLuaEngine::defaultEngine()->executeScriptFile(fullpath.c_str());
}


void LuaManager::addSearchPath(const string &path) {
    auto iter = find(_searchPath.begin(), _searchPath.end(), path);
    if (iter == _searchPath.end()) {
        _searchPath.push_back(path);
        CCLOG("LuaManager: add lua search path %s", path.c_str());
        CCLuaEngine::defaultEngine()->addSearchPath(path.c_str());
    }
}

void LuaManager::addCommonLuaSearchPath() {
    /*string filename = SlotResourceManager::getInstance()->getOtherResourceIdById(AssetsConfig::DEBUG_UTIL_LUA, OTHERRESTYPE_ASSETS);
    string fullpath = CCFileUtils::sharedFileUtils()->fullPathForFilename(filename.c_str());
    string dirPath = getDirPath(fullpath);
    addSearchPath(dirPath); */
}
