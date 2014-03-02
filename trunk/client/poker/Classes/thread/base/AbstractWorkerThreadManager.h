//
//  AbstractWorkerThreadManager.h
//
//  Created by zhouyan on 2013-01-08.
//

#ifndef __ABSTRACT_THREAD_MANAGER_H__
#define __ABSTRACT_THREAD_MANAGER_H__

#include <map>
#include <string>

#include "AbstractWorkerThread.h"
#include "AbstractGLThreadMessageHandler.h"

using namespace std;

class AbstractWorkerThreadManager {
public:
	AbstractWorkerThreadManager();
	virtual ~AbstractWorkerThreadManager() = 0;

	bool createWorkerThread(const string& name);
	void startWorkerThread(const string& name);
	void disposeWorkerThread(const string& name);

	void sendMessageFromGLThread(const string& name, Cloneable* message);
	void sendMessageToGLThread(Cloneable* message);

    void setGLThreadMessageHandler(AbstractGLThreadMessageHandler* glThreadHandler);
	void handleMessageInGLThread();

    void reset();
    bool isGLThreadChanged();
protected:
	virtual AbstractWorkerThread* createWorkerThreadImpl(const string& name) = 0;

private:
	map<string, AbstractWorkerThread*> threads;
	pthread_t glThread;
	BlockingQueue<Cloneable*> glThreadQueue;
	AbstractGLThreadMessageHandler* glThreadMessageHandler;

	bool ensureGLThread();
	AbstractWorkerThread* getWorkerThread(const string& name);
};

#endif  // __ABSTRACT_THREAD_MANAGER_H__
