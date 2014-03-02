//
//  ProgressBar.h
//
//
//  Created on 12-12-7.
//
//

#ifndef __Spacewar__ProgressBar__
#define __Spacewar__ProgressBar__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
class CCScale9ProgressBar;
USING_NS_CC;
USING_NS_CC_EXT;

class ProgressBar : public CCNode{
public:
    ProgressBar();
    virtual ~ProgressBar();
    static ProgressBar* create(CCSpriteFrame* bgFrame, CCSpriteFrame* fgFrame, float width);
    float getRatio();
	bool setRatio(float pRatio);
    void setFgColor(ccColor3B color);
protected:
    bool initWithRect(CCSpriteFrame* bgFrame, CCSpriteFrame* fgFrame, float width);
private:
    void addChildItems();
    void layout();
	
    
private:
    extension::CCScale9Sprite* _bg;
    CCScale9ProgressBar* _fg;
	float _maxWidth;
	float _ratio;
    float _threshold;
};

#endif /* defined(__Spacewar__ProgressBar__) */
