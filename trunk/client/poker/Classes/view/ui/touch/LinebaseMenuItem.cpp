//
//  LinebaseMenuItem.cpp
//  poker
//
//  Created by 苏 汝杰 on 13-12-18.
//
//

#include "LinebaseMenuItem.h"


LinebaseMenuItem::LinebaseMenuItem()
{
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(LinebaseMenuItem::setEnable), EventDef::SLOT_UI_LOCK_SPIN, NULL);
}

LinebaseMenuItem::~LinebaseMenuItem() {
    CCNotificationCenter::sharedNotificationCenter()->removeAllObservers(this);
}

LinebaseMenuItem * LinebaseMenuItem::create(CCNode* unactiveSprite, CCNode* activeSprite, CCObject* target, SEL_MenuHandler selector)
{
    LinebaseMenuItem *pRet = new LinebaseMenuItem();
    pRet->initWithNormalSprite(unactiveSprite, activeSprite, NULL, target, selector);
    pRet->autorelease();
    return pRet;
}


void LinebaseMenuItem::setActive(bool active){
    if (m_pNormalImage) {
        m_pNormalImage->setVisible(!active);
    }
    
    if (m_pSelectedImage) {
        m_pSelectedImage->setVisible(active);
    }

}

void LinebaseMenuItem::setEnable(CCObject* obj){
    bool disable=*(bool*)obj;
    setEnabled(!disable);
}


void LinebaseMenuItem::updateImagesVisibility()
{
    if (m_pSelectedImage) m_pSelectedImage->setVisible(true);
}
