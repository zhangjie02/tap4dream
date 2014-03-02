//
//  BaseUILayer.cpp
//  poker
//
//  Created by xiaoxiangzi on 13-11-15.
//
//

#include "BaseUILayer.h"
#include "KeyDispatcher.h"
#include "ResourceManager.h"
#include "ResourceKey.h"

BaseUILayer::BaseUILayer() {
    _resKey = ResourceManager::getInstance()->createResourceKey();
}

BaseUILayer::~BaseUILayer() {
    ResourceManager::getInstance()->releaseResourceKey(_resKey);
    _resKey = NULL;
}

bool BaseUILayer::init() {
    Layer::init();
    initRGBAProtocol(this);
    setNeedTouchChildren(true);
    return true;
}


void BaseUILayer::onEnter() {
	Layer::onEnter();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    KeyDispatcher::getInstance()->registerKeyBack(this);
#endif
}

void BaseUILayer::onExit() {
	Layer::onExit();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	KeyDispatcher::getInstance()->unregisterKeyBack(this);
#endif
}


bool BaseUILayer::doKeyBackClicked() {
	return false;
}

bool BaseUILayer::doKeyMenuClicked() {
	return false;
}

ResourceKey* BaseUILayer::getResourceKey() {
    return _resKey;
}

// RGBAProtocol
RGBAProtocol::RGBAProtocol()
: _displayedOpacity(255)
, _realOpacity(255)
, _displayedColor(ccWHITE)
, _realColor(ccWHITE)
, _cascadeColorEnabled(false)
, _cascadeOpacityEnabled(false)
, _relatedNode(NULL)
{}

RGBAProtocol::~RGBAProtocol() {}

void RGBAProtocol::initRGBAProtocol(CCNode* node)
{
    _relatedNode = node;
    _displayedOpacity = _realOpacity = 255;
    _displayedColor = _realColor = ccWHITE;
    _cascadeOpacityEnabled = _cascadeColorEnabled = false;
}

GLubyte RGBAProtocol::getOpacity(void)
{
	return _realOpacity;
}

GLubyte RGBAProtocol::getDisplayedOpacity(void)
{
	return _displayedOpacity;
}

void RGBAProtocol::setOpacity(GLubyte opacity)
{
    _displayedOpacity = _realOpacity = opacity;
    
	if (_cascadeOpacityEnabled)
    {
		GLubyte parentOpacity = 255;
        CCRGBAProtocol* pParent = dynamic_cast<CCRGBAProtocol*>(_relatedNode->getParent());
        if (pParent && pParent->isCascadeOpacityEnabled())
        {
            parentOpacity = pParent->getDisplayedOpacity();
        }
        this->updateDisplayedOpacity(parentOpacity);
	}
}

void RGBAProtocol::updateDisplayedOpacity(GLubyte parentOpacity)
{
	_displayedOpacity = _realOpacity * parentOpacity/255.0;
	
    if (_cascadeOpacityEnabled)
    {
        CCObject* pObj;
        CCARRAY_FOREACH(_relatedNode->getChildren(), pObj)
        {
            CCRGBAProtocol* item = dynamic_cast<CCRGBAProtocol*>(pObj);
            if (item)
            {
                item->updateDisplayedOpacity(_displayedOpacity);
            }
        }
    }
}

bool RGBAProtocol::isCascadeOpacityEnabled(void)
{
    return _cascadeOpacityEnabled;
}

void RGBAProtocol::setCascadeOpacityEnabled(bool cascadeOpacityEnabled)
{
    _cascadeOpacityEnabled = cascadeOpacityEnabled;
}

const ccColor3B& RGBAProtocol::getColor(void)
{
	return _realColor;
}

const ccColor3B& RGBAProtocol::getDisplayedColor()
{
	return _displayedColor;
}

void RGBAProtocol::setColor(const ccColor3B& color)
{
	_displayedColor = _realColor = color;
	
	if (_cascadeColorEnabled)
    {
		ccColor3B parentColor = ccWHITE;
        CCRGBAProtocol *parent = dynamic_cast<CCRGBAProtocol*>(_relatedNode->getParent());
		if (parent && parent->isCascadeColorEnabled())
        {
            parentColor = parent->getDisplayedColor();
        }
        
        updateDisplayedColor(parentColor);
	}
}

void RGBAProtocol::updateDisplayedColor(const ccColor3B& parentColor)
{
	_displayedColor.r = _realColor.r * parentColor.r/255.0;
	_displayedColor.g = _realColor.g * parentColor.g/255.0;
	_displayedColor.b = _realColor.b * parentColor.b/255.0;
    
    if (_cascadeColorEnabled)
    {
        CCObject *obj = NULL;
        CCARRAY_FOREACH(_relatedNode->getChildren(), obj)
        {
            CCRGBAProtocol *item = dynamic_cast<CCRGBAProtocol*>(obj);
            if (item)
            {
                item->updateDisplayedColor(_displayedColor);
            }
        }
    }
}

bool RGBAProtocol::isCascadeColorEnabled(void)
{
    return _cascadeColorEnabled;
}

void RGBAProtocol::setCascadeColorEnabled(bool cascadeColorEnabled)
{
    _cascadeColorEnabled = cascadeColorEnabled;
}

bool RGBAProtocol::isOpacityModifyRGB() {
    return false;
}

void RGBAProtocol::setOpacityModifyRGB(bool bValue) {}

