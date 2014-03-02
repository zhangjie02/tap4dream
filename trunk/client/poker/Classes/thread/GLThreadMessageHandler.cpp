#include "GLThreadMessageHandler.h"
#include "cocos2d.h"
#include "FileLoader.h"
#include "FileCache.h"
#include "LoadAssets.h"
using namespace cocos2d;

#define MODULE_LOG_TAG "GLThreadMessageHandler"

void GLThreadMessageHandler::processMessage(Cloneable* message) {
	string name = message->getName();
	CCLOG("GLThread Message: %s", name.c_str());

    if (name == FileLoaderAsyncResult::NAME) {
        FileCache::getInstance()->handleLoadFileAsycResult(dynamic_cast<CCObject*>(message));
    } else if(name == AssetsLoaderAsyncResult::NAME) {
        //SlotAssetsMgr::getInstance()->handleLoadAssetsAsycResult(message);
    }
}
