//
//  ResourceManager.cpp
//  ResourceManager
//
//  Created by xiaoxiangzi on 13-11-12.
//
//

#include "ResourceManager.h"
#include "ResourceKey.h"
#include <algorithm>
#include "ResourceAsyncLoadTask.h"

const string ResourceManager::LOCAL_STORE_KEY = "res.xml";

void ResourceManager::loadLocalResourceConfig() {
    loadResourceConfig(LOCAL_STORE_KEY, "");
}

void ResourceManager::loadResourceConfig(const string &resXmlPath, const string &resParentPath) {
    map<string, ResourceConfigCache>::iterator iter = _resConfigMap.find(resXmlPath);
    if (iter == _resConfigMap.end()) {
        ResourceConfigCache cache;
        cache.parse(resXmlPath, resParentPath);
        _resConfigMap.insert(make_pair(resXmlPath, cache));
    }
}

bool ResourceManager::containsKey(ResourceKey *key) const {
    vector<ResourceKey*>::const_iterator iter = find(_resourceKeys.begin(), _resourceKeys.end(), key);
    if (iter != _resourceKeys.end()) {
        return true;
    }
    
    return false;
}

void ResourceManager::addKey(ResourceKey *key) {
    if (containsKey(key)) {
        return;
    }
    key->setValid(true);
    _resourceKeys.push_back(key);
    CC_SAFE_RETAIN(key);
}

ResourceKey* ResourceManager::createResourceKey() {
    ResourceKey* key = ResourceKey::create();
    addKey(key);
    return key;
}

bool ResourceManager::isResKeyUsedInAsyncTask(ResourceKey *resKey) {
    for (auto iter = _asyncTasks.begin(); iter != _asyncTasks.end(); iter++) {
        ResourceAsyncLoadTask* task = *iter;
        if (task->getResourceKey() == resKey) {
            return true;
        }
    }
    
    return false;
}

void ResourceManager::releaseResourceKey(ResourceKey *key) {
    if (key == NULL) {
        return;
    }
    
    vector<ResourceKey*>::iterator iter = find(_resourceKeys.begin(), _resourceKeys.end(), key);
    if (iter != _resourceKeys.end()) {
        _resourceKeys.erase(iter);
        key->setValid(false);
        unbindKeyFromAllResources(key);
        if (isResKeyUsedInAsyncTask(key)) {
            addAppendingReleaseResKey(key);
        } else {
            CC_SAFE_RELEASE_NULL(key);
        }
    }
}

void ResourceManager::addAppendingReleaseResKey(ResourceKey *resKey) {
    auto iter = find(_appendingReleaseResKeys.begin(), _appendingReleaseResKeys.end(), resKey);
    if (iter != _resourceKeys.end()) {
        return;
    }
    
    _appendingReleaseResKeys.push_back(resKey);
}

void ResourceManager::unbindKeyFromAllResources(ResourceKey *key) {
    for (map<string, ResourceBindableByKey*>::iterator iter = _resources.begin(); iter != _resources.end();) {
        ResourceBindableByKey* res = iter->second;
        res->unbindKey(key);
        if (res->getKeyCount() == 0) {
//            CCLOG("release resource %s", res->getResAliasName().c_str());
            CC_SAFE_RELEASE_NULL(res);
            _resources.erase(iter++);
        } else {
            iter++;
        }
    }
}

const vector<const ResourceConfigCache*> ResourceManager::getPreferedConfigCaches(ResourceKey *resKey) const {
    const vector<string>& preferedStores = resKey->getPreferedStoreKeys();
    map<string, ResourceConfigCache>::const_iterator resMapIter;
    vector<const ResourceConfigCache*> caches;
    
    if (preferedStores.empty()) {
        resMapIter = _resConfigMap.find(LOCAL_STORE_KEY);
        if (resMapIter != _resConfigMap.end()) {
            caches.push_back(&(resMapIter->second));
        }
        return caches;
    }
    
    for (vector<string>::const_iterator iter = preferedStores.begin(); iter != preferedStores.end(); iter++) {
        resMapIter = _resConfigMap.find(*iter);
        if (resMapIter != _resConfigMap.end()) {
            caches.push_back(&(resMapIter->second));
        }
    }
    
    return caches;
}

