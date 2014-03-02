//
//  MenuItem.cpp
//  spacewar
//
//  Created by xiaoxiangzi on 13-9-26.
//
//

#include "MenuItem.h"
#include "AudioUtil.h"
#include "ResourceName.h"
#include "ShaderMgr.h"

MenuItem::MenuItem() : _hasTouchRectInited(false), _touchRect(CCRectZero), _touched(false), _clickSound(""), _clickSoundEnabled(true), _touchMovedCheckEnabled(false) {
    setUITouchEnabled(true);
    setCascadeOpacityEnabled(true);
    setClickSound(ResourceName::AUDIO_1_1);
}

bool MenuItem::hasTouched(cocos2d::CCTouch *touch) {
    CCPoint pos = this->convertTouchToNodeSpace(touch);
    
    if (!_hasTouchRectInited) {
        _touchRect = CCRectMake(0, 0, this->getContentSize().width, this->getContentSize().height);
        _hasTouchRectInited = true;
    }
    
    return _touchRect.containsPoint(pos);
}

bool MenuItem::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
    if (!isEnabled()) {
        return false;
    }
    
    if (hasTouched(pTouch)) {
        _touched = true;
        selected();
        return true;
    }
    
    return false;
}

void MenuItem::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
    if (!_touched) {
        return;
    }
    
    if (hasTouched(pTouch) && (!isTouchMoved(pTouch))) {
        selected();
    } else {
        unselected();
    }
}

void MenuItem::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
    endTouch(pTouch);
}

void MenuItem::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
    endTouch(pTouch);
}

void MenuItem::endTouch(cocos2d::CCTouch *touch) {
    if (!_touched) {
        return;
    }
    
    unselected();
    if (hasTouched(touch) && (!isTouchMoved(touch))) {
        activate();
    }
}

void MenuItem::onExit() {
    if (_touched) {
        unselected();
        _touched = false;
    }
    CCMenuItem::onExit();
}

void MenuItem::activate() {
    CCMenuItem::activate();
    if (_clickSoundEnabled && (_clickSound != "")) {
        AudioUtil::playSound(_clickSound.c_str());
    }
}

void MenuItem::setClickSoundEnabled(bool enabled) {
    _clickSoundEnabled = enabled;
}

void MenuItem::setClickSound(const std::string &sound) {
    _clickSound = sound;
}

void MenuItem::setTouchMovedCheckEnabled(bool enabled) {
    _touchMovedCheckEnabled = enabled;
}

bool MenuItem::isTouchMovedCheckEnabled() {
    return _touchMovedCheckEnabled;
}

bool MenuItem::isTouchMoved(cocos2d::CCTouch *touch) {
    if (isTouchMovedCheckEnabled()) {
        CCPoint moveDistance = ccpSub(this->convertToNodeSpace(touch->getStartLocation()), this->convertToNodeSpace(touch->getLocation()));
        float dis = sqrtf(moveDistance.x*moveDistance.x + moveDistance.y*moveDistance.y);
        //return fabs(SlotUIUtil::convertDistanceFromPointToInch(dis)) >= SlotUIUtil::MOVED_INCH;
    }
    
    return false;
}

// MenuItemSprite

MenuItemSprite::MenuItemSprite() :
m_pNormalImage(NULL),
m_pSelectedImage(NULL),
m_pDisabledImage(NULL) {}

MenuItemSprite * MenuItemSprite::create(CCNode* normalSprite, CCNode* selectedSprite, CCNode* disabledSprite)
{
    return MenuItemSprite::create(normalSprite, selectedSprite, disabledSprite, NULL, NULL);
}

MenuItemSprite * MenuItemSprite::create(CCNode* normalSprite, CCNode* selectedSprite, CCObject* target, SEL_MenuHandler selector)
{
    return MenuItemSprite::create(normalSprite, selectedSprite, NULL, target, selector);
}

MenuItemSprite * MenuItemSprite::create(CCNode *normalSprite, CCNode *selectedSprite, CCNode *disabledSprite, CCObject *target, SEL_MenuHandler selector)
{
    MenuItemSprite *pRet = new MenuItemSprite();
    pRet->initWithNormalSprite(normalSprite, selectedSprite, disabledSprite, target, selector);
    pRet->autorelease();
    return pRet;
}

