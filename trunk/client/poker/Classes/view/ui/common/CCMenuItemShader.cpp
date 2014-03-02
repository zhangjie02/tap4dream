//
//  CCMenuItemShader.cpp
//  spacewar
//
//  Created by xiaoxiangzi on 13-1-28.
//
//

#include "CCMenuItemShader.h"
#include "ShaderEffectSprite.h"
#include "ShaderMgr.h"
#include "LayoutUtil.h"
using namespace cocos2d;
using namespace extension;

CCMenuItemShader* CCMenuItemShader::createScale9MenuItem(CCSpriteFrame* frame, float width) {
    CCMenuItemShader* item = new CCMenuItemShader;
    item->initScale9MenuItem(frame, ShaderMgr::effect_null, ShaderMgr::effect_color_button_click, ShaderMgr::effect_color_gray, NULL, NULL, width, 0);
    item->autorelease();
    return item;
}

CCMenuItemShader* CCMenuItemShader::createScale9MenuItem(CCSpriteFrame* frame, float width, float height) {
    CCMenuItemShader* item = new CCMenuItemShader;
    item->initScale9MenuItem(frame, ShaderMgr::effect_null, ShaderMgr::effect_color_button_click, ShaderMgr::effect_color_gray, NULL, NULL, width, height);
    item->autorelease();
    return item;
}


CCMenuItemShader* CCMenuItemShader::createScale9MenuItem(CCSpriteFrame* frame, float width, cocos2d::CCObject *target, cocos2d::SEL_MenuHandler selector) {
    CCMenuItemShader* item = new CCMenuItemShader;
    item->initScale9MenuItem(frame, ShaderMgr::effect_null, ShaderMgr::effect_color_button_click, ShaderMgr::effect_color_gray, target, selector, width, 0);
    item->autorelease();
    return item;
}

CCMenuItemShader* CCMenuItemShader::createScale9MenuItem(CCSpriteFrame* frame, float width, float height, cocos2d::CCObject *target, cocos2d::SEL_MenuHandler selector) {
    CCMenuItemShader* item = new CCMenuItemShader;
    item->initScale9MenuItem(frame, ShaderMgr::effect_null, ShaderMgr::effect_color_button_click, ShaderMgr::effect_color_gray, target, selector, width, height);
    item->autorelease();
    return item;
}


CCMenuItemShader* CCMenuItemShader::create(CCSpriteFrame* frame) {
    CCMenuItemShader* item = new CCMenuItemShader;
    item->initCCMenuItemShader(frame, ShaderMgr::effect_null, ShaderMgr::effect_color_button_click, ShaderMgr::effect_color_gray, NULL, NULL);
    item->autorelease();
    return item;
}

CCMenuItemShader* CCMenuItemShader::create(CCSpriteFrame* frame, cocos2d::CCObject *target, cocos2d::SEL_MenuHandler selector) {
    CCMenuItemShader* item = new CCMenuItemShader;
    item->initCCMenuItemShader(frame, ShaderMgr::effect_null, ShaderMgr::effect_color_button_click, ShaderMgr::effect_color_gray, target, selector);
    item->autorelease();
    return item;
}

CCMenuItemShader* CCMenuItemShader::create(CCSpriteFrame* frame,
                                           const std::string &normalShader,
                                           const std::string &selectShader,
                                           const std::string &disableShader,
                                           cocos2d::CCObject *target, cocos2d::SEL_MenuHandler selector) {
    CCMenuItemShader* item = new CCMenuItemShader;
    item->initCCMenuItemShader(frame, normalShader, selectShader, disableShader, target, selector);
    item->autorelease();
    return item;
}

void CCMenuItemShader::initBasicProps(CCSpriteFrame* frame, const std::string &normalShader, const std::string &selectShader, const std::string &disableShader, cocos2d::CCObject *target, cocos2d::SEL_MenuHandler selector) {
    CCMenuItem::initWithTarget(target, selector);
    
    _normalShader = normalShader;
    _selectShader = selectShader;
    _disableShader = disableShader;
}

