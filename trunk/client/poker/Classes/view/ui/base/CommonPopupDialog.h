//
//  CommonPopupDialog.h
//  poker
//
//  Created by xiaoxiangzi on 14-1-22.
//
//

#ifndef __poker__CommonPopupDialog__
#define __poker__CommonPopupDialog__

#include "BasePopupLayer.h"

class PopupCommonBg;
class MenuItem;

class CommonPopupDialog : public BasePopupLayer {
    
public:
    static CommonPopupDialog* create(int width, int height);
    virtual void init(int width, int height);
    CommonPopupDialog();
protected:
    virtual void clickCloseCallback(CCObject* sender);
protected:
    MenuItem* _closeButton;
    PopupCommonBg* _bg;
};

#endif /* defined(__poker__CommonPopupDialog__) */
