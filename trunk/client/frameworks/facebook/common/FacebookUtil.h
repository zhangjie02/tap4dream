#ifndef __FACEBOOK_UTIL_H__
#define __FACEBOOK_UTIL_H__

#include <string>
#include <vector>
using std::vector;
using std::string;

#include "FacebookCallbackImpl.h"

class FacebookUtil {
public:
	static FacebookUtil* getInstance() {
		static FacebookUtil instance;
		instance.setCallback(new FacebookCallbackImpl());
		return &instance;
	}

	const string getToken();
	const string getId();
	const string getName();
	const string getGender();
	const string getPictureUrl();

	const vector<string>& getFriendIds();
    const vector<string>& getFriendsInstalled();
	const vector<string>& getFriendNames();
	const vector<string>& getFriendGenders();
	const vector<string>& getFriendPictureUrls();

	void login();
	void logout();

	void setCallback(FacebookCallback* callback);

	static void onLoginSuccess();
	static void onLoginFailed();
	static void onSessionClosed();
	
	string getRedirectedUrl(string fbId, bool smallPic);
	bool publishFeedDialog(string name, string caption, string description, string link, string pic, string toUserId);

	void postAppRequests(string title, string message, string link);
	void postAppRequestsToFriendsWithoutInstalled(string title, string message, string link);

	bool isLoaded();

private:
	FacebookUtil();
	FacebookUtil(const FacebookUtil&);
	FacebookUtil& operator=(const FacebookUtil&);

private:
	bool loaded;

	FacebookCallback* _callback;
	vector<string> _friendIds;
    vector<string> _friendIdsInstalled;
	vector<string> _friendNames;
	vector<string> _friendGenders;
	vector<string> _friendPictureUrls;
};

#endif  // __FACEBOOK_UTIL_H__