void CCMenuItemShader::initScale9MenuItem(CCSpriteFrame* frame,
                                          const std::string &normalShader,
                                          const std::string &selectShader,
                                          const std::string &disableShader,
                                          cocos2d::CCObject *target,
                                          cocos2d::SEL_MenuHandler selector,
                                          float width, float height) {
    initBasicProps(frame, normalShader, selectShader, disableShader, target, selector);
    _scale9Sprite = CCScale9SpriteExt::create(frame);
    if (height == 0) {
        height = _scale9Sprite->getContentSize().height;
    }
    _scale9Sprite->setContentSize(CCSizeMake(width, height));
    _scale9Sprite->setShader(_normalShader);
    _scale9Sprite->setAnchorPoint(LayoutUtil::getAnchorPoint(BOTTOM_LEFT));
    this->setContentSize(_scale9Sprite->getContentSize());
    this->addChild(_scale9Sprite);
}

CCMenuItemShader::CCMenuItemShader() : _itemShaderSprite(NULL), _scale9Sprite(NULL), _normalShader(""), _selectShader(""), _disableShader(""), _touchWidth(0), _touchHeight(0), _hasSetTouchArea(false) {
    m_bEnabled = true;
    m_bSelected = false;
}

CCMenuItemShader::~CCMenuItemShader() {
}

void CCMenuItemShader::initCCMenuItemShader(CCSpriteFrame* frame,
                                            const std::string &normalShader,
                                            const std::string &selectShader,
                                            const std::string &disableShader,
                                            cocos2d::CCObject *target, cocos2d::SEL_MenuHandler selector) {
    initBasicProps(frame, normalShader, selectShader, disableShader, target, selector);
    
    _itemShaderSprite = ShaderEffectSprite::create(frame, _normalShader);
    _itemShaderSprite->setAnchorPoint(LayoutUtil::getAnchorPoint(BOTTOM_LEFT));
    
    this->setContentSize(_itemShaderSprite->getContentSize());
    this->addChild(_itemShaderSprite);
}

void CCMenuItemShader::selected() {
    MenuItem::selected();
    changeShader(_selectShader);
}

void CCMenuItemShader::unselected() {
    MenuItem::unselected();
    if (isEnabled()) {
        changeShader(_normalShader);
    } else {
        changeShader(_disableShader);
    }
}

void CCMenuItemShader::activate() {
    MenuItem::activate();
}

void CCMenuItemShader::setEnabled(bool bEnabled) {
    if( m_bEnabled != bEnabled )
    {
        MenuItem::setEnabled(bEnabled);
        if (bEnabled) {
            changeShader(_normalShader);
        } else {
            changeShader(_disableShader);
        }
    }
}

void CCMenuItemShader::changeClickSize(const cocos2d::CCSize &clickSize) {
    this->setContentSize(clickSize);
    LayoutUtil::layoutParentCenter(_itemShaderSprite);
}

bool CCMenuItemShader::hasClicked(const cocos2d::CCPoint &worldPosition) {
    CCPoint localPos = this->convertToNodeSpace(worldPosition);
    CCSize buttonSize = this->getContentSize();
    CCRect buttonRect = CCRectMake(0, 0, buttonSize.width, buttonSize.height);
    bool hasClicked = false;
    if (buttonRect.containsPoint(localPos) && isEnabled()) {
        hasClicked = true;
    }
    
    return hasClicked;
}

CCNode* CCMenuItemShader::getShaderSprite() {
    if (_itemShaderSprite) {
        return _itemShaderSprite;
    } else {
        return _scale9Sprite;
    }
}

