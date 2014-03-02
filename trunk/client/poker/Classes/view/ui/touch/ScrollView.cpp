//
//  ScrollView.cpp
//  spacewar
//
//  Created by xiaoxiangzi on 13-5-3.
//
//

#include "ScrollView.h"
#include "Node.h"

ScrollView* ScrollView::create(cocos2d::CCSize size, cocos2d::CCNode* container) {
    ScrollView* pRet = new ScrollView();
    if (container == NULL) {
        CCNodeExt* tmp = CCNodeExt::create();
        tmp->ignoreAnchorPointForPosition(false);
        tmp->setAnchorPoint(ccp(0.0f, 0.0f));
        container = tmp;
    }

    if (pRet && pRet->initWithViewSize(size, container))
    {
        pRet->autorelease();
        pRet->setUITouchEnabled(true);
        pRet->setNeedTouchChildren(true);
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

void ScrollView::registerWithTouchDispatcher() {}