const RConfig* ResourceManager::getRConfig(const ResourceId &resourceId, ResourceKey *resKey, int resType) const {
    vector<const ResourceConfigCache*> preferedCaches = getPreferedConfigCaches(resKey);
    const RConfig* config = NULL;
    for (vector<const ResourceConfigCache*>::iterator iter = preferedCaches.begin(); iter != preferedCaches.end(); iter++) {
        const ResourceConfigCache* cache = *iter;
        config = getRConfig(cache, resourceId, resType);
        if (config) {
            break;
        }
    }
    
    if (config == NULL) {
        for (map<string, ResourceConfigCache>::const_iterator iter = _resConfigMap.begin(); iter != _resConfigMap.end(); iter++) {
            const ResourceConfigCache* cache = &iter->second;
            
            if (find(preferedCaches.begin(), preferedCaches.end(), cache) != preferedCaches.end()) {
                continue;
            }
            
            config = getRConfig(cache, resourceId, resType);
            if (config) {
                break;
            }
        }
    }
    
    return config;
}

const RConfig* ResourceManager::getRConfig(const ResourceConfigCache *cache, const ResourceId &resourceId, int resType) const {
    if (resType == IMAGE_CONFIG) {
        return cache->getImageConfig(resourceId);
    } else if (resType == PLIST_CONFIG) {
        return cache->getPlistConfig(resourceId);
    } else if (resType == VIDEO_CONFIG) {
        return cache->getVideoConfig(resourceId);
    } else if (resType == AUDIO_CONFIG) {
        return cache->getAudioConfig(resourceId);
    }
    
    return NULL;
}

const RPlistConfig* ResourceManager::getRPlistConfig(const string& plistId, ResourceKey* resKey) const {
    const RPlistConfig* config = dynamic_cast<const RPlistConfig*>(getRConfig(plistId, resKey, PLIST_CONFIG));
    return config;
}

const RVideoConfig* ResourceManager::getRVideoConfig(const string &videoId, ResourceKey* resKey) const {
    const RVideoConfig* config = dynamic_cast<const RVideoConfig*>(getRConfig(videoId, resKey, VIDEO_CONFIG));
    return config;
}

const RImageConfig* ResourceManager::getRImageConfig(const string &imageId, ResourceKey* resKey) const {
    const RImageConfig* config = dynamic_cast<const RImageConfig*>(getRConfig(imageId, resKey, IMAGE_CONFIG));
    return config;
}

const RAudioConfig* ResourceManager::getRAudioConfig(const string &audioId, ResourceKey* resKey) const {
    const RAudioConfig* config = dynamic_cast<const RAudioConfig*>(getRConfig(audioId, resKey, AUDIO_CONFIG));
    return config;
}

bool ResourceManager::isValidKey(ResourceKey *key) const {
    return key && key->isValid();
}

CCSprite* ResourceManager::getCCSprite(const char *imageId, ResourceKey *resKey) {
    if (!isValidKey(resKey)) {
        return NULL;
    }
    
    ResourceId resId(imageId);
    RTexture* res = dynamic_cast<RTexture*>(findResource(resId, resKey));
    res->bindKey(resKey);
    return res->getCCSprite(resId);
}

CCSpriteFrame* ResourceManager::getCCSpriteFrame(const char *imageId, ResourceKey *resKey) {
    if (!isValidKey(resKey)) {
        return NULL;
    }
    
    ResourceId resId(imageId);
    RTexture* res = findResource(resId, resKey);
    res->bindKey(resKey);
    return res->getCCSpriteFrame(resId);
}

CCScale9Sprite* ResourceManager::getCCScale9Sprite(const char* imageId, ResourceKey* resKey, const CCRect& capInsets/* = CCRectZero*/) {
    if (!isValidKey(resKey)) {
        return NULL;
    }
    
    ResourceId resId(imageId);
    RTexture* res = dynamic_cast<RTexture*>(findResource(resId, resKey));
    res->bindKey(resKey);
    return res->getCCScale9Sprite(resId, capInsets);
}

CCLabelAtlas* ResourceManager::getCCLabelAtlas(const char* imageId, ResourceKey* resKey, const char *text,  unsigned int itemWidth, unsigned int itemHeight, unsigned int startCharMap) {
    if (!isValidKey(resKey)) {
        return NULL;
    }
    
    ResourceId resId(imageId);
   RTexture* res = findResource(resId, resKey);
    res->bindKey(resKey);
    return res->getCCLabelAtlas(resId, text, itemWidth, itemHeight, startCharMap);
}

CCLabelBMFont* ResourceManager::getCCLabelBMFont(const char *imageId, ResourceKey *resKey, const char *text, CCTextAlignment alignment, int width) {
    if (!isValidKey(resKey)) {
        return NULL;
    }
    
    ResourceId resId(imageId);
    RTexture* res = findResource(resId, resKey);
    res->bindKey(resKey);
    return res->getCCLabelBMFont(resId, text, alignment, width);
}

