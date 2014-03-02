//
//  ObserverUtil.cpp
//  poker
//
//  Created by xiaoxiangzi on 13-12-20.
//
//

#include "ObserverUtil.h"

void ObserverUtil::unregisterObservers(cocos2d::CCNode *node) {
    if (node) {
        CCNotificationCenter::sharedNotificationCenter()->removeAllObservers(node);
        
        CCArray* children = node->getChildren();
        if (children && children->count() > 0) {
            CCObject* obj = NULL;
            CCARRAY_FOREACH(children, obj) {
                CCNode* child = dynamic_cast<CCNode*>(obj);
                if (child) {
                    unregisterObservers(child);
                }
            }
        }
    }
}
