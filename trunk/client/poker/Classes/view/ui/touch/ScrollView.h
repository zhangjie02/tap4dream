//
//  ScrollView.h
//  spacewar
//
//  Created by xiaoxiangzi on 13-5-3.
//
//

#ifndef __spacewar__ScrollView__
#define __spacewar__ScrollView__

#include <iostream>
#include "cocos-ext.h"
#include "UITouchDelegate.h"

class ScrollView : public cocos2d::extension::CCScrollView, public UITouchDelegate {
    
public:
    static ScrollView* create(cocos2d::CCSize size, CCNode* container = NULL);
private:
    virtual void registerWithTouchDispatcher();
};

#endif /* defined(__spacewar__ScrollView__) */
