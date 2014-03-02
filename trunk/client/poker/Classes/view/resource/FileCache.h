//
//  FileCache.h
//  poker
//
//  Created by xiaoxiangzi on 13-12-11.
//
//

#ifndef __poker__FileCache__
#define __poker__FileCache__

#include <iostream>
#include <map>
#include "cocos2d.h"
using namespace cocos2d;
using namespace std;

class File;

class FileCache {
public:
    static FileCache* getInstance();
    File* addFile(const char* path);
    void addFileAsyc(const char* path, CCObject* target, SEL_CallFuncO selector);
    void handleLoadFileAsycResult(CCObject* result);
    void removeFile(const char* path);
private:
    FileCache();
    FileCache(const FileCache&);
    FileCache& operator=(const FileCache&);
    ~FileCache();
    
    void addFileToCache(File* file, const string& path);
    
    map<string, File*> _filesMap;
};

#endif /* defined(__poker__FileCache__) */
