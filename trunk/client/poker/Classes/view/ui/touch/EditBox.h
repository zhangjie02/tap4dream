//
//  EditBox.h
//  spacewar
//
//  Created by xiaoxiangzi on 13-5-3.
//
//

#ifndef __spacewar__EditBox__
#define __spacewar__EditBox__

#include <iostream>
#include "cocos-ext.h"
#include "UITouchDelegate.h"

class EditBox : public cocos2d::extension::CCEditBox, public UITouchDelegate {
    
public:
    static EditBox* create(const cocos2d::CCSize& size, cocos2d::extension::CCScale9Sprite* pNormal9SpriteBg, cocos2d::extension::CCScale9Sprite* pPressed9SpriteBg = NULL, cocos2d::extension::CCScale9Sprite* pDisabled9SpriteBg = NULL);
    virtual void setPlaceHolder(const char *pText);
    virtual void setMaxLength(int maxLength);
private:
    virtual void registerWithTouchDispatcher();
};

#endif /* defined(__spacewar__EditBox__) */
