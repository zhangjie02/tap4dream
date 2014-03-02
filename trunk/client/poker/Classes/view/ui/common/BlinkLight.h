//
//  BlinkLight.h
//  poker
//
//  Created by xiaoxiangzi on 14-1-26.
//
//

#ifndef __poker__BlinkLight__
#define __poker__BlinkLight__

#include "cocos2d.h"
using namespace cocos2d;

class BlinkLight : public CCNodeRGBA {
    
public:
    static BlinkLight* create(CCSpriteFrame* one, CCSpriteFrame* two);
    void updateLight(float dt);
    BlinkLight();
    void resetShowFrame(bool show1,bool show2);
private:
    void initLight(CCSpriteFrame* one, CCSpriteFrame* two);
    void updateDisplay();
private:
    CCSprite* _one;
    CCSprite* _two;
    float _delay;
};

#endif /* defined(__poker__BlinkLight__) */
