#ifndef HTTP_MGR_H
#define HTTP_MGR_H

#include <map>
#include <string>
#include <list>
#include "Request.h"
#include "Callback.h"
#include "cocos-ext.h"
#include "EnhancedCCHttpRequest.h"
#include "libjson.h"
#include <list>

using namespace std;

class HttpMgr : public cocos2d::CCObject

{
public:
	static HttpMgr* getInstance() {
		static HttpMgr instance;
		return &instance;
	}
	~HttpMgr();

	void requestAsync(string url, ReqType type, Command* cmd, Callback* callback = NULL, bool isZlib = false);
    
	void reset();
    
    double getUrlFileSize(string url);
private:
	HttpMgr();

	void doRequest(Request* request);
    
	void onHttpRequestCompleted(CCHttpClient* client, CCHttpResponse* response);
    
    void handleResponse(Request* request, string data);
    void handlenotice(JSONNode &node);
private:

	static const int TIME_OUT_CONNECT	 = 20;
	static const int TIME_OUT_READ		 = 20;
	static const int MAX_RE_SEND_COUNT	 = 3;
    
    
    static const int NOTICE_TOURNAMENT_REWARD=1;
    static const int NOTICE_SHARE_GIFT=2;
};

#endif 






