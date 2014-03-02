//
//  ConfirmDialog.cpp
//  poker
//
//  Created by xiaoxiangzi on 13-12-23.
//
//

#include "ConfirmDialog.h"
#include "MenuItem.h"
#include "FontConstants.h"
#include "LayoutUtil.h"
#include "ResourceKey.h"
#include "ResourceName.h"
#include "PopupCommonBg.h"
#include "ResourceManager.h"
#include "UICommonConsts.h"

ConfirmDialog::ConfirmDialog() :
_closeTarget(NULL),
_closeCallback(NULL),
_okTarget(NULL),
_okCallback(NULL),
_okButton(NULL),
_textLabel(NULL),
_titleLabel(NULL),
_okButtonLabel(NULL) {}

ConfirmDialog::~ConfirmDialog() {}

bool ConfirmDialog::init() {
    CommonPopupDialog::init(714, 326);
    
    _okButton = MenuItemSprite::create(_resKey->getCCSprite(ResourceName::BTN_COMMON_GREEN_UP), _resKey->getCCSprite(ResourceName::BTN_COMMON_GREEN_DOWN), this, menu_selector(ConfirmDialog::okButtonCallback));
    this->addChild(_okButton);
    LayoutUtil::layout(_okButton, 0.5f, 0, _bg, 0.5f, 0, false, 0, UICommonConsts::POPUP_BOTTOM_BUTTON_PADDING_BOTTOM);

    return true;
}

void ConfirmDialog::setText(const string &title, const string &text, const string &okButtonText) {
    if (_titleLabel == NULL) {
        _titleLabel = _resKey->getCCLabelBMFont(ResourceName::ARIAL_ROUNDED_MT_BOLD_72, title.c_str(), kCCTextAlignmentCenter);
        this->addChild(_titleLabel);
    } else {
        _titleLabel->setString(title.c_str());
    }
    LayoutUtil::layout(_titleLabel, 0.5f, 1, _bg, 0.5f, 1, false, 0, UICommonConsts::POPUP_TITTLE_PADDING_TOP);
    
    if (_textLabel == NULL) {
        _textLabel = CCLabelTTF::create(text.c_str(), FontConstants::ARIAL_ROUNDED_MT_BOLD_TTF, 24, CCSizeMake(630, 0), kCCTextAlignmentCenter, kCCVerticalTextAlignmentCenter);
        this->addChild(_textLabel);
    } else {
        _textLabel->setString(text.c_str());
    }
    LayoutUtil::layout(_textLabel, 0.5f, 1, _bg, 0.5f, 1, false, 0, -90);
    
    if (_okButtonLabel == NULL) {
        _okButtonLabel = _resKey->getCCLabelBMFont(ResourceName::ARIAL_ROUNDED_MT_BOLD_40, okButtonText.c_str(), kCCTextAlignmentCenter);
        _okButton->addChild(_okButtonLabel);
    } else {
        _okButtonLabel->setString(okButtonText.c_str());
    }
    LayoutUtil::layoutParentCenter(_okButtonLabel, 0, UICommonConsts::POPUP_BUTTON_LABEL_CENTER_OFFSET_Y);
}

void ConfirmDialog::addOkCallback(cocos2d::CCObject *target, SEL_MenuHandler callback) {
    _okTarget = target;
    _okCallback = callback;
}

void ConfirmDialog::addCloseCallback(cocos2d::CCObject *target, SEL_MenuHandler callback) {
    _closeTarget = target;
    _closeCallback = callback;
}

void ConfirmDialog::okButtonCallback(cocos2d::CCObject *sender) {
    if (_okCallback && _okTarget) {
        (_okTarget->*_okCallback)(sender);
    }
    closePopup();
}

void ConfirmDialog::clickCloseCallback(cocos2d::CCObject *sender) {
    if (_closeCallback && _closeTarget) {
        (_closeTarget->*_closeCallback)(sender);
    }
    
    closePopup();
}
