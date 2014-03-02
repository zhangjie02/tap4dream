//
//  AssetsLoaderThread.h
//  poker
//
//  Created by jayson on 13-12-19.
//
//

#ifndef __poker__AssetsLoaderThread__
#define __poker__AssetsLoaderThread__

#include <iostream>
#include "AbstractWorkerThread.h"

class AssetsLoaderThread : public AbstractWorkerThread {
public:
    void init();
	bool processMessage(Cloneable* message);
};

#endif /* defined(__poker__AssetsLoaderThread__) */
