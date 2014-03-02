//
//  Screen.cpp
//  Cocos2dDemo
//
//  Created by linzi on 13-1-6.
//
//

#include <cstddef>
#include "Screen.h"

const float Screen::DESIGN_WIDTH = 1024.0f;
const float Screen::DESIGN_HEIGHT = 614.0f;
const float Screen::MIN_ASPECT_RATIO = 960.0 / 640.0;

static Screen* sCurrentScreen = NULL;
Screen* Screen::init(float screenWidth, float screenHeight) {
    if (sCurrentScreen != NULL) {
        delete sCurrentScreen;
    }
    sCurrentScreen = new Screen(screenWidth, screenHeight);
    return sCurrentScreen;
}

Screen* Screen::getCurrentScreen() {
    return sCurrentScreen;
}

Screen::Screen(float screenWidth, float screenHeight) {
    _realWidth = screenWidth;
    _realHeight = screenHeight;
    
    float scaleX = screenWidth / DESIGN_WIDTH;
    float scaleY = screenHeight / DESIGN_HEIGHT;
    float scale = scaleX < scaleY ? scaleX : scaleY;
    
    _scaledDesignWidth = screenWidth / scale;
    _scaledDesignHeight = screenHeight / scale;
    
    _fitScreenScaleX = _scaledDesignWidth / DESIGN_WIDTH;
    _fitScreenScaleY = _scaledDesignHeight / DESIGN_HEIGHT;
}

float Screen::getScreenWidth() const {
    return _realWidth;
}

float Screen::getScreenHeight() const {
    return _realHeight;
}

float Screen::getScaledDesignedWidth() const {
    return _scaledDesignWidth;
}

float Screen::getScaledDesignedHeight() const {
    return _scaledDesignHeight;
}

float Screen::getFitScreenScaleX() const {
    return _fitScreenScaleX;
}

float Screen::getFitScreenScaleY() const {
    return _fitScreenScaleY;
}
