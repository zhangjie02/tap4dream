#include "ShaderEffectSprite.h"
#include <sstream>
#include "ResourceKey.h"
#include "ResourceManager.h"

ShaderEffectSprite::ShaderEffectSprite() : shaderType("") {}


ShaderEffectSprite::~ShaderEffectSprite() {}

ShaderEffectSprite* ShaderEffectSprite::create(string shader){
	ShaderEffectSprite* graySprite = new ShaderEffectSprite;
    graySprite->shaderType = shader;
	if (graySprite && graySprite->init()){
		graySprite->autorelease();
		return graySprite;
	}else{
		CC_SAFE_RELEASE(graySprite);
		return NULL;
	}
}


ShaderEffectSprite* ShaderEffectSprite::create(cocos2d::CCSpriteFrame *frame, string shaderType){
	ShaderEffectSprite* graySprite = new ShaderEffectSprite;
    graySprite->shaderType = shaderType;
	if (graySprite && graySprite->initShaderSprite(frame, shaderType)){
		graySprite->autorelease();
		return graySprite;
	}else{
		CC_SAFE_RELEASE(graySprite);
		return NULL;
	}
}

bool ShaderEffectSprite::initShaderSprite(cocos2d::CCSpriteFrame *frame, const string &shaderType) {
    return initWithSpriteFrame(frame);
}


bool ShaderEffectSprite::initWithTexture(CCTexture2D* pTexture, const CCRect& tRect ){
	do{
		CC_BREAK_IF(!CCSprite::initWithTexture(pTexture, tRect));
        
		setShader(shaderType);
        
		return true;
	} while (0);
	return false;
}

void ShaderEffectSprite::changeShader(string shaderType){
	this->shaderType=shaderType;
	setShader(shaderType);
}

void ShaderEffectSprite::setShader(string shaderType){
	CCGLProgram* pProgram = ShaderMgr::getInstance()->getShaderProgram(shaderType);
	this->setShaderProgram(pProgram);
}

const std::string& ShaderEffectSprite::getShaderType() {
    return shaderType;
}
