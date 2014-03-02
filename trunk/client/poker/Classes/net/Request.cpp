#include "Request.h"
#include "CommandSender.h"

Request::Request(string pUrl, ReqType pType, Command* cmd, Callback* pCallback, bool pIsZlib) {
	this->url = pUrl;
	this->type = pType;
	this->cmd = cmd;
	this->callback = pCallback;
    this->isZlib = pIsZlib;

	reReqCount = 0;
}

Request::~Request() {
	if(cmd != NULL) {
		delete cmd;
		cmd = NULL;
	}
	if(callback != NULL) {
		delete callback;
		callback = NULL;
	}
}

string Request::getRequestBodyString() {
	if(cmd == NULL) return "";
	string result = cmd->toJson().write_formatted();
	return result;
}


