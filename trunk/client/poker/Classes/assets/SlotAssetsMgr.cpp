//
//  pokerAssetsMgr.cpp
//  poker
//
//  Created by jayson on 13-12-18.
//
//

#include "SlotAssetsMgr.h"
#include "Constant.h"
#include "MachineService.h"
#include "AssetsVersionMgr.h"
#include "FileUtil.h"
#include "cocos2d.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include "AssetsUtil.h"
#include "LoadAssets.h"
#include "Cloneable.h"
#include <regex.h>
#include "ResourceConfigCache.h"
#include "MD5Checksum.h"
#include "LoadInfoMgr.h"
#include "HttpMgr.h"
#include "NetErrorInfo.h"
#include "EventDef.h"
#include "Preferences.h"
#include "Global.h"
#include "AssetsVersionMgr.h"
#include "SceneManager.h"
#include "GameService.h"
#include "AssetsConfig.h"

USING_NS_CC;


string SlotAssetsMgr::DIR_SUFFIX_MACHINE_ZIP = "stages/";
string SlotAssetsMgr::DIR_SUFFIX_ICONS = "icons/";
string SlotAssetsMgr::DIR_SUFFIX_OTHERS = "others/";
string SlotAssetsMgr::DIR_FACEBOOK_HEAD = "facebook/";
string SlotAssetsMgr::FACEBOOK_HEAD_SUFFIX = ".fb";
string SlotAssetsMgr::KEY_FIRST_LAUNCH_INITED = "key_first_launch_inited";

SlotAssetsMgr::SlotAssetsMgr():
_iconConfigInited(false)

{
    _slotStorageDir = "";
/*#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    _slotStorageDir = "/mnt/sdcard/slot/";
#else
    _slotStorageDir = CCFileUtils::sharedFileUtils()->getWritablePath() + "slot/";
#endif*/
    _slotStorageDir = CCFileUtils::sharedFileUtils()->getWritablePath() + "slot/";
    
    initStorageDir();
#if ALWAYS_INIT_MACHINE_WHEN_LAUNCH
    Preferences::sharedPreferences()->setBoolForKey(KEY_FIRST_LAUNCH_INITED.data(), false);
#endif
    //第一次打开游戏，初始化第一个关卡
    initMachineWhenFirstLaunch();
}

SlotAssetsMgr::~SlotAssetsMgr() {
    Util::clearList(_loaderList);
}

void SlotAssetsMgr::handleLoadAssetsAsycResult(Cloneable* result) {
    AssetsLoaderAsyncResult* loaderResult = dynamic_cast<AssetsLoaderAsyncResult*>(result);
    AssetsLoader* loader = loaderResult->getAssetsLoader();
    
    string url = loader->getUrl();
    bool isZip = (string::npos != url.find(".zip"));
    
    if(loaderResult->getLoadResult()) {
        if(isZip) {
            int id = atoi(AssetsUtil::getFileName(url, false).data());
            MachineState& state = getMachineState(id);
            state.isLoaded = true;
            
            // 只处理zip文件版本
            LoadInfoMgr::getInstance()->remove(url);
        }
        
        if(loaderResult->getResultRedirectUrl().size() > 0 && loaderResult->getResultRedirectUrl() != loader->getRedirectUrl()) {
            // 重新加载url
            CCLOG("reload url : %s", loaderResult->getResultRedirectUrl().data());
            Preferences::sharedPreferences()->setStringForKey(getFacebookPrefixKey(url).data(), loaderResult->getResultRedirectUrl());
            loader->setUrlAndLoad(loaderResult->getResultRedirectUrl());
            return;
        }
    }else {
        // 增加一次失败机会
        loader->addFailedCount();
        
        // 非zip文件才失败重新加载
        if(!isZip) {
            // 3次加载机会
            if(loader->getFailedCount() >= 3) {
                //NetErrorInfo message(NetErrorType_Res, loader->getUrl());
                //CCNotificationCenter::sharedNotificationCenter()->postNotification(EventDef::SERVER_NETWORK_ERROR,(CCObject *)&message);
                
                // 如果是必需素材，才弹提示框
                if(loader->getIsNecessary()) {
                    SceneManager::getInstance()->showNetworkError();
                }
            }else {
                CCLOG("[assets mgr] load failed and reload ...");
                loader->startLoad();
                return;
            }
        }
    }
    
    // 这里的handle会删除loader
    loader->handleAsynLoad(loaderResult->getLoadResult());
}

