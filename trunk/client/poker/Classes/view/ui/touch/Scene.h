//
//  Scene.h
//  spacewar
//
//  Created by xiaoxiangzi on 13-5-3.
//
//

#ifndef __spacewar__Scene__
#define __spacewar__Scene__

#include <iostream>
#include "cocos2d.h"
#include "UITouchDelegate.h"
class Scene : public cocos2d::CCScene, public UITouchDelegate {
    
public:
    static Scene* create();
    
    void onEnter();
    void onExit();
    
protected:
    virtual bool init();
};

#endif /* defined(__spacewar__Scene__) */
