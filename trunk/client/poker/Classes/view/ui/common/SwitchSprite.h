//
//  SwitchSprite.h
//  poker
//
//  Created by xiaoxiangzi on 14-2-10.
//
//

#ifndef __poker__SwitchSprite__
#define __poker__SwitchSprite__

#include "cocos2d.h"
using namespace cocos2d;

class SwitchSprite : public CCNode {
    
public:
    static SwitchSprite* create(CCSpriteFrame* on, CCSpriteFrame* off);
    void setSwitchStatus(bool on);
    SwitchSprite();
    void initWithFrames(CCSpriteFrame* on, CCSpriteFrame* off);
private:
    void updateSwitchDisplay();
private:
    bool _isOn;
    CCSprite* _onSprite;
    CCSprite* _offSprite;
};

#endif /* defined(__poker__SwitchSprite__) */
