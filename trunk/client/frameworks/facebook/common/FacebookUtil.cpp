#include "FacebookUtil.h"
#include "cocos2d.h"

using namespace cocos2d;

void FacebookUtil::setCallback(FacebookCallback* callback) {
	this->_callback = callback;
}

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include "com_game_facebook_FacebookJNIHelper.h"



FacebookUtil::FacebookUtil() : _callback(NULL), _friendIds(),_friendIdsInstalled(), _friendNames(), _friendGenders(), _friendPictureUrls(), loaded(false) {
}

void FacebookUtil::login() {
	CCLOG("facebook login");

	JniMethodInfo mInfo;
	bool isHave = JniHelper::getStaticMethodInfo(mInfo, "com/game/facebook/FacebookJNIHelper", "login", "()V");

	CCLOG("Have this method: %d", isHave);
	if (isHave) {
		mInfo.env->CallStaticVoidMethod(mInfo.classID, mInfo.methodID);
	}
	mInfo.env->DeleteLocalRef(mInfo.classID);
}

void FacebookUtil::logout() {
	CCLOG("facebook logout");

	JniMethodInfo mInfo;
	bool isHave = JniHelper::getStaticMethodInfo(mInfo, "com/game/facebook/FacebookJNIHelper", "logout", "()V");

	CCLOG("Have this method: %d", isHave);
	if (isHave) {
		mInfo.env->CallStaticVoidMethod(mInfo.classID, mInfo.methodID);
	}
	mInfo.env->DeleteLocalRef(mInfo.classID);
}

string FacebookUtil::getRedirectedUrl(string fbId, bool smallPic) {
	CCLOG("getRedirectedUrl: %s", fbId.c_str());

	JniMethodInfo mInfo;
	bool isHave = JniHelper::getStaticMethodInfo(mInfo, "com/game/facebook/FacebookJNIHelper", "getRedirectedUrl", "(Ljava/lang/String;Z)Ljava/lang/String;");

	CCLOG("Have this method: %d", isHave);
	if (isHave) {
		jstring j_fbId = mInfo.env->NewStringUTF(fbId.c_str());
		jstring j_url;
		j_url = (jstring)mInfo.env->CallStaticObjectMethod(mInfo.classID, mInfo.methodID, j_fbId, smallPic);
		mInfo.env->DeleteLocalRef(mInfo.classID);
		mInfo.env->DeleteLocalRef(j_fbId);
		string ret = mInfo.env->GetStringUTFChars(j_url, NULL);
		mInfo.env->DeleteLocalRef(j_url);
		return ret;
	} else {
		return "";
	}
}

