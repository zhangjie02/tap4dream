//
//  LayoutUtil.cpp
//  spacewar
//
//  Created by xiaoxiangzi on 12-10-17.
//
//

#include "LayoutUtil.h"
#include "Screen.h"
using namespace cocos2d;

cocos2d::CCPoint LayoutUtil::getAnchorPoint(AnchorPointType anchorType) {
    CCPoint anchorPoint;
    switch (anchorType) {
        case TOP_LEFT:
            anchorPoint = ccp(0, 1);
            break;
        case BOTTOM_LEFT:
            anchorPoint = ccp(0, 0);
            break;
        case TOP_RIGHT:
            anchorPoint = ccp(1, 1);
            break;
        case BOTTOM_RIGHT:
            anchorPoint = ccp(1, 0);
            break;
        case CENTER:
            anchorPoint = ccp(0.5, 0.5);
            break;
        case LEFT_CENTER:
            anchorPoint = ccp(0, 0.5);
            break;
        case RIGHT_CENTER:
            anchorPoint = ccp(1, 0.5);
            break;
        case BOTTOM_CENTER:
            anchorPoint = ccp(0.5, 0);
            break;
        case TOP_CENTER:
            anchorPoint = ccp(0.5, 1);
            break;
        default: // center
            anchorPoint = ccp(0.5, 0.5);
            break;
    }
    
    return anchorPoint;
}

CCPoint LayoutUtil::getScreenCenter() {
    CCRect rect = LayoutUtil::getScreenVisibleRect();
    return ccp(rect.origin.x + rect.size.width / 2.0f, rect.origin.y + rect.size.height / 2.0f);
}

void LayoutUtil::layoutLeft(cocos2d::CCNode* view, cocos2d::CCNode* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 1, 0.5, target, 0, 0.5, false, offsetX, offsetY);
}

void LayoutUtil::layoutRight(cocos2d::CCNode* view, cocos2d::CCNode* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0, 0.5, target, 1, 0.5, false, offsetX, offsetY);
}

void LayoutUtil::layoutTop(cocos2d::CCNode* view, cocos2d::CCNode* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0.5, 0, target, 0.5, 1, false, offsetX, offsetY);
}

void LayoutUtil::layoutBottom(cocos2d::CCNode* view, cocos2d::CCNode* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0.5, 1, target, 0.5, 0, false, offsetX, offsetY);
}

void LayoutUtil::layoutCenter(cocos2d::CCNode* view, cocos2d::CCNode* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0.5, 0.5, target, 0.5, 0.5, false, offsetX, offsetY);
}

void LayoutUtil::layoutLeftTop(cocos2d::CCNode* view, cocos2d::CCNode* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 1, 1, target, 0, 1, false, offsetX, offsetY);
}

void LayoutUtil::layoutRightTop(cocos2d::CCNode* view, cocos2d::CCNode* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0, 1, target, 1, 1, false, offsetX, offsetY);
}

void LayoutUtil::layoutLeftBottom(cocos2d::CCNode* view, cocos2d::CCNode* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 1, 0, target, 0, 0, false, offsetX, offsetY);
}

void LayoutUtil::layoutRightBottom(cocos2d::CCNode* view, cocos2d::CCNode* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0, 0, target, 1, 0, false, offsetX, offsetY);
}

void LayoutUtil::layoutParentLeft(cocos2d::CCNode* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0, 0.5, view->getParent(), 0, 0.5, true, offsetX, offsetY);
}

void LayoutUtil::layoutParentRight(cocos2d::CCNode* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 1, 0.5, view->getParent(), 1, 0.5, true, offsetX, offsetY);
}

void LayoutUtil::layoutParentTop(cocos2d::CCNode* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0.5, 1, view->getParent(), 0.5, 1, true, offsetX, offsetY);
}

void LayoutUtil::layoutParentBottom(cocos2d::CCNode* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0.5, 0, view->getParent(), 0.5, 0, true, offsetX, offsetY);
}

void LayoutUtil::layoutParentCenter(cocos2d::CCNode* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0.5, 0.5, view->getParent(), 0.5, 0.5, true, offsetX, offsetY);
}

void LayoutUtil::layoutParentLeftTop(cocos2d::CCNode* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0, 1, view->getParent(), 0, 1, true, offsetX, offsetY);
}

void LayoutUtil::layoutParentRightTop(cocos2d::CCNode* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 1, 1, view->getParent(), 1, 1, true, offsetX, offsetY);
}

void LayoutUtil::layoutParentLeftBottom(cocos2d::CCNode* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0, 0, view->getParent(), 0, 0, true, offsetX, offsetY);
}

