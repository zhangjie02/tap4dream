//
//  pokerUIUtil.h
//  poker
//
//  Created by xiaoxiangzi on 14-2-17.
//
//

#ifndef __poker__SlotUIUtil__
#define __poker__SlotUIUtil__

#include <iostream>
#include "cocos2d.h"
#include "CCArmature.h"
#include "CCScale9Sprite.h"
using namespace cocos2d;
using namespace cocos2d::extension;
using namespace std;

class MenuItemSprite;

class SlotUIUtil {
    
public:
    static void setNodeShaderProgram(CCNode* node, string shaderType, bool recursive = true);
    static void setNodeChildrenShaderProgram(CCNode* node, string shaderType, bool recursive = true);
    static void replaceArmatureDisplay(CCArmature* armature, const char* boneName, CCDisplayData* displayData);
    static void replaceChildArmatureDisplay(CCArmature* armature, const char* boneName, const char* childBoneName, CCDisplayData* displayData);
    static void displayArmatureDisplay(CCArmature* armature, const char* boneName, bool visible);
    static float convertDistanceFromPointToInch(float pointDis);
    static MenuItemSprite* createButtonWithScale9Sprite(CCScale9Sprite* up, CCScale9Sprite* down, int width);
    
    static const float MOVED_INCH;
private:
    SlotUIUtil() {}
    SlotUIUtil(const SlotUIUtil&);
    SlotUIUtil& operator=(const SlotUIUtil&);
};

#endif /* defined(__poker__SlotUIUtil__) */
