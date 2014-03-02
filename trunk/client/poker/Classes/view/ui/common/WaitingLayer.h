//
//  WaitingLayer.h
//  spacewar
//
//  Created by xiaoxiangzi on 13-1-21.
//
//

#ifndef __spacewar__WaitingLayer__
#define __spacewar__WaitingLayer__

#include <iostream>
#include "cocos2d.h"
#include "BaseUILayer.h"

class WaitingPane;

class WaitingLayer : public BaseUILayer {
    
public:
    static WaitingLayer* create(const std::string& waitingText, bool isModal = true);
    virtual bool init();
    
    WaitingLayer();
    
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
private:
    WaitingPane* _waitingPane;
    std::string _waitingText;
    bool _isModal;
};

#endif /* defined(__spacewar__WaitingLayer__) */