bool SlotAssetsMgr::checkZipMd5(int machineId){
    char mid[10];
    sprintf(mid, "%d", machineId);
    string zipDir = getMachineZipDir().append(mid).append("/");
    string xmlPath = zipDir + "res.xml";
    if(!checkFileExists(xmlPath)) {
        CCLOG("[assets] res xml not exist: %s", xmlPath.c_str());
        return false;
    }
    
    ResourceConfigCache configCache;
    configCache.parse(xmlPath, zipDir);
    
    const map<ImageId, RImageConfig>& imageConfig = configCache.getImagesConfig();
    for(map<ImageId, RImageConfig>::const_iterator iter = imageConfig.begin(); iter != imageConfig.end(); iter++) {
        string imageFilePath = iter->second.getImageId();
        string imageMd5 = iter->second.getMd5Hexdigest();
        if(!iter->second.isInPlist() && !checkFileExists(imageFilePath)) {
            CCLOG("[assets] zip image file not exist, %s", imageFilePath.data());
            return false;
        }
        
        int startTime = Global::getLocalTime();
        string localImageMd5 = CMD5Checksum::GetMD5(imageFilePath);
        int endTime = Global::getLocalTime();
        if(endTime - startTime >= 3) {
            CCLOG("[warning] parse md5 time %d, path: %s", endTime - startTime, imageFilePath.data());
        }
        if(imageMd5 != localImageMd5) {
            CCLOG("[assets] zip image md5 not same, server: %s, local: %s", imageFilePath.data(),localImageMd5.data());
            return false;
        }
    }
    
    const map<VideoId, RVideoConfig>& vedioConfig = configCache.getVideosConfig();
    for(map<VideoId, RVideoConfig>::const_iterator iter = vedioConfig.begin(); iter != vedioConfig.end(); iter++) {
        string vedioFilePath = iter->second.getVideoId();
        string vedioMd5 = iter->second.getMd5Hexdigest();
        if(!checkFileExists(vedioFilePath)) {
            CCLOG("[assets] zip vedio file not exist, %s", vedioFilePath.data());
            return false;
        }
        
        string localVedioMd5 = CMD5Checksum::GetMD5(vedioFilePath);
        if(vedioMd5 != localVedioMd5) {
            CCLOG("[assets] zip vedio md5 not same, server: %s, local: %s", vedioMd5.data(),localVedioMd5.data());
            return false;
        }
    }
    
    
    return true;
}

void SlotAssetsMgr::initStorageDir() {
    if(!ifstream(_slotStorageDir.data())) {
        FileUtil::createDirectory(_slotStorageDir.data());
    }
}

