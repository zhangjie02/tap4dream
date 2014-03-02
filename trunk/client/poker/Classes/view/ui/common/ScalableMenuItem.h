//
//  ScalableMenuItem.h
//  poker
//
//  Created by xiaoxiangzi on 14-1-15.
//
//

#ifndef __poker__ScalableMenuItem__
#define __poker__ScalableMenuItem__

#include "MenuItem.h"
using namespace cocos2d;

class ScalableMenuItem : public MenuItem {
    
public:
    static ScalableMenuItem* create(CCNode* sprite);
    static ScalableMenuItem * create(CCNode* sprite, CCObject* target, SEL_MenuHandler selector);
    virtual void selected();
    virtual void unselected();
    virtual void activate();
    void setMinScale(float scale);
    void setFlipX(bool flip);
    void setScaleDuration(float duration);
    virtual void setScale(float scale);
    virtual void setEnabled(bool value);
protected:
    ScalableMenuItem();
    virtual void initScalableMenuItem(CCNode* sprite, CCObject* target, SEL_MenuHandler selector);
protected:
    static const float SCALE_DURATION;
    static const float MIN_SCALE;
    CCNode* _sprite;
    float _originScale;
    bool _hasScaled;
    float _minScale;
    float _scaleDuration;
};

#endif /* defined(__poker__ScalableMenuItem__) */