File* ResourceManager::getFile(const char *fileId, ResourceKey *resKey) {
    if (!isValidKey(resKey)) {
        return NULL;
    }
    
    ResourceId resId(fileId);
    RVideo* videoRes = findVideoResource(resId, resKey);
    videoRes->bindKey(resKey);
    return videoRes->getVideoFile();
}

const RAudio* ResourceManager::getAudioResource(const char *audioId, ResourceKey *resKey) {
    if (!isValidKey(resKey)) {
        return NULL;
    }
    
    ResourceId resId(audioId);
    RAudio* res = findAudioResource(resId, resKey);
    res->bindKey(resKey);
    return res;
}

RAudio* ResourceManager::findAudioResource(const ResourceId& resourceId, ResourceKey* resKey) {
    const RAudioConfig* audioConfig = getRAudioConfig(resourceId, resKey);
    
    auto iter = _resources.find(audioConfig->getAudioId());
    RAudio* res = NULL;
    if (iter == _resources.end()) {
        res = RAudio::create();
        res->initAudio(audioConfig);
        CC_SAFE_RETAIN(res);
        _resources.insert(make_pair(audioConfig->getAudioId(), res));
    } else {
        res = dynamic_cast<RAudio*>(iter->second);
    }
    
    return res;
}

RVideo* ResourceManager::findVideoResource(const ResourceId &resourceId, ResourceKey* resKey) {
    const RVideoConfig* videoConfig = getRVideoConfig(resourceId, resKey);
    if (videoConfig == NULL) {
        return NULL;
    }
    
    map<ResourceId, ResourceBindableByKey*>::iterator iter = _resources.find(videoConfig->getVideoId());
    RVideo* res = NULL;
    if (iter == _resources.end()) {
        RVideo* rVideo = RVideo::create();
        rVideo->initVideo(videoConfig);
        _resources.insert(make_pair(videoConfig->getVideoId(), rVideo));
        res = rVideo;
        CC_SAFE_RETAIN(rVideo);
    } else {
        res = dynamic_cast<RVideo*>(iter->second);
    }
    
    return res;
}

RTexture* ResourceManager::findResource(const ResourceId& resourceId, ResourceKey* resKey) {
    const RImageConfig* imageConfig = getRImageConfig(resourceId.c_str(), resKey);
    if (imageConfig == NULL) {
        return NULL;
    }
    
    map<ResourceId, ResourceBindableByKey*>::iterator iter;
    RTexture* resource = NULL;
    
    if (imageConfig->isInPlist()) {
        iter = _resources.find(imageConfig->getPlistId());
    } else {
        iter = _resources.find(resourceId);
    }
    
    if (iter == _resources.end()) {
        if (imageConfig->isInPlist()) {
            const RPlistConfig* plistConfig = getRPlistConfig(imageConfig->getPlistId().c_str(), resKey);
            RPlist* rPlist = RPlist::create();
            rPlist->initPlist(plistConfig);
            resource = rPlist;
            _resources.insert(make_pair(plistConfig->getPlistId(), resource));
        } else {
            RImage* rImage = RImage::create();
            rImage->initImage(imageConfig);
            resource = rImage;
            _resources.insert(make_pair(imageConfig->getImageId(), resource));
        }
        CC_SAFE_RETAIN(resource);
    } else {
        resource = dynamic_cast<RTexture*>(iter->second);
    }
    
    return resource;
}

void ResourceManager::loadResourceAsync(const string &resXmlPath, cocos2d::CCObject *target, SEL_CallFuncO selector, ResourceKey* resKey) {
    map<string, ResourceConfigCache>::const_iterator iter = _resConfigMap.find(resXmlPath);
    CCAssert(iter != _resConfigMap.end(), "res config has not been loaded yet");
    
    const ResourceConfigCache* cache = &iter->second;
    ResourceAsyncLoadTask* task = ResourceAsyncLoadTask::create();
    _appendingAddTasks.push_back(task);
    CC_SAFE_RETAIN(task);
    task->loadResAsync(cache, target, selector, resKey);
}

void ResourceManager::update() {
    if (_appendingAddTasks.size() > 0) {
        for (auto iter = _appendingAddTasks.begin(); iter != _appendingAddTasks.end(); iter++) {
            ResourceAsyncLoadTask* task = *iter;
            _asyncTasks.push_back(task);
        }
        _appendingAddTasks.clear();
    }
    
    if (_asyncTasks.empty()) {
        return;
    }
    
    for (vector<ResourceAsyncLoadTask*>::iterator iter = _asyncTasks.begin(); iter != _asyncTasks.end();) {
        ResourceAsyncLoadTask* task = *iter;
        if (task->hasTaskFinished()) {
            iter = _asyncTasks.erase(iter);
            CC_SAFE_RELEASE_NULL(task);
        } else {
            task->update();
            iter++;
        }
    }
    
    vector<ResourceKey*> keysToRelease;
    for (auto iter = _appendingReleaseResKeys.begin(); iter != _appendingReleaseResKeys.end();) {
        ResourceKey* key = *iter;
        if (isResKeyUsedInAsyncTask(key)) {
            iter++;
        } else {
            iter = _appendingReleaseResKeys.erase(iter);
            keysToRelease.push_back(key);
        }
    }
    
    for (auto iter = keysToRelease.begin(); iter != keysToRelease.end(); iter++) {
        ResourceKey* key = *iter;
        releaseResourceKey(key);
    }
}

