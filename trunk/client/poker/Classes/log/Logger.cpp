//
//  Logger.cpp
//  poker
//
//  Created by jayson on 14-1-20.
//
//

#include "Logger.h"

void Logger:: log(string tag, CCNode* node) {
    CCSize size = node->getContentSize();
    CCPoint point = node->getAnchorPoint();
    bool ignoreAnchorPoint = node->isIgnoreAnchorPointForPosition();
    CCPoint pos = node->getPosition();
    CCPoint globalPPos = node->convertToWorldSpace(pos);
    CCLOG("[%s]x:%f,y:%f,gx:%f,gy:%f,w:%f,h:%f,scaleX:%f,scaleY:%f,anchor:(%f,%f),ig:%d",tag.data(), pos.x,pos.y,globalPPos.x,globalPPos.y,size.width,size.height,node->getScaleX(), node->getScaleY(), point.x,point.y,ignoreAnchorPoint);
}