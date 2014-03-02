#ifndef __FACEBOOK_CONTROLLER_H__
#define __FACEBOOK_CONTROLLER_H__

#include <map>
#include <vector>
#include <string>

#include "libjson.h"
#include "cocos2d.h"

using namespace std;
USING_NS_CC;

class FacebookController : public CCObject {
public:
    
    static FacebookController* getInstance();
    
    
	static const int ActionNone = 0;
	static const int ActionTryBind = 1;
    static const int ActionAutoLogin = 2;
    static const int ActionLogout = 3;
	static const int ActionTrySwitch = 4;

	static const int LoginTypeBind = 1;
	static const int LoginTypeSwitch = 2;

	static const int ACCOUNT_BINDED_YET = 1103;

	FacebookController();
	bool checklogin();

	bool isLoginOK();
	string getFid();
	void setFid(string fid);

	void tryBind();
	void loadIconAndShow(string fid);
    
    

    
//	void handle(PhpFatalErrorEvent* event, void* data);
    

	void processFacebookLoginResult(JSONNode resultItem);
//	void processRedirectResult(InterThreadMessage* message);
//	void processDownloadFileSuccess(InterThreadMessage* message);

	string getLocalCachedIconFile(string fid);
	JSONNode getFriendIdsJson();

	void setNameAndIcon();
	const map<string, string>& getFriends();

	void postInvite(string friendFid);
	void postShare();
    void logout();
private:
    
    void onLoginSuccess(CCObject* obj);
    void onLoginFailed(CCObject* obj);
    void onSessionClosed(CCObject* obj);
    
    void resetAction();

private:

	bool loginOK;
	string myFid;

	map<string, string> iconUrlCache;
	map<string, string> iconPathCache;
	map<string, string> friends;

	int action;

	void doLogin();
	void showFail();
	void showSwitchNotify();
	void showBindOK();
	void showSwitchOK();

	void tryLoadIcon(string fid, string iconUrl);

    const static char* login_key;
    
};

#endif  // __FACEBOOK_CONTROLLER_H__
