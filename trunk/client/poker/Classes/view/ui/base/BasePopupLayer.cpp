//
//  BasePopupLayer.cpp
//  poker
//
//  Created by xiaoxiangzi on 13-11-15.
//
//

#include "BasePopupLayer.h"
#include "ObserverUtil.h"
#include "LayoutUtil.h"
#include "CCLuaEngine.h"
using namespace cocos2d;

BasePopupLayer::BasePopupLayer() :
_showPopupAnim(false),
_hasClosed(false),
_hasPopup(false),
_maskBg(NULL),
_popupType(Popup_Normal),
_closePopupLayerTarget(NULL),
_closePopupLayerCallback(NULL),
_closeScriptHandler(0) {}

BasePopupLayer::~BasePopupLayer() {
    unregisterScriptCloseHandler();
}

bool BasePopupLayer::init() {
    
    if (!BaseUILayer::init()) {
        return false;
    }

    ignoreAnchorPointForPosition(false);
    setShowPopupAnim(true);
    setUITouchEnabled(true);
    setNeedTouchChildren(true);
    setMaskVisible(true);
    setCascadeOpacityEnabled(true);
    return true;
}

void BasePopupLayer::onEnter() {
	BaseUILayer::onEnter();
    openPopup();
}

void BasePopupLayer::onExit() {
    BaseUILayer::onExit();
}

bool BasePopupLayer::doKeyBackClicked() {
	closePopup();
	return true;
}

void BasePopupLayer::openPopup() {
    if (_hasPopup) {
        return;
    }
    
    if (_showPopupAnim) {
        showOpenAnim();
    } else {
        didOpenPopup();
    }
}

void BasePopupLayer::closePopup() {
    if (_hasClosed) {
        return;
    }
    // 避免关闭动画播放还能点击到面板上按钮
    setNeedTouchChildren(false);
    _hasClosed = true;
    _hasPopup = false;
    ObserverUtil::unregisterObservers(this);
    
    executeCloseCallback();
    
    removeFromParentAndCleanup(true);
}

void BasePopupLayer::executeCloseCallback() {
    if (_closePopupLayerCallback && _closePopupLayerTarget) {
        (_closePopupLayerTarget->*_closePopupLayerCallback)(this);
    }
    
    if (kScriptTypeNone != m_eScriptType && _closeScriptHandler) {
        CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler(_closeScriptHandler, 0);
    }
}

void BasePopupLayer::showOpenAnim() {
    this->setOpacity(0);
    this->runAction(CCSequence::createWithTwoActions(CCFadeIn::create(0.3f), CCCallFunc::create(this, callfunc_selector(BasePopupLayer::didOpenPopup))));
}

void BasePopupLayer::didOpenPopup() {
    _hasPopup = true;
    _hasClosed = false;
}

void BasePopupLayer::setShowPopupAnim(bool showPopupAnim) {
    _showPopupAnim = showPopupAnim;
}

bool BasePopupLayer::hasPopedUp() const {
    return _hasPopup;
}

bool BasePopupLayer::hasClosed() const {
    return _hasClosed;
}

void BasePopupLayer::setMaskVisible(bool visible) {
    _isMaskVisible = visible;
    if (_isMaskVisible && _maskBg == NULL) {
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        _maskBg = CCLayerColor::create(ccc4(0, 0, 0, 155), winSize.width, winSize.height);
        this->addChild(_maskBg, -1);
        _maskBg->ignoreAnchorPointForPosition(false);
        LayoutUtil::layoutParentCenter(_maskBg);
    }
    
    if (_maskBg) {
        _maskBg->setVisible(_isMaskVisible);
    }
}

void BasePopupLayer::setPopupType(PopupDisplayType type) {
    _popupType = type;
}

PopupDisplayType BasePopupLayer::getPopupDisplayType() {
    return _popupType;
}

void BasePopupLayer::addClosePopupLayerCallback(cocos2d::CCObject *target, SEL_MenuHandler callback) {
    _closePopupLayerTarget = target;
    _closePopupLayerCallback = callback;
}

void BasePopupLayer::registerScriptCloseHandler(int luaHandler) {
    unregisterScriptCloseHandler();
    _closeScriptHandler = luaHandler;
    LUALOG("[LUA] Add BasePopupLayer clsoe script handler: %d", _closeScriptHandler);
}

void BasePopupLayer::unregisterScriptCloseHandler() {
    if (_closeScriptHandler) {
        CCScriptEngineManager::sharedManager()->getScriptEngine()->removeScriptHandler(_closeScriptHandler);
        LUALOG("[LUA] Remove BasePopupLayer close script handler: %d", m_nScriptTapHandler);
        _closeScriptHandler = 0;
    }
}

int BasePopupLayer::getScriptCloseHandler() {
    return _closeScriptHandler;
}

void BasePopupLayer::setMaskColor(const ccColor4B &color) {
    _maskBg->setColor(ccc3(color.r, color.g, color.b));
    _maskBg->setOpacity(color.a);
}


