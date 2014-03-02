//
//  AbstractWorkerThread.h
//
//  Created by zhouyan on 2013-01-08.
//

#ifndef __WORKER_THREAD_H__
#define __WORKER_THREAD_H__

#include "AbstractThread.h"
#include "Cloneable.h"
#include "BlockingQueue.h"

class AbstractWorkerThread : public AbstractThread {
	friend class AbstractWorkerThreadManager;

public:
	explicit AbstractWorkerThread();
	virtual ~AbstractWorkerThread() = 0;

	void run();
    void add(Cloneable* message);

protected:
	virtual void init() = 0;
	virtual bool processMessage(Cloneable* message) = 0;

private:
	BlockingQueue<Cloneable*> queue;
};

#endif  // __WORKER_THREAD_H__
