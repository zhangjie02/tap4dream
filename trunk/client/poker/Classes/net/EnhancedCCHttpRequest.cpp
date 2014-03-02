#include "EnhancedCCHttpRequest.h"

EnhancedCCHttpRequest::EnhancedCCHttpRequest(Request* reqCmd){
	_reqCmd = reqCmd;
}

EnhancedCCHttpRequest::~EnhancedCCHttpRequest() {
	// _reqCmd在调用层控制析构
}

Request* EnhancedCCHttpRequest::getReqCmd() {
	return _reqCmd;
}
