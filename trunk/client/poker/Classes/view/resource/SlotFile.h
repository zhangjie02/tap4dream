//
//  File.h
//  poker
//
//  Created by xiaoxiangzi on 13-12-5.
//
//

#ifndef __poker__File__
#define __poker__File__

#include <iostream>
#include <stdint.h>
#include "cocos2d.h"
using namespace cocos2d;
using namespace std;

class File;

class FileReader : public CCObject {
public:
    ~FileReader();
    static FileReader* create();
    int read(unsigned char* buf, int len);
    int64_t seek(int64_t offset, int whence);
    size_t getSize() const;
    FileReader();
    void open(File* file);
    void close();
private:
    int64_t _curPos;
    File* _file;
};

class File : public CCObject {
public:
    File();
    ~File();
    static File* create();
    const unsigned char* getContent() const;
    unsigned long getSize() const;
    void loadFile(const string& filePath);
    void loadFileAsync(const string& filePath);
    int readBytes(unsigned char* buf, int64_t offset, int size) const;
    bool isValidPos(int64_t pos) const;
    const string& getPath() const;
private:
    unsigned char* _buffer;
    unsigned long _size;
    string _fullpath;
};


#endif /* defined(__poker__File__) */
