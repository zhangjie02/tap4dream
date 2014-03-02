//
//  AssetsUtil.cpp
//  poker
//
//  Created by jayson on 13-12-19.
//
//

#include "AssetsUtil.h"
#include <regex.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "StringConverter.h"

string AssetsUtil::getFileName(string url, bool isWithSuffix) {
    char reg[] = "([a-z0-9A-Z_-]+)*\\.([a-z0-9A-Z_-]+)*$";
    const char* data = url.data();
    string name = "";
    regex_t pattern;
    size_t nmatch = 3;
    int nErrCode = 0;
    if((nErrCode = regcomp(&pattern, reg, REG_EXTENDED)) == 0){
        regmatch_t pmatch[nmatch];
        if ((nErrCode = regexec(&pattern, data, nmatch, pmatch, 0)) == 0) {
            int index = isWithSuffix ? 0 : 1;
            regoff_t so = pmatch[index].rm_so;
            regoff_t eo = pmatch[index].rm_eo;
            char result[32];
            memcpy(result, data + so, eo - so);
            result[eo - so] = '\0';
            name.append(result);
        }
        regfree(&pattern);
    }
    return name;
}

string AssetsUtil::getDir(string url) {
    string fileName = getFileName(url, true);
    return StringConverter::stringReplace(url, fileName, "");
}

string AssetsUtil::getNumberIdFromUrl(string url) {
    char reg[] = "([0-9]+)";
    const char* data = url.data();
    string name = "";
    regex_t pattern;
    size_t nmatch = 2;
    int nErrCode = 0;
    if((nErrCode = regcomp(&pattern, reg, REG_EXTENDED)) == 0){
        regmatch_t pmatch[nmatch];
        if ((nErrCode = regexec(&pattern, data, nmatch, pmatch, 0)) == 0) {
            regoff_t so = pmatch[1].rm_so;
            regoff_t eo = pmatch[1].rm_eo;
            char result[32];
            memcpy(result, data + so, eo - so);
            result[eo - so] = '\0';
            name.append(result);
        }
        regfree(&pattern);
    }
    return name;
}