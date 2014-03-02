//
//  CCNodeExt.h
//  spacewar
//
//  Created by xiaoxiangzi on 13-5-2.
//
//

#ifndef __spacewar__CCNodeExt__
#define __spacewar__CCNodeExt__

#include "cocos2d.h"
#include "UITouchDelegate.h"

class CCNodeExt : public cocos2d::CCNodeRGBA, public UITouchDelegate {
    
public:
    static CCNodeExt* create();
    CCNodeExt();
};

#endif /* defined(__spacewar__CCNodeExt__) */
