//
//  AssetsLoaderThread.cpp
//  poker
//
//  Created by jayson on 13-12-19.
//
//

#include "AssetsLoaderThread.h"

#include "LoadAssets.h"
#include "SlotFile.h"
#include "cocos2d.h"
#include <curl/curl.h>
#include <curl/easy.h>
#include "AssetsLoader.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#endif

#include "support/zip_support/unzip.h"
#include "FileUtil.h"
#include "AssetsUtil.h"
#include <sys/stat.h>
#include <fcntl.h>

USING_NS_CC;

void AssetsLoaderThread::init() {}

int assetsProgressFunc(void *ptr, double totalToDownload, double nowDownloaded, double totalToUpLoad, double nowUpLoaded)
{
    AssetsLoader* loader = (AssetsLoader*)ptr;
    double initSize = loader->getFileInitSize();
    
    if(totalToDownload == 0 && initSize == 0) {
        loader->setPercent(0);
        return 0;
    }
    int percent = ((nowDownloaded + initSize) / (totalToDownload + initSize) * 100);
    
    //CCLOG("[assetloader] initsize: %d, percent: %d, nowDownloaded: %d, nowDownloaded: %d",initSize, percent, totalToDownload, nowDownloaded);
    loader->setPercent(percent);
    return 0;
}

size_t downLoadPackage(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    FILE *fp = (FILE*)userdata;
    size_t written = fwrite(ptr, size, nmemb, fp);
    return written;
}

bool AssetsLoaderThread::processMessage(Cloneable *message) {
    AssetsLoaderAsyncCommand* command = dynamic_cast<AssetsLoaderAsyncCommand*>(message);
    
    string url = command->getUrl();
    AssetsLoader* loader = command->getAssetsLoader();
    bool isToResume = loader->getIsToResume();
    
    CCLOG("[assets] start load url: %s", url.data());
    
    AssetsLoaderAsyncResult loaderResult;
    loaderResult.setAssetsLoader(loader);
    
    CURL* _curl = curl_easy_init();
    if (! _curl)
    {
        CCLOG("can not init curl");
        loaderResult.setLoadResult(false);
        ThreadManager::getInstance()->sendMessageToGLThread(&loaderResult);
        return false;
    }
    
    string filepath = command->getFilePath();
    
    string fileOp = "wb";
    if(isToResume) {
        fileOp = "ab";
        CCLOG("[assets] resume downloading ... %s, initsize: %d", url.data(),(int)loader->getFileInitSize());
    }
    
    // 创建目录
    string saveDir = command->getSaveDir();
    FileUtil::createDirectory(saveDir.data());
    
    FILE *fp = fopen(filepath.c_str(), fileOp.data());
    if (!fp)
    {
        CCLOG("can not create file %s", filepath.c_str());
        loaderResult.setLoadResult(false);
        ThreadManager::getInstance()->sendMessageToGLThread(&loaderResult);
        fclose(fp);
        return false;
    }
    
    long curFileSize = loader->getFileInitSize();
    stringstream ss;
    ss << curFileSize << "-";
    const char* range = ss.str().c_str();
    
    CURLcode res;
    curl_easy_setopt(_curl, CURLOPT_URL, url.data());
    curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, downLoadPackage);
    curl_easy_setopt(_curl, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(_curl, CURLOPT_NOPROGRESS, false);
    curl_easy_setopt(_curl, CURLOPT_PROGRESSFUNCTION, assetsProgressFunc);
    curl_easy_setopt(_curl, CURLOPT_PROGRESSDATA, loader);
    curl_easy_setopt(_curl, CURLOPT_FOLLOWLOCATION, false);
    if(isToResume) {
        curl_easy_setopt(_curl, CURLOPT_RANGE, range);
    }
    
    // 如果http code > 400, 则报错, 这样就不会写文件了
    curl_easy_setopt(_curl, CURLOPT_FAILONERROR, true);
    
    // 如果在20秒内，速度小于1byte/s, 则报错
    curl_easy_setopt(_curl, CURLOPT_LOW_SPEED_LIMIT, 1L);
    curl_easy_setopt(_curl, CURLOPT_LOW_SPEED_TIME, 20L);
    
    res = curl_easy_perform(_curl);
    
    if (res != CURLE_OK) {
        loaderResult.setLoadResult(false);
        ThreadManager::getInstance()->sendMessageToGLThread(&loaderResult);
        fclose(fp);
        CCLOG("[assets] http error code: %d, assets: %s", res,url.data());
        return false;
    }
    
    char* redirectBuf;
    curl_easy_getinfo(_curl, CURLINFO_REDIRECT_URL, &redirectBuf);
    if(NULL != redirectBuf) loaderResult.setResultRedirectUrl(string(redirectBuf));
    
    fclose(fp);
    curl_easy_cleanup(_curl);
    
    // 设置权限
    int fd = open(filepath.data(), O_RDONLY);
    fchmod(fd, S_IRWXU|S_IRWXG|S_IRWXO);
    close(fd);
    
    if(string::npos != filepath.find(".zip")) {
        bool unzipResult = FileUtil::uncompressAndRemoveZip(filepath, saveDir);
        if(!unzipResult) {
            CCLOG("[unzip]unzip file error: %s", filepath.data());
            loaderResult.setLoadResult(false);
            ThreadManager::getInstance()->sendMessageToGLThread(&loaderResult);
            return false;
        }
    }
    
    loaderResult.setLoadResult(true);
    ThreadManager::getInstance()->sendMessageToGLThread(&loaderResult);

    return false;
}