//
//  UIUtil.cpp
//  poker
//
//  Created by xiaoxiangzi on 14-2-17.
//
//

#include "SlotUIUtil.h"
#include "ShaderMgr.h"
#include "MenuItem.h"

const float SlotUIUtil::MOVED_INCH = 7.0f/160.0f;

void SlotUIUtil::setNodeShaderProgram(cocos2d::CCNode *node, string shaderType, bool recursive) {
    if (node == NULL) {
        return;
    }
    CCGLProgram* shader = ShaderMgr::getInstance()->getShaderProgram(shaderType);
    node->setShaderProgram(shader);
    
    if (recursive) {
        setNodeChildrenShaderProgram(node, shaderType, recursive);
    }
}

void SlotUIUtil::setNodeChildrenShaderProgram(cocos2d::CCNode *node, string shaderType, bool recursive) {
    if (node == NULL) {
        return;
    }
    CCArray* children = node->getChildren();
    CCObject* obj = NULL;
    CCARRAY_FOREACH(children, obj) {
        CCNode* node = dynamic_cast<CCNode*>(obj);
        setNodeShaderProgram(node, shaderType, recursive);
    }
}

void SlotUIUtil::replaceArmatureDisplay(cocos2d::extension::CCArmature *armature, const char *boneName, cocos2d::extension::CCDisplayData *displayData) {
    CCBone* bone = armature->getBone(boneName);
    int curIndex = bone->getDisplayManager()->getCurrentDisplayIndex();
    bone->addDisplay(displayData, 0);
    bone->changeDisplayByIndex(0, false);
    bone->changeDisplayByIndex(curIndex, false);
}

void SlotUIUtil::replaceChildArmatureDisplay(cocos2d::extension::CCArmature *armature, const char *boneName, const char *childBoneName, cocos2d::extension::CCDisplayData *displayData) {
    CCBone* bone = armature->getBone(boneName);
    int curIndex = bone->getDisplayManager()->getCurrentDisplayIndex();
    bone->changeDisplayByIndex(0, false);
    CCArmature* childArmature = bone->getChildArmature();
    replaceArmatureDisplay(childArmature, childBoneName, displayData);
    bone->changeDisplayByIndex(curIndex, false);
}

void SlotUIUtil::displayArmatureDisplay(cocos2d::extension::CCArmature *armature, const char *boneName, bool visible) {
    CCBone* bone = armature->getBone(boneName);
    if (visible) {
        bone->changeDisplayByIndex(0, true);
    } else {
        bone->changeDisplayByIndex(-1, true);
    }
}

float SlotUIUtil::convertDistanceFromPointToInch(float pointDis) {
    float factor = ( CCEGLView::sharedOpenGLView()->getScaleX() + CCEGLView::sharedOpenGLView()->getScaleY() ) / 2;
    return pointDis * factor / CCDevice::getDPI();
}

MenuItemSprite* SlotUIUtil::createButtonWithScale9Sprite(cocos2d::extension::CCScale9Sprite *up, cocos2d::extension::CCScale9Sprite *down, int width) {
    up->setContentSize(CCSizeMake(width, up->getContentSize().height));
    down->setContentSize(CCSizeMake(width, down->getContentSize().height));
    
    MenuItemSprite* button = MenuItemSprite::create(up, down);
    return button;
}
