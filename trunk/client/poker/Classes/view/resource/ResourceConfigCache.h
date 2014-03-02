//
//  ResourceConfigCache.h
//  poker
//
//  Created by xiaoxiangzi on 13-11-18.
//
//

#ifndef __poker__ResourceConfigCache__
#define __poker__ResourceConfigCache__

#include <iostream>
#include <map>
#include "Resource.h"
#include "tinyxml2.h"
using namespace tinyxml2;
using namespace std;

class ResourceManager;
class ResourceAsyncLoadTask;

class ResourceConfigCache {
    
public:
    const string& getStoreKey() const;
    const RImageConfig* getImageConfig(const ImageId& imageId) const;
    const RPlistConfig* getPlistConfig(const PlistId& plistId) const;
    const RVideoConfig* getVideoConfig(const VideoId& plistId) const;
    const RAudioConfig* getAudioConfig(const AudioId& plistId) const;
    
    void parse(const std::string& resXMLPath, const string& resXMLParentDir);
    const map<ImageId, RImageConfig>& getImagesConfig() const;
    const map<PlistId, RPlistConfig>& getPlistsConfig() const;
    const map<VideoId, RVideoConfig>& getVideosConfig() const;
    const map<AudioId, RAudioConfig>& getAudiosConfig() const;
    void addSingleImagesConfig(const vector<string>& imagesPath, const string& parentDir);
    ResourceConfigCache();
private:
    void parseImages(XMLElement* imagesElement);
    void parsePlists(XMLElement* plistsElement);
    void parseVideo(XMLElement* videosElement);
    void parseAudio(XMLElement* audioElement);
    string getPath(const string& pathRelativeToParent) const;
private:
    map<ImageId, RImageConfig> _imagesConfig;
    map<PlistId, RPlistConfig> _plistsConfig;
    map<VideoId, RVideoConfig> _videosConfig;
    map<AudioId, RAudioConfig> _audiosConfig;
    string _storeKey;
    string _configXMLParentDir;
    
    bool _containsMd5;
    bool _hasInited;
    
    friend class ResourceManager;
    friend class ResourceAsyncLoadTask;
};

#endif /* defined(__poker__ResourceInfoParser__) */
