//
//  ResourceConfigCache.cpp
//  poker
//
//  Created by xiaoxiangzi on 13-11-18.
//
//

#include "ResourceConfigCache.h"
#include "cocos2d.h"
using namespace cocos2d;

ResourceConfigCache::ResourceConfigCache() :
_containsMd5(false),
_hasInited(false) {}

void ResourceConfigCache::parse(const std::string &resXMLPath, const string &resXMLParentDir) {
    if (resXMLPath == _storeKey) {
        CCLOG("%s has been loaded once, skipped.", resXMLPath.c_str());
        return;
    }
    _configXMLParentDir = resXMLParentDir;
    
    string fullpath = CCFileUtils::sharedFileUtils()->fullPathForFilename(resXMLPath.c_str());
    unsigned long length = 0;
    char* data = (char*) CCFileUtils::sharedFileUtils()->sharedFileUtils()->getFileData(fullpath.c_str(), "r", &length);
    
    do {
        XMLDocument resInfoXML;
        XMLError errorCode = resInfoXML.Parse(data, length);
        if (errorCode != XML_SUCCESS) {
            CCLOG("Resource %s parse failed with error %d", resXMLPath.c_str(), errorCode);
            break;
        }
        
        XMLElement* root = resInfoXML.RootElement();  //root
        XMLElement* element = root->FirstChildElement();
        root->QueryBoolAttribute("md5", &_containsMd5);
        while(element != NULL){
            string elementName = element->Name();
            if (elementName == "images") {
                parseImages(element);
            } else if (elementName == "plists") {
                parsePlists(element);
            } else if (elementName == "videos") {
                parseVideo(element);
            } else if (elementName == "audios") {
                parseAudio(element);
            }
            element = element->NextSiblingElement();
        }
        
        _storeKey = resXMLPath;
    } while (0);
    CC_SAFE_DELETE_ARRAY(data);
    
    _hasInited = true;
}

string ResourceConfigCache::getPath(const string &pathRelativeToParent) const {
    if (_configXMLParentDir == "") {
        return pathRelativeToParent;
    }
    string path = _configXMLParentDir;
    if (path.substr(path.size() - 1, 1) != "/") {
        path.append("/");
    }
    path.append(pathRelativeToParent);
    return path;
}

void ResourceConfigCache::parseImages(XMLElement* imagesElement) {
    _imagesConfig.clear();
    if (imagesElement == NULL) {
        return;
    }

    XMLElement* element = imagesElement->FirstChildElement();
    while (element != NULL) {
        string isInPlistValue = element->Attribute("isInPlist");
        bool isInPlist = false;
        ImageId imageId = element->Attribute("id");
        if (isInPlistValue == "true") {
            isInPlist = true;
        } else {
            imageId = getPath(imageId);
        }
        
        PlistId plistId = "";
        if (isInPlist) {
            plistId = getPath(element->Attribute("plistId"));
        }
        string md5Hexdigest = "";
        if (_containsMd5) {
            md5Hexdigest = element->Attribute("md5");
        }
        RImageConfig config(imageId, isInPlist, plistId);
        config.setMd5Hexdigest(md5Hexdigest);
//        CCLOG("RImageConfig(id=%s, isInPlist=%s, plistId=%s)", imageId.c_str(), isInPlistValue.c_str(), plistId.c_str());
        _imagesConfig.insert(make_pair(imageId, config));
        
        element = element->NextSiblingElement();
    }
}

void ResourceConfigCache::parsePlists(tinyxml2::XMLElement *plistsElement) {
    _plistsConfig.clear();
    if (plistsElement == NULL) {
        return;
    }
    
    XMLElement* element = plistsElement->FirstChildElement();
    while (element != NULL) {
        PlistId plistId = getPath(element->Attribute("id"));
        ImageId plistImageId = getPath(element->Attribute("imageId"));
        RPlistConfig config(plistId, plistImageId);
//        CCLOG("RPlistConfig(id=%s, imageId=%s)", plistId.c_str(), plistImageId.c_str());
        string md5Hexdigest = "";
        if (_containsMd5) {
            md5Hexdigest = element->Attribute("md5");
        }
        config.setMd5Hexdigest(md5Hexdigest);
        _plistsConfig.insert(make_pair(plistId, config));
        
        element = element->NextSiblingElement();
    }
}

