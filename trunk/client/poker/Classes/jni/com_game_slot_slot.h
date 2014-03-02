#include <jni.h>

#ifndef _Included_com_game_slot_slot
#define _Included_com_game_slot_slot
#ifdef __cplusplus
extern "C" {
#endif
	JNIEXPORT void JNICALL Java_com_game_slot_Slot_setUUID(JNIEnv *, jobject, jstring);
	JNIEXPORT void JNICALL Java_com_game_slot_Slot_setVersion(JNIEnv *, jobject, jstring);
    JNIEXPORT void JNICALL Java_com_game_slot_Slot_setPackageName(JNIEnv *, jobject, jstring);
#ifdef __cplusplus
}
#endif
#endif
