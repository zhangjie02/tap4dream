//
//  Resource.cpp
//  ResourceManager
//
//  Created by xiaoxiangzi on 13-11-13.
//
//

#include "Resource.h"
#include "ResourceKey.h"
#include "ResourceManager.h"
#include <algorithm>
#include "SlotFile.h"
#include "FileCache.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

// Class ResourceBindableByKey
ResourceBindableByKey::ResourceBindableByKey() {}

ResourceBindableByKey::~ResourceBindableByKey() {
    for (vector<ResourceKey*>::iterator iter = _keys.begin(); iter != _keys.end(); iter++) {
        ResourceKey* key = *iter;
        CC_SAFE_RELEASE_NULL(key);
    }
    _keys.clear();
}

unsigned int ResourceBindableByKey::getKeyCount() const {
    return _keys.size();
}

void ResourceBindableByKey::bindKey(ResourceKey *key) {
    vector<ResourceKey*>::iterator iter = find(_keys.begin(), _keys.end(), key);
    if (iter != _keys.end()) {
        // existed
        return;
    }
    CC_SAFE_RETAIN(key);
    _keys.push_back(key);
}

void ResourceBindableByKey::unbindKey(ResourceKey *key) {
    vector<ResourceKey*>::iterator iter = find(_keys.begin(), _keys.end(), key);
    if (iter == _keys.end()) {
        // not existed
        return;
    }
    CC_SAFE_RELEASE_NULL(key);
    _keys.erase(iter);
    
    if (getKeyCount() == 0) {
        releaseResource();
    }
}

// class RTexture
RTexture::RTexture() :
_texture(NULL) {}

RTexture::~RTexture() {
    CC_SAFE_RELEASE_NULL(_texture);
}

void RTexture::setTexture(cocos2d::CCTexture2D *texture) {
    CC_SAFE_RETAIN(texture);
    CC_SAFE_RELEASE_NULL(_texture);
    _texture = texture;
}

CCScale9Sprite* RTexture::getCCScale9Sprite(const ResourceId &resId) {
    return getCCScale9Sprite(resId, CCRectZero);
}

CCScale9Sprite* RTexture::getCCScale9Sprite(cocos2d::CCSpriteFrame *frame, const cocos2d::CCRect &capInsets) {
    CCRect capInsetsReal = capInsets;
    if (!capInsets.equals(CCRectZero)) {
        const CCRect& frameRect = frame->getRect();
        capInsetsReal = CCRectMake(capInsets.origin.x + frameRect.origin.x,
                                   capInsets.origin.y + frameRect.origin.y,
                                   capInsets.size.width, capInsets.size.height);
    }
    CCScale9Sprite* sprite = CCScale9Sprite::createWithSpriteFrame(frame, capInsetsReal);
    return sprite;
}

CCScale9Sprite* RTexture::getCCScale9Sprite(const ResourceId &resId, const CCRect& capInsets/* = CCRectZero*/) {
    CCSpriteFrame* frame = getCCSpriteFrame(resId);
    CCScale9Sprite* sprite = getCCScale9Sprite(frame, capInsets);
    sprite->setCascadeOpacityEnabled(true);
    return sprite;
}

// class RImage
RImage::RImage() : _imageConfig(NULL) {}

void RImage::initImage(const RImageConfig* imageConfig) {
    _imageConfig = imageConfig;
    CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage(_imageConfig->getImageId().c_str());
    setTexture(texture);
}

CCSprite* RImage::getCCSprite(const ResourceId &resId) {
    CCSprite* sprite = CCSprite::createWithTexture(_texture);
    return sprite;
}

CCSpriteFrame* RImage::getCCSpriteFrame(const ResourceId& resId) {
    CCSize size = _texture->getContentSize();
    CCRect rect = CCRectMake(0, 0, size.width, size.height);
    CCSpriteFrame* frame = CCSpriteFrame::createWithTexture(_texture, rect);
    return frame;
}

const string& RImage::getResAliasName() const {
    return _imageConfig->getImageId();
}

void RImage::releaseResource() {
    if (_texture) {
        CCTextureCache::sharedTextureCache()->removeTexture(_texture);
    }
}

