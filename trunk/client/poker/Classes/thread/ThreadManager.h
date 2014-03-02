#ifndef __THREAD_MANAGER_H__
#define __THREAD_MANAGER_H__

#include "AbstractWorkerThreadManager.h"

namespace ThreadName {
	static const string HttpClient = "HttpClientThread";
    static const string AssetsLoader = "AssetsLoader";
    static const string ZCILoader = "ZCILoader";
    static const string FileLoader = "FileLoader";
}

class ThreadManager : public AbstractWorkerThreadManager {
public:
    static ThreadManager* getInstance();
    void update();

protected:
	AbstractWorkerThread* createWorkerThreadImpl(const string& name);

private:
	ThreadManager();
    ThreadManager(const ThreadManager&);
    ThreadManager& operator=(const ThreadManager&);
};

#endif  // __THREAD_MANAGER_H__
