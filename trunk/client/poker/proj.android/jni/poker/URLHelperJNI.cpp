//
//  URLHelperJNI.cpp
//  MagicEra
//
//  Created by shengsh on 13-4-15.
//
//

#include "URLHelperJNI.h"
#include <jni.h>
#include "platform/android/jni/JniHelper.h"

using namespace cocos2d;

void URLHelperJNI::openURL(const char* url) {
	cocos2d::JniMethodInfo mInfo;
	if (cocos2d::JniHelper::getStaticMethodInfo(mInfo,"com/game/steamclan/URLHelper", "openURL", "(Ljava/lang/String;)V")) {
        jstring StringArg1 = mInfo.env->NewStringUTF(url);
		mInfo.env->CallStaticVoidMethod(mInfo.classID, mInfo.methodID, StringArg1);
		mInfo.env->DeleteLocalRef(StringArg1);
		mInfo.env->DeleteLocalRef(mInfo.classID);
    }

}
