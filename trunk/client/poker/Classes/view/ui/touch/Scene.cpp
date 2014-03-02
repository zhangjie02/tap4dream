//
//  Scene.cpp
//  spacewar
//
//  Created by xiaoxiangzi on 13-5-3.
//
//

#include "Scene.h"
USING_NS_CC;

Scene* Scene::create() {
    Scene* scene = new Scene;
    scene->init();
    scene->autorelease();
    return scene;
}

bool Scene::init() {
    if (!CCScene::init()) {
        return false;
    }
    setUITouchEnabled(false);
    setNeedTouchChildren(true);
    return true;
}

void Scene::onEnter() {
    CCScene::onEnter();
}

void Scene::onExit() {
    CCScene::onExit();
}