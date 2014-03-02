//
//  UITouchDelegate.h
//  spacewar
//
//  Created by xiaoxiangzi on 13-5-2.
//
//

#ifndef __spacewar__UITouchDelegate__
#define __spacewar__UITouchDelegate__

class UITouchDelegate {
public:
    virtual bool isUITouchEnabled();
    virtual bool needTouchChildren();
    virtual bool isPositionCheckEnabled();
    virtual bool isTouchSwallowed();
    
    virtual void setUITouchEnabled(bool enabled);
    virtual void setNeedTouchChildren(bool needTouchChildren);
    virtual void setPositionCheckEnabled(bool enabled);
    virtual void setTouchSwallowed(bool swallowed);
    
    virtual ~UITouchDelegate() {}
    UITouchDelegate();
private:
    bool _isUITouchEnabled;
    bool _needTouchChildren;
    bool _isPositionCheckEnabled;
    bool _isTouchSwallowed;
};

#endif /* defined(__spacewar__UITouchDelegate__) */
