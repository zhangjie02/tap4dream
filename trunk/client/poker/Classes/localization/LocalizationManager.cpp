//
//  LocalizationManager.mm
//  DinosaurIos
//
//  Created by 陈 红艳 on 12-10-22.
//  Copyright (c) 2012年 Droidhen. All rights reserved.
//

#include "LocalizationManager.h"

#include "FontConstants.h"
#include "tinyxml2.h"
#include "FileCache.h"
#include "SlotFile.h"

#include <sstream>
#include <string>

using namespace tinyxml2;
using namespace std;
USING_NS_CC;


const char* LocalizationManager::LOCALE_DIR[LOCALIZATION_TYPE_NUMBER]={"Resources.en","Resources.zh"};

LocalizationType LocalizationManager::_localizationType = ENGLISH;
bool LocalizationManager::_hasLoadedCommonLocalizationMap = false;
std::map<const std::string, const std::string> LocalizationManager::_localizationCommonMap;
bool LocalizationManager::_hasTypeInited = false;

void LocalizationManager::initCommonLocalizationMap(){
    checkAndInitLocalizationType();
    
    stringstream ss;
    ss<<"localization/"<<LOCALE_DIR[_localizationType]<<"/strings.xml";
    
    string path=ss.str();
    
    initLocalizationMapByPath(path,_localizationCommonMap);
    
    _hasLoadedCommonLocalizationMap = true;
}

void LocalizationManager::initLocalizationMapByPath(string path,map<const string, const string>& map){
    map.clear();
    
    File* file = FileCache::getInstance()->addFile(path.c_str());
    
    XMLDocument xmlDoc;
    XMLError error = xmlDoc.Parse((char*)file->getContent(), file->getSize());
    
    if(error != tinyxml2::XML_NO_ERROR){
        CCLOG("OpenXMLError:%d of file:%s",error,path.c_str());
    }else{
        tinyxml2::XMLElement* root=xmlDoc.RootElement();
        tinyxml2::XMLElement* element = root->FirstChildElement();
        while(element!=NULL){
            map.insert(pair<const string, const string>(element->Value(),element->GetText()));
            element = element->NextSiblingElement();
        }
    }
    FileCache::getInstance()->removeFile(path.c_str());
}


const char* LocalizationManager::getFont(const char* font) {
    _checkCommonLocalizationInit();
    

//    if(_localizationType == SIMPLIFIED_CHINESE) {
//        return FontConstants::SIMSUM_BMFONT;
//    }

    
    return font;
}

const char* LocalizationManager::getCommonLocalizedString(const char *key)
{

    _checkCommonLocalizationInit();
    
    if(_localizationCommonMap.find(key) == _localizationCommonMap.end()) {
        CCLOG("[localization]can't find key %s", key);
        return "";
    }
    return _localizationCommonMap.at(key).c_str();
}

LocalizationType LocalizationManager::getLocalizationType()
{
    checkAndInitLocalizationType();
    
    return _localizationType;
}

void LocalizationManager::checkAndInitLocalizationType() {
    if (_hasTypeInited) {
        return;
    }


    _hasTypeInited = true;
    ccLanguageType lan = CCApplication::sharedApplication()->getCurrentLanguage();
    lan = kLanguageEnglish;
    if(lan==kLanguageChinese){
        _localizationType = SIMPLIFIED_CHINESE;
    }else{
        _localizationType = ENGLISH;
    }

}

void LocalizationManager::_checkCommonLocalizationInit() {
    if(!_hasLoadedCommonLocalizationMap){
        initCommonLocalizationMap();
    }
}



