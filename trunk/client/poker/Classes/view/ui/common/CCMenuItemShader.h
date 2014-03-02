//
//  CCMenuItemShader.h
//  spacewar
//
//  Created by xiaoxiangzi on 13-1-28.
//
//

#ifndef __spacewar__CCMenuItemShader__
#define __spacewar__CCMenuItemShader__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "MenuItem.h"
#include "UITouchDelegate.h"

class ShaderEffectSprite;

class CCScale9SpriteExt : public cocos2d::extension::CCScale9Sprite {
    
public:
    static CCScale9SpriteExt* create(CCSpriteFrame* frame);
    void setShader(const std::string& shaderType);
    const std::string& getShaderType();
    virtual ~CCScale9SpriteExt();
private:
    void initCCScale9SpriteExt(CCSpriteFrame* frame);
private:
    CCScale9SpriteExt();
    std::string _curShaderType;
};

class CCMenuItemShader : public MenuItem {
    
public:
    static CCMenuItemShader* createScale9MenuItem(CCSpriteFrame* frame, float width);
    static CCMenuItemShader* createScale9MenuItem(CCSpriteFrame* frame, float width, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector);
    static CCMenuItemShader* createScale9MenuItem(CCSpriteFrame* frame, float width, float height);
    static CCMenuItemShader* createScale9MenuItem(CCSpriteFrame* frame, float width, float height,
                                                  cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector);
    
    static CCMenuItemShader* create(CCSpriteFrame* frame);
    static CCMenuItemShader* create(CCSpriteFrame* frame, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector);
    static CCMenuItemShader* create(CCSpriteFrame* frame,
                                    const std::string& normalShader,
                                    const std::string& selectShader,
                                    const std::string& disableShader,
                                    cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector);
    
    virtual void selected();
    virtual void unselected();
    virtual void activate();
    virtual void setEnabled(bool bEnabled);
    bool hasClicked(const cocos2d::CCPoint& worldPosition);
    void changeClickSize(const cocos2d::CCSize& clickSize);
    cocos2d::CCNode* getShaderSprite();
    void changeDisplayImg(CCSpriteFrame* frame);
    void changeSelectShader(const std::string& selectShader);
    void changeNormalShader(const std::string& normalShader);
    void changeDisableShader(const std::string& disableShader);
    void changeShader(const std::string& shaderType);
    const std::string& getCurrentShader() const;
    
    // override to extend touch area
    virtual cocos2d::CCRect rect();
    void setTouchArea(float width, float height);
    
    virtual ~CCMenuItemShader();
protected:
    CCMenuItemShader();
    void initBasicProps(CCSpriteFrame* frame,
                        const std::string& normalShader,
                        const std::string& selectShader,
                        const std::string& disableShader,
                        cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector);
    void initCCMenuItemShader(CCSpriteFrame* frame,
                              const std::string& normalShader,
                              const std::string& selectShader,
                              const std::string& disableShader,
                              cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector);
    void initScale9MenuItem(CCSpriteFrame* frame,
                            const std::string &normalShader,
                            const std::string &selectShader,
                            const std::string &disableShader,
                            cocos2d::CCObject *target, cocos2d::SEL_MenuHandler selector, float width, float height);
    void updateShader();
private:
    ShaderEffectSprite* _itemShaderSprite;
    CCScale9SpriteExt* _scale9Sprite;
    
    std::string _normalShader;
    std::string _selectShader;
    std::string _disableShader;
    
    float _touchWidth;
    float _touchHeight;
    bool _hasSetTouchArea;
};

#endif /* defined(__spacewar__CCMenuItemShader__) */