void ResourceConfigCache::parseVideo(tinyxml2::XMLElement *videosElement) {
    _videosConfig.clear();
    if (videosElement == NULL) {
        return;
    }
    
    XMLElement* element = videosElement->FirstChildElement();
    while (element != NULL) {
        VideoId videoId = getPath(element->Attribute("id"));
        RVideoConfig config(videoId);
        string md5Hexdigest = "";
        if (_containsMd5) {
            md5Hexdigest = element->Attribute("md5");;
        }
//        CCLOG("RVideoConfig(id=%s)", videoId.c_str());
        config.setMd5Hexdigest(md5Hexdigest);
        _videosConfig.insert(make_pair(videoId, config));
        
        element = element->NextSiblingElement();
    }
}

void ResourceConfigCache::parseAudio(tinyxml2::XMLElement *audioElement) {
    _audiosConfig.clear();
    if (audioElement == NULL) {
        return;
    }
    
    XMLElement* element = audioElement->FirstChildElement();
    while (element != NULL) {
        AudioId audioId = getPath(element->Attribute("id"));
        string isMusicStr = element->Attribute("isMusic");
        bool isMusic = false;
        if (isMusicStr == "true") {
            isMusic = true;
        }
        RAudioConfig config(audioId, isMusic);
        string md5Hexdigest = "";
        if (_containsMd5) {
            md5Hexdigest = element->Attribute("md5");;
        }
        config.setMd5Hexdigest(md5Hexdigest);
        _audiosConfig.insert(make_pair(audioId, config));
        
        element = element->NextSiblingElement();
    }
}

const RImageConfig* ResourceConfigCache::getImageConfig(const ImageId& imageId) const  {
    map<ImageId, RImageConfig>::const_iterator iter = _imagesConfig.find(imageId);
    if (iter != _imagesConfig.end()) {
        return &(iter->second);
    }
    
    return NULL;
}

const RPlistConfig* ResourceConfigCache::getPlistConfig(const PlistId& plistId) const {
    map<PlistId, RPlistConfig>::const_iterator iter = _plistsConfig.find(plistId);
    if (iter != _plistsConfig.end()) {
        return &(iter->second);
    }
    
    return NULL;
}

const RVideoConfig* ResourceConfigCache::getVideoConfig(const VideoId &videoId) const {
    map<VideoId, RVideoConfig>::const_iterator iter = _videosConfig.find(videoId);
    if (iter != _videosConfig.end()) {
        return &(iter->second);
    }
    
    return NULL;

}

const RAudioConfig* ResourceConfigCache::getAudioConfig(const AudioId &audioId) const {
    map<AudioId, RAudioConfig>::const_iterator iter = _audiosConfig.find(audioId);
    if (iter != _audiosConfig.end()) {
        return &(iter->second);
    }
    
    return NULL;
    
}

const map<ImageId, RImageConfig>& ResourceConfigCache::getImagesConfig() const {
    return _imagesConfig;
}

const map<PlistId, RPlistConfig>& ResourceConfigCache::getPlistsConfig() const {
    return _plistsConfig;
}

const map<VideoId, RVideoConfig>& ResourceConfigCache::getVideosConfig() const {
    return _videosConfig;
}

const map<AudioId, RAudioConfig>& ResourceConfigCache::getAudiosConfig() const {
    return _audiosConfig;
}

void ResourceConfigCache::addSingleImagesConfig(const vector<string> &imagesPath, const string &parentDir) {
    if (_hasInited && (parentDir != _storeKey)) {
        CCLOG("%s does not belong to cache store key %s", parentDir.c_str(), _storeKey.c_str());
        return;
    }
    
    _configXMLParentDir = parentDir;
    _storeKey = _configXMLParentDir;
    for (auto iter = imagesPath.begin(); iter != imagesPath.end(); iter++) {
        const string& relativePath = *iter;
        bool isInPlist = false;
        ImageId imageId = getPath(relativePath);
        auto imageIter = _imagesConfig.find(imageId);
        if (imageIter == _imagesConfig.end()) {
            RImageConfig config(imageId, isInPlist, "");
            _imagesConfig.insert(make_pair(imageId, config));
        }
    }
    _hasInited = true;
}