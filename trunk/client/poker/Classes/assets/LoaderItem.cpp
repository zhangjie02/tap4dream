//
//  LoaderItem.cpp
//  poker
//
//  Created by jayson on 13-12-5.
//
//

#include "LoaderItem.h"

LoaderItem::LoaderItem(AssetsLoader* pLoader, int pServerVersion,  CCObject* pTarget, SEL_CallFunc pSuccessCallFunc, SEL_CallFunc pFailedCallFunc) {
    loader = pLoader;
    serverVersion = pServerVersion;
    
    _target = pTarget;
    _successCallFunc = pSuccessCallFunc;
    _failedCallFunc = pFailedCallFunc;
}

LoaderItem::~LoaderItem() {
    delete loader;
}

void LoaderItem::success() const {
    if(_target != NULL && _successCallFunc != NULL) {
        (_target->*_successCallFunc)();
    }
}

void LoaderItem::fail() const {
    if(_target != NULL && _successCallFunc != NULL) {
        (_target->*_failedCallFunc)();
    }
}

void LoaderItem::setInvalid() {
    _target = NULL;
}

CCObject* LoaderItem::getTarget() {
    return _target;
}