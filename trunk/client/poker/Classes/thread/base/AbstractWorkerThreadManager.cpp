#include "AbstractWorkerThreadManager.h"

#define MODULE_LOG_TAG "AbstractWorkerThreadManager"
#include "cocos2d.h"

AbstractWorkerThreadManager::AbstractWorkerThreadManager() : glThreadQueue(), threads() {
	glThread = pthread_self();
}

AbstractWorkerThreadManager::~AbstractWorkerThreadManager() {
}

AbstractWorkerThread* AbstractWorkerThreadManager::getWorkerThread(const string& name) {
	CCAssert(ensureGLThread(), "You should use AbstractWorkerThreadManager only in gl-thread! (getWorkerThread)");

	map<string, AbstractWorkerThread*>::iterator it = threads.find(name);
	if (it == threads.end()) {
		return NULL;
	} else {
		return it->second;
	}
}

bool AbstractWorkerThreadManager::createWorkerThread(const string& name) {
	CCLOG("create worker thread: %s", name.c_str());
    CCAssert(ensureGLThread(), "You should use AbstractWorkerThreadManager only in gl-thread! (createWorkerThread)");

	AbstractWorkerThread* thread = getWorkerThread(name);
	if (thread != NULL) {
		return false;
	}

	AbstractWorkerThread* workerThread = createWorkerThreadImpl(name);
	if (workerThread == NULL) {
		CCLOG("Cannot create new thread: %s", name.c_str());
	}
	threads.insert(pair<string, AbstractWorkerThread*>(name, workerThread));
	return true;
}

void AbstractWorkerThreadManager::startWorkerThread(const string& name) {
	CCLOG("start worker thread: %s", name.c_str());
    CCAssert(ensureGLThread(), "You should use AbstractWorkerThreadManager only in gl-thread! (startWorkerThread)");

	AbstractWorkerThread* thread = getWorkerThread(name);
	if (thread != NULL) {
		thread->start();
	}
}

void AbstractWorkerThreadManager::disposeWorkerThread(const string& name) {
	CCLOG("dispose worker thread: %s", name.c_str());
    CCAssert(ensureGLThread(), "You should use AbstractWorkerThreadManager only in gl-thread! (disposeWorkerThread)");

	AbstractWorkerThread* thread = getWorkerThread(name);
	if (thread != NULL) {
		delete thread;
	}
}

bool AbstractWorkerThreadManager::ensureGLThread() {
	pthread_t current = pthread_self();
	// The pthread_equal(pthread_t t1, pthread_t t2) function shall return a non-zero value if t1 and t2 are equal;
	return pthread_equal(glThread, current) != 0;
}

void AbstractWorkerThreadManager::sendMessageFromGLThread(const string& name, Cloneable* message) {
    CCAssert(ensureGLThread(), "You should use AbstractWorkerThreadManager only in gl-thread! (sendMessageFromGLThread)");

	AbstractWorkerThread* thread = getWorkerThread(name);
	if (thread != NULL) {
		thread->add(message);
	}
}

void AbstractWorkerThreadManager::sendMessageToGLThread(Cloneable* message) {
	CCLOG("send message to gl-thread, content: %s", message->getName().c_str());
	glThreadQueue.add(message->clone());
}

void AbstractWorkerThreadManager::setGLThreadMessageHandler(AbstractGLThreadMessageHandler* glThreadHandler) {
    this->glThreadMessageHandler = glThreadHandler;
}

void AbstractWorkerThreadManager::handleMessageInGLThread() {
    CCAssert(ensureGLThread(), "You should use AbstractWorkerThreadManager only in gl-thread! (handleMessageInGLThread)");

	while (glThreadQueue.size() > 0) {
		Cloneable* message = glThreadQueue.remove();
		CCLOG("dispatch message: %s", message->getName().c_str());
        if (glThreadMessageHandler != NULL) {
            glThreadMessageHandler->processMessage(message);
        } else {
            CCLOG("Cannot find GLThreadMassageHandler!");
        }
        delete message;
	}
}

void AbstractWorkerThreadManager::reset() {
    glThread = pthread_self();
}

bool AbstractWorkerThreadManager::isGLThreadChanged() {
    return !ensureGLThread();
}
