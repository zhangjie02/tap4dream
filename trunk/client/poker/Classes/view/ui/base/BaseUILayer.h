//
//  BaseUILayer.h
//  poker
//
//  Created by xiaoxiangzi on 13-11-15.
//
//

#ifndef __poker__BaseUILayer__
#define __poker__BaseUILayer__

#include "Layer.h"
using namespace cocos2d;

class ResourceKey;

class RGBAProtocol : public CCRGBAProtocol {
public:
    RGBAProtocol();
    virtual ~RGBAProtocol();
    
    void initRGBAProtocol(CCNode* node);
    
    virtual GLubyte getOpacity();
    virtual GLubyte getDisplayedOpacity();
    virtual void setOpacity(GLubyte opacity);
    virtual void updateDisplayedOpacity(GLubyte parentOpacity);
    virtual bool isCascadeOpacityEnabled();
    virtual void setCascadeOpacityEnabled(bool cascadeOpacityEnabled);
    
    virtual const ccColor3B& getColor(void);
    virtual const ccColor3B& getDisplayedColor();
    virtual void setColor(const ccColor3B& color);
    virtual void updateDisplayedColor(const ccColor3B& parentColor);
    virtual bool isCascadeColorEnabled();
    virtual void setCascadeColorEnabled(bool cascadeColorEnabled);
    
    virtual void setOpacityModifyRGB(bool bValue);
    virtual bool isOpacityModifyRGB();
    
protected:
	GLubyte		_displayedOpacity;
    GLubyte     _realOpacity;
	ccColor3B	_displayedColor;
    ccColor3B   _realColor;
	bool		_cascadeColorEnabled;
    bool        _cascadeOpacityEnabled;
    
    CCNode* _relatedNode;
};

class BaseUILayer : public Layer, public RGBAProtocol {
    
public:
    CREATE_FUNC(BaseUILayer);
    
    virtual void onExit();
	virtual void onEnter();
    
    virtual bool doKeyBackClicked();
	virtual bool doKeyMenuClicked();
    
    BaseUILayer();
    virtual ~BaseUILayer();
    ResourceKey* getResourceKey();
protected:
    virtual bool init();
    
    ResourceKey* _resKey;
};

#endif /* defined(__poker__BaseUILayer__) */
