//
//  BaseScene.cpp
//  poker
//
//  Created by xiaoxiangzi on 13-11-15.
//
//

#include "BaseScene.h"
#include "BaseUILayer.h"
#include "WaitingLayer.h"
#include "LayoutUtil.h"
#include "ResourceKey.h"
#include "ResourceManager.h"
using namespace cocos2d;

BaseScene::BaseScene() :
_logicLayer(NULL),
_mainUILayer(NULL),
_messageLayer(NULL),
_systemMessageLayer(NULL),
_waitingLayer(NULL),
_waitingCount(0),
_popupLayer(NULL) {
    _resKey = ResourceManager::getInstance()->createResourceKey();
}

BaseScene::~BaseScene() {
    ResourceManager::getInstance()->releaseResourceKey(_resKey);
    _resKey = NULL;
}

bool BaseScene::init() {
    Scene::init();
    // 场景逻辑层容器
    _logicLayer = BaseUILayer::create();
    this->addChild(_logicLayer);
    LayoutUtil::layoutParentCenter(_logicLayer);
    
    // 场景主UI容器
    _mainUILayer = BaseUILayer::create();
    this->addChild(_mainUILayer, 100);
    LayoutUtil::layoutParentCenter(_mainUILayer);
    
    _popupLayer = BaseUILayer::create();
    this->addChild(_popupLayer, 200);
    LayoutUtil::layoutParentCenter(_popupLayer);
    
    _waitingLayer = WaitingLayer::create("");
    this->addChild(_waitingLayer, 300);
    LayoutUtil::layoutParentCenter(_waitingLayer);
    _waitingLayer->setVisible(false);
    
    // 场景消息层容器
    _messageLayer = BaseUILayer::create();
    this->addChild(_messageLayer, 400);
    LayoutUtil::layoutParentCenter(_messageLayer);
    
    // 系统消息层容器
    _systemMessageLayer = BaseUILayer::create();
    this->addChild(_systemMessageLayer, 500);
    LayoutUtil::layoutParentCenter(_systemMessageLayer);
    
    return true;
}

BaseUILayer* BaseScene::getMainUILayer() {
    return _mainUILayer;
}

BaseUILayer* BaseScene::getMessageLayer() {
    return _messageLayer;
}

BaseUILayer* BaseScene::getSystemMessageLayer() {
    return _systemMessageLayer;
}

BaseUILayer* BaseScene::getLogicLayer() {
    return _logicLayer;
}

void BaseScene::showWaitingLayer() {
    _waitingLayer->setVisible(true);
    _waitingCount++;
}

BaseUILayer* BaseScene::getPopupLayer() {
    return _popupLayer;
}

void BaseScene::hideWaitingLayer() {
    _waitingCount--;
    if (_waitingCount <= 0) {
        _waitingCount = 0;
        _waitingLayer->setVisible(false);
    }
}