void SlotAssetsMgr::initMachineWhenFirstLaunch() {
    bool inited = Preferences::sharedPreferences()->getBoolForKey(KEY_FIRST_LAUNCH_INITED.data(), false);
    if(!inited) {
        int mid = MachineService::getInstance()->getFirstMachineId();
        
        stringstream srcSS;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
         srcSS << "assets/zip/" << mid << ".zip";
#else
         srcSS << "zip/" << mid << ".zip";
#endif
        if(!CCFileUtils::sharedFileUtils()->isFileExist(srcSS.str().data())) {
            CCLOG("[assets_init] file %s not exist !", srcSS.str().data());
            return;
        }
        
        stringstream dstSS;
        dstSS << getMachineZipDir() << mid << ".zip";
        if(ifstream(dstSS.str().data())) {
            remove(dstSS.str().data());
        }
        
        string srcPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(srcSS.str().data());
        string dstPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(dstSS.str().data());
        
        
        unsigned long len = 0;
        unsigned char *data = NULL;
        
        data = CCFileUtils::sharedFileUtils()->getFileData(srcSS.str().data(),"r",&len);
        if(data==NULL) {
            CCLOG("[assets_init] file %s data null !", srcSS.str().data());
            return;
        }
        
        string dstDir = AssetsUtil::getDir(dstPath);
        FileUtil::createDirectory(dstDir.data());
        FILE *fp = fopen(dstPath.c_str(),"wb");
        fwrite(data,sizeof(char),len,fp);
        fclose(fp);
        delete []data;
        data = NULL;
        
        CCLOG("[asset_init] copy zip file %s to %s", srcSS.str().data(), dstSS.str().data());
        
        bool unzipResult = FileUtil::uncompressAndRemoveZip(dstSS.str(), getMachineZipDir());
        if(!unzipResult) {
            CCLOG("[asset_init] unzip file error: %s", dstSS.str().data());
            return;
        }
        
        // 设置zip版本
        string url = getUrl(AssetsType_Machine_Zip, mid);
        AssetsVersionMgr::getInstance()->setVersion(url, MachineService::getInstance()->getMachineZipVersion(mid));
        
        Preferences::sharedPreferences()->setBoolForKey(KEY_FIRST_LAUNCH_INITED.data(), true);
    }
}

string SlotAssetsMgr::getZipPath(int machineId) {
    string resRelativePath = getResRelativePath(AssetsType_Machine_Zip, machineId);
    string fileName = AssetsUtil::getFileName(resRelativePath, true);
    return getMachineZipDir() + fileName;
}

void SlotAssetsMgr::release(AssetsType type, int id) {
    string urlpath = getUrl(type, id);
    AssetsLoader* assetsLoader = getLoader(urlpath);
    if(assetsLoader != NULL) {
        LoaderItem* loaderItem = getLoaderItem(assetsLoader);
        if(loaderItem) loaderItem->setInvalid();
    }
}

void SlotAssetsMgr::release(CCObject* target) {
    for(list<LoaderItem*>::iterator iter = _loaderList->begin(); iter != _loaderList->end(); iter++) {
        if(target == (*iter)->getTarget()) {
            return (*iter)->setInvalid();
        }
    }
}

void SlotAssetsMgr::load(AssetsType type, int id, int serverVersion, CCObject* target, SEL_CallFunc successCallFunc, SEL_CallFunc failedCallFunc) {
    string urlpath = getUrl(type, id);
    string filename = AssetsUtil::getFileName(urlpath, true);
    
    // 先检测是否需要重新加载
    CheckNeedLoadResult checkResult = checkNeedLoad(type, urlpath, id, serverVersion);
    if(checkResult == CheckNeedLoad_No) {
        if(target != NULL) (target->*successCallFunc)();
        return;
    }
    
    string saveDir = getDirByRelativePath(getResRelativePath(type, id));
    
    if(isLoading(urlpath)) {
        CCLOG("[info] url: %s is loading... ", urlpath.data());
        return;
    }
    
    double totalSize = 0;
    //只处理zip文件的断点恢复
    if(string::npos != urlpath.find(".zip")) {
        totalSize = HttpMgr::getInstance()->getUrlFileSize(urlpath);
        if(totalSize > 0) {
            LoadInfoMgr::getInstance()->setInfo(urlpath, totalSize, serverVersion);
        }else {
            if(target != NULL) {
                (target->*failedCallFunc)();
                return;
            }
        }
    }
    
    bool isToResume = (checkResult == CheckNeedLoad_Resume);
    AssetsLoader* loader = new AssetsLoader(urlpath, saveDir, this);
    long initSize = isToResume ? FileUtil::getFileSize(loader->getFilePath().data()) : 0;
    _loaderList->push_back(new LoaderItem(loader,serverVersion, target, successCallFunc, failedCallFunc));
    loader->setInfo(isToResume, initSize);
    loader->startLoad();
}

