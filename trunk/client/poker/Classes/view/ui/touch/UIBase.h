//
//  UIBase.h
//  xiyou
//
//  Created by Liu Jian on 6/27/13.
//
//

#ifndef xiyou_UIBase_h
#define xiyou_UIBase_h

#include "Node.h"
#include "EditBox.h"
#include "layer.h"
#include "Scene.h"
#include "ScrollView.h"
#include "TableView.h"
#include "TableViewCell.h"
using namespace cocos2d;
namespace UIBase {
    bool checkNodeTouch(CCNode* node, CCTouch* touch);
    CCPoint pointAdd(const CCPoint& a, const CCPoint& b);
    CCPoint pointSub(const CCPoint& a, const CCPoint& b);
    float pointDistance(const CCPoint& a, const CCPoint& b);
}

#endif
