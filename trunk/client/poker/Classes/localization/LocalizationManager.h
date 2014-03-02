//
//  LocalizationManager.h
//  DinosaurIos
//
//  Created by �?红艳 on 12-10-22.
//  Copyright (c) 2012�?Droidhen. All rights reserved.
//

#ifndef DinosaurIos_LocalizationManager_h
#define DinosaurIos_LocalizationManager_h
#include <map>
#include <string>
#include "Global.h"
#include <iostream>
#include "cocos2d.h"
#include "LocalizationKeys.h"

using namespace std;


enum LocalizationType
{
    ENGLISH,
    SIMPLIFIED_CHINESE,
};

class LocalizationManager {
    
public:

    static const char* getCommonLocalizedString(const char* key);
    static LocalizationType getLocalizationType();
    
    // 根据language type获得 bm font
    static const char* getFont(const char* font);
    
private:
    static void initLocalizationMapByPath(string path,map<const string,const string>& map);
private:
    static LocalizationType _localizationType;
    static const int LOCALIZATION_TYPE_NUMBER = 2;
    static const char* LOCALE_DIR[LOCALIZATION_TYPE_NUMBER];
    
    static bool _hasLoadedCommonLocalizationMap;
    static bool _hasTypeInited;
    static map<const string, const string> _localizationCommonMap;
    
    static void initCommonLocalizationMap();

    static void checkAndInitLocalizationType();
    static void _checkCommonLocalizationInit();
};


#endif
