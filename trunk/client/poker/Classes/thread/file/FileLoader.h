//
//  FileLoader.h
//  poker
//
//  Created by xiaoxiangzi on 13-12-11.
//
//

#ifndef __poker__FileLoader__
#define __poker__FileLoader__

#include <iostream>
#include "cocos2d.h"
#include "ThreadManager.h"
#include <string>
using namespace std;
using namespace cocos2d;

class File;

class FileLoaderAsyncCommand : public Cloneable {
    CC_SYNTHESIZE(string, _path, Path);
    CC_SYNTHESIZE(CCObject*, _target, Target);
    CC_SYNTHESIZE(SEL_CallFuncO, _selector, Selector);
public:
    static const char* NAME;
    FileLoaderAsyncCommand();
    Cloneable* clone();
};

class FileLoaderAsyncResult : public Cloneable, public CCObject {
    CC_SYNTHESIZE(string, _path, Path);
    CC_SYNTHESIZE(CCObject*, _target, Target);
    CC_SYNTHESIZE(SEL_CallFuncO, _selector, Selector);
    CC_SYNTHESIZE(File*, _file, File);
    CC_SYNTHESIZE(string*, _redirectUrl, RedirectUrl);
public:
    static const char* NAME;
    FileLoaderAsyncResult();
    Cloneable* clone();
};

#endif /* defined(__poker__FileLoader__) */
