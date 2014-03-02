//
//  CommonPopupDialog.cpp
//  poker
//
//  Created by xiaoxiangzi on 14-1-22.
//
//

#include "CommonPopupDialog.h"
#include "MenuItem.h"
#include "LayoutUtil.h"
#include "ResourceKey.h"
#include "ResourceName.h"
#include "UICommonConsts.h"

CommonPopupDialog::CommonPopupDialog() :
_bg(NULL),
_closeButton(NULL) {}

CommonPopupDialog* CommonPopupDialog::create(int width, int height) {
    CommonPopupDialog* dialog = new CommonPopupDialog();
    dialog->init(width, height);
    dialog->autorelease();
    return dialog;
}

void CommonPopupDialog::init(int width, int height) {
    BasePopupLayer::init();
    _bg = PopupCommonBg::create(width, height);
    this->addChild(_bg);
    LayoutUtil::layoutParentCenter(_bg);
    
    _closeButton = MenuItemSprite::create(_resKey->getCCSprite(ResourceName::BTN_POPUPBOX_CLOSE_UP), _resKey->getCCSprite(ResourceName::BTN_POPUPBOX_CLOSE_DOWN), this, menu_selector(CommonPopupDialog::clickCloseCallback));
    this->addChild(_closeButton);
    LayoutUtil::layout(_closeButton, 1, 1, _bg, 1, 1, false, UICommonConsts::POPUP_CLOSE_BTN_PADDING_X, UICommonConsts::POPUP_CLOSE_BTN_PADDING_Y);
}

void CommonPopupDialog::clickCloseCallback(cocos2d::CCObject *sender) {
    closePopup();
}

