#ifndef __FACEBOOK_CALLBACK_H__
#define __FACEBOOK_CALLBACK_H__

class FacebookCallback {
public:
	virtual void onLoginSuccess() = 0;
	virtual void onLoginFailed() = 0;
	virtual void onSessionClosed() = 0;
};

#endif  // __FACEBOOK_CALLBACK_H__
