//
//  CCNodeExt.cpp
//  spacewar
//
//  Created by xiaoxiangzi on 13-5-2.
//
//

#include "Node.h"

CCNodeExt* CCNodeExt::create() {
    CCNodeExt* node = new CCNodeExt;
    node->autorelease();
    return node;
}

CCNodeExt::CCNodeExt() {}
