#include "PurchaseHelperJni.h"
#include "platform/android/jni/JniHelper.h"

#include <android/log.h>

#define  LOG_TAG    "PurchaseHelperJni"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  CLASS_NAME "com/game/billing/PurchaseHelper"

extern "C" {
	void purchaseItemJNI(const char* itemId) {
		cocos2d::JniMethodInfo methodInfo;
		if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "purchaseItem", "(Ljava/lang/String;)V")) {
			// LOGD("no such method: purchaseItem");
			return;
		}
		jstring stringArg = methodInfo.env->NewStringUTF(itemId);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, stringArg);
		methodInfo.env->DeleteLocalRef(stringArg);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);   
    }
	
	void purchaseItemWithDeveloperPayloadJNI(const char* itemId, const char* developerPayload) {
		cocos2d::JniMethodInfo methodInfo;
		if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "purchaseItem", "(Ljava/lang/String;Ljava/lang/String;)V")) {
			return;
		}
		jstring arg1 = methodInfo.env->NewStringUTF(itemId);
		jstring arg2 = methodInfo.env->NewStringUTF(developerPayload);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, arg1, arg2);
		methodInfo.env->DeleteLocalRef(arg1);
		methodInfo.env->DeleteLocalRef(arg2);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}

	void initPurchaseJNI() {
		cocos2d::JniMethodInfo methodInfo;
		if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "initPurchase", "()V")) {
			return;
		}
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}

	void confirmPurchaseOnlineJNI(const char* sku, const char* token) {
		cocos2d::JniMethodInfo methodInfo;
		if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "confirmPurchaseOnline", "(Ljava/lang/String;Ljava/lang/String;)V")) {
			return;
		}
		jstring arg1 = methodInfo.env->NewStringUTF(sku);
		jstring arg2 = methodInfo.env->NewStringUTF(token);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, arg1, arg2);
		methodInfo.env->DeleteLocalRef(arg1);
		methodInfo.env->DeleteLocalRef(arg2);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}
}