void CCMenuItemShader::changeDisplayImg(cocos2d::CCSpriteFrame *frame) {
    if (_itemShaderSprite) {
        _itemShaderSprite->setDisplayFrame(frame);
    } else {
        CCSize size = _scale9Sprite->getContentSize();
        float width = size.width;
        float height = size.height;
        string curShader = _scale9Sprite->getShaderType();
        _scale9Sprite->removeFromParentAndCleanup(true);
        initScale9MenuItem(frame, _normalShader, _selectShader, _disableShader, m_pListener, m_pfnSelector, width, height);
        
        _scale9Sprite->setShader(curShader);
    }
}

void CCMenuItemShader::changeDisableShader(const std::string &disableShader) {
    _disableShader.clear();
    _disableShader.append(disableShader);
    if (!m_bEnabled) {
        changeShader(_disableShader);
    }
}

void CCMenuItemShader::changeSelectShader(const std::string &selectShader) {
    _selectShader.clear();
    _selectShader.append(selectShader);
    if (m_bSelected) {
        changeShader(_selectShader);
    }
}

void CCMenuItemShader::changeNormalShader(const std::string &normalShader) {
    _normalShader.clear();
    _normalShader.append(normalShader);
    if (m_bEnabled && (!m_bSelected)) {
        changeShader(_normalShader);
    }
}

void CCMenuItemShader::changeShader(const std::string &shaderType) {
    if (_itemShaderSprite) {
        _itemShaderSprite->changeShader(shaderType);
    } else if (_scale9Sprite) {
        _scale9Sprite->setShader(shaderType);
    }
}

const std::string& CCMenuItemShader::getCurrentShader() const {
    if (_itemShaderSprite) {
        return _itemShaderSprite->getShaderType();
    } else {
        return _scale9Sprite->getShaderType();
    }
}

CCRect CCMenuItemShader::rect() {
    if (_hasSetTouchArea) {
        CCRect itemRect = this->boundingBox();
        return CCRectMake(itemRect.origin.x + itemRect.size.width / 2.0f - _touchWidth  / 2.0f,
                          itemRect.origin.y + itemRect.size.height / 2.0f - _touchHeight / 2.0f,
                          _touchWidth, _touchHeight);
    } else {
        return this->boundingBox();
    }
}

void CCMenuItemShader::setTouchArea(float width, float height) {
    _hasSetTouchArea = true;
    _touchWidth = width;
    _touchHeight = height;
}

// Class CCScale9SpriteExt
CCScale9SpriteExt::CCScale9SpriteExt() :
_curShaderType("") {}

CCScale9SpriteExt::~CCScale9SpriteExt() {}

CCScale9SpriteExt* CCScale9SpriteExt::create(cocos2d::CCSpriteFrame *frame) {
    CCScale9SpriteExt* sprite = new CCScale9SpriteExt();
    sprite->initCCScale9SpriteExt(frame);
    sprite->autorelease();
    return sprite;
}

void CCScale9SpriteExt::initCCScale9SpriteExt(cocos2d::CCSpriteFrame *frame) {
    //    const CCRect& frameRect = frame->getRect();
    //    CCRect capInsets = CCRectZero;
    //    CCRect capInsetsReal = CCRectMake(capInsets.origin.x + frameRect.origin.x,
    //                                      capInsets.origin.y + frameRect.origin.y,
    //                                      capInsets.size.width, capInsets.size.height);
    initWithSpriteFrame(frame, CCRectZero);
}

void CCScale9SpriteExt::setShader(const std::string &shaderType) {
    if (_curShaderType != shaderType) {
        _curShaderType.clear();
        _curShaderType.append(shaderType);
    }
    
    CCGLProgram* shader = ShaderMgr::getInstance()->getShaderProgram(_curShaderType);
    _scale9Image->setShaderProgram(shader);
    CCArray* children = _scale9Image->getChildren();
    for (int i = 0; i < children->count(); i++) {
        CCNode* child = dynamic_cast<CCNode*>(children->objectAtIndex(i));
        child->setShaderProgram(shader);
    }
}

const std::string& CCScale9SpriteExt::getShaderType() {
    return _curShaderType;
}


