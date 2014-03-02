#ifndef __poker__NetMessage__
#define __poker__NetMessage__

#include <iostream>
#include <string>

using namespace std;

enum NetErrorType {
    NetErrorType_Cmd,
    NetErrorType_Res
};

class NetErrorInfo {
public:
    NetErrorInfo(NetErrorType pType, string pUrl, string pTip = ""): errorTpye(pType), url(pUrl), tip(pTip){}
    
public:
    NetErrorType errorTpye;
    string url;
    string tip;
};

#endif /* defined(__poker__NetMessage__) */
