//
//  WaitingPane.cpp
//  DinosaurIos
//
//  Created by shengsh on 12-10-16.
//  Copyright (c) 2012年 Droidhen. All rights reserved.
//

#include "WaitingPane.h"
#include "WaitingCircle.h"
#include "LayoutUtil.h"
#include "ResourceName.h"
#include "FontConstants.h"
#include "SlotResourceManager.h"
#include "ResourceKey.h"
#include "ResourceManager.h"
using namespace cocos2d;

WaitingPane::WaitingPane() : _waitingText(), _waiting(NULL), _background(NULL), _waitingCircle(NULL) {
    _resKey = ResourceManager::getInstance()->createResourceKey();
}

WaitingPane::~WaitingPane() {
    ResourceManager::getInstance()->releaseResourceKey(_resKey);
    _resKey = NULL;
}

bool WaitingPane::init() {
    _background = _resKey->getCCScale9Sprite(ResourceName::WAITING_BG);
    _background->setOpacity(255 * 0.7f);
    addChild(_background);
    
    _waitingCircle = WaitingCircle::create();
    addChild(_waitingCircle, 1);
    
    const CCSize& size = _waitingCircle->getContentSize();
    this->setContentSize(size);
    
    _background->setContentSize(CCSizeMake(75, 75));
    
    layout();
    return true;
}

void WaitingPane::layout() {
    if (_waiting == NULL) {
        LayoutUtil::layoutParentCenter(_waitingCircle);
        LayoutUtil::layoutParentCenter(_background);
    } else {
        LayoutUtil::layout(_background, 0.5f, 0.5f, this, 0.5f, 0.5f, true);
        LayoutUtil::layout(_waitingCircle, 0.5f, 0.5f, _background, 0.2f, 0.5f);
        _waiting->setAnchorPoint(ccp(0,0.5));
        LayoutUtil::layout(_waiting, 0, 0.5f, _background, 0.4f, 0.5f);
    }
}

void WaitingPane::startWaiting() {
    CCDelayTime* delay = CCDelayTime::create(0.1f);
    CCSequence* seq = CCSequence::createWithTwoActions(delay, CCCallFunc::create(this, callfunc_selector(WaitingPane::update)));
    this->runAction(CCRepeatForever::create(seq));
}

void WaitingPane::stopWaiting() {
    this->stopAllActions();
}

void WaitingPane::update() {
    _waitingCircle->update();
}

void WaitingPane::setWaitingText(const std::string &waitingText) {
    if (waitingText == "") {
        return;
    }
    _waitingText.clear();
    _waitingText.append(waitingText);
    if (_waiting == NULL) {
        _background->setContentSize(CCSizeMake(320, 130));
        
        _waiting = CCLabelTTF::create(waitingText.c_str(),  FontConstants::ARIAL_ROUNDED_MT_TTF, 32);
        _waiting->setColor(ccWHITE);
        addChild(_waiting);
    } else {
        _waiting->setString(_waitingText.c_str());
    }
    
    layout();
}