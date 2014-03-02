//
//  ShaderEffectSprite.h
//  poker
//
//  Created by xiaoxiangzi on 13-12-3.
//
//

#ifndef slot_ShaderEffectSprite_h
#define slot_ShaderEffectSprite_h

#include "ShaderMgr.h"
#include "cocos2d.h"
#include <string>
using namespace std;
USING_NS_CC;

class ShaderEffectSprite : public CCSprite{
    
    
public:
	ShaderEffectSprite();
	virtual ~ShaderEffectSprite();
	static ShaderEffectSprite* create(string shaderType);
	static ShaderEffectSprite* create(CCSpriteFrame* frame, string shaderType);
	bool initWithTexture(CCTexture2D* pTexture, const CCRect& tRect);
    
	void changeShader(string shaderType);
    const std::string& getShaderType();
private:
	bool initShaderSprite(CCSpriteFrame* frame, const string& shaderType);
	void setShader(string shaderType);
private:
    
    string shaderType;
};

#endif
