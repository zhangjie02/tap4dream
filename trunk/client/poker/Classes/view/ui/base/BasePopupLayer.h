//
//  BasePopupLayer.h
//  poker
//
//  Created by xiaoxiangzi on 13-11-15.
//
//

#ifndef __poker__BasePopupLayer__
#define __poker__BasePopupLayer__

#include "BaseUILayer.h"
#include "UIPopupManager.h"
using namespace cocos2d;

class BasePopupLayer : public BaseUILayer {
    
public:
    virtual void closePopup();
    virtual bool init();
    virtual bool doKeyBackClicked();
    CREATE_FUNC(BasePopupLayer);
    
    virtual void onEnter();
    virtual void onExit();
    void setShowPopupAnim(bool showPopupAnim = true);
    bool hasClosed() const;
    bool hasPopedUp() const;
    virtual ~BasePopupLayer();
    void setMaskVisible(bool visible);
    void setPopupType(PopupDisplayType type);
    PopupDisplayType getPopupDisplayType();
    void addClosePopupLayerCallback(CCObject* target, SEL_MenuHandler callback);
    
    virtual void registerScriptCloseHandler(int luaHandler);
    virtual void unregisterScriptCloseHandler(void);
    int getScriptCloseHandler();
    void setMaskColor(const ccColor4B& color);
protected:
    BasePopupLayer();
    void showOpenAnim();
    void openPopup();
    void didOpenPopup();
    void executeCloseCallback();
private:
    bool _showPopupAnim;
    bool _hasClosed;
    bool _hasPopup;
    CCLayerColor* _maskBg;
    bool _isMaskVisible;
    PopupDisplayType _popupType;
    
    CCObject* _closePopupLayerTarget;
    SEL_MenuHandler _closePopupLayerCallback;
    
    int _closeScriptHandler;
};


#endif /* defined(__poker__BasePopupLayer__) */
