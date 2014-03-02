//
//  Settings.h
//  MagicEra
//
//  Created by shengsh on 12-11-14.
//
//

#ifndef Cocos2dDemo_Settings_h
#define Cocos2dDemo_Settings_h

#include <string>

class Settings {
public:
    static void init();
    
    static bool isSoundEnabled();
    static bool isMusicEnabled();
    static bool isAdStatusEnabled();
    static bool isRateStatusEnabled();

    
    static void enableSound(bool enable);
    static void enableMusic(bool enable);
    static void enableAdStatus(bool enable);
    static void enableRateStatus(bool enable);
    
    static bool getHasShowRateTag();
    static void setHasShowRateTag();
    static bool getShowRateTag();
    static void setShowRateTag(bool v);
    static int getLastShowRateTime();
    static void setShowRate();
    
    static void setStringForKey(const char* key, const std::string& value);
    static std::string getStringForKey(const char* key);
    
private:
    static const char* CONFIG_SOUND_KEY;
    static const char* CONFIG_MUSIC_KEY;
    static const char* CONFIG_AD_STATUS_KEY;
    static const char* CONFIG_RATE_STATUS_KEY;
    static const char* HAS_RATE_KEY;
    static const char* LAST_SHOW_RATE_TIME;
    
    static void setBoolForKey(const char* key, bool value);
private:
    static bool hasSoundEnabled;
    static bool hasMusicEndable;
    static bool hasAdEnabled;
    static bool hasRateEnabled;
    
    static bool hasShownRate;
    static bool needShowRate;
    static int lastShowRateTime;

};
#endif
