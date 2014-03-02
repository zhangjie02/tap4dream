//
//  MsgDialogLayer.h
//  poker
//
//  Created by 苏 汝杰 on 14-2-20.
//
//

#ifndef __poker__MsgDialogLayer__
#define __poker__MsgDialogLayer__

#include <iostream>
#include "BaseUILayer.h"
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class MsgDialogLayer : public BaseUILayer {
    
public:
    
    CREATE_FUNC(MsgDialogLayer);
    
    ~MsgDialogLayer();
    
    bool init();
    
    void setMsg(string msg);
    
    
private:
    
    MsgDialogLayer();
    
    void closeDialog();
    
    
    
    
};

#endif /* defined(__poker__MsgDialogLayer__) */
