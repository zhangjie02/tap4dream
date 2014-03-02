#include "PreferencesJni.h"
#include "platform/android/jni/JniHelper.h"

#include <android/log.h>
#include "cocos2d.h"

#define  LOG_TAG    "PreferencesJni"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  CLASS_NAME "com/game/slot/PreferencesHelper"

extern "C" {
	bool getBoolForKeyJNI(const char* key, bool defaultValue) {
		cocos2d::JniMethodInfo methodInfo;
        if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "getBoolForKey", "(Ljava/lang/String;Z)Z")) {
            return defaultValue;
        }
        jstring jKey = methodInfo.env->NewStringUTF(key);
        jboolean ret = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID, jKey, defaultValue);
        methodInfo.env->DeleteLocalRef(jKey);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
		return ret;
    }

	int getIntForKeyJNI(const char* key, int defaultValue) {
		cocos2d::JniMethodInfo methodInfo;
        if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "getIntForKey", "(Ljava/lang/String;I)I")) {
            return defaultValue;
        }
        jstring jKey = methodInfo.env->NewStringUTF(key);
        jint ret = methodInfo.env->CallStaticIntMethod(methodInfo.classID, methodInfo.methodID, jKey, defaultValue);
        methodInfo.env->DeleteLocalRef(jKey);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return ret;
	}

	float getFloatForKeyJNI(const char* key, float defaultValue) {
		cocos2d::JniMethodInfo methodInfo;
        if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "getFloatForKey", "(Ljava/lang/String;F)F")) {
            return defaultValue;
        }
        jstring jKey = methodInfo.env->NewStringUTF(key);
        jfloat ret = methodInfo.env->CallStaticFloatMethod(methodInfo.classID, methodInfo.methodID, jKey, defaultValue);
        methodInfo.env->DeleteLocalRef(jKey);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return ret;
	}

	//double getDoubleForKeyJNI(const char* key, double defaultValue) {
	//    cocos2d::JniMethodInfo methodInfo;
    //    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "getDoubleForKey", "(Ljava/lang/String;D)D")) {
    //        return defaultValue;
    //    }
    //    jstring jKey = methodInfo.env->NewStringUTF(key);
    //    jdouble ret = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID, jKey, defaultValue);
    //    methodInfo.env->DeleteLocalRef(jKey);
    //    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    //    return ret;
	//}

	string getStringForKeyJNI(const char* key, const string& defaultValue) {
	    cocos2d::JniMethodInfo methodInfo;
        if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "getStringForKey", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;")) {
            return defaultValue;
        }
        jstring jKey = methodInfo.env->NewStringUTF(key);
		jstring jValue = methodInfo.env->NewStringUTF(defaultValue.c_str());
        jstring str = (jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID, jKey, jValue);
        string ret = methodInfo.env->GetStringUTFChars(str, NULL);
		methodInfo.env->DeleteLocalRef(jKey);
		methodInfo.env->DeleteLocalRef(jValue);
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
		return ret;
	}

	void setBoolForKeyJNI(const char* key, bool value) {
	    cocos2d::JniMethodInfo methodInfo;
        if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "setBoolForKey", "(Ljava/lang/String;Z)V")) {
            return;
        }
        jstring jKey = methodInfo.env->NewStringUTF(key);
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jKey, value);
        methodInfo.env->DeleteLocalRef(jKey);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}

	void setIntForKeyJNI(const char* key, int value) {
		cocos2d::JniMethodInfo methodInfo;
        if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "setIntForKey", "(Ljava/lang/String;I)V")) {
            return;
        }
        jstring jKey = methodInfo.env->NewStringUTF(key);
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jKey, value);
        methodInfo.env->DeleteLocalRef(jKey);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}

	void setFloatForKeyJNI(const char* key, float value) {
	    cocos2d::JniMethodInfo methodInfo;
        if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "setFloatForKey", "(Ljava/lang/String;F)V")) {
            return;
        }
        jstring jKey = methodInfo.env->NewStringUTF(key);
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jKey, value);
        methodInfo.env->DeleteLocalRef(jKey);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}

	//void setDoubleForKeyJNI(const char* key, double value) {
	//    cocos2d::JniMethodInfo methodInfo;
    //    if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "setDoubleForKey", "(Ljava/lang/String;D)V")) {
    //        return;
    //    }
    //    jstring jKey = methodInfo.env->NewStringUTF(key);
    //    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jKey, value);
    //    methodInfo.env->DeleteLocalRef(jKey);
    //    methodInfo.env->DeleteLocalRef(methodInfo.classID);
	//}

	void setStringForKeyJNI(const char* key, const string& value) {
	    cocos2d::JniMethodInfo methodInfo;
        if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "setStringForKey", "(Ljava/lang/String;Ljava/lang/String;)V")) {
        	cocos2d::CCLog("set String failed");
            return;
        }
        jstring jKey = methodInfo.env->NewStringUTF(key);
		jstring jValue = methodInfo.env->NewStringUTF(value.c_str());
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jKey, jValue);
        methodInfo.env->DeleteLocalRef(jKey);
		methodInfo.env->DeleteLocalRef(jValue);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}
}