bool MenuItemSprite::initWithNormalSprite(CCNode* normalSprite, CCNode* selectedSprite, CCNode* disabledSprite, CCObject* target, SEL_MenuHandler selector)
{
    MenuItem::initWithTarget(target, selector);
    setNormalImage(normalSprite);
    setSelectedImage(selectedSprite);
    setDisabledImage(disabledSprite);
    
    if(m_pNormalImage)
    {
        this->setContentSize(m_pNormalImage->getContentSize());
    }
    
    setCascadeColorEnabled(true);
    setCascadeOpacityEnabled(true);
    
    return true;
}

/**
 @since v0.99.5
 */
void MenuItemSprite::selected()
{
    MenuItem::selected();
    
    if (m_pNormalImage)
    {
        if (m_pDisabledImage)
        {
            m_pDisabledImage->setVisible(false);
        }
        
        if (m_pSelectedImage)
        {
            m_pNormalImage->setVisible(false);
            m_pSelectedImage->setVisible(true);
        }
        else
        {
            m_pNormalImage->setVisible(true);
        }
    }
}

void MenuItemSprite::unselected()
{
    MenuItem::unselected();
    if (m_pNormalImage)
    {
        m_pNormalImage->setVisible(true);
        
        if (m_pSelectedImage)
        {
            m_pSelectedImage->setVisible(false);
        }
        
        if (m_pDisabledImage)
        {
            m_pDisabledImage->setVisible(false);
        }
    }
}

void MenuItemSprite::setEnabled(bool bEnabled)
{
    if( m_bEnabled != bEnabled )
    {
        MenuItem::setEnabled(bEnabled);
        this->updateImagesVisibility();
    }
}

// Helper
void MenuItemSprite::updateImagesVisibility()
{
    if (m_bEnabled)
    {
        if (m_pNormalImage)   {
            m_pNormalImage->setVisible(true);
            //SlotUIUtil::setNodeChildrenShaderProgram(m_pNormalImage, ShaderMgr::effect_null);
        }
        if (m_pSelectedImage) m_pSelectedImage->setVisible(false);
        if (m_pDisabledImage) m_pDisabledImage->setVisible(false);
    }
    else
    {
        if (m_pDisabledImage)
        {
            if (m_pNormalImage)   m_pNormalImage->setVisible(false);
            if (m_pSelectedImage) m_pSelectedImage->setVisible(false);
            if (m_pDisabledImage) m_pDisabledImage->setVisible(true);
        }
        else
        {
            if (m_pNormalImage) {
                m_pNormalImage->setVisible(true);
                //SlotUIUtil::setNodeChildrenShaderProgram(m_pNormalImage, ShaderMgr::effect_color_gray);
            }
            if (m_pSelectedImage) m_pSelectedImage->setVisible(false);
            if (m_pDisabledImage) m_pDisabledImage->setVisible(false);
        }
    }
}

CCNode * MenuItemSprite::getNormalImage()
{
    return m_pNormalImage;
}

void MenuItemSprite::setNormalImage(CCNode* pImage)
{
    if (pImage != m_pNormalImage)
    {
        if (pImage)
        {
            addChild(pImage, 0, kNormalTag);
            pImage->setAnchorPoint(ccp(0, 0));
        }
        
        if (m_pNormalImage)
        {
            removeChild(m_pNormalImage, true);
        }
        
        m_pNormalImage = pImage;
        this->setContentSize(m_pNormalImage->getContentSize());
        this->updateImagesVisibility();
    }
}

CCNode * MenuItemSprite::getSelectedImage()
{
    return m_pSelectedImage;
}

void MenuItemSprite::setSelectedImage(CCNode* pImage)
{
    if (pImage != m_pNormalImage)
    {
        if (pImage)
        {
            addChild(pImage, 0, kSelectedTag);
            pImage->setAnchorPoint(ccp(0, 0));
        }
        
        if (m_pSelectedImage)
        {
            removeChild(m_pSelectedImage, true);
        }
        
        m_pSelectedImage = pImage;
        this->updateImagesVisibility();
    }
}

CCNode * MenuItemSprite::getDisabledImage()
{
    return m_pDisabledImage;
}

void MenuItemSprite::setDisabledImage(CCNode* pImage)
{
    if (pImage != m_pNormalImage)
    {
        if (pImage)
        {
            addChild(pImage, 0, kDisableTag);
            pImage->setAnchorPoint(ccp(0, 0));
        }
        
        if (m_pDisabledImage)
        {
            removeChild(m_pDisabledImage, true);
        }
        
        m_pDisabledImage = pImage;
        this->updateImagesVisibility();
    }
}

