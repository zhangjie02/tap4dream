//
//  ColorfulLabelTTF.h
//  xiyou
//
//  Created by Liu Jian on 10/23/13.
//
//

#ifndef __xiyou__ColorfulLabelTTF__
#define __xiyou__ColorfulLabelTTF__

#include "cocos2d.h"
USING_NS_CC;

class ColorfulLabelTTF :public CCNodeRGBA {
public:
    static ColorfulLabelTTF* create(int width,const char* text,const char* fontName,int fontSize, CCTextAlignment horizentalAlightment, int marginOf1stLine=0,int marginOfElseLines=0);
    bool init(int width,const char* text,const char* fontName,int fontSize, CCTextAlignment horizentalAlightmentint, int marginOf1stLine,int marginOfElseLines);
private:
    void extraColor(unsigned short* utf16str,int pos,int strLen,bool* isColorInfo,ccColor3B* retColor);
    CCLabelTTF* createTTF(unsigned short* utf16str,int start,int end,const ccColor3B& color,const char* fontName,int fontSize);
};

#endif /* defined(__xiyou__ColorfulLabelTTF__) */
