//
//  UITouchEventDispatcher.cpp
//  spacewar
//
//  Created by xiaoxiangzi on 13-5-2.
//
//

#include "UITouchEventDispatcher.h"
#include "UITouchDelegate.h"
#include "UIBase.h"
using namespace cocos2d;

const int UITouchEventDispatcher::TOUCH_PRIORITY = -1000;

UITouchEventDispatcher::UITouchEventDispatcher() :
_touchableNode(),
_currentTouchId(0) {}

UITouchEventDispatcher::~UITouchEventDispatcher() {
    for (auto current : _touchableNode ) {
        CC_SAFE_RELEASE_NULL(current);
    }
    _touchableNode.clear();
}

void UITouchEventDispatcher::registerTouch() {
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, TOUCH_PRIORITY, true);
}

void UITouchEventDispatcher::unregisterTouch() {
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

bool UITouchEventDispatcher::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
    
    if (_touchableNode.size() > 0) {
        /* 只处理单点事件，多点直接无视 */
        CCLOG("deal with single-point-touch only, multi-touch is discarded");
        return true;
    }
    
    CCDirector* director = CCDirector::sharedDirector();
    CCScene* curScene = director->getRunningScene();
    CCScene* nextScene = director->getNextScene();
    if (nextScene) {
        /* 场景即将被替换，不响应touch */
        CCLOG("new scene is staging, return true");
        return true;
    }
    
    touchNode(curScene, pTouch, pEvent);
    if (_touchableNode.size() > 0) {
        _currentTouchId = pTouch->getID();
        CCLOG("touch node handler count %lu, touch id %d", _touchableNode.size(), _currentTouchId);
        return true;
    } else {
        CCLOG("no ui layer for touch event, return false");
        return false;
    }
}

void UITouchEventDispatcher::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
    if (_touchableNode.size() > 0 && (_currentTouchId == pTouch->getID())) {
        for (auto current : _touchableNode) {
            if (current->getParent() && current->isRunning()) {
                CCTouchDelegate* touchDelegate = dynamic_cast<CCTouchDelegate*>(current);
                touchDelegate->ccTouchMoved(pTouch, pEvent);
            }
        }
    }
}

void UITouchEventDispatcher::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
    if (_touchableNode.size() > 0 && (_currentTouchId == pTouch->getID())) {
        for (auto current : _touchableNode ) {
            if (current->getParent() &&  current->isRunning()) {
                CCTouchDelegate* touchDelegate = dynamic_cast<CCTouchDelegate*>(current);
                touchDelegate->ccTouchEnded(pTouch, pEvent);
            }
            CC_SAFE_RELEASE_NULL(current);
        }
        _touchableNode.clear();
    }
}

void UITouchEventDispatcher::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
    if (_touchableNode.size() > 0 && (_currentTouchId == pTouch->getID())) {
        for (auto current : _touchableNode) {
            if (current->getParent() && current->isRunning()) {
                CCTouchDelegate* touchDelegate = dynamic_cast<CCTouchDelegate*>(current);
                touchDelegate->ccTouchCancelled(pTouch, pEvent);
            }
            CC_SAFE_RELEASE_NULL(current);
        }
        _touchableNode.clear();
    }
}

void UITouchEventDispatcher::prepareCheckNode(cocos2d::CCNode *node) {
    if (node) {
        node->sortAllChildren();
    }
}

bool UITouchEventDispatcher::touchNode(cocos2d::CCNode *current, cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
    if (!current || !current->isVisible() || !current->isRunning()) {
        return false;
    }
    
    UITouchDelegate* delegate = dynamic_cast<UITouchDelegate*>(current);
    if (!delegate) {
        return false;
    }
    
    if (delegate->isPositionCheckEnabled() && !UIBase::checkNodeTouch(current, pTouch)) {
        return false;
    }
    
    CCArray* children = NULL;
    if (delegate->needTouchChildren()) {
        prepareCheckNode(current);
        CCArray* childrenOrigin = current->getChildren();
        if (childrenOrigin != NULL && childrenOrigin->count() > 0) {
            /* 拷贝，以避免在遍历过程中的处理改变绘制树导致遍历出错 */
            children = CCArray::createWithCapacity(childrenOrigin->count());
            CCObject* obj = NULL;
            CCARRAY_FOREACH(childrenOrigin, obj) {
                children->addObject(obj);
            }
        }
    }
    //liujian : print for debug
//    if (children) {
//        CCLog("liujian children of %s",typeid(*current).name());
//    for(int i=children->count()-1; i>=0;i--) {
//        CCLog("liujian %d,%s",i,typeid(*(children->objectAtIndex(i))).name());
//    }
//    }
//    string classname = typeid(*current).name();
//    if(classname.find("CardSlotHeaderLayer") != classname.npos) {
//        int i=0 ;
//        i++;
//    }
    //print for debug end
    
    bool isCurrentHandled = false;
    if (children) {
        for (int i = children->count() - 1; i >= 0; i--) {
            CCNode* child = dynamic_cast<CCNode*>(children->objectAtIndex(i));
            
            if (child && child->getZOrder() < 0) {
                /* 子节点在父节点下方 */
                /* 子节点已排序，所以第一个zorder为负的子节点即为应该处理当前节点的位置 */
                if (!isCurrentHandled) {
                    isCurrentHandled = true;
                    if (handleTouch(current, pTouch, pEvent)) {
                        return true;
                    }
                }
            }
            
            if (touchNode(child, pTouch, pEvent)) {
                return true;
            }
        }
    }
    
    if (!isCurrentHandled) {
        if (handleTouch(current, pTouch, pEvent)) {
            return true;
        }
    }
    
    return false;
}

bool UITouchEventDispatcher::handleTouch(cocos2d::CCNode *current, cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
    if (!current || !current->isVisible() || !current->isRunning()) {
        return false;
    }
    
    UITouchDelegate* delegate = dynamic_cast<UITouchDelegate*>(current);
    if (!delegate->isUITouchEnabled()) {
        return false;
    }
    
    bool swallowed = false;
    CCTouchDelegate* ccTouchDelegate = dynamic_cast<CCTouchDelegate*>(current);
    if (ccTouchDelegate) {
        if (ccTouchDelegate->ccTouchBegan(pTouch, pEvent)) {
            CC_SAFE_RETAIN(current);
            _touchableNode.push_back(current);
            swallowed = delegate->isTouchSwallowed();
        }
    }
    return swallowed;
}
