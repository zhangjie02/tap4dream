//
//  Layer.cpp
//  spacewar
//
//  Created by xiaoxiangzi on 13-5-3.
//
//

#include "Layer.h"
using namespace cocos2d;

Layer* Layer::create() {
    Layer* layer = new Layer;
    layer->init();
    layer->autorelease();
    return layer;
}

bool Layer::init() {
    if (!CCLayer::init()) {
        return false;
    }
    setUITouchEnabled(false);
    setNeedTouchChildren(false);
    ignoreAnchorPointForPosition(false);
    return true;
}

bool Layer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
    if (isUITouchEnabled()) {
        if (kScriptTypeNone != m_eScriptType) {
            CCScriptEngineManager::sharedManager()->getScriptEngine()->executeLayerTouchEvent(this, CCTOUCHBEGAN, pTouch);
            return isTouchSwallowed();
        }
    }
    
    return isUITouchEnabled();
}

void Layer::registerWithTouchDispatcher() {}

// Class LayerColor
LayerColor* LayerColor::create() {
    LayerColor* layer = new LayerColor;
    layer->init();
    layer->autorelease();
    return layer;
}

LayerColor* LayerColor::create(const cocos2d::ccColor4B &color) {
    LayerColor* layer = new LayerColor;
    layer->initWithColor(color);
    layer->autorelease();
    return layer;
}

LayerColor* LayerColor::create(const cocos2d::ccColor4B &color, GLfloat width, GLfloat height) {
    LayerColor* layer = new LayerColor;
    layer->initWithColor(color, width, height);
    layer->autorelease();
    return layer;
}

bool LayerColor::initWithColor(const cocos2d::ccColor4B &color, GLfloat width, GLfloat height) {
    CCLayerColor::initWithColor(color, width, height);
    ignoreAnchorPointForPosition(false);
    return true;
}

bool LayerColor::initWithColor(const cocos2d::ccColor4B &color) {
    CCLayerColor::initWithColor(color);
    ignoreAnchorPointForPosition(false);
    return true;
}

bool LayerColor::init() {
    CCLayerColor::init();
    ignoreAnchorPointForPosition(false);
    return true;
}

bool LayerColor::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
    return isUITouchEnabled();
}

void LayerColor::registerWithTouchDispatcher() {}

// Class LayerRect
LayerRect* LayerRect::create(const cocos2d::ccColor4B &color, GLfloat width, GLfloat height) {
    LayerRect* layer = new LayerRect;
    layer->initWithColor(color, width, height);
    layer->m_tViewSize = CCSizeMake(width, height);
    layer->autorelease();
    return layer;
}

// clip area out of bounds. Copy from CCScrollView
void LayerRect::visit()
{
	// quick return if not visible
	if (!isVisible())
    {
		return;
    }
    
	kmGLPushMatrix();
	
    if (m_pGrid && m_pGrid->isActive())
    {
        m_pGrid->beforeDraw();
        this->transformAncestors();
    }
    
	this->transform();
    this->beforeDraw();
    
	if(m_pChildren)
    {
		ccArray *arrayData = m_pChildren->data;
		unsigned int i=0;
		
		// draw children zOrder < 0
		for( ; i < arrayData->num; i++ )
        {
			CCNode *child =  (CCNode*)arrayData->arr[i];
			if ( child->getZOrder() < 0 )
            {
				child->visit();
			}
            else
            {
				break;
            }
		}
		
		// this draw
		this->draw();
		
		// draw children zOrder >= 0
		for( ; i < arrayData->num; i++ )
        {
			CCNode* child = (CCNode*)arrayData->arr[i];
			child->visit();
		}
        
	}
    else
    {
		this->draw();
    }
    
    this->afterDraw();
	if ( m_pGrid && m_pGrid->isActive())
    {
		m_pGrid->afterDraw(this);
    }
    
	kmGLPopMatrix();
}

CCRect LayerRect::getViewRect()
{
    CCPoint screenPos = this->convertToWorldSpace(CCPointZero);
    
    float scaleX = this->getScaleX();
    float scaleY = this->getScaleY();
    
    for (CCNode *p = m_pParent; p != NULL; p = p->getParent()) {
        scaleX *= p->getScaleX();
        scaleY *= p->getScaleY();
    }
    
    return CCRectMake(screenPos.x, screenPos.y, m_tViewSize.width*scaleX, m_tViewSize.height*scaleY);
}

void LayerRect::beforeDraw()
{
    m_bScissorRestored = false;
    CCRect frame = getViewRect();
    if (CCEGLView::sharedOpenGLView()->isScissorEnabled()) {
        m_bScissorRestored = true;
        m_tParentScissorRect = CCEGLView::sharedOpenGLView()->getScissorRect();
        //set the intersection of m_tParentScissorRect and frame as the new scissor rect
        if (frame.intersectsRect(m_tParentScissorRect)) {
            float x = MAX(frame.origin.x, m_tParentScissorRect.origin.x);
            float y = MAX(frame.origin.y, m_tParentScissorRect.origin.y);
            float xx = MIN(frame.origin.x+frame.size.width, m_tParentScissorRect.origin.x+m_tParentScissorRect.size.width);
            float yy = MIN(frame.origin.y+frame.size.height, m_tParentScissorRect.origin.y+m_tParentScissorRect.size.height);
            CCEGLView::sharedOpenGLView()->setScissorInPoints(x, y, xx-x, yy-y);
        }
    }
    else {
        glEnable(GL_SCISSOR_TEST);
        CCEGLView::sharedOpenGLView()->setScissorInPoints(frame.origin.x, frame.origin.y, frame.size.width, frame.size.height);
    }    
}

void LayerRect::afterDraw()
{

    if (m_bScissorRestored) {//restore the parent's scissor rect
        CCEGLView::sharedOpenGLView()->setScissorInPoints(m_tParentScissorRect.origin.x, m_tParentScissorRect.origin.y, m_tParentScissorRect.size.width, m_tParentScissorRect.size.height);
    }
    else {
        glDisable(GL_SCISSOR_TEST);
    }
}