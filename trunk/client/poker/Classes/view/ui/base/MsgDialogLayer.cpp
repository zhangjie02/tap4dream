//
//  MsgDialogLayer.cpp
//  poker
//
//  Created by 苏 汝杰 on 14-2-20.
//
//

#include "MsgDialogLayer.h"
#include "ResourceKey.h"
#include "ResourceName.h"
#include "LayoutUtil.h"

MsgDialogLayer::MsgDialogLayer()
{
    
}

MsgDialogLayer::~MsgDialogLayer(){}


bool MsgDialogLayer::init(){
    BaseUILayer::init();
    CCDelayTime* delay=CCDelayTime::create(2);
    CCCallFunc* fun=CCCallFunc::create(this, callfunc_selector(MsgDialogLayer::closeDialog));
    CCSequence* action=CCSequence::create(delay,fun,NULL);
    this->runAction(action);
    return true;
}

void MsgDialogLayer::setMsg(string msg){
    CCLabelBMFont* labelMsg=_resKey->getCCLabelBMFont(ResourceName::ARIAL_ROUNDED_MT_BOLD_40, msg.c_str(), kCCTextAlignmentCenter);
    this->addChild(labelMsg);
    LayoutUtil::layoutParentCenter(labelMsg);
}

void MsgDialogLayer::closeDialog(){
    this->removeFromParentAndCleanup(true);
}



