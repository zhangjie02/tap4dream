#include "AbstractWorkerThread.h"
#include "cocos2d.h"

#define MODULE_LOG_TAG "AbstractWorkerThread"

AbstractWorkerThread::AbstractWorkerThread() : queue() {
}

AbstractWorkerThread::~AbstractWorkerThread() {
	// make sure all messages in queue have been deleted
	if (queue.size() > 0) {
		CCLOG("size of queue is not zero when WorkThread is delete, memory leak might happen");
	}
};

void AbstractWorkerThread::run() {
	this->init();
	while (true) {
		Cloneable* message = queue.remove();
		bool finish = processMessage(message);
		delete message;
		if (finish) {
			break;
		}
	}
}

void AbstractWorkerThread::add(Cloneable* message) {
    queue.add(message->clone());
}