bool FacebookUtil::publishFeedDialog(string name, string caption, string description, string link, string pic, string toUserId) {
	CCLOG("publishFeedDialog");

	JniMethodInfo mInfo;
	bool isHave = JniHelper::getStaticMethodInfo(mInfo, "com/game/facebook/FacebookJNIHelper", "publishFeedDialog", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z");

	CCLOG("Have this method: %d", isHave);
	bool result = false;
	if (isHave) {
		jstring j_name = mInfo.env->NewStringUTF(name.c_str());
		jstring j_caption = mInfo.env->NewStringUTF(caption.c_str());
		jstring j_description = mInfo.env->NewStringUTF(description.c_str());
		jstring j_link = mInfo.env->NewStringUTF(link.c_str());
		jstring j_pic = mInfo.env->NewStringUTF(pic.c_str());
		jstring j_toUserId = mInfo.env->NewStringUTF(toUserId.c_str());

		jboolean j_success = (jboolean)mInfo.env->CallStaticBooleanMethod(mInfo.classID, mInfo.methodID, j_name, j_caption, j_description, j_link, j_pic, j_toUserId);
		mInfo.env->DeleteLocalRef(mInfo.classID);

		mInfo.env->DeleteLocalRef(j_name);
		mInfo.env->DeleteLocalRef(j_caption);
		mInfo.env->DeleteLocalRef(j_description);
		mInfo.env->DeleteLocalRef(j_link);
		mInfo.env->DeleteLocalRef(j_pic);
		mInfo.env->DeleteLocalRef(j_toUserId);

		result = static_cast<bool>(j_success);
	}
	CCLOG("open publish feed dialog %s", result ? "success" : "failed");
	return result;
}

const string FacebookUtil::getToken() {
	CCLOG("getToken");

	JniMethodInfo mInfo;
	bool isHave = JniHelper::getStaticMethodInfo(mInfo, "com/game/facebook/FacebookJNIHelper", "getToken", "()Ljava/lang/String;");

	CCLOG("Have this method: %d", isHave);
	if (isHave) {
		jstring j_token;
		j_token = (jstring)mInfo.env->CallStaticObjectMethod(mInfo.classID, mInfo.methodID);
		mInfo.env->DeleteLocalRef(mInfo.classID);
		string ret = mInfo.env->GetStringUTFChars(j_token, NULL);
		mInfo.env->DeleteLocalRef(j_token);
		return ret;
	} else {
		return "";
	}
}

const string FacebookUtil::getId() {
	CCLOG("getId");

	JniMethodInfo mInfo;
	bool isHave = JniHelper::getStaticMethodInfo(mInfo, "com/game/facebook/FacebookJNIHelper", "getId", "()Ljava/lang/String;");

	CCLOG("Have this method: %d", isHave);
	if (isHave) {
		jstring j_id;
		j_id = (jstring)mInfo.env->CallStaticObjectMethod(mInfo.classID, mInfo.methodID);
		mInfo.env->DeleteLocalRef(mInfo.classID);
		string ret = mInfo.env->GetStringUTFChars(j_id, NULL);
		mInfo.env->DeleteLocalRef(j_id);
		return ret;
	} else {
		return "";
	}
}

const string FacebookUtil::getName() {
	CCLOG("getName");

	JniMethodInfo mInfo;
	bool isHave = JniHelper::getStaticMethodInfo(mInfo, "com/game/facebook/FacebookJNIHelper", "getName", "()Ljava/lang/String;");

	CCLOG("Have this method: %d", isHave);
	if (isHave) {
		jstring j_name;
		j_name = (jstring)mInfo.env->CallStaticObjectMethod(mInfo.classID, mInfo.methodID);
		mInfo.env->DeleteLocalRef(mInfo.classID);
		string ret = mInfo.env->GetStringUTFChars(j_name, NULL);
		mInfo.env->DeleteLocalRef(j_name);
		return ret;
	} else {
		return "";
	}
}

const string FacebookUtil::getGender() {
	CCLOG("getGender");

	JniMethodInfo mInfo;
	bool isHave = JniHelper::getStaticMethodInfo(mInfo, "com/game/facebook/FacebookJNIHelper", "getGender", "()Ljava/lang/String;");

	CCLOG("Have this method: %d", isHave);
	if (isHave) {
		jstring j_gender;
		j_gender = (jstring)mInfo.env->CallStaticObjectMethod(mInfo.classID, mInfo.methodID);
		mInfo.env->DeleteLocalRef(mInfo.classID);
		string ret = mInfo.env->GetStringUTFChars(j_gender, NULL);
		mInfo.env->DeleteLocalRef(j_gender);
		return ret;
	} else {
		return "";
	}
}

const string FacebookUtil::getPictureUrl() {
	CCLOG("getPictureUrl");

	JniMethodInfo mInfo;
	bool isHave = JniHelper::getStaticMethodInfo(mInfo, "com/game/facebook/FacebookJNIHelper", "getPictureUrl", "()Ljava/lang/String;");

	CCLOG("Have this method: %d", isHave);
	if (isHave) {
		jstring j_picture_url;
		j_picture_url = (jstring)mInfo.env->CallStaticObjectMethod(mInfo.classID, mInfo.methodID);
		mInfo.env->DeleteLocalRef(mInfo.classID);
		string ret = mInfo.env->GetStringUTFChars(j_picture_url, NULL);
		mInfo.env->DeleteLocalRef(j_picture_url);
		return ret;
	} else {
		return "";
	}
}

const vector<string>& FacebookUtil::getFriendIds() {
	CCLOG("getFriendIds");
	_friendIds.clear();
	JniMethodInfo mInfo;
	bool isHave = JniHelper::getStaticMethodInfo(mInfo, "com/game/facebook/FacebookJNIHelper", "getFriendIds", "()[Ljava/lang/String;");

	CCLOG("Have this method: %d", isHave);
	if (isHave) {
		jobjectArray ids;
		ids = (jobjectArray)mInfo.env->CallStaticObjectMethod(mInfo.classID, mInfo.methodID);
		int length = mInfo.env->GetArrayLength(ids);
		for(int i = 0; i < length; i++) {
			jstring oneId = (jstring)mInfo.env->GetObjectArrayElement(ids, i);
			_friendIds.push_back(mInfo.env->GetStringUTFChars(oneId, NULL));
			mInfo.env->DeleteLocalRef(oneId);
		}
		mInfo.env->DeleteLocalRef(ids);
	}

	mInfo.env->DeleteLocalRef(mInfo.classID);
	return _friendIds;
}

const vector<string>& FacebookUtil::getFriendsInstalled() {
	CCLOG("getFriendsInstalled");
	_friendIdsInstalled.clear();
	JniMethodInfo mInfo;
	bool isHave = JniHelper::getStaticMethodInfo(mInfo, "com/game/facebook/FacebookJNIHelper", "getFriendsInstalled", "()[Ljava/lang/String;");
    
	CCLOG("Have this method: %d", isHave);
	if (isHave) {
		jobjectArray ids;
		ids = (jobjectArray)mInfo.env->CallStaticObjectMethod(mInfo.classID, mInfo.methodID);
		int length = mInfo.env->GetArrayLength(ids);
		for(int i = 0; i < length; i++) {
			jstring oneId = (jstring)mInfo.env->GetObjectArrayElement(ids, i);
			_friendIdsInstalled.push_back(mInfo.env->GetStringUTFChars(oneId, NULL));
			mInfo.env->DeleteLocalRef(oneId);
		}
		mInfo.env->DeleteLocalRef(ids);
	}
    
	mInfo.env->DeleteLocalRef(mInfo.classID);
	return _friendIds;
}

const vector<string>& FacebookUtil::getFriendNames() {
	CCLOG("getFriendNames");
	_friendNames.clear();
	JniMethodInfo mInfo;
	bool isHave = JniHelper::getStaticMethodInfo(mInfo, "com/game/facebook/FacebookJNIHelper", "getFriendNames", "()[Ljava/lang/String;");

	CCLOG("Have this method: %d", isHave);
	if (isHave) {
		jobjectArray names;
		names = (jobjectArray)mInfo.env->CallStaticObjectMethod(mInfo.classID, mInfo.methodID);
		int length = mInfo.env->GetArrayLength(names);
		for(int i = 0; i < length; i++) {
			jstring oneName = (jstring)mInfo.env->GetObjectArrayElement(names, i);
			_friendNames.push_back(mInfo.env->GetStringUTFChars(oneName, NULL));
			mInfo.env->DeleteLocalRef(oneName);
		}
		mInfo.env->DeleteLocalRef(names);
	}

	mInfo.env->DeleteLocalRef(mInfo.classID);
	return _friendNames;
}

const vector<string>& FacebookUtil::getFriendGenders() {
	CCLOG("getFriendGenders");
	_friendGenders.clear();
	JniMethodInfo mInfo;
	bool isHave = JniHelper::getStaticMethodInfo(mInfo, "com/game/facebook/FacebookJNIHelper", "getFriendGenders", "()[Ljava/lang/String;");

	CCLOG("Have this method: %d", isHave);
	if (isHave) {
		jobjectArray genders;
		genders = (jobjectArray)mInfo.env->CallStaticObjectMethod(mInfo.classID, mInfo.methodID);
		int length = mInfo.env->GetArrayLength(genders);
		for(int i = 0; i < length; i++) {
			jstring oneGender = (jstring)mInfo.env->GetObjectArrayElement(genders, i);
			if (oneGender == NULL) {
				_friendGenders.push_back("unknown");
			} else {
				_friendGenders.push_back(mInfo.env->GetStringUTFChars(oneGender, NULL));
				mInfo.env->DeleteLocalRef(oneGender);
			}
		}
		mInfo.env->DeleteLocalRef(genders);
	}

	mInfo.env->DeleteLocalRef(mInfo.classID);
	return _friendGenders;
}

const vector<string>& FacebookUtil::getFriendPictureUrls() {
	CCLOG("getFriendPictureUrls");
	_friendPictureUrls.clear();
	JniMethodInfo mInfo;
	bool isHave = JniHelper::getStaticMethodInfo(mInfo, "com/game/facebook/FacebookJNIHelper", "getFriendPictureUrls", "()[Ljava/lang/String;");

	CCLOG("Have this method: %d", isHave);
	if (isHave) {
		jobjectArray pictureUrls;
		pictureUrls = (jobjectArray)mInfo.env->CallStaticObjectMethod(mInfo.classID, mInfo.methodID);
		int length = mInfo.env->GetArrayLength(pictureUrls);
		for(int i = 0; i < length; i++) {
			jstring onePictureUrl = (jstring)mInfo.env->GetObjectArrayElement(pictureUrls, i);
			_friendPictureUrls.push_back(mInfo.env->GetStringUTFChars(onePictureUrl, NULL));
			mInfo.env->DeleteLocalRef(onePictureUrl);
		}
		mInfo.env->DeleteLocalRef(pictureUrls);
	}

	mInfo.env->DeleteLocalRef(mInfo.classID);
	return _friendPictureUrls;
}

/*
 * Class:     com_game_facebook_FacebookJNIHelper
 * Method:    nativeOnLoginSuccess
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_game_facebook_FacebookJNIHelper_nativeOnLoginSuccess
  (JNIEnv *, jclass) {
	  FacebookUtil::onLoginSuccess();
}

/*
 * Class:     com_game_facebook_FacebookJNIHelper
 * Method:    nativeOnLoginFailed
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_game_facebook_FacebookJNIHelper_nativeOnLoginFailed
  (JNIEnv *, jclass) {
	  FacebookUtil::onLoginFailed();
}

/*
 * Class:     com_game_facebook_FacebookJNIHelper
 * Method:    nativeOnSessionClosed
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_game_facebook_FacebookJNIHelper_nativeOnSessionClosed
  (JNIEnv *, jclass) {
	  FacebookUtil::onSessionClosed();
}

void FacebookUtil::onLoginSuccess() {
	CCLOG("onLoginSuccess");

	FacebookUtil::getInstance()->loaded = true;

	FacebookCallback* callback = FacebookUtil::getInstance()->_callback;
	if (callback != NULL) {
		callback->onLoginSuccess();
	}
}

void FacebookUtil::onLoginFailed() {
	CCLOG("onLoginFailed");

	FacebookCallback* callback = FacebookUtil::getInstance()->_callback;
	if (callback != NULL) {
		callback->onLoginFailed();
	}
}

void FacebookUtil::onSessionClosed() {
	CCLOG("onSessionClosed");

	FacebookCallback* callback = FacebookUtil::getInstance()->_callback;
	if (callback != NULL) {
		callback->onSessionClosed();
	}
}

bool FacebookUtil::isLoaded() {
	return loaded;
}

void FacebookUtil::postAppRequests(string title, string message, string link) {
	CCLOG("postAppRequests");

	JniMethodInfo mInfo;
	bool isHave = JniHelper::getStaticMethodInfo(mInfo, "com/game/facebook/FacebookJNIHelper", "postAppRequests", "(Ljava/lang/String;Ljava/lang/String;)V");

	CCLOG("Have this method: %d", isHave);
	if (isHave) {
		jstring j_title = mInfo.env->NewStringUTF(title.c_str());
		jstring j_message = mInfo.env->NewStringUTF(message.c_str());
		jstring j_link = mInfo.env->NewStringUTF(link.c_str());
		mInfo.env->CallStaticVoidMethod(mInfo.classID, mInfo.methodID, j_title, j_message, j_link);
		mInfo.env->DeleteLocalRef(j_title);
		mInfo.env->DeleteLocalRef(j_message);
		mInfo.env->DeleteLocalRef(j_link);
	}
	mInfo.env->DeleteLocalRef(mInfo.classID);
}

void FacebookUtil::postAppRequestsToFriendsWithoutInstalled(string title, string message, string link) {
	CCLOG("postAppRequestsToFriendsWithoutInstalled");

	JniMethodInfo mInfo;
	bool isHave = JniHelper::getStaticMethodInfo(mInfo, "com/game/facebook/FacebookJNIHelper", "postAppRequestsToFriendsWithoutInstalled", "(Ljava/lang/String;Ljava/lang/String;)V");

	CCLOG("Have this method: %d", isHave);
	if (isHave) {
		jstring j_title = mInfo.env->NewStringUTF(title.c_str());
		jstring j_message = mInfo.env->NewStringUTF(message.c_str());
		jstring j_link = mInfo.env->NewStringUTF(link.c_str());
		mInfo.env->CallStaticVoidMethod(mInfo.classID, mInfo.methodID, j_title, j_message, j_link);
		mInfo.env->DeleteLocalRef(j_title);
		mInfo.env->DeleteLocalRef(j_message);
		mInfo.env->DeleteLocalRef(j_link);
	}
	mInfo.env->DeleteLocalRef(mInfo.classID);
}

#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#include "FacebookHelper.h"

FacebookUtil::FacebookUtil() : _callback(NULL), _friendIds(), _friendNames(), _friendGenders(), _friendPictureUrls(), loaded(false) {
    FacebookHelper::getInstance()->setFacebookNotification(new FacebookNotification());
}

const string FacebookUtil::getToken() {
	return FacebookHelper::getInstance()->getToken();
}

const string FacebookUtil::getId() {
	return FacebookHelper::getInstance()->getUserId();
}

const string FacebookUtil::getName() {
	return FacebookHelper::getInstance()->getUserName();
}

const string FacebookUtil::getGender() {
	return FacebookHelper::getInstance()->getUserGender();
}

const string FacebookUtil::getPictureUrl() {
	return FacebookHelper::getInstance()->getUserPicUrl();
}

const vector<string>& FacebookUtil::getFriendIds() {
    _friendIds.clear();
    vector<string> values = FacebookHelper::getInstance()->getFriendIds();
    for (int i = 0; i < values.size(); i++) {
        _friendIds.push_back(values[i]);
    }
	return _friendIds;
}

const vector<string>& FacebookUtil::getFriendsInstalled() {
    _friendIdsInstalled.clear();
    vector<string> values = FacebookHelper::getInstance()->getFriendIdsInstalled();
    for (int i = 0; i < values.size(); i++) {
        _friendIdsInstalled.push_back(values[i]);
    }
	return _friendIdsInstalled;
}

const vector<string>& FacebookUtil::getFriendNames() {
    _friendNames.clear();
    vector<string> values = FacebookHelper::getInstance()->getFriendNames();
    for (int i = 0; i < values.size(); i++) {
        _friendNames.push_back(values[i]);
    }
	return _friendNames;
}

const vector<string>& FacebookUtil::getFriendGenders() {
    _friendGenders.clear();
    vector<string> values = FacebookHelper::getInstance()->getFriendGenders();
    for (int i = 0; i < values.size(); i++) {
        _friendGenders.push_back(values[i]);
    }
	return _friendGenders;
}

const vector<string>& FacebookUtil::getFriendPictureUrls() {
    _friendPictureUrls.clear();
    vector<string> values = FacebookHelper::getInstance()->getFriendPictureUrls();
    for (int i = 0; i < values.size(); i++) {
        _friendPictureUrls.push_back(values[i]);
    }
	return _friendPictureUrls;
}

void FacebookUtil::login() {
    FacebookHelper::getInstance()->facebookLogin();
}

void FacebookUtil::logout() {
    FacebookHelper::getInstance()->facebookLogout();
}

string FacebookUtil::getRedirectedUrl(string fbId, bool smallPic) {
	return "";
}

bool FacebookUtil::publishFeedDialog(string name, string caption, string descrption, string link, string pic, string toUserId) {
	FacebookHelper::getInstance()->publishFeedDialog(name, caption, descrption, link, pic);
    return true;
}

bool FacebookUtil::isLoaded() {
	return loaded;
}

void FacebookUtil::postAppRequests(string title, string message, string link) {

}

void FacebookUtil::postAppRequestsToFriendsWithoutInstalled(string title, string message, string link) {
    
}

void FacebookUtil::onLoginSuccess() {
	CCLOG("onLoginSuccess");
    
	FacebookUtil::getInstance()->loaded = true;
    
	FacebookCallback* callback = FacebookUtil::getInstance()->_callback;
	if (callback != NULL) {
		callback->onLoginSuccess();
	}
}

void FacebookUtil::onLoginFailed() {
	CCLOG("onLoginFailed");
    
	FacebookCallback* callback = FacebookUtil::getInstance()->_callback;
	if (callback != NULL) {
		callback->onLoginFailed();
	}
}

void FacebookUtil::onSessionClosed() {
	CCLOG("onSessionClosed");
    
	FacebookCallback* callback = FacebookUtil::getInstance()->_callback;
	if (callback != NULL) {
		callback->onSessionClosed();
	}
}

#else

FacebookUtil::FacebookUtil() : _callback(NULL), _friendIds(), _friendNames(), _friendGenders(), _friendPictureUrls(), loaded(false) {
}

const string FacebookUtil::getToken() {
	return "";
}

const string FacebookUtil::getId() {
	return "";
}

const string FacebookUtil::getName() {
	return "";
}

const string FacebookUtil::getGender() {
	return "";
}

const string FacebookUtil::getPictureUrl() {
	return "";
}

const vector<string>& FacebookUtil::getFriendIds() {
	return _friendIds;
}

const vector<string>& FacebookUtil::getFriendNames() {
	return _friendNames;
}

const vector<string>& FacebookUtil::getFriendGenders() {
	return _friendGenders;
}

const vector<string>& FacebookUtil::getFriendPictureUrls() {
	return _friendPictureUrls;
}

void FacebookUtil::login() {

}

void FacebookUtil::logout() {

}

string FacebookUtil::getRedirectedUrl(string fbId, bool smallPic) {
	return "";
}

bool FacebookUtil::publishFeedDialog(string name, string caption, string descrption, string link, string pic, string toUserId) {
	return true;
}

bool FacebookUtil::isLoaded() {
	return loaded;
}

void FacebookUtil::postAppRequests(string title, string message, string link) {

}

void FacebookUtil::postAppRequestsToFriendsWithoutInstalled(string title, string message, string link) {

}

#endif