void SlotAssetsMgr::loadFacebookHead(string savename, string url, CCObject* target, SEL_CallFunc successCallFunc, SEL_CallFunc failedCallFunc) {
    string redUrl = Preferences::sharedPreferences()->getStringForKey(getFacebookPrefixKey(url).data());
    
    string saveDir = getStorageRoot().append(DIR_FACEBOOK_HEAD);
    AssetsLoader* loader = new AssetsLoader(url, saveDir, this);
    loader->setFileName(savename + FACEBOOK_HEAD_SUFFIX);
    _loaderList->push_back(new LoaderItem(loader,0, target, successCallFunc, failedCallFunc));
    loader->setRedirectUrl(redUrl);
    loader->setIsNecessary(false);
    loader->startLoad();
}

string SlotAssetsMgr::getFacebookPrefixKey(string url) {
    return "fb_" + url;
}

string SlotAssetsMgr::getFacebookHeadPath(string id) {
    return DIR_FACEBOOK_HEAD + id + FACEBOOK_HEAD_SUFFIX;
}

int SlotAssetsMgr::getLoadPercent(AssetsType type, int machineId) {
    // 如果没有正在下载压缩包，则按初始化的值
    if(type == AssetsType_Machine_Zip && !isLoading(getUrl(type, machineId))) {
        MachineState state = getMachineState(machineId);
        return state.loadPercent;
    }
    return AssetsMgr::getLoadPercent(getUrl(type, machineId));
}

bool SlotAssetsMgr::isMachineLoaded(int mid) {
    MachineState state = getMachineState(mid);
    return state.isLoaded;
}

MachineState& SlotAssetsMgr::getMachineState(int machineId) {
    MachineState& state = _machineStateMap[machineId];
    if(!state.inited) {
        state.machineId = machineId;
        
        // 初始化是否需要加载
        string urlpath = getUrl(AssetsType_Machine_Zip, machineId);
        string filename = AssetsUtil::getFileName(urlpath, true);
        string filepath = getZipPath(machineId);
        int serverVersion = MachineService::getInstance()->getMachineZipVersion(machineId);
        CheckNeedLoadResult result = checkNeedLoad(AssetsType_Machine_Zip, urlpath, machineId, serverVersion);
        state.isLoaded = (result == CheckNeedLoad_No);
        
        if(state.isLoaded) {
            state.loadPercent = 100;
        }
        else if(result == CheckNeedLoad_Resume) {
            LoadInfo loadInfo = LoadInfoMgr::getInstance()->getLoadInfo(urlpath);
            if(loadInfo.totalSize > 0) {
                state.loadPercent = FileUtil::getFileSize(filepath.data()) * 100 / loadInfo.totalSize;
                CCLOG("[assets] init resume machine state percent, %d, %s",state.loadPercent,urlpath.data());
            }
        }
        state.inited = true;
        _machineStateMap[machineId] = state;
    }
    return state;
}

string SlotAssetsMgr::getResRelativePath(AssetsType type, int id) {
    string resRelativePath;
    if(type == AssetsType_Machine_Zip) {
        resRelativePath = MachineService::getInstance()->getCfgMachineZipById(id)->zip;
    }else if(type == AssetsType_Icon) {
        resRelativePath = MachineService::getInstance()->getCfgMachineIconById(id)->icon;
    }else if(type == AssetsType_Others) {
        resRelativePath = GameService::getInstance()->getCfgAssetsVOById(id)->path;
    }
    return resRelativePath;
}

