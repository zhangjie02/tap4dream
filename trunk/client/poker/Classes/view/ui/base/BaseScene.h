//
//  BaseScene.h
//  poker
//
//  Created by xiaoxiangzi on 13-11-15.
//
//

#ifndef __poker__BaseScene__
#define __poker__BaseScene__

#include "Scene.h"

class UIPopupManager;
class BaseUILayer;
class WaitingLayer;
class ResourceKey;

class BaseScene : public Scene {
    
public:
    void showWaitingLayer();
    void hideWaitingLayer();
protected:
    BaseScene();
    virtual bool init();
    virtual ~BaseScene();
protected:
    BaseUILayer* getLogicLayer();
    BaseUILayer* getMainUILayer();
    BaseUILayer* getPopupLayer();
    BaseUILayer* getMessageLayer();
    BaseUILayer* getSystemMessageLayer();
private:
    BaseUILayer* _logicLayer;
    BaseUILayer* _mainUILayer;
    BaseUILayer* _popupLayer;
    BaseUILayer* _messageLayer;
    BaseUILayer* _systemMessageLayer;
    
    WaitingLayer* _waitingLayer;
    friend class UIPopupManager;
    int _waitingCount;
protected:
    ResourceKey* _resKey;
};

#endif /* defined(__poker__BaseScene__) */
