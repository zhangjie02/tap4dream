//
//  MenuItem.h
//  spacewar
//
//  Created by xiaoxiangzi on 13-9-26.
//
//

#ifndef __spacewar__MenuItem__
#define __spacewar__MenuItem__

#include <iostream>
#include "cocos2d.h"
#include "UITouchDelegate.h"
using namespace cocos2d;

class MenuItem : public cocos2d::CCMenuItem, public cocos2d::CCTouchDelegate, public UITouchDelegate {
    
public:
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    MenuItem();
    bool hasTouched(cocos2d::CCTouch* touch);
    void setClickSound(const std::string& sound);
    void setClickSoundEnabled(bool enabled);
    void setTouchMovedCheckEnabled(bool enabled);
    virtual void activate();
    
protected:
    void onExit();
    void endTouch(cocos2d::CCTouch* touch);
    bool isTouchMovedCheckEnabled();
    bool isTouchMoved(CCTouch* touch);
    
    cocos2d::CCRect _touchRect;
    bool _hasTouchRectInited;
    bool _touched;
    std::string _clickSound;
    bool _clickSoundEnabled;
    bool _touchMovedCheckEnabled;
};


class MenuItemSprite : public MenuItem {
    /** the image used when the item is not selected */
    CC_PROPERTY(CCNode*, m_pNormalImage, NormalImage);
    /** the image used when the item is selected */
    CC_PROPERTY(CCNode*, m_pSelectedImage, SelectedImage);
    /** the image used when the item is disabled */
    CC_PROPERTY(CCNode*, m_pDisabledImage, DisabledImage);
public:
    MenuItemSprite();

    /** creates a menu item with a normal, selected and disabled image*/
    static MenuItemSprite * create(CCNode* normalSprite, CCNode* selectedSprite, CCNode* disabledSprite = NULL);
    /** creates a menu item with a normal and selected image with target/selector */
    static MenuItemSprite * create(CCNode* normalSprite, CCNode* selectedSprite, CCObject* target, SEL_MenuHandler selector);
    /** creates a menu item with a normal,selected  and disabled image with target/selector */
    static MenuItemSprite * create(CCNode* normalSprite, CCNode* selectedSprite, CCNode* disabledSprite, CCObject* target, SEL_MenuHandler selector);
    
    /** initializes a menu item with a normal, selected  and disabled image with target/selector */
    bool initWithNormalSprite(CCNode* normalSprite, CCNode* selectedSprite, CCNode* disabledSprite, CCObject* target, SEL_MenuHandler selector);
    
    /**
     @since v0.99.5
     */
    virtual void selected();
    virtual void unselected();
    virtual void setEnabled(bool bEnabled);
    
    virtual void setOpacityModifyRGB(bool bValue) {CC_UNUSED_PARAM(bValue);}
    virtual bool isOpacityModifyRGB(void) { return false;}
protected:
    virtual void updateImagesVisibility();
private:
    static const unsigned int    kNormalTag = 0x1;
    static const unsigned int    kSelectedTag = 0x2;
    static const unsigned int    kDisableTag = 0x3;
};

#endif /* defined(__spacewar__MenuItem__) */