CCLabelAtlas* RImage::getCCLabelAtlas(const ResourceId &resId, const char *text, unsigned int itemWidth, unsigned int itemHeight, unsigned int startCharMap){
    CCLabelAtlas* label = new CCLabelAtlas;
    label->initWithString(text, _texture, itemWidth, itemHeight, startCharMap);
    label->setAnchorPoint(ccp(0.5, 0.5));
    label->autorelease();
    return label;
}

CCLabelBMFont* RImage::getCCLabelBMFont(const ResourceId &resId, const char *text, CCTextAlignment alignment, int width) {
    string fntFile = getFNTFileName(_imageConfig->getImageId());
    CCLabelBMFont* label = CCLabelBMFont::create(text, fntFile.c_str(), width, alignment);
    return label;
}
                                                 
string RImage::getFNTFileName(const string &pngFile) const {
    size_t index = pngFile.rfind(".png");
    if (index == pngFile.npos) {
        CCLOG("wrong file");
        return "";
    }
    
    string fntFile = pngFile.substr(0, index) + ".fnt";
    return fntFile;
}

// class RPlist
RPlist::RPlist() : _plistConfig(NULL) {}
void RPlist::initPlist(const RPlistConfig* plistConfig) {
    if (_plistConfig && _plistConfig->getPlistId() == plistConfig->getPlistId()) {
        return;
    }
    
    _plistConfig = plistConfig;
    CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage(_plistConfig->getImageId().c_str());
    setTexture(texture);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(_plistConfig->getPlistId().c_str(), texture);
}

CCSpriteFrame* RPlist::getCCSpriteFrame(const ResourceId &resId) {
    CCSpriteFrame* frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(resId.c_str());
    return frame;
}

CCSprite* RPlist::getCCSprite(const ResourceId &resId) {
    CCSpriteFrame* frame = getCCSpriteFrame(resId);
    CCSprite* sprite = CCSprite::createWithSpriteFrame(frame);
    return sprite;
}

CCLabelBMFont* RPlist::getCCLabelBMFont(const ResourceId &resId, const char *text, CCTextAlignment alignment, int width) {
    return NULL;
}

const string& RPlist::getResAliasName() const {
    return _plistConfig->getPlistId();
}

void RPlist::releaseResource() {
    CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromTexture(_texture);
    CCTextureCache::sharedTextureCache()->removeTexture(_texture);
}

CCLabelAtlas* RPlist::getCCLabelAtlas(const ResourceId &resId, const char *text, unsigned int itemWidth, unsigned int itemHeight, unsigned int startCharMap) {
    return NULL;
}

// RVideo
RVideo::RVideo() :
_videoConfig(NULL),
_videoFile(NULL){}

RVideo::~RVideo() {
    CC_SAFE_RELEASE_NULL(_videoFile);
}

void RVideo::initVideo(const RVideoConfig *videoConfig) {
    if (_videoConfig && _videoConfig->getVideoId() == videoConfig->getVideoId()) {
        return;
    }
    
    _videoConfig = videoConfig;
    CC_SAFE_RELEASE_NULL(_videoFile);
    _videoFile = FileCache::getInstance()->addFile(_videoConfig->getVideoId().c_str());
    CC_SAFE_RETAIN(_videoFile);
}

void RVideo::releaseResource() {
    if (_videoFile) {
        FileCache::getInstance()->removeFile(_videoFile->getPath().c_str());
    }
    CC_SAFE_RELEASE_NULL(_videoFile);
}

const string& RVideo::getResAliasName() const {
    return _videoConfig->getVideoId();
}

File* RVideo::getVideoFile() const {
    return _videoFile;
}


RAudio::RAudio() : _audioConfig(NULL) {}

RAudio::~RAudio() {
    unloadAudio();
}

void RAudio::initAudio(const RAudioConfig *audioConfig) {
    _audioConfig = audioConfig;
    preloadAudio();
}

void RAudio::preloadAudio() {
    if (_audioConfig->isMusic()) {
        SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(_audioConfig->getAudioId().c_str());
    } else {
        SimpleAudioEngine::sharedEngine()->preloadEffect(_audioConfig->getAudioId().c_str());
    }
}

void RAudio::unloadAudio() {
    SimpleAudioEngine::sharedEngine()->unloadEffect(_audioConfig->getAudioId().c_str());
}

const string& RAudio::getResAliasName() const {
    return _audioConfig->getAudioId();
}

void RAudio::releaseResource() {
    unloadAudio();
}
