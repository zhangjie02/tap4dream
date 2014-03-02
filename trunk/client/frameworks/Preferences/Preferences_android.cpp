#include "../../../Preferences/Preferences.h"
#include "PreferencesJni.h"

using std::string;

bool Preferences::getBoolForKey(const char* key, bool defaultValue) {
	return getBoolForKeyJNI(key, defaultValue);
}

int Preferences::getIntForKey(const char* key, int defaultValue) {
	return getIntForKeyJNI(key, defaultValue);
}

float Preferences::getFloatForKey(const char* key, float defaultValue) {
	return getFloatForKeyJNI(key, defaultValue);
}

//double Preferences::getDoubleForKey(const char* key, double defaultValue) {
//	getDoubleForKeyJNI(key, defaultValue);
//}

string Preferences::getStringForKey(const char* key, const std::string& defaultValue) {
	return getStringForKeyJNI(key, defaultValue);
}

void Preferences::setBoolForKey(const char* key, bool value) {
	setBoolForKeyJNI(key, value);
}

void Preferences::setIntForKey(const char* key, int value) {
	setIntForKeyJNI(key, value);
}

void Preferences::setFloatForKey(const char* key, float value) {
	setFloatForKeyJNI(key, value);
}

//void Preferences::setDoubleForKey(const char* key, double value) {
//	setDoubleForKeyJNI(key, value);
//}

void Preferences::setStringForKey(const char* key, const string& value) {
	setStringForKeyJNI(key, value);
}

