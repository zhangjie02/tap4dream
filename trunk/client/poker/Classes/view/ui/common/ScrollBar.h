//
//  ScrollBar.h
//  MagicEra
//
//  Created by shengsh on 12-12-11.
//
//

#ifndef __MagicEra__ScrollBar__
#define __MagicEra__ScrollBar__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
using namespace cocos2d;
using namespace extension;

class ScrollBar : public cocos2d::CCNode {
public:
    ScrollBar();
    ~ScrollBar();
    static ScrollBar* create(CCSpriteFrame* bg, CCSpriteFrame* fg, float maxLength);
    void setScrollableLength(float scrollableLength);
    void setOffset(float offset);
    void setMaxLength(float maxLength);
    bool needShowScrollBar();
private:
    void setNeedShowScrollBar(bool needShowScrollBar);
private:
    cocos2d::extension::CCScale9Sprite* _bg;
    cocos2d::extension::CCScale9Sprite* _fg;
    float _maxLength;
    float _scrollLength;
    
    void addChildItems();
    void layout();
    
    bool init(CCSpriteFrame* bg, CCSpriteFrame* fg, float maxLength);
private:
    cocos2d::CCRect vislbleRect;
    bool _needShowScrollBar;
    
};

#endif /* defined(__MagicEra__ScrollBar__) */
