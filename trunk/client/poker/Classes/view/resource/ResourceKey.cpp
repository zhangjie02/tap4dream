//
//  ResourceKey.cpp
//  ResourceManager
//
//  Created by xiaoxiangzi on 13-11-12.
//
//

#include "ResourceKey.h"
#include "ResourceManager.h"
#include <algorithm>

ResourceKey::ResourceKey() : _valid(false), _preferedStoreKeys() {}

ResourceKey::ResourceKey(const ResourceKey& resKey) {}

ResourceKey& ResourceKey::operator=(const ResourceKey & resKey) {
    return *this;
}

bool ResourceKey::isValid() const {
    return _valid;
}

void ResourceKey::setValid(bool valid) {
    _valid = valid;
}

CCSprite* ResourceKey::getCCSprite(const char *imageId) {
    return ResourceManager::getInstance()->getCCSprite(imageId, this);
}

CCSpriteFrame* ResourceKey::getCCSpriteFrame(const char *imageId) {
    return ResourceManager::getInstance()->getCCSpriteFrame(imageId, this);
}

CCScale9Sprite* ResourceKey::getCCScale9Sprite(const char *imageId, const CCRect& capInsets/* = CCRectZero*/) {
    return ResourceManager::getInstance()->getCCScale9Sprite(imageId, this, capInsets);
}

CCScale9Sprite* ResourceKey::getCCScale9Sprite(const char *imageId) {
    return getCCScale9Sprite(imageId, CCRectZero);
}

CCLabelAtlas* ResourceKey::getCCLabelAtlas(const char *imageId, const char *text, unsigned int itemWidth, unsigned int itemHeight, unsigned int startCharMap) {
    return ResourceManager::getInstance()->getCCLabelAtlas(imageId, this, text, itemWidth, itemHeight, startCharMap);
}

CCLabelBMFont* ResourceKey::getCCLabelBMFont(const char *imageId, const char *text, CCTextAlignment alignment, int width) {
    return ResourceManager::getInstance()->getCCLabelBMFont(imageId, this, text, alignment, width);
}

File* ResourceKey::getVideoFile(const char *videoId) {
    return ResourceManager::getInstance()->getFile(videoId, this);
}

const RAudio* ResourceKey::getAudio(const char *audioId) {
    return ResourceManager::getInstance()->getAudioResource(audioId, this);
}

void ResourceKey::addPreferedStoreKey(const string &storeKey) {
    vector<string>::iterator iter = find(_preferedStoreKeys.begin(), _preferedStoreKeys.end(), storeKey);
    if (iter == _preferedStoreKeys.end()) {
        _preferedStoreKeys.push_back(storeKey);
    }
}

const vector<string>& ResourceKey::getPreferedStoreKeys() const {
    return _preferedStoreKeys;
}
