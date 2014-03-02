//
//  AssetsMgr.cpp
//  poker
//
//  Created by jayson on 13-12-4.
//
//

#include "AssetsMgr.h"
#include "AssetsLoader.h"
#include "cocos2d.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include "ArrayUtil.h"
#include "FileUtil.h"
#include "Constant.h"
#include "AssetsVersionMgr.h"
#include <sstream>
#include <regex.h>

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
#include <dirent.h>
#include <sys/stat.h>
#endif

using namespace cocos2d;
using namespace std;


AssetsMgr::AssetsMgr() {
    _loaderList = new list<LoaderItem*>();
    
}

AssetsMgr::~AssetsMgr() {
    ArrayUtil::clearList(_loaderList);
    delete _loaderList;
}

string AssetsMgr::getDirFromFile(string filepath) {
    char reg[] = "(\\.[a-z0-9A-Z_-]+)*$";
    const char* url = filepath.data();
    string sufix = "";
    regex_t pattern;
    size_t nmatch = 2;
    int nErrCode = 0;
    if((nErrCode = regcomp(&pattern, reg, REG_EXTENDED)) == 0){
        regmatch_t pmatch[nmatch];
        if ((nErrCode = regexec(&pattern, url, nmatch, pmatch, 0)) == 0) {
            regoff_t so = pmatch[1].rm_so;
            regoff_t eo = pmatch[1].rm_eo;
            char result[64];
            memcpy(result, url + so, eo - so);
            result[eo - so] = '\0';
            sufix.append(result);
        }
        regfree(&pattern);
    }
    if(sufix.size() > 0) {
        filepath.replace(filepath.find(sufix), sufix.size(), "");
        return filepath;
    }
    
    CCLOG("[assets]get dir from file error, file %s, result: %s", filepath.data(), sufix.data());
    return "";
}

bool AssetsMgr::isLoading(string url) {
    AssetsLoader* loader = getLoader(url);
    if(loader) {
        return loader->isLoading();
    }
    return false;
}

void AssetsMgr::onError(int errorCode, AssetsLoader* loader) {
    LoaderItem* item = getLoaderItem(loader);
    removeItemFromList(item);
    if(item) {
        item->fail();
    }
    CCLOG("[error]assets failed: %s", loader->getUrl().data());
    delete item;
}

void AssetsMgr::onProgress(int percent, AssetsLoader* loader) {
    
}

void AssetsMgr::onSuccess(AssetsLoader* loader) {
    LoaderItem* item = getLoaderItem(loader);
    AssetsVersionMgr::getInstance()->setVersion(item->loader->getUrl(), item->serverVersion);
    removeItemFromList(item);
    
    if(item) {
        item->success();
    }
    delete item;
}

float AssetsMgr::getLoadPercent(string url) {
    AssetsLoader* loader = getLoader(url);
    if(loader == NULL) {
        return 0;
    }
    return loader->getPercent();
}

LoaderItem* AssetsMgr::getLoaderItem(AssetsLoader* loader) {
    for(list<LoaderItem*>::iterator iter = _loaderList->begin(); iter != _loaderList->end(); iter++) {
        if(loader == (*iter)->loader) {
            return *iter;
        }
    }
    CCLOG("can't find item:%s", loader->getUrl().data());
    return NULL;
}

AssetsLoader* AssetsMgr::getLoader(string url) {
    for(list<LoaderItem*>::iterator iter = _loaderList->begin(); iter != _loaderList->end(); iter++) {
        if(url == (*iter)->loader->getUrl()) {
            return (*iter)->loader;
        }
    }
    //CCLOG("can't find loader: %s", url.data());
    return NULL;
}

void AssetsMgr::removeItemFromList(LoaderItem* item) {
    for(list<LoaderItem*>::iterator iter = _loaderList->begin(); iter != _loaderList->end(); iter++) {
        if(item == (*iter)) {
            _loaderList->erase(iter);
            //CCLOG("[assets] remove item, new size: %d", (int)_loaderList->size());
            break;
        }
    }
}