//
//  BlinkLight.cpp
//  poker
//
//  Created by xiaoxiangzi on 14-1-26.
//
//

#include "BlinkLight.h"
#include "LayoutUtil.h"

BlinkLight* BlinkLight::create(cocos2d::CCSpriteFrame *one, cocos2d::CCSpriteFrame *two) {
    BlinkLight* light = new BlinkLight;
    light->initLight(one, two);
    light->autorelease();
    return light;
}

BlinkLight::BlinkLight() :
_two(NULL),
_delay(0),
_one(NULL) {}

void BlinkLight::initLight(cocos2d::CCSpriteFrame *one, cocos2d::CCSpriteFrame *two) {
    CCNodeRGBA::init();
    setCascadeOpacityEnabled(true);
    
    _one = CCSprite::createWithSpriteFrame(one);
    _two = CCSprite::createWithSpriteFrame(two);
    setContentSize(_one->getContentSize());
    this->addChild(_one);
    LayoutUtil::layoutParentCenter(_one);
    
    this->addChild(_two);
    LayoutUtil::layoutParentCenter(_two);
    
    resetShowFrame(true,false);
}

void BlinkLight::updateLight(float dt) {
    _delay += dt;
    if (_delay >= 0.5) {
        _delay = 0;
        _one->setVisible(!_one->isVisible());
        _two->setVisible(!_two->isVisible());
    }
}

void BlinkLight::resetShowFrame(bool show1,bool show2){
    _one->setVisible(show1);
    _two->setVisible(show2);
}

