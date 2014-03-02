//
//  NumberChangableNode.h
//  poker
//
//  Created by xiaoxiangzi on 14-1-2.
//
//

#ifndef __poker__NumberChangableNode__
#define __poker__NumberChangableNode__

#include "Node.h"
using namespace cocos2d;
using namespace std;

class NumberChangableNode : public CCNodeExt {
    
public:
    CREATE_FUNC(NumberChangableNode);
    virtual void setValue(int64_t value, bool showAnim = false);
    virtual void setValue(string valueStr, bool showAnim = false);
    virtual int64_t getValue();
    virtual void update(float dt);
    void setMinValue(int64_t minValue);
    void setMaxValue(int64_t maxValue);
    int64_t getDisplayValue();
    bool hasReachTargetValue();
    NumberChangableNode();
    virtual ~NumberChangableNode();
    
    void setUpdateLabelCallback(CCObject* target, SEL_CallFuncO callback);
    void setSpeedRate(float rate);
protected:
    virtual void updateLabel(int64_t value);
    bool init();
private:
    void updateDisplayValue(int64_t value);
    
    void addLabel(CCLabelProtocol* labelProtocol, CCNode* labelNode);
    
    int64_t _currentDisplayValue;
    int64_t _targetValue;
    int64_t _updateStepValue;
    
    bool _showAnimation;
    
    int64_t _minValue;
    int64_t _maxValue;
    float _speedRate;
    
    CCObject* _target;
    SEL_CallFuncO _callback;
};

#endif /* defined(__poker__NumberChangableNode__) */
