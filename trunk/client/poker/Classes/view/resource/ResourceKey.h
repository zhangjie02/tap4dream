//
//  ResourceKey.h
//  ResourceManager
//
//  Created by xiaoxiangzi on 13-11-12.
//
//

#ifndef __ResourceManager__ResourceKey__
#define __ResourceManager__ResourceKey__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include <vector>
using namespace std;
using namespace cocos2d;
using namespace extension;

class ResourceManager;
class ResourceBindableByKey;
class CCMenuItemShader;
class File;
class RAudio;

class ResourceKey : public CCObject {
    
public:
    bool isValid() const;
    CCSprite* getCCSprite(const char* imageId);
    CCSpriteFrame* getCCSpriteFrame(const char* imageId);
    CCScale9Sprite* getCCScale9Sprite(const char* imageId);
    CCScale9Sprite* getCCScale9Sprite(const char* imageId, const CCRect& capInsets);
    CCLabelAtlas* getCCLabelAtlas(const char *imageId, const char *text,  unsigned int itemWidth, unsigned int itemHeight, unsigned int startCharMap);
    CCLabelBMFont* getCCLabelBMFont(const char* imageId, const char* text, CCTextAlignment alignment, int width = 0);
    File* getVideoFile(const char* videoId);
    const RAudio* getAudio(const char* audioId);
    void addPreferedStoreKey(const string& storeKey);
    const vector<string>& getPreferedStoreKeys() const;
private:
    CREATE_FUNC(ResourceKey);
    bool init() { return true; }
    ResourceKey();
    ResourceKey(const ResourceKey& resKey);
    ResourceKey& operator=(const ResourceKey& resKey);
    void setValid(bool valid);
private:
    bool _valid;
    vector<string> _preferedStoreKeys;
    friend class ResourceManager;
};

#endif /* defined(__ResourceManager__ResourceKey__) */
