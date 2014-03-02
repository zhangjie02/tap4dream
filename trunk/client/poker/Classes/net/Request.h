#ifndef REQUEST_H_
#define REQUEST_H_

#include "Callback.h"
#include <string>
#include <list>
#include "Callback.h"
#include "Command.h"

using namespace std;

enum ReqType{
	ReqType_GET, ReqType_POST
};


class Request {
public:
	/**
	 * @param pCallback 总的request回来后的回调函数
	 */
	Request(string pUrl, ReqType pType, Command* cmd,Callback* pCallback = NULL, bool isZlib = false);

	~Request();

	string getRequestBodyString();

public:
	string url;
	ReqType type;
	Command* cmd;
    bool isZlib;

	Callback* callback;

	// 重发次数
	int reReqCount;
};

#endif /* REQUEST_H_ */
