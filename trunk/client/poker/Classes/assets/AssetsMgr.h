//
//  AssetsMgr.h
//  poker
//
//  Created by jayson on 13-12-4.
//
//

#ifndef __poker__AssetsMgr__
#define __poker__AssetsMgr__

#include <iostream>
#include <string>
#include "Callback.h"
#include <list>
#include "AssetsLoader.h"
#include "LoaderItem.h"

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
#include <dirent.h>
#include <sys/stat.h>
#endif

using namespace std;

enum AssetsType {
    AssetsType_Machine_Zip,
    AssetsType_Icon,
    AssetsType_Others
};

class AssetsMgr : public AssetsLoaderDelegateProtocol{
public:
    static AssetsMgr* getInstance() {
        static AssetsMgr instance;
        return &instance;
    }

public:
    AssetsMgr();
    ~AssetsMgr();
    
    /* =============== loader protocol ================= */
    virtual void onError(int errorCode, AssetsLoader* loader);
    
    virtual void onProgress(int percent, AssetsLoader* loader);
    
    virtual void onSuccess(AssetsLoader* loader);
    
    
    float getLoadPercent(string url);
    
protected:
    LoaderItem* getLoaderItem(AssetsLoader* loader);
    
    AssetsLoader* getLoader(string url);
    
    string getDirFromFile(string filepath);
    
    void removeItemFromList(LoaderItem* item);
    
    /**
     * 判断是否正在下载
     */
    bool isLoading(string url);

protected:
    list<LoaderItem*>* _loaderList;
};

#endif /* defined(__poker__AssetsMgr__) */
