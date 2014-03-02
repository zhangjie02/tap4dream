//
//  WaitingLayer.cpp
//  spacewar
//
//  Created by xiaoxiangzi on 13-1-21.
//
//

#include "WaitingLayer.h"
#include "WaitingPane.h"
#include "LayoutUtil.h"
using namespace cocos2d;

WaitingLayer* WaitingLayer::create(const std::string &waitingText, bool isModal) {
    WaitingLayer* layer = new WaitingLayer();
    layer->_waitingText = waitingText;
    layer->_isModal = isModal;
    layer->init();
    layer->autorelease();
    return layer;
}

WaitingLayer::WaitingLayer() : _waitingPane(NULL), _isModal(true) {}

bool WaitingLayer::init() {
    BaseUILayer::init();
    ignoreAnchorPointForPosition(false);
    setUITouchEnabled(_isModal);
    _waitingPane = WaitingPane::create();
    _waitingPane->setWaitingText(_waitingText);
    _waitingPane->startWaiting();
    this->addChild(_waitingPane);
    LayoutUtil::layoutParentCenter(_waitingPane);
    
    return true;
}

bool WaitingLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
    if (_isModal) {
        return true;
    }
    
    return false;
}