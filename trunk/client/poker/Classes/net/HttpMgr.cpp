
#include <sstream>
#include "HttpMgr.h"
#include "libjson.h"
#include "JSONUtil.h"
#include "Global.h"
#include <pthread.h>
#include <string>
#include "Request.h"
#include "Global.h"
#include <zlib.h>
#include <zconf.h>
#include <curl/curl.h>
#include <curl/easy.h>

class JSONNode;

using namespace std;
using namespace cocos2d;

USING_NS_CC_EXT;

HttpMgr::HttpMgr()
{
	CCHttpClient::getInstance()->setTimeoutForConnect(TIME_OUT_CONNECT);
	CCHttpClient::getInstance()->setTimeoutForRead(TIME_OUT_READ);
}

void HttpMgr::requestAsync(string url, ReqType type, Command* requestBody, Callback* callback, bool isZlib) {
	Request* request = new Request(url, type, requestBody, callback, isZlib);
	doRequest(request);
}


void HttpMgr::reset() {
	
}

double fileSize = 0;

double HttpMgr::getUrlFileSize(string url) {
    CURL* _curl = curl_easy_init();
    curl_easy_setopt(_curl, CURLOPT_URL, url.data());
    curl_easy_setopt(_curl, CURLOPT_HEADER, 1);
    curl_easy_setopt(_curl, CURLOPT_NOBODY, 1);
    
    // 如果http code > 400, 则报错, 这样就不会写文件了
    curl_easy_setopt(_curl, CURLOPT_FAILONERROR, true);
    
    // 如果在20秒内，速度小于1byte/s, 则报错
    curl_easy_setopt(_curl, CURLOPT_LOW_SPEED_LIMIT, 1L);
    curl_easy_setopt(_curl, CURLOPT_LOW_SPEED_TIME, 20L);
    
    CURLcode res = curl_easy_perform(_curl);

    if (res == CURLE_OK) {
        curl_easy_getinfo(_curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &fileSize);
    } else {
        fileSize = 0;
    }
    curl_easy_cleanup(_curl);
    return fileSize;
}

void HttpMgr::doRequest(Request* request) {
	EnhancedCCHttpRequest* httpRequest = new EnhancedCCHttpRequest(request);
	httpRequest->setUrl(request->url.c_str());
	if(request->type == ReqType_POST) {
        std::vector<std::string> headers;
        headers.push_back("Content-Type: application/json; charset=utf-8");
        headers.push_back("Content-Encoding: gzip");
        httpRequest->setHeaders(headers);
        
        httpRequest->setRequestType(CCHttpRequest::kHttpPost);
    }
	else {
        httpRequest->setRequestType(CCHttpRequest::kHttpGet);
    }

    httpRequest->setResponseCallback(this, httpresponse_selector(HttpMgr::onHttpRequestCompleted));

	string bodystr = request->getRequestBodyString();
    
    httpRequest->setRequestData(bodystr.c_str(), bodystr.length());
    
    CCLOG("====== http request url:%s, body: %s ", request->url.c_str(), bodystr.c_str());

	CCHttpClient::getInstance()->send(httpRequest);
    httpRequest->release();
}

void HttpMgr::onHttpRequestCompleted(CCHttpClient* client, CCHttpResponse* response) {
    EnhancedCCHttpRequest* enRequest = static_cast<EnhancedCCHttpRequest*>(response->getHttpRequest());
    
	int statusCode = response->getResponseCode();
	if (!response->isSucceed())
	{
		CCLOG("response failed, error buffer: %s, error code:%d", response->getErrorBuffer(),statusCode);

		Request* request = enRequest->getReqCmd();
		request->reReqCount ++;
		if(request->reReqCount >= MAX_RE_SEND_COUNT) {
			CCLOG("reconnect reach max ..");
            //NetErrorInfo message(NetErrorType_Cmd, request->cmd->cmd);
            //CCNotificationCenter::sharedNotificationCenter()->postNotification(EventDef::SERVER_NETWORK_ERROR,(CCObject *)&message);
		}else {
			CCLOG("reconnect ..");
			doRequest(enRequest->getReqCmd());
		}
        return;
	}
	std::vector<char> *buffer = response->getResponseData();
	std::string data(buffer->begin(), buffer->end());

    CCLOG("handle response: %s",data.c_str());
    handleResponse(enRequest->getReqCmd(), data);
    
    delete enRequest->getReqCmd();
}

void HttpMgr::handleResponse(Request* request, string data) {
    if (request->type == ReqType_POST) {
        string jsonInfo=data.c_str();
        bool isvalid = libjson::is_valid(jsonInfo);
        if (!isvalid) {
            CCLOG("[http] error, response is not json");
        }
        JSONNode node = libjson::parse(jsonInfo);
        int errorCode = JSONUtil::getInt(node, "error_code");
        if(errorCode > 0) {
            //CCNotificationCenter::sharedNotificationCenter()->postNotification(EventDef::SLOT_SYS_CMD_ERROR,(CCObject *)&node);
            return;
        }
        Command* cmd = request->cmd;
        cmd->handleResponse(&node);
        
        handlenotice(node);
        
    }else if(request->type == ReqType_GET){
		if(request->callback != NULL) request->callback->Execute(&request);
	}
}


void HttpMgr::handlenotice(JSONNode &node){
    string key="notice";
    if (!JSONUtil::hasKey(node, key.c_str())) {
        return;
    }
    
    JSONNode noticenode=JSONUtil::getNode(node, key.c_str());
    
    
    JSONNode::iterator itr=noticenode.begin();
    while (itr!=noticenode.end()) {
        int type=JSONUtil::getInt(*itr, "type");
        switch (type) {
        
                break;
            case NOTICE_SHARE_GIFT:
            {
                int counter=JSONUtil::getInt(*itr, "counter");
                //CCNotificationCenter::sharedNotificationCenter()->postNotification(EventDef::SLOT_SYS_SHOW_SHAREGIFT,(CCObject*)&counter);
            }
                break;
        }

        itr++;
    }

}


HttpMgr::~HttpMgr()
{
	reset();
}




