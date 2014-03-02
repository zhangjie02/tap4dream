//
//  ObserverUtil.h
//  poker
//
//  Created by xiaoxiangzi on 13-12-20.
//
//

#ifndef __poker__ObserverUtil__
#define __poker__ObserverUtil__

#include "cocos2d.h"
using namespace cocos2d;

class ObserverUtil {
    
public:
    static void unregisterObservers(CCNode* node);
private:
    ObserverUtil() {}
    ObserverUtil(const ObserverUtil&);
    ObserverUtil& operator=(const ObserverUtil&);
};

#endif /* defined(__poker__ObserverUtil__) */
