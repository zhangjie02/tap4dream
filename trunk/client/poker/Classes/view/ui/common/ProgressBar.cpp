//
//  ProgressBar.cpp
//  
//
//  Created on 12-12-7.

//
//

#include "ProgressBar.h"
#include "LayoutUtil.h"
#include "CCScale9ProgressBar.h"

ProgressBar::ProgressBar(): _ratio(0), _maxWidth(0), _bg(NULL), _fg(NULL) {}

ProgressBar::~ProgressBar(){}

ProgressBar* ProgressBar::create(cocos2d::CCSpriteFrame *bgFrame, cocos2d::CCSpriteFrame *fgFrame, float width) {
    ProgressBar* pb = new ProgressBar();
	if(pb && pb->initWithRect(bgFrame, fgFrame, width)){
		pb->autorelease();
		return pb;
	}
    
	CC_SAFE_DELETE(pb);
	return NULL;
}

void ProgressBar::setFgColor(ccColor3B color) {
    _fg->setColor(color);
}

bool ProgressBar::initWithRect(cocos2d::CCSpriteFrame *bgFrame, cocos2d::CCSpriteFrame *fgFrame, float width){
    _fg = CCScale9ProgressBar::createWithSpriteFrame(fgFrame);
    _fg->setContentSize(CCSize(width, _fg->getContentSize().height));
    
    if (bgFrame) {
        _bg = CCScale9Sprite::createWithSpriteFrame(bgFrame);
        _bg->setContentSize(CCSize(width, _bg->getContentSize().height));
        this->setContentSize(_bg->getContentSize());
    } else {
        this->setContentSize(_fg->getContentSize());
    }
    
	addChildItems();
	layout();
    setRatio(0);
	return true;
}

void ProgressBar::addChildItems(){
    if (_bg) {
        addChild(_bg);
    }
	addChild(_fg);
}

void ProgressBar::layout(){
    if (_bg) {
        LayoutUtil::layoutParentCenter(_bg);
    } 
	LayoutUtil::layoutParentCenter(_fg);
}

bool ProgressBar::setRatio(float pRatio){
//	CCAssert(pRatio >=0 && pRatio <=1, "ratio must be in [0,1]");
    if (pRatio > 1) {
        pRatio = 1;
    } else if (pRatio < 0) {
        pRatio = 0;
    }
    _ratio = pRatio;
	_fg->setVisibleRatio(pRatio);
	layout();
	return true;
}

float ProgressBar::getRatio(){
	return _ratio;
}
