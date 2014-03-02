//
//  FileLoaderThread.h
//  poker
//
//  Created by xiaoxiangzi on 13-12-11.
//
//

#ifndef __poker__FileLoaderThread__
#define __poker__FileLoaderThread__

#include <iostream>
#include "AbstractWorkerThread.h"
using namespace std;

class FileLoaderThread : public AbstractWorkerThread {
public:
	void init();
	bool processMessage(Cloneable* message);
};

#endif /* defined(__poker__FileLoaderThread__) */
