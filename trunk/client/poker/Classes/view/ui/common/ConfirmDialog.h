//
//  ConfirmDialog.h
//  poker
//
//  Created by xiaoxiangzi on 13-12-23.
//
//

#ifndef __poker__ConfirmDialog__
#define __poker__ConfirmDialog__

using namespace std;

class MenuItem;
class PopupCommonBg;

class ConfirmDialog : public CommonPopupDialog {
    
public:
    CREATE_FUNC(ConfirmDialog);
    void setText(const string& title, const string& text, const string& okButtonText);
    void addCloseCallback(CCObject* target, SEL_MenuHandler callback);
    void addOkCallback(CCObject* target, SEL_MenuHandler callback);
    virtual ~ConfirmDialog();
protected:
    virtual bool init();
    void okButtonCallback(CCObject* sender);
    void clickCloseCallback(CCObject* sender);
private:
    ConfirmDialog();
private:
    CCLabelTTF* _textLabel;
    MenuItem* _okButton;
    
    CCObject* _closeTarget;
    SEL_MenuHandler _closeCallback;
    
    CCObject* _okTarget;
    SEL_MenuHandler _okCallback;
    
    CCLabelBMFont* _titleLabel;
    CCLabelBMFont* _okButtonLabel;
};

#endif /* defined(__poker__ConfirmDialog__) */
