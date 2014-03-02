//
//  AssetsLoader.cpp
//  poker
//
//  Created by jayson on 13-12-4.
//
//

#include "AssetsLoader.h"
#include "HttpMgr.h"
#include "callback.h"
#include "cocos2d.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include "FileUtil.h"
#include <string>
#include "AssetsUtil.h"
#include "LoadAssets.h"

using namespace cocos2d;
using namespace std;

AssetsLoader::AssetsLoader(string url, string dir, AssetsLoaderDelegateProtocol* pDelegate) {
    _url = url;
    _dir = dir;
    _delegate = pDelegate;
    _curl = NULL;
    _isLoading = false;
    _isToResume = false;
    _fileInitSize = 0;
    _percent = 0;
    _failedCount = 0;
    _redirectUrl = "";
    _filename = "";
    _isNecessaryRes = false;
}

AssetsLoader::~AssetsLoader() {
    
}

void AssetsLoader::handleAsynLoad(bool result) {
    if(result) {
        _delegate->onSuccess(this);
    }else {
        _delegate->onError(0,this);
    }
    _isLoading = false;
}

void AssetsLoader::setInfo(bool toResume, double currentSize) {
    _isToResume = toResume;
    _fileInitSize = currentSize;
}

void AssetsLoader::setRedirectUrl(string url) {
    _redirectUrl = url;
}

void AssetsLoader::setFileName(string name) {
    _filename = name;
}

void AssetsLoader::startLoad() {
    _isLoading = true;
    
    AssetsLoaderAsyncCommand command;
    command.setUrl(_url);
    command.setSaveDir(_dir);
    command.setFilePath(getFilePath());
    command.setAssetsLoader(this);
    command.setRedictUrl(_redirectUrl);
    ThreadManager::getInstance()->sendMessageFromGLThread(ThreadName::AssetsLoader, &command);
}

void AssetsLoader::setUrlAndLoad(string url) {
    _url = url;
    _redirectUrl = url;
    startLoad();
}

bool AssetsLoader::isLoading() {
    return _isLoading;
}

string AssetsLoader::getUrl() {
    return _url;
}

int AssetsLoader::getPercent() {
    return _percent;
}

void AssetsLoader::setPercent(float percent) {
    _percent = percent;
}

bool AssetsLoader::getIsToResume() {
    return _isToResume;
}

double AssetsLoader::getFileInitSize() {
    return _fileInitSize;
}

void AssetsLoader::addFailedCount() {
    _failedCount ++;
}

int AssetsLoader::getFailedCount() {
    return _failedCount;
}

void AssetsLoader::setIsNecessary(bool isNecessary) {
    _isNecessaryRes = isNecessary;
}

bool AssetsLoader::getIsNecessary() {
    return _isNecessaryRes;
}

string AssetsLoader::getFilePath() {
    if(_filename.size() > 0) return _dir + _filename;
    // 否则使用url提取
    return _dir + AssetsUtil::getFileName(_url, true);
}

string AssetsLoader::getRedirectUrl() {
    return _redirectUrl;
}