//
//  AudioUtil.cpp
//  Cocos2dDemo
//
//  Created by shengsh on 12-11-14.
//
//

#include "AudioUtil.h"
#include "SimpleAudioEngine.h"
#include "Settings.h"
#include "ResourceName.h"
#include "cocos2d.h"
#include "Global.h"
#include "Constant.h"
#include "ResourceManager.h"
using namespace CocosDenshion;
using namespace cocos2d;
using namespace std;

bool AudioUtil::_isUnactive = false;
string AudioUtil::_curBgm = "";
bool AudioUtil::_isForced = false;
float AudioUtil::_effectQuotiety = 1.0;

void AudioUtil::playMusic(const char *file){
    if(Settings::isMusicEnabled()){
        _curBgm = file;
        SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(1);//volume ranges in [0,1]
        SimpleAudioEngine::sharedEngine()->playBackgroundMusic(file, true);
    }
}

unsigned int AudioUtil::playSound(const char *file, bool loop) {
    if(Settings::isSoundEnabled()){
        SimpleAudioEngine::sharedEngine()->setEffectsVolume(1 * _effectQuotiety);//volume ranges in [0,1]
        return SimpleAudioEngine::sharedEngine()->playEffect(file, loop);
    }
    
    return 0;
}

void AudioUtil::setEffectQuotiety(float volumn) {
    _effectQuotiety = volumn;
}

void AudioUtil::init() {}

void AudioUtil::playBgm() {}

void AudioUtil::stopBgm(){
    if (_curBgm != "") {
        SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    }
    _curBgm = "";
}

void AudioUtil::stopAll(){
    stopBgm();
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
}

void AudioUtil::stopEffect(unsigned int effectId) {
    if (effectId > 0) {
        SimpleAudioEngine::sharedEngine()->stopEffect(effectId);
    }
}

void AudioUtil::pauseOnUnactive(bool forced) {
    CCLOG("audio pauseOnUnactive _isForced %d forced %d", _isForced, forced);
    if (forced || (!_isForced)) {
        _isForced = forced;
    }
    
    _isUnactive = true;
    string tmp = _curBgm;
    stopAll();
    _curBgm = tmp;
    CCLOG("after audio pauseOnUnactive _isForced %d forced %d", _isForced, forced);
}

void AudioUtil::resumeOnActive(bool forced) {
    CCLOG("audio resumeOnActive _isForced %d forced %d", _isForced, forced);
    if (_isForced && !forced) {
        return;
    }
    
    if ((_curBgm != "") && _isUnactive) {
        AudioUtil::playMusic(_curBgm.c_str());
    }
    _isForced = false;
    _isUnactive = false;
    CCLOG("after audio resumeOnActive _isForced %d forced %d", _isForced, forced);
}

void AudioUtil::reset() {
    CCLOG("reset audio");
    _isForced = false;
    _isUnactive = false;
    _curBgm = "";
}