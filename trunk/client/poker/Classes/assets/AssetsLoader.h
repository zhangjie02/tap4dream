//
//  AssetsLoader.h
//  poker
//
//  Created by jayson on 13-12-4.
//
//

#ifndef __poker__AssetsLoader__
#define __poker__AssetsLoader__

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <curl/easy.h>
#include "Callback.h"
#include "cocos2d.h"
#include "ExtensionMacros.h"

using namespace std;

class AssetsLoader;

class AssetsLoaderDelegateProtocol {
public:
    virtual void onError(int errorCode, AssetsLoader* loader) {};
    
    virtual void onProgress(int percent, AssetsLoader* loader) {};
    
    virtual void onSuccess(AssetsLoader* loader) {};
};

class AssetsLoader {
public:
    AssetsLoader(string url, string savedir, AssetsLoaderDelegateProtocol* pDelegate);
    ~AssetsLoader();
    
    void startLoad();
    
    void setUrlAndLoad(string url);
    
    /**
     * 设置加载信息，包括是否断点续传
     */
    void setInfo(bool isToResume, double currentSize);
    
    /**
     * 设置重定向url, 暂时只给facebook头像用
     */
    void setRedirectUrl(string url);
    
    /**
     * 保存的文件名
     */
    void setFileName(string name);
    
    void setIsNecessary(bool isNecessary);
    bool getIsNecessary();
    
    /**
     * 判断是否横在下载
     */
    bool isLoading();
    
    /**
     * 网络异步加载完成
     */
    void handleAsynLoad(bool result);
    
    string getUrl();
    
    int getPercent();
    
    void setPercent(float percent);
    
    bool getIsToResume();
    
    string getRedirectUrl();
    
    double getFileInitSize();
    
    /**
     * 增加一次失败
     */
    void addFailedCount();
    
    int getFailedCount();
    
    /**
     * 获得url对应文件在本地的路径
     */
    string getFilePath();
    
private:
    string _url;
    CURL* _curl;
    int _percent;
    string _redirectUrl;
    string _filename;
    
    string _dir;
    string _version;
    
    // 是否是必需的资源
    bool _isNecessaryRes;
    
    bool _isLoading;
    
    bool _isToResume;
    double _fileInitSize;
    
    int _failedCount;
    
    AssetsLoaderDelegateProtocol* _delegate;
};

#endif /* defined(__poker__AssetsLoader__) */