void ResourceManager::bindKeyToResource(const string &resourceId, ResourceKey *resKey, int resType) {
    ResourceBindableByKey* res = NULL;
    if (resType == VIDEO_CONFIG) {
        res = findVideoResource(resourceId, resKey);
    } else if (resType == AUDIO_CONFIG) {
        res = findAudioResource(resourceId, resKey);
    } else {
        res = findResource(resourceId, resKey);
    }
    res->bindKey(resKey);
}

void ResourceManager::loadPlistResource(const string &plistId, ResourceKey *resKey) {
    const RPlistConfig* plistConfig = getRPlistConfig(plistId, resKey);
    auto iter = _resources.find(plistConfig->getPlistId());
    if (iter != _resources.end()) {
        CCLOG("plist %s has already been loaded", plistConfig->getPlistId().c_str());
        return;
    }
    
    RPlist* rPlist = RPlist::create();
    rPlist->initPlist(plistConfig);
    _resources.insert(make_pair(plistConfig->getPlistId(), rPlist));
    rPlist->bindKey(resKey);
    CC_SAFE_RETAIN(rPlist);
}

void ResourceManager::unbindKeyFromResource(const string &resourceId, ResourceKey *resKey) {
    auto iter = _resources.find(resourceId);
    if (iter == _resources.end()) {
        CCLOG("resource %s does not exist", resourceId.c_str());
        return;
    }
    
    ResourceBindableByKey* res = iter->second;
    res->unbindKey(resKey);
    
    if (res->getKeyCount() == 0) {
        _resources.erase(iter);
        CC_SAFE_RELEASE_NULL(res);
    }
}

void ResourceManager::unbindKeyFromResourcesInStoreConfig(const string &resXmlPath, ResourceKey *resKey) {
    auto iter = _resConfigMap.find(resXmlPath);
    if (iter == _resConfigMap.end()) {
        CCLOG("no res config find by %s", resXmlPath.c_str());
        return;
    }
    
    const ResourceConfigCache& cache = iter->second;
    auto imagesList = cache.getImagesConfig();
    for (auto iter = imagesList.begin(); iter != imagesList.end(); iter++) {
        const RImageConfig& config = iter->second;
        unbindKeyFromResource(config.getImageId(), resKey);
    }
    
    auto plistsList = cache.getPlistsConfig();
    for (auto iter = plistsList.begin(); iter != plistsList.end(); iter++) {
        const RPlistConfig& config = iter->second;
        unbindKeyFromResource(config.getPlistId(), resKey);
    }
    
    auto videoList = cache.getVideosConfig();
    for (auto iter = videoList.begin(); iter != videoList.end(); iter++) {
        const RVideoConfig& config = iter->second;
        unbindKeyFromResource(config.getVideoId(), resKey);
    }
    
    auto audioList = cache.getAudiosConfig();
    for (auto iter = audioList.begin(); iter != audioList.end(); iter++) {
        const RAudioConfig& config = iter->second;
        unbindKeyFromResource(config.getAudioId(), resKey);
    }
}

void ResourceManager::cancelAllAsyncLoadTasks() {
    cancelAsyncTaskList(_appendingAddTasks);
    cancelAsyncTaskList(_asyncTasks);
}

void ResourceManager::cancelAsyncTaskList(const vector<ResourceAsyncLoadTask *> &taskList) {
    for (auto iter = taskList.begin(); iter != taskList.end(); iter++) {
        ResourceAsyncLoadTask* task = *iter;
        task->cancelTask();
    }
}

void ResourceManager::loadSingleImagesResourceConfig(const vector<string> &imagesPath, const string &parentPath) {
    auto iter = _resConfigMap.find(parentPath);
    if (iter == _resConfigMap.end()) {
        ResourceConfigCache cache;
        cache.addSingleImagesConfig(imagesPath, parentPath);
        _resConfigMap.insert(make_pair(parentPath, cache));
    } else {
        ResourceConfigCache& cache = iter->second;
        cache.addSingleImagesConfig(imagesPath, parentPath);
    }
}