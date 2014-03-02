//
//  LoadAssets.cpp
//  poker
//
//  Created by jayson on 13-12-19.
//
//

#include "LoadAssets.h"

const char* AssetsLoaderAsyncCommand::NAME = "AssetsLoaderAsyncCommand";

AssetsLoaderAsyncCommand::AssetsLoaderAsyncCommand() : Cloneable(AssetsLoaderAsyncCommand::NAME),
_url(""),
_saveDir("")
{}

Cloneable* AssetsLoaderAsyncCommand::clone() {
    return new AssetsLoaderAsyncCommand(*this);
}

const char* AssetsLoaderAsyncResult::NAME = "AssetsLoaderAsyncResult";

AssetsLoaderAsyncResult::AssetsLoaderAsyncResult() : Cloneable(AssetsLoaderAsyncResult::NAME){}

Cloneable* AssetsLoaderAsyncResult::clone() {
    return new AssetsLoaderAsyncResult(*this);
}
