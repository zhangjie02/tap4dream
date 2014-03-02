#include "FacebookUtil.h"
#include "FacebookCallbackImpl.h"
#include "cocos2d.h"
#include "FacebookEventDef.h"
USING_NS_CC;

void FacebookCallbackImpl::onLoginSuccess() {
	CCLOG("onLoginSuccess");

	// note: write your client code below

	FacebookUtil* facebookUtil = FacebookUtil::getInstance();
	string token = facebookUtil->getToken();
	CCLOG("token: %s", token.c_str());

	string id = facebookUtil->getId();
	CCLOG("id: %s", id.c_str());

	string name = facebookUtil->getName();
	CCLOG("name: %s", name.c_str());

	string gender = facebookUtil->getGender();
	CCLOG("gender: %s", gender.c_str());

	string pictureUrl = facebookUtil->getPictureUrl();
	CCLOG("pictureUrl: %s", pictureUrl.c_str());

	vector<string> ids = facebookUtil->getFriendIds();
	vector<string> names = facebookUtil->getFriendNames();
	vector<string> genders = facebookUtil->getFriendGenders();
	vector<string> pictureUrls = facebookUtil->getFriendPictureUrls();
	CCLOG("friend data:");
	for (int i = 0; i < ids.size(); i++) {
		CCLOG("%d id: %s, name: %s, gender: %s, pictureUrl: %s", i, ids[i].c_str(), names[i].c_str(), genders[i].c_str(), pictureUrls[i].c_str());;
	}

    CCNotificationCenter::sharedNotificationCenter()->postNotification(FacebookEventDef::SLOT_FACEBOOK_ONLOGIN_SUCCESS);
}

void FacebookCallbackImpl::onLoginFailed() {
	CCLOG("onLoginFailed");

	// note: write your client code below

    CCNotificationCenter::sharedNotificationCenter()->postNotification(FacebookEventDef::SLOT_FACEBOOK_ONLOGIN_FAILED);
}

void FacebookCallbackImpl::onSessionClosed() {
	CCLOG("onSessionClosed");

	// note: write your client code below

    CCNotificationCenter::sharedNotificationCenter()->postNotification(FacebookEventDef::SLOT_FACEBOOK_ONSESSION_CLOSED);
}
