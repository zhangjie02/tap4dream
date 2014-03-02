//
//  UIBase.cpp
//  xiyou
//
//  Created by zhouyan on 13-7-25.
//
//

#include "UIBase.h"

#include <cmath>
using std::sqrt;
using std::pow;

bool UIBase::checkNodeTouch(CCNode* node, CCTouch* touch) {
    if (node != NULL) {
        CCRect rect = node->boundingBox();
        CCSize contentSize = node->getContentSize();
        float deltaX = (rect.size.width - contentSize.width * node->getScaleX()) / 2;
        float deltaY = (rect.size.height - contentSize.height * node->getScaleY()) / 2;
        rect.origin.x += deltaX;
        rect.origin.y += deltaY;
        rect.size.width -= deltaX;
        rect.size.height -= deltaY;
        CCPoint location = touch->getLocation();
        if (node->getParent() != NULL) {
            location = node->getParent()->convertTouchToNodeSpace(touch);
        }
        return rect.containsPoint(location);
    }
    return false;
}

CCPoint UIBase::pointAdd(const CCPoint& a, const CCPoint& b) {
    return ccp(a.x + b.x, a.y + b.y);
}

CCPoint UIBase::pointSub(const CCPoint& a, const CCPoint& b) {
    return ccp(a.x - b.x, a.y - b.y);
}

float UIBase::pointDistance(const CCPoint& a, const CCPoint& b) {
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}
