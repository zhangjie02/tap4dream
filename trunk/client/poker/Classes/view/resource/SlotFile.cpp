//
//  File.cpp
//  poker
//
//  Created by xiaoxiangzi on 13-12-5.
//
//

#include "SlotFile.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/CCFileUtilsAndroid.h"
#endif

// Class FileReader

FileReader* FileReader::create() {
    FileReader* reader = new FileReader;
    reader->autorelease();
    return reader;
}

FileReader::FileReader() : _curPos(0), _file(NULL) {}

void FileReader::open(File* file) {
    CC_SAFE_RETAIN(file);
    CC_SAFE_RELEASE_NULL(_file);
    _file = file;
}

void FileReader::close() {
    CC_SAFE_RELEASE_NULL(_file);
    _curPos = 0;
}

FileReader::~FileReader() {
    close();
}

int FileReader::read(unsigned char *buf, int len) {
    int readCount = _file->readBytes(buf, _curPos, len);
    if (readCount < 0) {
        return -1;
    }
    _curPos += readCount;
    return readCount;
}

int64_t FileReader::seek(int64_t offset, int whence) {
    int64_t beginPos = 0;
    if (whence == SEEK_CUR) {
        beginPos = _curPos;
    } else if (whence == SEEK_SET) {
        beginPos = 0;
    } else if (whence == SEEK_END) {
        beginPos = _file->getSize();
    } else {
        return -1;
    }
    
    int pos = beginPos + offset;
    if (!_file->isValidPos(pos)) {
        return -1;
    }
    
    _curPos = pos;
    return _curPos;
}

size_t FileReader::getSize() const {
    return _file->getSize();
}

// Class File
File::File() : _buffer(NULL), _fullpath(""), _size(0) {}

File::~File() {
    CC_SAFE_DELETE_ARRAY(_buffer);
    _size = 0;
    _fullpath = "";
}

File* File::create() {
    File* file = new File();
    file->autorelease();
    return file;
}

void File::loadFile(const string &filePath) {
    string fullpath = CCFileUtils::sharedFileUtils()->fullPathForFilename(filePath.c_str());
    if (fullpath == _fullpath) {
        return;
    }
    CC_SAFE_DELETE_ARRAY(_buffer);
    _fullpath = fullpath;
    _size = 0;
    _buffer = CCFileUtils::sharedFileUtils()->getFileData(_fullpath.c_str(), "rb", &_size);
}

void File::loadFileAsync(const string &filePath) {
    string fullpath = CCFileUtils::sharedFileUtils()->fullPathForFilename(filePath.c_str());
    if (fullpath == _fullpath) {
        return;
    }
    CC_SAFE_DELETE_ARRAY(_buffer);
    _fullpath = fullpath;
    _size = 0;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    CCFileUtilsAndroid *fileUitls = (CCFileUtilsAndroid*)CCFileUtils::sharedFileUtils();
    _buffer = fileUitls->getFileDataForAsync(_fullpath.c_str(), "rb", &_size);
#else
    _buffer = CCFileUtils::sharedFileUtils()->getFileData(_fullpath.c_str(), "rb", &_size);
#endif
    
}

unsigned long File::getSize() const {
    return _size;
}

const unsigned char* File::getContent() const {
    return _buffer;
}

bool File::isValidPos(int64_t pos) const {
    return (pos >= 0) && (pos < _size);
}

int File::readBytes(unsigned char *buf, int64_t offset, int size) const {
    if (!isValidPos(offset)) {
        return -1;
    }
    
    int count = 0;
    for (int64_t i = offset; (i < _size) && (count < size); i++) {
        buf[count] = _buffer[i];
        count++;
    }
    
    return count;
}

const string& File::getPath() const {
    return _fullpath;
}
