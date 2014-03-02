//
//  SceneManager.h
//  poker
//
//  Created by xiaoxiangzi on 13-11-15.
//
//

#ifndef __poker__SceneManager__
#define __poker__SceneManager__

#include "cocos2d.h"

using namespace cocos2d;

class BaseScene;

class SceneManager : public CCObject {
    
public:
    static SceneManager* getInstance();
    
    void startGame();
    
    BaseScene* getCurScene();
    
    CCSize getPlayerInfoBarSize();
    CCSize getSpinBarSize();
private:
    SceneManager();
    SceneManager(const SceneManager&);
    SceneManager& operator=(const SceneManager&);
    
    void cleanCurScene();
    
    void cbExit(CCObject* sender);
};

#endif /* defined(__poker__SceneManager__) */
