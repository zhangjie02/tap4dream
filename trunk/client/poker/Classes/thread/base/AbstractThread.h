//
//  AbstractThread.h
//
//  Created by zhouyan on 2013-01-06.
//
//  Note: the thread will detach itself automatically after the work is done.
//

#ifndef __ABSTRACT_THREAD_H__
#define __ABSTRACT_THREAD_H__

#include <pthread.h>

class AbstractThread {
public:
	AbstractThread();
	virtual ~AbstractThread() = 0;

	bool start();
	bool join();
	pthread_t getTid();

	virtual void run() = 0;

private:
	pthread_t tid;
	bool started;
};

#endif  // __ABSTRACT_THREAD_H__
