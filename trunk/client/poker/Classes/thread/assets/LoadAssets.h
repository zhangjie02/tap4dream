//
//  LoadAssets.h
//  poker
//
//  Created by jayson on 13-12-19.
//
//

#ifndef __poker__LoadAssets__
#define __poker__LoadAssets__

#include <iostream>

#include <iostream>
#include "cocos2d.h"
#include "ThreadManager.h"
#include <string>
#include "AssetsLoader.h"
using namespace std;
using namespace cocos2d;

class AssetsLoaderAsyncCommand : public Cloneable {
    CC_SYNTHESIZE(string, _url, Url);
    CC_SYNTHESIZE(string, _saveDir, SaveDir);
    CC_SYNTHESIZE(string, _filePath, FilePath);
    CC_SYNTHESIZE(AssetsLoader*, _assetsLoader, AssetsLoader);
    CC_SYNTHESIZE(string, _redictUrl, RedictUrl);
public:
    static const char* NAME;
    AssetsLoaderAsyncCommand();
    Cloneable* clone();
};

class AssetsLoaderAsyncResult : public Cloneable, public CCObject {
    CC_SYNTHESIZE(bool, _loadResult, LoadResult);
    CC_SYNTHESIZE(string, _resultRedirectUrl, ResultRedirectUrl);
    CC_SYNTHESIZE(AssetsLoader*, _assetsLoader, AssetsLoader);
public:
    static const char* NAME;
    AssetsLoaderAsyncResult();
    Cloneable* clone();
};

#endif /* defined(__poker__LoadAssets__) */
