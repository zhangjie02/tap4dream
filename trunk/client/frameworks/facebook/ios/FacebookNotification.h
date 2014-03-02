//
//  FacebookNotification.h
//  pickit
//
//  Created by zhouyan on 13-6-25.
//
//

#ifndef pickit_FacebookNotification_h
#define pickit_FacebookNotification_h

class FacebookNotification {
public:
    void onSessionLoginSuccess();
    void onSessionLoginFailed();
    void onSessionClosed();
    void onSessionClosedFailed();
    void onSessionTryLoginSuccess();
    void onSessionTryLoginFailed();
    void onRequestUserInfoSuccess();
    void onRequestUserInfoFailed();
    void onRequestFriendInfoSuccess();
    void onRequestFriendInfoFailed();
};

#endif
