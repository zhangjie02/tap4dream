//
//  ColorfulLabelTTF.cpp
//  xiyou
//
//  Created by Liu Jian on 10/23/13.
//
//

#include "ColorfulLabelTTF.h"
#include <vector>
#include "LayoutUtil.h"
#include "StringConverter.h"
#include "FontsUtil.h"
using namespace std;

ColorfulLabelTTF* ColorfulLabelTTF::create(int width,const char* text,const char* fontName,int fontSize, CCTextAlignment horizentalAlightmentint, int marginOf1stLine, int marginOfElseLines) {
    ColorfulLabelTTF* ret = new ColorfulLabelTTF;
    ret->init(width, text, fontName, fontSize, horizentalAlightmentint, marginOf1stLine, marginOfElseLines);
    ret->autorelease();
    return ret;
}



bool ColorfulLabelTTF::init(int totalWidth, const char *text, const char *fontName, int fontSize, CCTextAlignment horizentalAlightment, int marginOf1stLine, int marginOfElseLines) {
    setCascadeOpacityEnabled(true);
    int utf16Size = 0;
   unsigned short* utf16str = cc_utf8_to_utf16(text,-1,&utf16Size);
    vector<int> starVec;
    vector<int> endVec;
    vector<ccColor3B> colorVec;
    bool isColor = true;
    int i=0;
    ccColor3B newColor;
    extraColor(utf16str, i,utf16Size, &isColor,&newColor);
    if(isColor) {
        starVec.push_back(8);
        i+=8;
    }else {
        starVec.push_back(0);
    }
    colorVec.push_back(newColor);
    
    for(;i<utf16Size ; i++) {
        extraColor(utf16str, i,utf16Size, &isColor,&newColor);
        if(isColor) {
            endVec.push_back(i);
            colorVec.push_back(newColor);
            starVec.push_back(i+8);
            i+=7;
            continue;
        }
    }
    endVec.push_back(utf16Size);
    //========切块完毕===========
    
    vector<vector<CCLabelTTF*> > children;
    vector<CCLabelTTF*> emptyLine;
    children.push_back(emptyLine);
    int width = marginOf1stLine;
    int lineNo = 0;
    int totalHeight = 0;
    int maxHeightOfLine = 0;
    for(int i=0 ; i<colorVec.size() ; i++) {
        int start = starVec[i];
        int end = endVec[i];
        CCLabelTTF* rect = createTTF(utf16str, start, end, colorVec[i], fontName, fontSize);
        int cellWidth = rect->getContentSize().width;
        int cellHeight = rect->getContentSize().height;
        if(width + cellWidth < totalWidth) {
            children[lineNo].push_back(rect);
            width += cellWidth;
            maxHeightOfLine = std::max(maxHeightOfLine,cellHeight);
        } else {
            for(int j=start;j<end;j++) {
                CCLabelTTF* rect = createTTF(utf16str, j, j+1, colorVec[i], fontName, fontSize);
                int cellWidth = rect->getContentSize().width;
                int cellHeight = rect->getContentSize().height;
                if(width + cellWidth < totalWidth) {
                    children[lineNo].push_back(rect);
                    width += cellWidth;
                    maxHeightOfLine = std::max(maxHeightOfLine,cellHeight);
                } else {
                    totalHeight+=maxHeightOfLine;
                    lineNo++;
                    children.push_back(emptyLine);
                    width = marginOfElseLines + cellWidth;
                    maxHeightOfLine = cellHeight;
                    children[lineNo].push_back(rect);
                }
            }
        }
    }
    totalHeight += maxHeightOfLine;
    //======拼装=======
    if(children.size() == 1) {
        //只有一行的话，就不要用totalWidth做宽度了，需要用所有的child的宽度之和
        int widthOfLine = 0;
        for(CCLabelTTF* cell : children[0]) {
            widthOfLine += cell->getContentSize().width;
        }
        setContentSize(CCSizeMake(widthOfLine, totalHeight));
    } else {
        setContentSize(CCSizeMake(totalWidth, totalHeight));
    }

    int topOffset = 0;
    for(vector<CCLabelTTF*> line : children) {
        int leftOffset = (topOffset==0?marginOf1stLine:marginOfElseLines);
        int lineHeight = 0;
        int cellsWidth = 0;
        for(CCLabelTTF* cell:line) {
            int cellWidth = cell->getContentSize().width;
            cellsWidth += cellWidth;
        }
        if (horizentalAlightment == kCCTextAlignmentCenter) {
            leftOffset += (getContentSize().width - cellsWidth) / 2;
        } else if (horizentalAlightment == kCCTextAlignmentRight) {
            leftOffset += getContentSize().width - cellsWidth;
        }
        
        for(CCLabelTTF* cell:line) {
            int cellWidth = cell->getContentSize().width;
            int cellHeight = cell->getContentSize().height;
            addChild(cell);
            LayoutUtil::layoutParentLeftTop(cell,leftOffset,-topOffset);
            leftOffset+=cellWidth;
            lineHeight=std::max(lineHeight, cellHeight);
        }
        
        topOffset += lineHeight;
    }
    return true;
}

CCLabelTTF* ColorfulLabelTTF::createTTF(unsigned short* utf16str,int start,int end,const ccColor3B& color,const char* fontName,int fontSize) {
    long itemRead,itemWrite;
    char* utf8Str = cc_utf16_to_utf8(utf16str+start, end-start,&itemRead,&itemWrite);
    CCLabelTTF* ret = CCLabelTTF::create(utf8Str, fontName, fontSize);
    ret->setColor(color);
    free(utf8Str);
    return ret;
}

void ColorfulLabelTTF::extraColor(unsigned short* utf16str,int pos,int strLen,bool* isColorInfo,ccColor3B* retColor) {
    *isColorInfo = true;
    if(pos>=strLen-8 || utf16str[pos] !='<' || utf16str[pos+7] != '>') {
        *isColorInfo = false;
    } else {
        for(int i=pos+1;i<pos+7;i++) {
            unsigned short num = utf16str[i];
            if(!((num>='0'&&num <='9') || (num>='A'&&num<='F') || (num>='a'&&num<='f'))) {
                *isColorInfo = false;
                break;
            }
        }
    }
    if(*isColorInfo) {
        long itemRead,itemWrite;
        char* color = cc_utf16_to_utf8(utf16str+pos+1, 6,&itemRead,&itemWrite);
        long colorInt = strtol(color,NULL,16);
        ccColor3B ret = FontsUtil::convertToColor3B(colorInt);
        free(color);
        retColor->r = ret.r;
        retColor->g = ret.g;
        retColor->b = ret.b;
    }
}

