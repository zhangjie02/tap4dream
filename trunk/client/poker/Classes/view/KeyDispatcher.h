#ifndef KEYDISPATCHER_H_
#define KEYDISPATCHER_H_

#include "cocos2d.h"
#include <vector>
#include <list>
#include "BaseUILayer.h"

using namespace std;

USING_NS_CC;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

class KeyDispatcher : public CCObject, public CCKeypadDelegate {
public:
	static KeyDispatcher* getInstance() {
		static KeyDispatcher instance;
		return &instance;
	}

public:

	// 按键响应,从front到end, 顺序根据basiclayer的onstart和onend来保证
    virtual void keyBackClicked();
    virtual void keyMenuClicked();

    void registerKeyBack(BaseUILayer* layer);
    void unregisterKeyBack(BaseUILayer* layer);

	void clear();

private:
	KeyDispatcher();

private:
	list<BaseUILayer*>* _layerList;
};

#endif


#endif /* KEYDISPATCHER_H_ */
