//
//  ScalableMenuItem.cpp
//  poker
//
//  Created by xiaoxiangzi on 14-1-15.
//
//

#include "ScalableMenuItem.h"
#include "LayoutUtil.h"
#include "MathUtil.h"
#include "ShaderMgr.h"
#include "SlotUIUtil.h"

const float ScalableMenuItem::SCALE_DURATION = 0.2;
const float ScalableMenuItem::MIN_SCALE = 0.9;

ScalableMenuItem::ScalableMenuItem() :
_sprite(NULL),
_hasScaled(false),
_minScale(0),
_scaleDuration(SCALE_DURATION) {}

ScalableMenuItem* ScalableMenuItem::create(cocos2d::CCNode *sprite) {
    ScalableMenuItem* item = new ScalableMenuItem;
    item->initScalableMenuItem(sprite, NULL, NULL);
    item->autorelease();
    return item;
}

ScalableMenuItem* ScalableMenuItem::create(cocos2d::CCNode *sprite, cocos2d::CCObject *target, SEL_MenuHandler selector) {
    ScalableMenuItem* item = new ScalableMenuItem;
    item->initScalableMenuItem(sprite, target, selector);
    item->autorelease();
    return item;
}

void ScalableMenuItem::initScalableMenuItem(cocos2d::CCNode *sprite, cocos2d::CCObject *target, SEL_MenuHandler selector) {
    MenuItem::initWithTarget(target, selector);
    _sprite = sprite;
    _sprite->setAnchorPoint(LayoutUtil::getAnchorPoint(CENTER));
    _originScale = this ->getScale();
    setMinScale(MIN_SCALE);
    this->addChild(_sprite);
    this->setContentSize(_sprite->boundingBox().size);
    this->setAnchorPoint(LayoutUtil::getAnchorPoint(CENTER));
    LayoutUtil::layoutParentCenter(_sprite);
}

void ScalableMenuItem::selected() {
    MenuItem::selected();
    this->stopAllActions();
    float time = _scaleDuration *  MathUtil::absf((this->getScale() - _minScale) / (_originScale - _minScale));
    this->runAction(CCEaseBounceInOut::create(CCScaleTo::create(time, _minScale)));
    SlotUIUtil::setNodeShaderProgram(this, ShaderMgr::effect_color_button_click);
}

void ScalableMenuItem::unselected() {
    MenuItem::unselected();
    this->stopAllActions();
    float time = _scaleDuration *  MathUtil::absf((_originScale - this->getScale()) / (_originScale - _minScale));
    this->runAction(CCEaseBackInOut::create(CCScaleTo::create(time, _originScale)));
    SlotUIUtil::setNodeShaderProgram(this, ShaderMgr::effect_null);
}

void ScalableMenuItem::setMinScale(float scale) {
    _minScale = scale * _originScale;
}

void ScalableMenuItem::setFlipX(bool flip) {
    CCSprite* sprite = dynamic_cast<CCSprite*>(_sprite);
    if (sprite) {
        sprite->setFlipX(flip);
        LayoutUtil::layoutParentCenter(sprite);
    }
}

void ScalableMenuItem::activate() {
    MenuItem::activate();
}

void ScalableMenuItem::setScaleDuration(float duration) {
    _scaleDuration = duration;
}

void ScalableMenuItem::setScale(float scale) {
    MenuItem::setScale(scale);
    _originScale = scale;
}

void ScalableMenuItem::setEnabled(bool value) {
    MenuItem::setEnabled(value);
    if (isEnabled()) {
        SlotUIUtil::setNodeShaderProgram(this, ShaderMgr::effect_null);
    } else {
        SlotUIUtil::setNodeShaderProgram(this, ShaderMgr::effect_color_gray);
    }
}