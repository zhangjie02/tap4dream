//
//  SwitchSprite.cpp
//  poker
//
//  Created by xiaoxiangzi on 14-2-10.
//
//

#include "SwitchSprite.h"
#include "LayoutUtil.h"

SwitchSprite* SwitchSprite::create(cocos2d::CCSpriteFrame *on, cocos2d::CCSpriteFrame *off) {
    SwitchSprite* sprite = new SwitchSprite;
    sprite->initWithFrames(on, off);
    sprite->autorelease();
    return sprite;
}

SwitchSprite::SwitchSprite() : _onSprite(NULL), _offSprite(NULL), _isOn(false) {}

void SwitchSprite::initWithFrames(cocos2d::CCSpriteFrame *on, cocos2d::CCSpriteFrame *off) {
    _onSprite = CCSprite::createWithSpriteFrame(on);
    _offSprite = CCSprite::createWithSpriteFrame(off);
    
    this->addChild(_onSprite);
    this->addChild(_offSprite);
    this->setContentSize(_onSprite->getContentSize());
    LayoutUtil::layoutParentCenter(_onSprite);
    LayoutUtil::layoutParentCenter(_offSprite);
}

void SwitchSprite::setSwitchStatus(bool on) {
    _isOn = on;
    updateSwitchDisplay();
}

void SwitchSprite::updateSwitchDisplay() {
    _onSprite->setVisible(_isOn);
    _offSprite->setVisible(!_isOn);
}
