//
//  FacebookHelper.h
//  Defender3
//
//  Created by lu lu on 13-5-23.
//
//

#ifndef _FACEBOOK_HELPER_H_
#define _FACEBOOK_HELPER_H_

#include <iostream>
#include "cocos2d.h"
#include "FacebookNotification.h"

using namespace std;
using namespace cocos2d;

class FeedDialogParams;

class FacebookHelper{
    
public:
    static FacebookHelper* getInstance() {
        static FacebookHelper instance;
        return &instance;
    }
    
protected:
    FacebookHelper();
    ~FacebookHelper();
public:
    void facebookLogin();
    void facebookLoginWithoutUI();
    void facebookLogout();
    void requestForMe();
    void requestUserInfo();
    void requestForMyFriend();
    void requestFriendInfo();
    void requestPublishPermission();
    void createNewSession();
    void publishFeedDialog(string name, string caption, string description, string link, string pic);
    void handlePendingAction();
    void continuePostFeedDialog();
    bool hasPublishPermission();
    
public:
    string getUserId();
    string getUserName();
    string getUserGender();
    string getUserPicUrl();
    string getToken();
    vector<string> getFriendIds();
    vector<string> getFriendIdsInstalled();
    vector<string> getFriendNames();
    vector<string> getFriendGenders();
    vector<string> getFriendPictureUrls();
    FacebookNotification* getFacebookNotification();
    int getFacebookAction();
    void setFacebookAction(int action);
    void setToken(string token);
    void setFacebookNotification(FacebookNotification *facebookNotification);
    
public:
    static const int NONE;
    static const int LOGIN;
    static const int LOGOUT;
    static const int TRY_LOGIN;
    
protected:
    static const int ACTION_NONE;
    static const int ACTION_POST_FEEDDIALOG;
    
protected:
    FeedDialogParams* _feedDialogParams;
    int _pendingAction;
    int _facebookAction;
    string _userID;
    string _userName;
    string _userGender;
    string _userPicUrl;
    string _token;
    vector<string> _friendIds;
    vector<string> _friendIdsInstalled;
    vector<string> _friendNames;
    vector<string> _friendGenders;
	vector<string> _friendPictureUrls;
    FacebookNotification* _facebookNotification;
};

class FeedDialogParams : public CCObject{
    
public:
    static FeedDialogParams* createfeedDialogParams(string name, string caption, string description, string link, string pic);
    
protected:
    FeedDialogParams(string name, string caption, string description, string link, string pic);
    
public:
    string _name;
    string _caption;
    string _description;
    string _link;
    string _pic;
};


#endif