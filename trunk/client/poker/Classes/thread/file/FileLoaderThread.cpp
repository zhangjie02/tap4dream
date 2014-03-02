//
//  FileLoaderThread.cpp
//  poker
//
//  Created by xiaoxiangzi on 13-12-11.
//
//

#include "FileLoaderThread.h"
#include "FileLoader.h"
#include "SlotFile.h"
void FileLoaderThread::init() {}

bool FileLoaderThread::processMessage(Cloneable *message) {
    CCThread thread;
    thread.createAutoreleasePool();
    
    FileLoaderAsyncCommand* command = dynamic_cast<FileLoaderAsyncCommand*>(message);
    string path = CCFileUtils::sharedFileUtils()->fullPathForFilename(command->getPath().c_str());
    
    File* file = new File();
    file->loadFileAsync(path);
    
    FileLoaderAsyncResult result;
    result.setFile(file);
    result.setPath(command->getPath());
    result.setSelector(command->getSelector());
    result.setTarget(command->getTarget());
    ThreadManager::getInstance()->sendMessageToGLThread(&result);
    
    return false;
}
