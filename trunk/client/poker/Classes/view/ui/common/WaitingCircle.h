//
//  WaitingCircle.h
//  DinosaurIos
//
//  Created by shengsh on 12-10-16.
//  Copyright (c) 2012年 Droidhen. All rights reserved.
//

#ifndef DinosaurIos_WaitingCircle_h
#define DinosaurIos_WaitingCircle_h

#include "cocos2d.h"

class ResourceKey;

class WaitingCircle:public cocos2d::CCNode {
public:
    WaitingCircle();
    ~WaitingCircle();
    bool init();
    static WaitingCircle* create();
    void update();
public:
    static const int SPOT_NUMBER;
private:
    static const float SPOT_ALPHA[8];
    int counter;
    cocos2d::CCSprite* m_pSpots[8];
    void addChildItems();
    void layout();
    
    ResourceKey* _resKey;
};

#endif
