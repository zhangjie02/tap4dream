//
//  WaitingPane.h
//  DinosaurIos
//
//  Created by shengsh on 12-10-16.
//  Copyright (c) 2012年 Droidhen. All rights reserved.
//

#ifndef DinosaurIos_WaitingPane_h
#define DinosaurIos_WaitingPane_h

#include "cocos2d.h"
#include "cocos-ext.h"

class WaitingCircle;
class ResourceKey;

class WaitingPane: public cocos2d::CCNode {
public:
    WaitingPane();
    virtual ~WaitingPane();
    
    bool init();
    CREATE_FUNC(WaitingPane);
    void setWaitingText(const std::string& waitingText);
    void startWaiting();
    void stopWaiting();
private:
    void update();
    void layout();
    
private:
    WaitingCircle* _waitingCircle;
    cocos2d::CCLabelTTF* _waiting;
    cocos2d::extension::CCScale9Sprite* _background;
    
    std::string _waitingText;
    
    ResourceKey* _resKey;
};

#endif
