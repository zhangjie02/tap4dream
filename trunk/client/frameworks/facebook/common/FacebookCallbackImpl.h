#ifndef __FACEBOOK_CALLBACK_IMPL_H__
#define __FACEBOOK_CALLBACK_IMPL_H__

#include "FacebookCallback.h"

class FacebookCallbackImpl : public FacebookCallback {
public:
	void onLoginSuccess();
	void onLoginFailed();
	void onSessionClosed();
};

#endif  // __FACEBOOK_CALLBACK_IMPL_H__
