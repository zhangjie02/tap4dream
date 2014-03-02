//
//  UIPopupManager.h
//  poker
//
//  Created by xiaoxiangzi on 13-11-15.
//
//

#ifndef __poker__UIPopupManager__
#define __poker__UIPopupManager__

#include "cocos2d.h"
#include <vector>
using namespace std;
using namespace cocos2d;

class BasePopupLayer;

enum PopupDisplayType {
    Popup_Normal = 0,
    Popup_System,
    Popup_Bonus,
};

class UIPopupManager : public CCObject {
    
public:
    static UIPopupManager* getInstance();
    void showPopupLayer(BasePopupLayer* uiLayer, bool needSequenceShow = false, PopupDisplayType type = Popup_Normal);
    void showMsgDialog(string msg);
    void update();
    unsigned int getDisplayedPopupLayerCount() const;
    void reset();
private:
    UIPopupManager();
    UIPopupManager(const UIPopupManager&);
    UIPopupManager& operator=(const UIPopupManager&);
    virtual ~UIPopupManager();
    
    void updateDisplayCount();
    bool isUnusedLayer(BasePopupLayer* layer);
    void showPopupLayerIndeed(BasePopupLayer* uiLayer);
    void releasePopupLayers();
private:
    vector<BasePopupLayer*> _popupStack;
    unsigned int _displayedPopupCount;
    list<BasePopupLayer*> _seqPopupList;
};

#endif /* defined(__poker__UIPopupManager__) */
