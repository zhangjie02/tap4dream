//
//  LinebaseMenuItem.h
//  poker
//
//  Created by 苏 汝杰 on 13-12-18.
//
//

#ifndef __poker__LinebaseMenuItem__
#define __poker__LinebaseMenuItem__


#include "MenuItem.h"
using namespace cocos2d;


class LinebaseMenuItem : public MenuItemSprite{
    
public:
    
    static LinebaseMenuItem * create(CCNode* unactiveSprite, CCNode* activeSprite, CCObject* target, SEL_MenuHandler selector);
    
    
    void setActive(bool active);
    
    void setEnable(CCObject* obj);
    virtual ~LinebaseMenuItem();
protected:
    
    virtual void updateImagesVisibility();
    
private:
    LinebaseMenuItem();
    
    
};

#endif /* defined(__poker__LinebaseMenuItem__) */
