//
//  UIPopupManager.cpp
//  poker
//
//  Created by xiaoxiangzi on 13-11-15.
//
//

#include "UIPopupManager.h"
#include "SceneManager.h"
#include "BaseScene.h"
#include "BasePopupLayer.h"
#include "LayoutUtil.h"
#include "MsgDialogLayer.h"

UIPopupManager* UIPopupManager::getInstance() {
    static UIPopupManager manager;
    return &manager;
}

UIPopupManager::UIPopupManager() :
_displayedPopupCount(0) {}

UIPopupManager::~UIPopupManager() {
    releasePopupLayers();
}

void UIPopupManager::showPopupLayer(BasePopupLayer *uiLayer, bool needSequenceShow, PopupDisplayType type/* = Normal */) {
    uiLayer->setPopupType(type);
    updateDisplayCount();
    if (needSequenceShow && getDisplayedPopupLayerCount() > 0) {
        CC_SAFE_RETAIN(uiLayer);
        _seqPopupList.push_back(uiLayer);
    } else {
        showPopupLayerIndeed(uiLayer);
    }
}

void UIPopupManager::showPopupLayerIndeed(BasePopupLayer *uiLayer) {
    BaseScene* curScene = SceneManager::getInstance()->getCurScene();
    PopupDisplayType type = uiLayer->getPopupDisplayType();
    if (type == Popup_System) {
        BaseUILayer* messageLayer = curScene->getSystemMessageLayer();
        messageLayer->addChild(uiLayer);
    } else if (type == Popup_Bonus) {
        BaseUILayer* logicLayer = curScene->getLogicLayer();
        logicLayer->addChild(uiLayer);
    } else {
        BaseUILayer* popupLayer = curScene->getPopupLayer();
        popupLayer->addChild(uiLayer);
    }
    LayoutUtil::layoutParentCenter(uiLayer);
    CC_SAFE_RETAIN(uiLayer);
    _popupStack.push_back(uiLayer);
    updateDisplayCount();
}

void UIPopupManager::update() {
    if (_popupStack.empty()) {
        return;
    }
    
    for (vector<BasePopupLayer*>::iterator iter = _popupStack.begin(); iter != _popupStack.end();) {
        BasePopupLayer* layer = *iter;
        if (isUnusedLayer(layer)) {
            CC_SAFE_RELEASE_NULL(layer);
            iter = _popupStack.erase(iter);
        } else {
            iter++;
        }
    }
    updateDisplayCount();
    
    if ((_seqPopupList.size() > 0) && (_displayedPopupCount <= 0)) {
        BasePopupLayer* layer = _seqPopupList.front();
        _seqPopupList.pop_front();
        showPopupLayerIndeed(layer);
        CC_SAFE_RELEASE_NULL(layer);
    }
}

void UIPopupManager::updateDisplayCount() {
    unsigned int count = 0;
    for (vector<BasePopupLayer*>::iterator iter = _popupStack.begin(); iter != _popupStack.end(); iter++) {
        BasePopupLayer* layer = *iter;
        if (!isUnusedLayer(layer)) {
            count++;
        }
    }
    _displayedPopupCount = count;
}

unsigned int UIPopupManager::getDisplayedPopupLayerCount() const {
    return _displayedPopupCount;
}

bool UIPopupManager::isUnusedLayer(BasePopupLayer *layer) {
    return (layer->getParent() == NULL) && layer->hasClosed();
}

void UIPopupManager::reset() {
    releasePopupLayers();
}

void UIPopupManager::releasePopupLayers() {
    for (vector<BasePopupLayer*>::iterator iter = _popupStack.begin(); iter != _popupStack.end(); iter++) {
        BasePopupLayer* layer = *iter;
        CC_SAFE_RELEASE_NULL(layer);
    }
    _popupStack.clear();
    
    for (auto iter = _seqPopupList.begin(); iter != _seqPopupList.end(); iter++) {
        BasePopupLayer* layer = *iter;
        CC_SAFE_RELEASE_NULL(layer);
    }
    _seqPopupList.clear();
    _displayedPopupCount = 0;
}




void UIPopupManager::showMsgDialog(string msg){
    BaseScene* curScene = SceneManager::getInstance()->getCurScene();
    MsgDialogLayer* layer=MsgDialogLayer::create();
    layer->setMsg(msg);
    curScene->getMessageLayer()->addChild(layer);
    LayoutUtil::layoutParentCenter(layer);
}
