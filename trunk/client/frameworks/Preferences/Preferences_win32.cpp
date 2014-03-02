#include "../../../Preferences/Preferences.h"
#include "cocos2d.h"

using namespace cocos2d;
using std::string;

bool Preferences::getBoolForKey(const char* key, bool defaultValue) {
	CCUserDefault* userDefault = CCUserDefault::sharedUserDefault();
	return userDefault->getBoolForKey(key, defaultValue);
}

int Preferences::getIntForKey(const char* key, int defaultValue) {
	CCUserDefault* userDefault = CCUserDefault::sharedUserDefault();
	return userDefault->getIntegerForKey(key, defaultValue);
}

float Preferences::getFloatForKey(const char* key, float defaultValue) {
	CCUserDefault* userDefault = CCUserDefault::sharedUserDefault();
	return userDefault->getFloatForKey(key, defaultValue);
}

//double Preferences::getDoubleForKey(const char* key, double defaultValue) {
//	CCUserDefault* userDefault = CCUserDefault::sharedUserDefault();
//	userDefault->getDoubleForKey(key, defaultValue);
//}

string Preferences::getStringForKey(const char* key, const std::string& defaultValue) {
	CCUserDefault* userDefault = CCUserDefault::sharedUserDefault();
	return userDefault->getStringForKey(key, defaultValue);
}

void Preferences::setBoolForKey(const char* key, bool value) {
	CCUserDefault* userDefault = CCUserDefault::sharedUserDefault();
	userDefault->setBoolForKey(key, value);
	userDefault->flush();
}

void Preferences::setIntForKey(const char* key, int value) {
	CCUserDefault* userDefault = CCUserDefault::sharedUserDefault();
	userDefault->setIntegerForKey(key, value);
	userDefault->flush();
}

void Preferences::setFloatForKey(const char* key, float value) {
	CCUserDefault* userDefault = CCUserDefault::sharedUserDefault();
	userDefault->setFloatForKey(key, value);
	userDefault->flush();
}

//void Preferences::setDoubleForKey(const char* key, double value) {
//	CCUserDefault* userDefault = CCUserDefault::sharedUserDefault();
//	userDefault->setDoubleForKey(key, value);
//	userDefault->flush();
//}

void Preferences::setStringForKey(const char* key, const string& value) {
	CCUserDefault* userDefault = CCUserDefault::sharedUserDefault();
	userDefault->setStringForKey(key, value);
	userDefault->flush();
}

