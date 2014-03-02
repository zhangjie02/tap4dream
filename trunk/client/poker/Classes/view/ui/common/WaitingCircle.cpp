//
//  WaitingCircle.cpp
//  DinosaurIos
//
//  Created by shengsh on 12-10-16.
//  Copyright (c) 2012年 Droidhen. All rights reserved.
//

#include "WaitingCircle.h"
#include "LayoutUtil.h"
#include "ResourceKey.h"
#include "ResourceName.h"
#include "ResourceManager.h"
using namespace cocos2d;

const int WaitingCircle::SPOT_NUMBER =8;
const float WaitingCircle::SPOT_ALPHA[SPOT_NUMBER]={1,0.9f,0.8f,0.6f,0.5f,0.4f,0.3f,0.2f};

WaitingCircle::WaitingCircle() : counter(0){
    _resKey = ResourceManager::getInstance()->createResourceKey();
}

WaitingCircle::~WaitingCircle(){
    ResourceManager::getInstance()->releaseResourceKey(_resKey);
}

bool WaitingCircle::init(){

    for(int i=0; i<SPOT_NUMBER; i++){
        m_pSpots[i] = _resKey->getCCSprite(ResourceName::WAITING_POINT);
    }
    
    this->setContentSize(CCSize(32,32));
    addChildItems();
    layout();
    return true;
}

void WaitingCircle::addChildItems(){
    for(int i=0; i<SPOT_NUMBER; i++){
        addChild(m_pSpots[i]);
    }
}

void WaitingCircle::layout(){
    float offsetX[] = {0,-18,-25,-18,0,18,25,18};
    float offsetY[] = {25,18,0,-18,-25,-18,0,18};
    for(int i=0; i<SPOT_NUMBER; i++){
        LayoutUtil::layout(m_pSpots[i], 0.5, 0.5, this, 0.5, 0.5, true, offsetX[i], offsetY[i]);
    }
}

WaitingCircle* WaitingCircle::create(){
    WaitingCircle* p = new WaitingCircle();
    if(p && p->init()){
        p->autorelease();
        return p;
    }
    CC_SAFE_DELETE(p);
    return NULL;
}



void WaitingCircle::update(){
    for(int i=0; i<SPOT_NUMBER; i++){
        m_pSpots[i]->setOpacity(255*SPOT_ALPHA[(i+counter)%SPOT_NUMBER]);
    }
    
    counter++;
    counter=counter%SPOT_NUMBER;
}