//
//  NumberChangableNode.cpp
//  poker
//
//  Created by xiaoxiangzi on 14-1-2.
//
//

#include "NumberChangableNode.h"
#include "LayoutUtil.h"
#include "StringConverter.h"

NumberChangableNode::NumberChangableNode() :
_currentDisplayValue(0),
_updateStepValue(0),
_showAnimation(false),
_minValue(INT64_MIN),
_maxValue(INT64_MAX),
_targetValue(0),
_target(NULL),
_callback(NULL),
_speedRate(1) {}

NumberChangableNode::~NumberChangableNode() {}

bool NumberChangableNode::init() {
    CCNodeExt::init();
    scheduleUpdate();
    return true;
}

void NumberChangableNode::setValue(int64_t value, bool showAnim) {
    int64_t newTargetValue = value;
    if (newTargetValue < _minValue) {
        newTargetValue = _minValue;
    } else if (newTargetValue > _maxValue) {
        newTargetValue = _maxValue;
    }

    _targetValue = newTargetValue;
    _showAnimation = showAnim;
    if (_showAnimation) {
        if (_currentDisplayValue != _targetValue) {
            _updateStepValue = abs(_targetValue - _currentDisplayValue);
            if (_updateStepValue == 0) {
                _updateStepValue = 1;
            }
            
            if (_targetValue < _currentDisplayValue) {
                _updateStepValue = -_updateStepValue;
            }
        }
    } else {
        updateDisplayValue(_targetValue);
    }
}

int64_t NumberChangableNode::getValue() {
    return _targetValue;
}

void NumberChangableNode::updateDisplayValue(int64_t value) {
    if (value == _currentDisplayValue) {
        return;
    }
    
    _currentDisplayValue = value;
    updateLabel(_currentDisplayValue);
}

void NumberChangableNode::update(float dt) {
    if (!_showAnimation) {
        return;
    }
    
    int64_t value = _currentDisplayValue;
    int64_t deltaValue = _updateStepValue * dt * _speedRate;
    
    if (_updateStepValue > 0) {
        deltaValue = deltaValue == 0 ? 1 : deltaValue;
    } else if (_updateStepValue < 0) {
        deltaValue = deltaValue == 0 ? -1 : deltaValue;
    }
    
    value += deltaValue;
    if (_updateStepValue > 0) {
        if (value >= _targetValue) {
            value = _targetValue;
            _showAnimation = false;
        }
    } else {
        if (value <= _targetValue) {
            value = _targetValue;
            _showAnimation = false;
        }
    }
    updateDisplayValue(value);
}

void NumberChangableNode::setMaxValue(int64_t maxValue) {
    _maxValue = maxValue;
}

void NumberChangableNode::setMinValue(int64_t minValue) {
    _minValue = minValue;
}

int64_t NumberChangableNode::getDisplayValue() {
    return _currentDisplayValue;
}

bool NumberChangableNode::hasReachTargetValue() {
    return getDisplayValue() == getValue();
}

void NumberChangableNode::updateLabel(int64_t value) {
    if (_target && _callback) {
        (_target->*_callback)((CCObject*)&value);
    }
}

void NumberChangableNode::setUpdateLabelCallback(cocos2d::CCObject *target, SEL_CallFuncO callback) {
    _target = target;
    _callback = callback;
}

void NumberChangableNode::setValue(string valueStr, bool showAnim) {
    int64_t value = StringConverter::toInt64(valueStr);
    setValue(value, showAnim);
}

void NumberChangableNode::setSpeedRate(float rate) {
    _speedRate = rate;
}


