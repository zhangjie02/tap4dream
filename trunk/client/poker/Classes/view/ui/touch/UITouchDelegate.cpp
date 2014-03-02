//
//  UITouchDelegate.cpp
//  spacewar
//
//  Created by xiaoxiangzi on 13-5-2.
//
//

#include "UITouchDelegate.h"

UITouchDelegate::UITouchDelegate() :
_isUITouchEnabled(false),
_needTouchChildren(false),
_isPositionCheckEnabled(false),
_isTouchSwallowed(true) {}

bool UITouchDelegate::isUITouchEnabled() {
    return _isUITouchEnabled;
}

bool UITouchDelegate::needTouchChildren() {
    return _needTouchChildren;
}

bool UITouchDelegate::isPositionCheckEnabled() {
    return _isPositionCheckEnabled;
}

bool UITouchDelegate::isTouchSwallowed() {
    return _isTouchSwallowed;
}

void UITouchDelegate::setUITouchEnabled(bool enabled) {
    _isUITouchEnabled = enabled;
}

void UITouchDelegate::setNeedTouchChildren(bool needTouchChildren) {
    _needTouchChildren = needTouchChildren;
}

void UITouchDelegate::setPositionCheckEnabled(bool enabled) {
    _isPositionCheckEnabled = enabled;
}

void UITouchDelegate::setTouchSwallowed(bool swallowed) {
    _isTouchSwallowed = swallowed;
}
