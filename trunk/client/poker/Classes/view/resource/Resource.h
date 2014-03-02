//
//  Resource.h
//  ResourceManager
//
//  Created by xiaoxiangzi on 13-11-13.
//
//

#ifndef __ResourceManager__Resource__
#define __ResourceManager__Resource__

#include "cocos2d.h"
#include "cocos-ext.h"
#include <vector>

using namespace cocos2d;
using namespace extension;
using namespace std;

class ResourceManager;
class ResourceKey;
class File;

typedef string ResourceId;
typedef ResourceId ImageId;
typedef ResourceId PlistId;
typedef ResourceId VideoId;
typedef ResourceId AudioId;

class RConfig {
public:
    virtual ~RConfig() {}
    void setMd5Hexdigest(const string& md5Hexdigest) { _md5Hexdigest = md5Hexdigest; }
    const string& getMd5Hexdigest() const { return _md5Hexdigest; }
private:
    string _md5Hexdigest;
};

class RImageConfig : public RConfig {
public:
    RImageConfig(ImageId imageId, bool isInPlist, PlistId plistId) : _id(imageId), _isInPlist(isInPlist), _plistId(plistId) {}
    inline const ImageId& getImageId() const { return _id; }
    inline const bool isInPlist() const { return _isInPlist; }
    inline const PlistId& getPlistId() const { return _plistId; };
private:
    ImageId _id;
    bool _isInPlist;
    PlistId _plistId;
};

class RPlistConfig : public RConfig {
public:
    RPlistConfig(PlistId plistId, ImageId imageId) : _plistId(plistId), _imageId(imageId) {}
    inline const ImageId& getImageId() const { return _imageId; }
    inline const PlistId& getPlistId() const { return _plistId; }
private:
    PlistId _plistId;
    ImageId _imageId;
};

class RVideoConfig : public RConfig {
public:
    RVideoConfig(VideoId videoId) : _videoId(videoId) {}
    inline const VideoId& getVideoId() const { return _videoId; }
private:
    VideoId _videoId;
};

class RAudioConfig : public RConfig {
public:
    RAudioConfig(AudioId audioId, bool isMusic) : _audioId(audioId), _isMusic(isMusic) {}
    inline const AudioId& getAudioId() const { return _audioId; }
    const bool isMusic() const { return _isMusic; }
private:
    AudioId _audioId;
    bool _isMusic;
};

class ResourceBindableByKey : public CCObject {
public:
    unsigned int getKeyCount() const;
    void bindKey(ResourceKey* key);
    void unbindKey(ResourceKey* key);
    virtual ~ResourceBindableByKey();
    virtual const string& getResAliasName() const = 0;
protected:
    ResourceBindableByKey();
    virtual void releaseResource() = 0;
protected:
    vector<ResourceKey*> _keys;
};

class RTexture : public ResourceBindableByKey {
public:
    virtual CCScale9Sprite* getCCScale9Sprite(const ResourceId& resId);
    virtual CCSprite* getCCSprite(const ResourceId& resId) = 0;
    virtual CCSpriteFrame* getCCSpriteFrame(const ResourceId& resId) = 0;
    virtual CCScale9Sprite* getCCScale9Sprite(const ResourceId& resId, const CCRect& capInsets);
    virtual CCLabelAtlas* getCCLabelAtlas(const ResourceId& resId, const char *text,  unsigned int itemWidth, unsigned int itemHeight, unsigned int startCharMap) = 0;
    virtual CCLabelBMFont* getCCLabelBMFont(const ResourceId& resId, const char* text, CCTextAlignment alignment, int width = 0) = 0;
protected:
    RTexture();
    virtual ~RTexture();
    void setTexture(CCTexture2D* texture);
    CCScale9Sprite* getCCScale9Sprite(CCSpriteFrame* frame, const CCRect& capInsets);
protected:
    CCTexture2D* _texture;
};

class RImage : public RTexture {
public:
    virtual CCSprite* getCCSprite(const ResourceId& resId);
    virtual CCSpriteFrame* getCCSpriteFrame(const ResourceId& resId);
   virtual CCLabelAtlas* getCCLabelAtlas(const ResourceId& resId, const char *text,  unsigned int itemWidth, unsigned int itemHeight, unsigned int startCharMap);
    virtual const string& getResAliasName() const;
    virtual CCLabelBMFont* getCCLabelBMFont(const ResourceId& resId, const char* text, CCTextAlignment alignment, int width = 0);
protected:
    CREATE_FUNC(RImage)
    RImage();
    bool init() { return true; }
    void initImage(const RImageConfig* imageId);
    virtual void releaseResource();
    string getFNTFileName(const string& pngFile) const;
private:
    const RImageConfig* _imageConfig;
    
    friend class ResourceManager;
};

class RPlist : public RTexture {
public:
    virtual CCSprite* getCCSprite(const ResourceId& resId);
    virtual CCSpriteFrame* getCCSpriteFrame(const ResourceId& resId);
    virtual CCLabelAtlas* getCCLabelAtlas(const ResourceId& resId, const char *text,  unsigned int itemWidth, unsigned int itemHeight, unsigned int startCharMap);
    virtual CCLabelBMFont* getCCLabelBMFont(const ResourceId& resId, const char* text, CCTextAlignment alignment, int width = 0);
    virtual const string& getResAliasName() const;
protected:
    RPlist();
    CREATE_FUNC(RPlist);
    bool init() { return true; }
    void initPlist(const RPlistConfig* plistConfig);
    virtual void releaseResource();
private:
    const RPlistConfig* _plistConfig;
    friend class ResourceManager;
};

class RVideo : public ResourceBindableByKey {
public:
    virtual const string& getResAliasName() const;
    File* getVideoFile() const;
protected:
    RVideo();
    virtual ~RVideo();
    CREATE_FUNC(RVideo);
    bool init() { return true; }
    void initVideo(const RVideoConfig* videoConfig);
    virtual void releaseResource();
    
private:
    File* _videoFile;
    const RVideoConfig* _videoConfig;
    
    friend class ResourceManager;
};

class RAudio : public ResourceBindableByKey {
public:
    virtual const string& getResAliasName() const;
protected:
    RAudio();
    virtual ~RAudio();
    CREATE_FUNC(RAudio);
    bool init() { return true; }
    void initAudio(const RAudioConfig* audioConfig);
    virtual void releaseResource();
    void unloadAudio();
    void preloadAudio();
private:
    const RAudioConfig* _audioConfig;
    
    friend class ResourceManager;
};

#endif /* defined(__ResourceManager__Resource__) */
