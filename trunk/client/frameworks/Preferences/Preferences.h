#ifndef __DROIDHEN_FRAMEWORK_PREFERENCES_H__
#define __DROIDHEN_FRAMEWORK_PREFERENCES_H__

#include <string>

class Preferences {
public:
	static Preferences* sharedPreferences() {
		static Preferences preferences;
		return &preferences;
	}

	bool getBoolForKey(const char* key, bool defaultValue = false);
	int getIntForKey(const char* key, int defaultValue = 0);
	float getFloatForKey(const char* key, float defaultValue = 0.0f);
	//double getDoubleForKey(const char* key, double defaultValue = 0.0);
	std::string getStringForKey(const char* key, const std::string& defaultValue = "");

	void setBoolForKey(const char* key, bool value);
	void setIntForKey(const char* key, int value);
	void setFloatForKey(const char* key, float value);
	//void setDoubleForKey(const char* key, double value);
	void setStringForKey(const char* key, const std::string& value);

private:
	Preferences() {}
	Preferences(const Preferences&);
	Preferences& operator=(const Preferences&);
};

#endif

