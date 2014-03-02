//
//  FileCache.cpp
//  poker
//
//  Created by xiaoxiangzi on 13-12-11.
//
//

#include "FileCache.h"
#include "SlotFile.h"
#include "FileLoader.h"

FileCache::FileCache() {}

FileCache::~FileCache() {
    for (map<string, File*>::iterator iter = _filesMap.begin(); iter != _filesMap.end(); iter++) {
        File* file = iter->second;
        CC_SAFE_RELEASE_NULL(file);
    }
    _filesMap.clear();
}

void FileCache::handleLoadFileAsycResult(cocos2d::CCObject *result) {
    FileLoaderAsyncResult* fileResult = dynamic_cast<FileLoaderAsyncResult*>(result);
    File* file = fileResult->getFile();
    string path = fileResult->getPath();
    CCObject* target = fileResult->getTarget();
    SEL_CallFuncO selector = fileResult->getSelector();
    addFileToCache(file, path);
    file->autorelease();
    if (target && selector) {
        (target->*selector)(file);
    }
    
}

void FileCache::addFileToCache(File *file, const string &path) {
    map<string, File*>::iterator iter = _filesMap.find(path);
    bool needInsert = true;
    if (iter != _filesMap.end()) {
        File* originalFile = iter->second;
        if (file != originalFile) {
            _filesMap.erase(iter);
            CC_SAFE_RELEASE_NULL(originalFile);
        } else {
            needInsert = false;
        }
    }
    
    if (needInsert) {
        _filesMap.insert(make_pair(path, file));
        CC_SAFE_RETAIN(file);
    }
}

FileCache* FileCache::getInstance() {
    static FileCache cache;
    return &cache;
}

File* FileCache::addFile(const char *path) {
    string fullpath = CCFileUtils::sharedFileUtils()->fullPathForFilename(path);
    map<string, File*>::iterator iter = _filesMap.find(fullpath);
    
    if (iter != _filesMap.end()) {
        return iter->second;
    }
    
    File* file = File::create();
    file->loadFile(fullpath);
    addFileToCache(file, fullpath);
    
    return file;
}

void FileCache::addFileAsyc(const char *path, cocos2d::CCObject *target, SEL_CallFuncO selector) {
    string fullpath = CCFileUtils::sharedFileUtils()->fullPathForFilename(path);
    map<string, File*>::iterator iter = _filesMap.find(fullpath);
    
    if (iter != _filesMap.end()) {
        File* file = iter->second;
        if (target && selector) {
            (target->*selector)(file);
        }
        
        return;
    }
    
    FileLoaderAsyncCommand command;
    command.setPath(fullpath);
    command.setTarget(target);
    command.setSelector(selector);
    ThreadManager::getInstance()->sendMessageFromGLThread(ThreadName::FileLoader, &command);
}

void FileCache::removeFile(const char *path) {
    string fullpath = CCFileUtils::sharedFileUtils()->fullPathForFilename(path);
    map<string, File*>::iterator iter = _filesMap.find(fullpath);
    File* file = NULL;
    if (iter != _filesMap.end()) {
        file = iter->second;
        _filesMap.erase(iter);
        CC_SAFE_RELEASE_NULL(file);
    }
}


