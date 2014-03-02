//
//  EditBox.cpp
//  spacewar
//
//  Created by xiaoxiangzi on 13-5-3.
//
//

#include "EditBox.h"
using namespace cocos2d;
using namespace extension;
using namespace std;

EditBox* EditBox::create(const cocos2d::CCSize& size, cocos2d::extension::CCScale9Sprite* pNormal9SpriteBg, cocos2d::extension::CCScale9Sprite* pPressed9SpriteBg, cocos2d::extension::CCScale9Sprite* pDisabled9SpriteBg) {
    EditBox* pRet = new EditBox();
    
    if (pRet != NULL && pRet->initWithSizeAndBackgroundSprite(size, pNormal9SpriteBg))
    {
        if (pPressed9SpriteBg != NULL)
        {
            pRet->setBackgroundSpriteForState(pPressed9SpriteBg, CCControlStateHighlighted);
        }
        
        if (pDisabled9SpriteBg != NULL)
        {
            pRet->setBackgroundSpriteForState(pDisabled9SpriteBg, CCControlStateDisabled);
        }
        pRet->autorelease();
        pRet->setUITouchEnabled(true);
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    
    return pRet;
}

void EditBox::registerWithTouchDispatcher() {}

void EditBox::setPlaceHolder(const char *pText) {
    int maxNum = getMaxLength();
    string holderStr = pText;
    if ((holderStr.size() > maxNum) && (maxNum > 0)) {
        holderStr = holderStr.substr(0, maxNum);
        holderStr.append("...");
    }
    
    CCEditBox::setPlaceHolder(holderStr.c_str());
}

void EditBox::setMaxLength(int maxLength) {
    if (getMaxLength() != maxLength) {
        CCEditBox::setMaxLength(maxLength);
        setPlaceHolder(getPlaceHolder());
    }
}
