#include "AbstractThread.h"

#define MODULE_LOG_TAG "AbstractThread"
#include "cocos2d.h"

USING_NS_CC;

AbstractThread::AbstractThread() : started(false) {}

AbstractThread::~AbstractThread() {}

static void* runThread(void* arg) {
	AbstractThread* thread = static_cast<AbstractThread*>(arg);
	thread->run();
	// should not call AbstractThread::getTid(), because this object might have been deleted
	pthread_t self = pthread_self();
	int result = pthread_detach(self);
	if (result != 0) {
		CCLOG("detach thread failed: %d", result);
	}
	return NULL;
}

bool AbstractThread::start() {
	if (started) {
		CCLOG("thread has already started");
		return false;
	}
	int result = pthread_create(&tid, NULL, runThread, this);
	if (result != 0) {
		CCLOG("create thread failed: %d", result);
		return false;
	}
	started = true;
	CCLOG("create thread successfully");
	return true;
}

bool AbstractThread::join() {
	int result = pthread_join(tid, NULL);
	if (result != 0) {
		CCLOG("join thread failed: %d", result);
		return false;
	}
	return true;
}

pthread_t AbstractThread::getTid() {
	return tid;
}
