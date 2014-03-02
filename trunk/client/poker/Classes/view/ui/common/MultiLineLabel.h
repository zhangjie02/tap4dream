//
//  MultiLineLabel.h
//  spacewar
//
//  Created by xiaoxiangzi on 13-6-28.
//
//

#ifndef __spacewar__MultiLineLabel__
#define __spacewar__MultiLineLabel__

#include <iostream>
#include "cocos2d.h"

class MultiLineLabel : public cocos2d::CCNodeRGBA, public cocos2d::CCLabelProtocol {
    
public:
    static MultiLineLabel* createWithTTFLabel(const char* text,
                                              const char* fontFile,
                                              int fontSize,
                                              float lineSpace = 0,
                                              cocos2d::CCTextAlignment alignment = cocos2d::kCCTextAlignmentCenter);
    
    virtual void setColor(const cocos2d::ccColor3B& color);
    virtual const cocos2d::ccColor3B& getColor(void);
    virtual GLubyte getOpacity(void);
    virtual void setOpacity(GLubyte opacity);
    virtual void setOpacityModifyRGB(bool bValue);
    virtual bool isOpacityModifyRGB(void);
    virtual void setString(const char *label);
    virtual const char* getString();
    void setLineSpace(float lineSpace);
    void setFontSize(int fontSize);
private:
    MultiLineLabel();
    void updateString(bool needUpdateLabel = true);
    void initWithTTFLabel(const char* text, const char* fontFile, int fontSize, float lineSpace, cocos2d::CCTextAlignment alignment);
private:
    std::string _text;
    std::string _fontFile;
    int _fontSize;
    float _lineSpace;
    cocos2d::ccColor3B _color;
    GLubyte _opacity;
    bool _isOpacityModifyRGB;
    cocos2d::CCTextAlignment _horizentalAlighment;
};

#endif /* defined(__spacewar__MultiLineLabel__) */
