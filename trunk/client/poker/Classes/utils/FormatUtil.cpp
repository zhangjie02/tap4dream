//
//  FormatUtil.cpp
//  slot
//
//  Created by 苏 汝杰 on 13-12-20.
//
//

#include "FormatUtil.h"
#include "MathUtil.h"
#include "StringConverter.h"

const int64_t FormatUtil::BILLION = 1000000000;
const int64_t FormatUtil::MILLION = 1000000;
const int64_t FormatUtil::THOUSAND = 1000;

string FormatUtil::getScientificNotation(int64_t value, const std::string splitter) {
    if (value == 0) {
        return "0";
    }
    
    std::list<int> values;
    while (true) {
        int mod = value % 1000;
        values.push_front(mod);
        value /= 1000;
        
        if (value < 1000) {
            if (value > 0) {
                values.push_front(value);
            }
            break;
        }
    }
    stringstream ss;
    int i = 0;
    size_t size = values.size() - 1;
    for (std::list<int>::iterator iter = values.begin(); iter != values.end(); iter++, i++) {
        int value = *iter;
        if (value == 0) {
            ss << "000";
        } else {
            if (i != 0) {
                if (value < 10) {
                    ss << "00";
                } else  if (value < 100) {
                    ss << "0";
                }
            }
            ss << value;
        }
        
        if (i != size) {
            ss << splitter;
        }
    }
    std::string result = "";
    result.append(ss.str());
    
    return result;
}

string FormatUtil::getfScientificNotationDivedby100(int64_t value){
    return getfScientificNotationDivedby100(value, ":", ";");
}


string FormatUtil::getfScientificNotationDivedby100(string valueStr, const std::string splitter, const string dot) {
    int64_t value = StringConverter::toInt64(valueStr);
    return getfScientificNotationDivedby100(value, splitter, dot);
}

std::string FormatUtil::getfScientificNotationDivedby100(int64_t value, const std::string splitter, const string dot) {
    int64_t parta=value/100;
    stringstream ss;
    ss << parta;
    int64_t partb=MathUtil::mod(value, 100);
    string partastr=getScientificNotation(ss.str(),splitter);
    ss.str("");
    ss<<partastr;
    if (partb!=0) {
        if (partb < 10) {
            ss << dot << "0" << partb;
        } else {
            ss<< dot <<partb;
        }
    }
    std::string result = "";
    result.append(ss.str());
    return result;
}

string FormatUtil::getScientificNotation(string valueStr, const std::string splitter/* = ","*/) {
    int64_t value = StringConverter::toInt64(valueStr);
    return getScientificNotation(value, splitter);
}

string FormatUtil::getfScientificNotationDivedby100(string valueStr) {
    int64_t value = StringConverter::toInt64(valueStr);
    return getfScientificNotationDivedby100(value);
}


string FormatUtil::getTimeStrByMaxUnit(int currentSecs) {
    if(currentSecs == 0) {
        return "None";
    }
    
    stringstream ss;
    
    int oneMinute = 60;
    int oneHour = 60 * oneMinute;
    int oneDay = 24 * oneHour;
    int oneWeek = 7 * oneDay;
    
    bool isMulti = false;
    
    if(currentSecs > oneWeek) {
        int weeks = currentSecs / oneWeek;
        ss << weeks << " week";
        isMulti = weeks > 1;
    }else if(currentSecs > oneDay) {
        int days = currentSecs / oneDay;
        ss << days << " day";
        isMulti = days > 1;
    }else if(currentSecs > oneHour) {
        int hours = currentSecs / oneHour;
        ss << hours << " hour";
        isMulti = hours > 1;
    }else if(currentSecs > oneMinute) {
        int minutes = currentSecs / oneMinute;
        ss << minutes << " minute";
        isMulti = minutes > 1;
    }else {
        ss << currentSecs << " second";
        isMulti = currentSecs > 1;
    }
    if(isMulti) {
        ss << "s";
    }
    return ss.str();
}

std::string FormatUtil::getTimeStr(int currentSecs, bool showNone, bool ifUseImage) {
	stringstream ss;
	if(currentSecs == 0)
	{
		if(!showNone)
			ss <<  "" ;
		else
		{
			if(!ifUseImage)
				ss <<  "None";
			else
				ss <<  "N"<<"O"<<"P"<<"Q";//"None";
            
		}
	}
	else
	{
		int _seconds = currentSecs;
		int oneday = 3600*24;
		int _day =  _seconds/oneday;
		_seconds %=  oneday;
		int _hour = _seconds/3600;
		_seconds %= 3600;
		int _minite = _seconds/60;
		_seconds %= 60;
		if(_day > 0)		{
			if(_hour > 0)
			{
				if(!ifUseImage)
					ss << _day << "d " << _hour << "h";
				else//":" d  //";" h //"<" m //"=" seconds;
					ss << _day << ":" << _hour << ";";
                
			}
			else//_hour == 0
			{
				if(!ifUseImage)
					ss << _day << "d";
				else
					ss << _day << ":" ;
			}
            
		}
		else		{//_day == 0
			if(_hour > 0)				{
				if(_minite > 0)
				{
					if(!ifUseImage)
						ss << _hour << "h " << _minite << "m";
					else
						ss << _hour << ";" << _minite << "=";
                    
				}
				else		//_minite == 0
				{
					if(!ifUseImage)
						ss << _hour << "h";
					else
						ss << _hour << ";";
                    
				}
			}
			else {//_hour == 0
				if(_minite > 0)				{
					if(_seconds > 0)
					{
						if(!ifUseImage)
							ss << _minite << "m "<< _seconds << "s" ;
						else
							ss << _minite << "="<< _seconds << "<" ;
                        
					}
					else
					{
						if(!ifUseImage)
							ss << _minite <<  "m";
						else
							ss << _minite <<  "=";
                        
					}
				}
				else		{//_minite == 0
					if(_seconds > 0)
					{
						if(!ifUseImage)
							ss << _seconds << "s" ;
						else
							ss << _seconds << "<" ;
					}
				}
			}
		}
	}
    
    string result = "";
    result.append(ss.str());
    return result;
}

string FormatUtil::getNumShorthand(int64_t num) {
    int64_t tenMillion = MILLION * 10LL;
    stringstream ss;
    int64_t unitCount = 0;
    if (num < tenMillion) {
        int64_t hundredThousands = THOUSAND * 100LL;
        if (num < hundredThousands) {
            ss << getScientificNotation(num, ",");
            return ss.str();
        } else {
            unitCount = num / THOUSAND;
            ss << getScientificNotation(unitCount, ",") << "K";
            return ss.str();
        }
    }
    
    int64_t tenBillion = BILLION * 10LL;
    if (num < tenBillion) {
        unitCount = num / MILLION;
        if (unitCount > 0) {
            ss << getScientificNotation(unitCount, ",") << "M";
            return ss.str();
        }
    }
    
    unitCount = num / BILLION;
    ss << getScientificNotation(unitCount, ",") << "B";
    return ss.str();
}

string FormatUtil::getNumShorthandFromString(string numStr) {
    int64_t num = StringConverter::toInt64(numStr);
    return getNumShorthand(num);
}

string FormatUtil::getCentsShorhand(int64_t cents) {
    int64_t dollars = cents / 100;
    return getNumShorthand(dollars);
}

string FormatUtil::getCentsShorhandFromString(string centsStr) {
    int64_t cents = StringConverter::toInt64(centsStr);
    return getCentsShorhand(cents);
}
