//
//  FormatUtil.h
//  slot
//
//  Created by 苏 汝杰 on 13-12-20.
//
//

#ifndef __slot__FormatUtil__
#define __slot__FormatUtil__

#include <iostream>
#include <list>
#include <string>
#include <sstream>
using namespace std;



class FormatUtil {
public:
    static std::string getScientificNotation(string valueStr, const std::string splitter);
    static std::string getfScientificNotationDivedby100(string valueStr);
    static std::string getfScientificNotationDivedby100(string valueStr, const std::string splitter, const string dot);
    
    static std::string getTimeStr(int currentSecs, bool showNone = false, bool ifUseImage = false);
    /**
     * 根据最大单位取时间描述，如果1d2h3m -> 1d
     */
    static std::string getTimeStrByMaxUnit(int currentSecs);
    
    static std::string getScientificNotation(int64_t value, const std::string splitter);
    static std::string getfScientificNotationDivedby100(int64_t value);
    static std::string getfScientificNotationDivedby100(int64_t value, const std::string splitter, const string dot);
    
    static string getNumShorthand(int64_t num);
    static string getNumShorthandFromString(string numStr);
    static string getCentsShorhand(int64_t cents);
    static string getCentsShorhandFromString(string centsStr);
private:
    static const int64_t THOUSAND;
    static const int64_t MILLION;
    static const int64_t BILLION;
};

#endif /* defined(__slot__FormatUtil__) */
