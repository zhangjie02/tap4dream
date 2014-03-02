//
//  ScrollBar.cpp
//  MagicEra
//
//  Created by shengsh on 12-12-11.
//
//

#include "ScrollBar.h"
#include "LayoutUtil.h"
#include <math.h>
#include <cmath>

ScrollBar::ScrollBar():_maxLength(0),_scrollLength(0),_needShowScrollBar(false){
    
}

ScrollBar::~ScrollBar(){
    
}

ScrollBar* ScrollBar::create(CCSpriteFrame* bg, CCSpriteFrame* fg, float maxLength) {
    ScrollBar* sb = new ScrollBar();
    if(sb && sb->init(bg, fg, maxLength)){
        return sb;
    }
    CC_SAFE_DELETE(sb);
    return NULL;
}

bool ScrollBar::init(CCSpriteFrame* bg, CCSpriteFrame* fg, float maxLength) {
    _bg = CCScale9Sprite::createWithSpriteFrame(bg, CCRectZero);
    _fg = CCScale9Sprite::createWithSpriteFrame(fg, CCRectZero);
    addChildItems();
    setMaxLength(maxLength);
    
    return true;
}

void ScrollBar::setMaxLength(float maxLength) {
    _maxLength = maxLength;
    
    _bg->setContentSize(CCSize(maxLength, _bg->getContentSize().height));
    
    this->setContentSize(_bg->getContentSize());

    layout();
}

void ScrollBar::addChildItems(){
    addChild(_bg);
    addChild(_fg);
}

void ScrollBar::layout(){
    LayoutUtil::layoutParentCenter(_bg);
}

void ScrollBar::setScrollableLength(float scrollableLength){
    _scrollLength = scrollableLength;
    float ratio = _maxLength/scrollableLength;
    if(_scrollLength<_maxLength){
        ratio = _scrollLength/_maxLength;
        setNeedShowScrollBar(false);
    }else{
        setNeedShowScrollBar(true);
    }
    _fg->setContentSize(CCSize(_maxLength*ratio, _fg->getContentSize().height));
    LayoutUtil::layoutParentLeft(_fg);
}

void ScrollBar::setOffset(float offset){
    float ratio;
    if(offset == 0){
        ratio = 0;
    }else if(_scrollLength<_maxLength){
        ratio = _scrollLength/_maxLength;
    }else{
        ratio = _maxLength/_scrollLength;
    }
    if (abs(offset) + _maxLength > _scrollLength) {
        _fg->setAnchorPoint(ccp(1, 0.5));
        LayoutUtil::layout(_fg,1,0.5,_bg,1,0.5,false);
        _fg->setContentSize(CCSize(_maxLength*_maxLength/(abs(offset)+_maxLength), _fg->getContentSize().height));
    }else if (offset > 0) {
        _fg->setAnchorPoint(ccp(0, 0.5));
        LayoutUtil::layout(_fg,0,0.5,_bg,0,0.5,false);
        _fg->setContentSize(CCSize(_maxLength*_maxLength/(_scrollLength+_maxLength + offset), _fg->getContentSize().height));
    }else{
        LayoutUtil::layout(_fg,0,0.5,_bg,0,0.5,false, -offset*ratio,0);
    }
}

void ScrollBar::setNeedShowScrollBar(bool needShowScrollBar) {
    _needShowScrollBar = needShowScrollBar;
    _bg->setVisible(needShowScrollBar);
    _fg->setVisible(needShowScrollBar);
}

bool ScrollBar::needShowScrollBar() {
    return _needShowScrollBar;
}
