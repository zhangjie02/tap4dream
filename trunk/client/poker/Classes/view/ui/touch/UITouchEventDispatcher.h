//
//  UITouchEventDispatcher.h
//  spacewar
//
//  Created by xiaoxiangzi on 13-5-2.
//
//

#ifndef __spacewar__UITouchEventDispatcher__
#define __spacewar__UITouchEventDispatcher__

#include <list>
using namespace std;

#include "cocos2d.h"
USING_NS_CC;

class UITouchEventDispatcher :public CCObject, public CCTouchDelegate {
    
public:
    static UITouchEventDispatcher* getInstance() {
        static UITouchEventDispatcher dispatcher;
        return &dispatcher;
    }
    
    void registerTouch();
    void unregisterTouch();

    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
public:
    static const int TOUCH_PRIORITY;
private:
    UITouchEventDispatcher();
    UITouchEventDispatcher(const UITouchEventDispatcher&);
    UITouchEventDispatcher& operator=(const UITouchEventDispatcher&);
    ~UITouchEventDispatcher();
    
    void prepareCheckNode(cocos2d::CCNode* node);
    bool touchNode(cocos2d::CCNode* current, cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    bool handleTouch(cocos2d::CCNode* current, cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    
private:
    list<CCNode*> _touchableNode;
    int _currentTouchId;
};

#endif /* defined(__spacewar__UITouchEventDispatcher__) */
