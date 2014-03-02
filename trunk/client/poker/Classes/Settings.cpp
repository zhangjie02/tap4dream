//
//  Settings.cpp
//  MagicEra
//
//  Created by shengsh on 12-11-14.
//
//

#include "Settings.h"
#include "cocos2d.h"
#include "Preferences.h"
#include "Global.h"
#include "AudioUtil.h"

const char* Settings::CONFIG_SOUND_KEY = "sound";
const char* Settings::CONFIG_MUSIC_KEY = "music";
const char* Settings::CONFIG_AD_STATUS_KEY = "adStatus";
const char* Settings::CONFIG_RATE_STATUS_KEY = "rateStatus";
const char* Settings::HAS_RATE_KEY = "hasrated";
const char* Settings::LAST_SHOW_RATE_TIME = "lastShowRateTime";

bool Settings::hasAdEnabled = true;
bool Settings::hasMusicEndable = true;
bool Settings::hasRateEnabled = true;
bool Settings::hasSoundEnabled = true;
bool Settings::hasShownRate = false;
bool Settings::needShowRate = false;
int Settings::lastShowRateTime = 0;

void Settings::init() {
    Preferences* pref = Preferences::sharedPreferences();
    hasAdEnabled = pref->getBoolForKey(CONFIG_AD_STATUS_KEY, true);
    hasMusicEndable = pref->getBoolForKey(CONFIG_MUSIC_KEY, true);
    hasRateEnabled = pref->getBoolForKey(CONFIG_RATE_STATUS_KEY, true);
    hasSoundEnabled = pref->getBoolForKey(CONFIG_SOUND_KEY, true);
    hasShownRate = pref->getBoolForKey(HAS_RATE_KEY,false);
    needShowRate = false;
    lastShowRateTime = pref->getIntForKey(LAST_SHOW_RATE_TIME,0);
}

bool Settings::isSoundEnabled() {
    return hasSoundEnabled;
}

bool Settings::isMusicEnabled() {
    return hasMusicEndable;
}

bool Settings::isAdStatusEnabled() {
    return hasAdEnabled;
}

bool Settings::isRateStatusEnabled(){
    return hasRateEnabled;
}

void Settings::enableSound(bool enable) {
    hasSoundEnabled = enable;
    setBoolForKey(CONFIG_SOUND_KEY, enable);
}

void Settings::enableMusic(bool enable) {
    hasMusicEndable = enable;
    setBoolForKey(CONFIG_MUSIC_KEY, enable);
    if(enable){
        AudioUtil::playBgm();
    }else{
        AudioUtil::stopBgm();
    }
}

void Settings::enableAdStatus(bool enable) {
    hasAdEnabled = enable;
    setBoolForKey(CONFIG_AD_STATUS_KEY, enable);
}

void Settings::enableRateStatus(bool enable){
    hasRateEnabled = enable;
    setBoolForKey(CONFIG_RATE_STATUS_KEY, enable);
}

bool Settings::getHasShowRateTag(){
    return hasShownRate;
}

void Settings::setHasShowRateTag(){
    hasShownRate=true;
    if (hasShownRate) {
        needShowRate=false;
    }
    setBoolForKey(HAS_RATE_KEY, true);
}

int Settings::getLastShowRateTime(){
    return lastShowRateTime;
}

void Settings::setShowRate(){
    needShowRate=false;
    lastShowRateTime=Global::getServerTimeWithUpdate();
    Preferences::sharedPreferences()->setIntForKey(LAST_SHOW_RATE_TIME, lastShowRateTime);
}

bool Settings::getShowRateTag(){
    return needShowRate;
}

void Settings::setShowRateTag(bool v){
    needShowRate=v;
}

void Settings::setBoolForKey(const char* key, bool value) {
    Preferences::sharedPreferences()->setBoolForKey(key, value);
}

void Settings::setStringForKey(const char* key, const std::string& value) {
    Preferences::sharedPreferences()->setStringForKey(key, value);
}

std::string Settings::getStringForKey(const char* key) {
    return Preferences::sharedPreferences()->getStringForKey(key, "");
}
