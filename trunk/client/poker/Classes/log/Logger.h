//
//  Logger.h
//  poker
//
//  Created by jayson on 14-1-20.
//
//

#ifndef __poker__Logger__
#define __poker__Logger__

#include <iostream>
#include "cocos2d.h"
#include <string>

USING_NS_CC;
using namespace std;

namespace Logger {
    void log(string tag, CCNode* node);
};

#endif /* defined(__poker__Logger__) */
