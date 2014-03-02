//
//  Layer.h
//  spacewar
//
//  Created by xiaoxiangzi on 13-5-3.
//
//

#ifndef __spacewar__Layer__
#define __spacewar__Layer__

#include <iostream>
#include "cocos2d.h"
#include "UITouchDelegate.h"

class Layer : public cocos2d::CCLayer, public UITouchDelegate {
    
public:
    static Layer* create();
    bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
protected:
    virtual bool init();
private:
    virtual void registerWithTouchDispatcher();
};

class LayerColor : public cocos2d::CCLayerColor, public UITouchDelegate {
    
public:
    static LayerColor* create();
    static LayerColor* create(const cocos2d::ccColor4B& color, GLfloat width, GLfloat height);
    static LayerColor* create(const cocos2d::ccColor4B& color);
    virtual bool init();
    virtual bool initWithColor(const cocos2d::ccColor4B& color);
    virtual bool initWithColor(const cocos2d::ccColor4B& color, GLfloat width, GLfloat height);
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

private:
    virtual void registerWithTouchDispatcher();
};

class LayerRect : public LayerColor {
public:
    static LayerRect* create(const cocos2d::ccColor4B& color, GLfloat width, GLfloat height);
    
    virtual void visit();
    void beforeDraw();
    void afterDraw();
    cocos2d::CCRect getViewRect();
protected:
    void setScissorInPoints(float x , float y , float w , float h);
    cocos2d::CCSize m_tViewSize;
    cocos2d::CCRect m_tParentScissorRect;
    bool m_bScissorRestored;
};
#endif /* defined(__spacewar__Layer__) */
