//
//  MultiLineLabel.cpp
//  spacewar
//
//  Created by xiaoxiangzi on 13-6-28.
//
//

#include "MultiLineLabel.h"
#include "LayoutUtil.h"
#include "FontConstants.h"
using namespace cocos2d;
using namespace std;

MultiLineLabel::MultiLineLabel() :
_text(""),
_fontFile(FontConstants::ARIAL_ROUNDED_MT_TTF),
_lineSpace(0),
_fontSize(20),
_opacity(255),
_isOpacityModifyRGB(true),
_color(ccWHITE),
_horizentalAlighment(kCCTextAlignmentCenter) {}

MultiLineLabel* MultiLineLabel::createWithTTFLabel(const char *text, const char *fontFile,
                                                   int fontSize, float lineSpace/* = 0*/,
                                                   cocos2d::CCTextAlignment alignment/* = cocos2d::kCCTextAlignmentCenter*/) {
    MultiLineLabel* label = new MultiLineLabel;
    label->initWithTTFLabel(text, fontFile, fontSize, lineSpace, alignment);
    label->autorelease();
    return label;
}

void MultiLineLabel::initWithTTFLabel(const char *text, const char *fontFile, int fontSize, float lineSpace, cocos2d::CCTextAlignment alignment) {
    _fontFile = fontFile;
    _lineSpace = lineSpace;
    _fontSize = fontSize;
    _horizentalAlighment = alignment;
    setString(text);
}

void MultiLineLabel::setLineSpace(float lineSpace) {
    _lineSpace = lineSpace;
    updateString(false);
}

void MultiLineLabel::setString(const char *label) {
    if (_text == label) {
        return;
    }
    _text = label;
    updateString();
}

void MultiLineLabel::updateString(bool needUpdateLabel/* = true*/) {
    if (needUpdateLabel) {
        this->removeAllChildrenWithCleanup(true);
        vector<string> subStrings;
        subStrings.clear();
        string tmp = "";
        
        if (_text.size() > 0) {
            for (size_t i = 0; i < _text.size(); i++) {
                char c = _text.at(i);
                if (c == '\n') {
                    subStrings.push_back(tmp);
                    tmp.clear();
                } else if (i == (_text.size() - 1)) {
                    tmp.push_back(c);
                    subStrings.push_back(tmp);
                    tmp.clear();
                } else {
                    tmp.push_back(c);
                }
            }
        } else {
            subStrings.push_back("");
        }
        
        
        for (vector<string>::iterator iter = subStrings.begin(); iter != subStrings.end(); iter++) {
            const string& str = *iter;
            CCLabelTTF* label = CCLabelTTF::create(str.c_str(), _fontFile.c_str(), _fontSize, CCSizeZero, _horizentalAlighment);
            this->addChild(label);
        }
    }
    
    float width = 0;
    float height = 0;
    CCNode* lastLabel = NULL;
    CCArray* children = getChildren();
    
    if (children == NULL || children->count() == 0) {
        return;
    }
    
    for (size_t i = 0; i < children->count(); i++) {
        CCNode* label = dynamic_cast<CCNode*>(children->objectAtIndex(i));
        CCSize size = label->getContentSize();
        if (size.width > width) {
            width = size.width;
        }
        height += size.height + _lineSpace;
    }
    height -= _lineSpace;
    this->setContentSize(CCSizeMake(width, height));
    
    lastLabel = NULL;
    for (size_t i = 0; i < children->count(); i++) {
        CCNode* label = dynamic_cast<CCNode*>(children->objectAtIndex(i));
        if (_horizentalAlighment == kCCTextAlignmentLeft) {
            if (lastLabel == NULL) {
                LayoutUtil::layoutParentLeftTop(label);
            } else {
                LayoutUtil::layout(label, 0, 1, lastLabel, 0, 0, false, 0, -_lineSpace);
            }
        } else if (_horizentalAlighment == kCCTextAlignmentRight) {
            if (lastLabel == NULL) {
                LayoutUtil::layoutParentRightTop(label);
            } else {
                LayoutUtil::layout(label, 1, 1, lastLabel, 1, 0, false, 0, -_lineSpace);
            }
        } else if (_horizentalAlighment == kCCTextAlignmentCenter) {
            if (lastLabel == NULL) {
                LayoutUtil::layoutParentTop(label);
            } else {
                LayoutUtil::layoutBottom(label, lastLabel, 0, -_lineSpace);
            }
        }
    
        lastLabel = label;
    }
}

void MultiLineLabel::setColor(const cocos2d::ccColor3B &color) {
    _color = color;
    CCObject* obj = NULL;
    CCARRAY_FOREACH(getChildren(), obj) {
        CCRGBAProtocol* label = dynamic_cast<CCRGBAProtocol*>(obj);
        if (label) {
            label->setColor(_color);
        }
    }
}

const ccColor3B& MultiLineLabel::getColor() {
    return _color;
}

void MultiLineLabel::setOpacity(GLubyte opacity) {
    _opacity = opacity;
    CCObject* obj = NULL;
    CCARRAY_FOREACH(getChildren(), obj) {
        CCRGBAProtocol* label = dynamic_cast<CCRGBAProtocol*>(obj);
        if (label) {
            label->setOpacity(_opacity);
        }
    }
}

GLubyte MultiLineLabel::getOpacity() {
    return _opacity;
}

void MultiLineLabel::setOpacityModifyRGB(bool bValue) {
    _isOpacityModifyRGB = bValue;
    CCObject* obj = NULL;
    CCARRAY_FOREACH(getChildren(), obj) {
        CCRGBAProtocol* label = dynamic_cast<CCRGBAProtocol*>(obj);
        if (label) {
            label->setOpacityModifyRGB(_isOpacityModifyRGB);
        }
    }
}

bool MultiLineLabel::isOpacityModifyRGB() {
    return _isOpacityModifyRGB;
}

const char* MultiLineLabel::getString() {
    return _text.c_str();
}

void MultiLineLabel::setFontSize(int fontSize) {
    if (_fontSize != fontSize) {
        _fontSize = fontSize;
        updateString(true);
    }
}