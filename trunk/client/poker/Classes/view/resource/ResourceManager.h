//
//  ResourceManager.h
//  ResourceManager
//
//  Created by xiaoxiangzi on 13-11-12.
//
//

#ifndef __ResourceManager__ResourceManager__
#define __ResourceManager__ResourceManager__

#include <iostream>
#include "cocos2d.h"
#include "ResourceConfigCache.h"
#include <map>
using namespace std;
using namespace cocos2d;

class ResourceKey;
class ResourceBindableByKey;
class File;

class ResourceManager {
    
public:
    static ResourceManager* getInstance() {
        static ResourceManager manager;
        return &manager;
    }
    
    void loadLocalResourceConfig();
    void loadResourceConfig(const string& resXmlPath, const string& resParentPath);
    void loadSingleImagesResourceConfig(const vector<string>& imagesPath, const string& parentPath);
    
    ResourceKey* createResourceKey();
    void releaseResourceKey(ResourceKey* key);
    
    void loadResourceAsync(const string& resXmlPath, CCObject* target, SEL_CallFuncO selector, ResourceKey* resKey);
    
    void update();
    
    void loadPlistResource(const string& plistId, ResourceKey* resKey);
    void unbindKeyFromResource(const string& resourceId, ResourceKey* resKey);
    void unbindKeyFromResourcesInStoreConfig(const string& resXmlPath, ResourceKey* resKey);
    void cancelAllAsyncLoadTasks();
private:
    CCSprite* getCCSprite(const char* imageId, ResourceKey* resKey);
    CCSpriteFrame* getCCSpriteFrame(const char* imageId, ResourceKey* resKey);
    CCScale9Sprite* getCCScale9Sprite(const char* imageId, ResourceKey* resKey, const CCRect& capInsets);
    CCLabelAtlas* getCCLabelAtlas(const char* imageId, ResourceKey* resKey, const char *text,  unsigned int itemWidth, unsigned int itemHeight, unsigned int startCharMap);
    CCLabelBMFont* getCCLabelBMFont(const char* imageId, ResourceKey* resKey, const char* text, CCTextAlignment alignment, int width);
    const RAudio* getAudioResource(const char* audioId, ResourceKey* resKey);
    
    File* getFile(const char* fileId, ResourceKey* resKey);
    
    void addKey(ResourceKey* key);
    bool containsKey(ResourceKey* key) const;
    RAudio* findAudioResource(const ResourceId& resourceId, ResourceKey* resKey);
    RTexture* findResource(const ResourceId& resourceId, ResourceKey* resKey);
    RVideo* findVideoResource(const ResourceId& resourceId, ResourceKey* resKey);
    const RImageConfig* getRImageConfig(const string& imageId, ResourceKey* resKey) const;
    const RPlistConfig* getRPlistConfig(const string& plistId, ResourceKey* resKey) const;
    const RVideoConfig* getRVideoConfig(const string& videoId, ResourceKey* resKey) const;
    const RAudioConfig* getRAudioConfig(const string& audioId, ResourceKey* resKey) const;
    const RConfig* getRConfig(const ResourceId& resourceId, ResourceKey* resKey, int resType) const;
    const RConfig* getRConfig(const ResourceConfigCache* cache, const ResourceId& resourceId, int resType) const;
    bool isValidKey(ResourceKey* key) const;
    void unbindKeyFromAllResources(ResourceKey* key);
    const vector<const ResourceConfigCache*> getPreferedConfigCaches(ResourceKey* resKey) const;
    void bindKeyToResource(const string& resourceId, ResourceKey* resKey, int resType);
    
    void addAppendingReleaseResKey(ResourceKey* resKey);
    bool isResKeyUsedInAsyncTask(ResourceKey* resKey);
    void addPlistResource(const RPlistConfig* plistConfig);
    void cancelAsyncTaskList(const vector<ResourceAsyncLoadTask*>& taskList);
private:
    ResourceManager() {}
    ResourceManager(const ResourceManager&);
    ResourceManager& operator=(const ResourceManager&);
public:
    static const string LOCAL_STORE_KEY;
private:
    static const int IMAGE_CONFIG = 0;
    static const int PLIST_CONFIG = 1;
    static const int VIDEO_CONFIG = 2;
    static const int AUDIO_CONFIG = 3;
    
    // stage, cache pair
    map<string, ResourceConfigCache> _resConfigMap;
    
    vector<ResourceKey*> _resourceKeys;
    
    map<ResourceId, ResourceBindableByKey*> _resources;
    
    vector<ResourceAsyncLoadTask*> _asyncTasks;
    vector<ResourceAsyncLoadTask*> _appendingAddTasks;
    
    vector<ResourceKey*> _appendingReleaseResKeys;
    
    friend class ResourceKey;
    friend class ResourceAsyncLoadTask;
};

#endif /* defined(__ResourceManager__ResourceManager__) */