void LayoutUtil::layoutParentRightBottom(cocos2d::CCNode* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 1, 0, view->getParent(), 1, 0, true, offsetX, offsetY);
}

void LayoutUtil::layoutScreenLeft(cocos2d::CCNode* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layoutParentLeft(view, offsetX, offsetY);
}

void LayoutUtil::layoutScreenRight(cocos2d::CCNode* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layoutParentRight(view, offsetX, offsetY);
}

void LayoutUtil::layoutScreenTop(cocos2d::CCNode* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layoutParentTop(view, offsetX, offsetY);
}

void LayoutUtil::layoutScreenBottom(cocos2d::CCNode* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layoutParentBottom(view, offsetX, offsetY);
}

void LayoutUtil::layoutScreenLeftTop(cocos2d::CCNode* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layoutParentLeftTop(view, offsetX, offsetY);
}

void LayoutUtil::layoutScreenRightTop(cocos2d::CCNode* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layoutParentRightTop(view, offsetX, offsetY);
}

void LayoutUtil::layoutScreenLeftBottom(cocos2d::CCNode* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layoutParentLeftBottom(view, offsetX, offsetY);
}

void LayoutUtil::layoutScreenRightBottom(cocos2d::CCNode* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layoutParentRightBottom(view, offsetX, offsetY);
}



void LayoutUtil::layout(cocos2d::CCNode* src, float srcAlignX, float srcAlignY, cocos2d::CCNode* target,
                        float targetAlignX, float targetAlignY, bool targetIsParent /* = false */, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    const CCPoint& srcAnchorPoint = src->getAnchorPoint();
    const CCPoint& anchorPointDiff = CCPoint(srcAlignX - srcAnchorPoint.x, srcAlignY - srcAnchorPoint.y);
    const CCPoint& targetAnchorPoint = target->getAnchorPoint();
    float targetAlignXPosition,targetAlignYPosition;
    if (targetIsParent) {
        targetAlignXPosition = target->getContentSize().width * targetAlignX;
        targetAlignYPosition = target->getContentSize().height * targetAlignY;
    } else {
        targetAlignXPosition = target->getPositionX() + target->boundingBox().size.width * (targetAlignX - targetAnchorPoint.x);
        targetAlignYPosition = target->getPositionY() + target->boundingBox().size.height * (targetAlignY - targetAnchorPoint.y);
    }
    src->setPosition(ccp(targetAlignXPosition - anchorPointDiff.x * src->boundingBox().size.width + offsetX,
                         targetAlignYPosition - anchorPointDiff.y * src->boundingBox().size.height + offsetY));
    
}

void LayoutUtil::fitScreen(cocos2d::CCNode* background) {
//    CCSize phoneSize = CCDirector::sharedDirector()->getWinSize();
//    if (phoneSize.width / phoneSize.height >= Screen::MIN_ASPECT_RATIO) {
    Screen* currentScreen = Screen::getCurrentScreen();
    background->setScaleX(currentScreen->getFitScreenScaleX());
    background->setScaleY(currentScreen->getFitScreenScaleY());
//    }
}

void LayoutUtil::fullfillScreen(cocos2d::CCNode *node) {
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    fullfillToTargetSize(node, visibleSize);
}

void LayoutUtil::fullfillToTargetSize(cocos2d::CCNode *node, const cocos2d::CCSize &targetSize, bool keepRatio) {
    const CCSize& nodeSize = node->getContentSize();
    float scaleX = targetSize.width / nodeSize.width;
    float scaleY = targetSize.height / nodeSize.height;
    if (keepRatio) {
        float scale = MIN(scaleX, scaleY);
        node->setScale(scale);
    } else {
        node->setScaleX(targetSize.width / nodeSize.width);
        node->setScaleY(targetSize.height / nodeSize.height);
    }
}

float LayoutUtil::getScreenVisibleOffsetX() {
    return (Screen::DESIGN_WIDTH - CCDirector::sharedDirector()->getVisibleSize().width) / 2.0f;
}

float LayoutUtil::getScreenVisibleOffsetY() {
    return (Screen::DESIGN_HEIGHT - CCDirector::sharedDirector()->getVisibleSize().height) / 2.0f;
}

CCRect LayoutUtil::getScreenVisibleRect() {
    CCDirector* director = CCDirector::sharedDirector();
    CCPoint visibleOrigin = director->getVisibleOrigin();
    CCSize visibleSize = director->getVisibleSize();
    
    return CCRectMake(visibleOrigin.x, visibleOrigin.y, visibleSize.width, visibleSize.height);
}

bool LayoutUtil::isWideScreen(){
	CCSize phoneSize = CCDirector::sharedDirector()->getWinSize();
	return phoneSize.width / phoneSize.height < Screen::MIN_ASPECT_RATIO;
}




