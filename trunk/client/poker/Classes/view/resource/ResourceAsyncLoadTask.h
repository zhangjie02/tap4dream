//
//  ResourceAsyncLoadTask.h
//  poker
//
//  Created by xiaoxiangzi on 13-12-13.
//
//

#ifndef __poker__ResourceAsyncLoadTask__
#define __poker__ResourceAsyncLoadTask__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
using namespace std;

class ResourceConfigCache;
class ResourceKey;
class RImageConfig;
class RVideoConfig;
class RPlistConfig;
class RAudioConfig;

class ResourceAsyncLoadTask : public CCObject {
    
public:
    ResourceAsyncLoadTask();
    static ResourceAsyncLoadTask* create();
    void loadResAsync(const ResourceConfigCache* cache, CCObject* target, SEL_CallFuncO selector, ResourceKey* resKey);
    bool hasTaskFinished() const;
    void update();
    ResourceKey* getResourceKey();
    void cancelTask();
private:
    void initLoadImages();
    void initLoadVideos();
    void initLoadPlists();
    void initLoadAudios();
    
    void loadImage();
    void loadVideo();
    void loadPlist();
    void loadAudio();
private:
    const ResourceConfigCache* _cache;
    CCObject* _target;
    SEL_CallFuncO _selector;
    ResourceKey* _resKey;
    
    bool _hasFinished;
    
    bool _hasLoadVideoStarted;
    bool _hasLoadImageStarted;
    bool _hasLoadPlistStarted;
    bool _hasLoadAudioStarted;
    
    vector<const RImageConfig*> _imagesToLoad;
    vector<const RVideoConfig*> _videosToLoad;
    vector<const RPlistConfig*> _plistsToLoad;
    vector<const RAudioConfig*> _audiosToLoad;
};

#endif /* defined(__poker__ResourceAsyncLoadTask__) */