void SlotAssetsMgr::testLoad() {
    //int machineId = 1;
    //int serverVersion = MachineService::getInstance()->getMachineIconVersion(machineId);
    //load(AssetsType_Icon, machineId, serverVersion, NULL);
    //load(AssetsType_Icon, 2, serverVersion, NULL);
    
    //int serverVersion = MachineService::getInstance()->getMachineZipVersion(machineId);
    //serverVersion = 3;
    //load(AssetsType_Machine_Zip, machineId, serverVersion, NULL);
    
    int serverVersion = GameService::getInstance()->getAssetsVersion(AssetsConfig::HEAD_ID_1);
    //load(AssetsType_Others, AssetsConfig::HEAD_ID_1, serverVersion, NULL, NULL, NULL);
    string url = "http://graph.facebook.com/569830656/picture";
    //loadFacebookHead(url, NULL, NULL, NULL);
    
    string path = getFacebookHeadPath("569830656");
    CCSprite* sprite = CCSprite::create(path.data());
    CCLOG("w:%d, h: %d", sprite->getContentSize().width, sprite->getContentSize().height);
}

string SlotAssetsMgr::getMachineZipDir() {
    return _slotStorageDir + DIR_SUFFIX_MACHINE_ZIP;
}

string SlotAssetsMgr::getDirByRelativePath(string url) {
    return _slotStorageDir + AssetsUtil::getDir(url);
}

string SlotAssetsMgr::getStorageRoot() {
    return _slotStorageDir;
}

CheckNeedLoadResult SlotAssetsMgr::checkNeedLoad(AssetsType type, string urlpath, int id, int newVersion) {
    int oldVersion = AssetsVersionMgr::getInstance()->getVersion(urlpath);
    bool iszip = string::npos != urlpath.find("zip");
    if(oldVersion >= newVersion) {
        if(iszip) {
            bool zipCheck = checkZipMd5(id);
            if(!zipCheck ) {
                CCLOG("[assets] res is broken, reload %s",urlpath.data());
                return CheckNeedLoad_New;
            }
        }
        return CheckNeedLoad_No;
    }else {
        // 处理zip的情况
        if(iszip) {
            
            // 只有success的时候才会setVersion, 所以如果version小了，说明可能需要断点续传
            LoadInfo loadInfo = LoadInfoMgr::getInstance()->getLoadInfo(urlpath);
            if(loadInfo.version >= newVersion) {
                return CheckNeedLoad_Resume;
            }else {
                // 如果本地是老版本，则删除，防止断点续传是一个错误的版本, 因为网络线程file是aw的
                string filename = AssetsUtil::getFileName(urlpath, true);
                string path = getMachineZipDir().append(filename);
                remove(path.data());
            }
        }
    }
    CCLOG("[assets] new version is %d, old version is %d, reload %s", newVersion, oldVersion, urlpath.data());
    return CheckNeedLoad_New;
}

bool SlotAssetsMgr::checkFileExists(string filepath) {
    return CCFileUtils::sharedFileUtils()->isFileExist(filepath);
}

list<string> SlotAssetsMgr::getFileListFromStrInfo(string info) {
    list<string> filelist;
    
    char reg[] = "\"([/a-z0-9A-Z_-]+\\.[a-zA-Z]+)\"";
    const char* data = info.data();
    regex_t pattern;
    int nErrCode = 0;
    if((nErrCode = regcomp(&pattern, reg, REG_EXTENDED)) == 0){
        regmatch_t pmatch;
        
        regoff_t last_match=0;
        while(regexec(&pattern, data+last_match, 1, &pmatch, 0) == 0) {
            //printf("start=%lld end=%lld\n", pmatch.rm_so + last_match, pmatch.rm_eo + last_match);
            char result[64];
            // 1两边的双引号，删除
            memcpy(result, data + pmatch.rm_so + last_match + 1, pmatch.rm_eo - pmatch.rm_so - 2);
            result[pmatch.rm_eo - pmatch.rm_so - 2] = '\0';
            //CCLOG("%s",string(result).data());
            filelist.push_back(string(result));
            
            last_match += pmatch.rm_so+1;
        }
        regfree(&pattern);
    }
    return filelist;
}

string SlotAssetsMgr::getUrl(AssetsType type, int id) {
    string resRelativePath = getResRelativePath(type, id);
    string baseurl = Constant::URL_ASSETS;
    return baseurl.append(resRelativePath);
}