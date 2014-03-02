//
//  FileLoader.cpp
//  poker
//
//  Created by xiaoxiangzi on 13-12-11.
//
//

#include "FileLoader.h"

const char* FileLoaderAsyncCommand::NAME = "FileLoaderAsyncCommand";

FileLoaderAsyncCommand::FileLoaderAsyncCommand() : Cloneable(FileLoaderAsyncCommand::NAME),
_path(""),
_target(NULL),
_selector(NULL) {}

Cloneable* FileLoaderAsyncCommand::clone() {
    return new FileLoaderAsyncCommand(*this);
}

const char* FileLoaderAsyncResult::NAME = "FileLoaderAsyncResult";

FileLoaderAsyncResult::FileLoaderAsyncResult() : Cloneable(FileLoaderAsyncResult::NAME),
_selector(NULL),
_file(NULL),
_path(""),
_target(NULL) {}

Cloneable* FileLoaderAsyncResult::clone() {
    return new FileLoaderAsyncResult(*this);
}
