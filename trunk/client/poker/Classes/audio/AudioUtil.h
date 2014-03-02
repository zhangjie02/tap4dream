//
//  AudioUtil.h
//  Cocos2dDemo
//
//  Created by shengsh on 12-11-14.
//
//

#ifndef Cocos2dDemo_AudioUtil_h
#define Cocos2dDemo_AudioUtil_h

#include "stdint.h"
#include <string>
#include <map>
using namespace std;

class AudioStatus {
    
public:
    AudioStatus(int64_t durationInMs_, int64_t lastPlayTimeInMs_) :
    durationInMs(durationInMs_),
    lastPlayTimeInMs(lastPlayTimeInMs_) {}
    
    int64_t durationInMs;
    int64_t lastPlayTimeInMs;
};

class AudioUtil{
public:
    static unsigned int playSound(const char* file, bool loop = false);
    static void stopAll();
    static void playMusic(const char* file);
    static void playBgm();
    static void stopBgm();
    static void stopEffect(unsigned int effectId);
    
    static void pauseOnUnactive(bool forced = false);
    static void resumeOnActive(bool forced = false);
    
    static void setEffectQuotiety(float volumn);
    
    static void reset();
private:
    static void init();
    static float getVolumn(const char* file, bool isBgm);
private:
    static char* _lastBgm;
    
    static bool _isUnactive;
    static bool _isForced;
    
    static string _curBgm;
    
    static float _effectQuotiety;
};

#endif
