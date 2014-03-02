//
//  AssetsUtil.h
//  poker
//
//  Created by jayson on 13-12-19.
//
//

#ifndef __poker__AssetsUtil__
#define __poker__AssetsUtil__

#include <iostream>
#include <string>

using namespace std;

class AssetsUtil {
public:
    static string getFileName(string url, bool isWithSuffix);
    
    static string getDir(string url);
    
    static string getNumberIdFromUrl(string url);
};

#endif /* defined(__poker__AssetsUtil__) */
