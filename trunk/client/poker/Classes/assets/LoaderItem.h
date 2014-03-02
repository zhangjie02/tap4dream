//
//  LoaderItem.h
//  poker
//
//  Created by jayson on 13-12-5.
//
//

#ifndef __poker__LoaderItem__
#define __poker__LoaderItem__

#include <iostream>
#include <string>
#include "AssetsLoader.h"
#include "Callback.h"
#include "cocos2d.h"

USING_NS_CC;

using namespace std;

class LoaderItem {
public:
    LoaderItem(AssetsLoader* pLoader, int serverVersion,  CCObject* target, SEL_CallFunc successCallFunc, SEL_CallFunc failedCallFunc);

    ~LoaderItem();
    
    void success() const;
    
    void fail() const;
    
    void setInvalid();
    
    CCObject* getTarget();
public:
    int serverVersion;
    
    AssetsLoader* loader;
    
    CCObject* _target;
    SEL_CallFunc _successCallFunc;
    SEL_CallFunc _failedCallFunc;
};

#endif /* defined(__poker__LoaderItem__) */
