//
//  SceneManager.cpp
//  poker
//
//  Created by xiaoxiangzi on 13-11-15.
//
//

#include "SceneManager.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "URLHelperJNI.h"
#endif
#include "BaseScene.h"
#include "ObserverUtil.h"
#include "ResourceManager.h"
#include "AudioUtil.h"
#include "UIPopupManager.h"

SceneManager::SceneManager() {
    
}

SceneManager* SceneManager::getInstance() {
    static SceneManager manager;
    return &manager;
}

BaseScene* SceneManager::getCurScene() {
    BaseScene* scene = dynamic_cast<BaseScene*>(CCDirector::sharedDirector()->getRunningScene());
    return scene;
}

void SceneManager::cleanCurScene() {
    CCScene* scene = getCurScene();
    if (scene) {
        scene->cleanup();
        ObserverUtil::unregisterObservers(scene);
    }
    UIPopupManager::getInstance()->reset();
    ResourceManager::getInstance()->cancelAllAsyncLoadTasks();
    CCArmatureDataManager::sharedArmatureDataManager()->removeAll();
    AudioUtil::stopAll();
}

void SceneManager::cbExit(cocos2d::CCObject *sender) {
    CCDirector::sharedDirector()->end();
}
