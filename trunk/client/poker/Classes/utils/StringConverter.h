#ifndef __STRING_CONVERTER_H__
#define __STRING_CONVERTER_H__

#include <string>
#include <cstdlib>
#include <sstream>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>

#include "stdint.h"

using namespace std;

namespace StringConverter {
	extern int32_t toInt32(const string& s);
	extern int64_t toInt64(const string& s);
	extern float toFloat(const string& s);
	extern double toDouble(const string& s);
    extern int32_t toInt32FromHex(const string& hexS);

	extern string toString(int32_t v);
	extern string toString(int64_t v);
    extern string toString(long v);
	extern string toString(float v);
	extern string toString(double v);
    extern string toString(const string& s);

	extern string& ltrim(string &s);
	extern string& rtrim(string &s);
	extern string& trim(string &s);
    
    extern string toTimeStringMinuteSecond(int second);
    extern string toTimeStringHourMinuteSecond(int second);
    
    extern string toString(const char* format, ...);
    
    extern string formatTime1(int hour, int minute, int second, const char* split=":");
    extern string formatTime2(int minute, int second, const char* split=":");
    
    extern string stringReplace(string src, string const& target, string const& repl);
    

};

#endif  // __STRING_CONVERTER_H__
