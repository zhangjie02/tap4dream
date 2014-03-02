#include "KeyDispatcher.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

KeyDispatcher::KeyDispatcher() {
	_layerList = new list<BaseUILayer*>();
}

void KeyDispatcher::keyBackClicked(){
//    CCLOG("key back");
	for(list<BaseUILayer*>::iterator iter = _layerList->begin(); iter != _layerList->end(); iter++) {
		if((*iter)->doKeyBackClicked()) {
			return;
		}
	}
    
}

void KeyDispatcher::keyMenuClicked() {
	for(list<BaseUILayer*>::iterator iter = _layerList->begin(); iter != _layerList->end(); iter++) {
		if((*iter)->doKeyMenuClicked()) {
			return;
		}
	}
}

void KeyDispatcher::registerKeyBack(BaseUILayer* layer) {
//    CCLOG("key back:register");
	_layerList->push_front(layer);
}

void KeyDispatcher::unregisterKeyBack(BaseUILayer* layer) {
	for(list<BaseUILayer*>::iterator iter = _layerList->begin(); iter != _layerList->end(); iter++) {
		if((*iter) == layer) {
			_layerList->erase(iter);
			break;
		}
	}
}

void KeyDispatcher::clear() {
	_layerList->clear();
}
#endif
