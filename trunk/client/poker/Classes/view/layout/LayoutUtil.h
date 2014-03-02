//
//  LayoutUtil.h
//  spacewar
//
//  Created by xiaoxiangzi on 12-10-17.
//
//

#ifndef __spacewar__LayoutUtil__
#define __spacewar__LayoutUtil__

#include "cocos2d.h"

enum AnchorPointType {
    BOTTOM_LEFT = 0,
    BOTTOM_RIGHT,
    CENTER,
    TOP_RIGHT,
    TOP_LEFT,
    TOP_CENTER,
    LEFT_CENTER,
    RIGHT_CENTER,
    BOTTOM_CENTER
};

namespace LayoutUtil {
    
    cocos2d::CCPoint getScreenCenter();
    
    cocos2d::CCPoint getAnchorPoint(AnchorPointType anchorType);
    
    void layoutLeft(cocos2d::CCNode* view, cocos2d::CCNode* target, float offsetX = 0.0, float offsetY = 0.0);
    void layoutRight(cocos2d::CCNode* view, cocos2d::CCNode* target, float offsetX = 0.0, float offsetY = 0.0);
    void layoutTop(cocos2d::CCNode* view, cocos2d::CCNode* target, float offsetX = 0.0, float offsetY = 0.0);
    void layoutBottom(cocos2d::CCNode* view, cocos2d::CCNode* target, float offsetX = 0.0, float offsetY = 0.0);
    void layoutCenter(cocos2d::CCNode* view, cocos2d::CCNode* target, float offsetX = 0.0, float offsetY = 0.0);
    void layoutLeftTop(cocos2d::CCNode* view, cocos2d::CCNode* target, float offsetX = 0.0, float offsetY = 0.0);
    void layoutRightTop(cocos2d::CCNode* view, cocos2d::CCNode* target, float offsetX = 0.0, float offsetY = 0.0);
    void layoutLeftBottom(cocos2d::CCNode* view, cocos2d::CCNode* target, float offsetX = 0.0, float offsetY = 0.0);
    void layoutRightBottom(cocos2d::CCNode* view, cocos2d::CCNode* target, float offsetX = 0.0, float offsetY = 0.0);
    
    void layoutParentLeft(cocos2d::CCNode* view, float offsetX = 0.0, float offsetY = 0.0);
    void layoutParentRight(cocos2d::CCNode* view, float offsetX = 0.0, float offsetY = 0.0);
    void layoutParentTop(cocos2d::CCNode* view, float offsetX = 0.0, float offsetY = 0.0);
    void layoutParentBottom(cocos2d::CCNode* view, float offsetX = 0.0, float offsetY = 0.0);
    void layoutParentCenter(cocos2d::CCNode* view, float offsetX = 0.0, float offsetY = 0.0);
    void layoutParentLeftTop(cocos2d::CCNode* view, float offsetX = 0.0, float offsetY = 0.0);
    void layoutParentRightTop(cocos2d::CCNode* view, float offsetX = 0.0, float offsetY = 0.0);
    void layoutParentLeftBottom(cocos2d::CCNode* view, float offsetX = 0.0, float offsetY = 0.0);
    void layoutParentRightBottom(cocos2d::CCNode* view, float offsetX = 0.0, float offsetY = 0.0);
    
    void layoutScreenLeft(cocos2d::CCNode* view, float offsetX = 0.0, float offsetY = 0.0);
    void layoutScreenRight(cocos2d::CCNode* view, float offsetX = 0.0, float offsetY = 0.0);
    void layoutScreenTop(cocos2d::CCNode* view, float offsetX = 0.0, float offsetY = 0.0);
    void layoutScreenBottom(cocos2d::CCNode* view, float offsetX = 0.0, float offsetY = 0.0);
    void layoutScreenLeftTop(cocos2d::CCNode* view, float offsetX = 0.0, float offsetY = 0.0);
    void layoutScreenRightTop(cocos2d::CCNode* view, float offsetX = 0.0, float offsetY = 0.0);
    void layoutScreenLeftBottom(cocos2d::CCNode* view, float offsetX = 0.0, float offsetY = 0.0);
    void layoutScreenRightBottom(cocos2d::CCNode* view, float offsetX = 0.0, float offsetY = 0.0);
    
    void layout(cocos2d::CCNode* view, float viewAlignX, float viewAlignY, cocos2d::CCNode* target,
                float targetAlignX, float targetAlignY, bool targetIsParent = false, float offsetX = 0.0, float offsetY = 0.0);
    
    void fitScreen(cocos2d::CCNode* background);
    void fullfillScreen(cocos2d::CCNode* node);
    void fullfillToTargetSize(cocos2d::CCNode* node, const cocos2d::CCSize& targetSize, bool keepRatio = false);
    
    float getScreenVisibleOffsetX();
    float getScreenVisibleOffsetY();
    
    /*retrieve the world screen visible rect*/
    cocos2d::CCRect getScreenVisibleRect();
    
    bool isWideScreen();
};

#endif /* defined(__spacewar__LayoutUtil__) */
