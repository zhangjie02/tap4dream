#include "StringConverter.h"
#include <stdio.h>
#include <list>

int32_t StringConverter::toInt32(const string& s) {
    istringstream iss(s);
    int32_t val = 0;
    iss >> val;
    return val;
}

int32_t StringConverter::toInt32FromHex(const string &hexS) {
    stringstream ss;
    ss << std::hex << hexS;
    int32_t val = 0;
    ss >> val;
    return val;
}

int64_t StringConverter::toInt64(const string& s) {
	istringstream iss(s);
	int64_t val;
	iss >> val;
	return val;
}

float StringConverter::toFloat(const string& s) {
	istringstream iss(s);
	float val;
	iss >> val;
	return val;
}

double StringConverter::toDouble(const string& s) {
	istringstream iss(s);
	double val;
	iss >> val;
	return val;
}

string StringConverter::toString(int32_t t) {
	ostringstream oss;
	oss << t;
	return oss.str();
}

string StringConverter::toString(int64_t t) {
	ostringstream oss;
	oss << t;
	return oss.str();
}

string StringConverter::toString(long v) {
    ostringstream oss;
    oss << v;
    
    return oss.str();
}

string StringConverter::toString(float t) {
	ostringstream oss;
	oss << t;
	return oss.str();
}

string StringConverter::toString(double t) {
	ostringstream oss;
	oss << t;
	return oss.str();
}

string StringConverter::toString(const string& s) {
    return s;
}


static const size_t MAX_LEN = 1024 * 10;
string StringConverter::toString(const char* format, ...) {
    va_list arg_ptr;
    
    char buf[MAX_LEN];
    
    va_start(arg_ptr, format);
    
    vsnprintf(buf, MAX_LEN, format, arg_ptr);
    
    va_end(arg_ptr);
    
    return string(buf);
}

string StringConverter::formatTime1(int hour, int minute, int second, const char* split) {
    stringstream ss;
    
    if (hour < 10) {
        ss << "0" << hour;
    } else {
        ss << hour;
    }
    
    ss << split;
    
    if (minute < 10) {
        ss << "0" << minute;
    } else {
        ss << minute;
    }
    
    ss << split;
    
    if (second < 10) {
        ss << "0" << second;
    } else {
        ss << second;
    }
    
    return ss.str();
}

string StringConverter::formatTime2(int minute, int second, const char* split) {
    stringstream ss;

    if (minute < 10) {
        ss << "0" << minute;
    } else {
        ss << minute;
    }
    
    ss << split;
    
    if (second < 10) {
        ss << "0" << second;
    } else {
        ss << second;
    }
    
    return ss.str();
}

string& StringConverter::ltrim(string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	return s;
}

string& StringConverter::rtrim(string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	return s;
}

string& StringConverter::trim(string &s) {
	return ltrim(rtrim(s));
}

string StringConverter::toTimeStringMinuteSecond(int second) {
    string info;
    int min = second / 60;
    int sec = second % 60;
    info += toString(min / 10);
    info += toString(min % 10);
    info += ":";
    info += toString(sec / 10);
    info += toString(sec % 10);
    
    return info;
}

string StringConverter::toTimeStringHourMinuteSecond(int second) {
    string info;
    int hour = second / 3600;
    second = second % 3600;
    int min = second / 60;
    int sec = second % 60;
    info += toString(hour / 10);
    info += toString(hour % 10);
    info += ":";
    info += toString(min / 10);
    info += toString(min % 10);
    info += ":";
    info += toString(sec / 10);
    info += toString(sec % 10);
    
    return info;
}

string StringConverter::stringReplace(string src, const string &target, const string &repl) {
    // handle error situations/trivial cases
	if (target.length() == 0) {
		// searching for a match to the empty string will result in
		//  an infinite loop
		//  it might make sense to throw an exception for this case
		return src;
	}
    
	if (src.length() == 0) {
		return src;  // nothing to match against
	}
    
	size_t idx = 0;
    
	for (;;) {
		idx = src.find(target, idx);
		if (idx == string::npos)
			break;
        
		src.replace(idx, target.length(), repl);
		idx += repl.length();
	}
    
	return src;
}

