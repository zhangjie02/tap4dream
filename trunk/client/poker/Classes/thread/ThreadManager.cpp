#include "ThreadManager.h"
#include "GLThreadMessageHandler.h"
//#include "HttpClientThread.h"
#include "FileLoaderThread.h"
#include "AssetsLoaderThread.h"

ThreadManager* ThreadManager::getInstance() {
    static ThreadManager instance;
    return &instance;
}

ThreadManager::ThreadManager() {
    static GLThreadMessageHandler glThreadHandler;
    this->setGLThreadMessageHandler(&glThreadHandler);
}

AbstractWorkerThread* ThreadManager::createWorkerThreadImpl(const string& name) {
    if (name == ThreadName::FileLoader) {
        return new FileLoaderThread();
    } else if (name == ThreadName::AssetsLoader) {
        return new AssetsLoaderThread();
    }
    
	return NULL;
}

void ThreadManager::update() {
	handleMessageInGLThread();
}
