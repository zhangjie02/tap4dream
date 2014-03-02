#ifndef __DROIDHEN_FRAMEWORK_PREFERENCES_JNI_H__
#define __DROIDHEN_FRAMEWORK_PREFERENCES_JNI_H__

#include <jni.h>
#include <string>
using std::string;

extern "C" {
	bool getBoolForKeyJNI(const char* key, bool defaultValue);
	int getIntForKeyJNI(const char* key, int defaultValue);
	float getFloatForKeyJNI(const char* key, float defaultValue);
	//double getDoubleForKeyJNI(const char* key, double defaultValue);
	string getStringForKeyJNI(const char* key, const string& defaultValue);

	void setBoolForKeyJNI(const char* key, bool value);
	void setIntForKeyJNI(const char* key, int value);
	void setFloatForKeyJNI(const char* key, float value);
	//void setDoubleForKeyJNI(const char* key, double value);
	void setStringForKeyJNI(const char* key, const string& value);
}

#endif

