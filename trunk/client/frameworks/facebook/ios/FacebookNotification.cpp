#include "FacebookNotification.h"
#include "FacebookHelper.h"
#include "FacebookUtil.h"

void FacebookNotification::onSessionLoginSuccess() {
    FacebookHelper::getInstance()->requestUserInfo();
}

void FacebookNotification::onSessionLoginFailed() {
    FacebookUtil::onLoginFailed();
}

void FacebookNotification::onSessionClosed() {
    FacebookUtil::onSessionClosed();
}

void FacebookNotification::onSessionClosedFailed() {
    
}

void FacebookNotification::onSessionTryLoginSuccess() {
    FacebookHelper::getInstance()->requestUserInfo();
}

void FacebookNotification::onSessionTryLoginFailed() {
    FacebookUtil::onLoginFailed();
}

void FacebookNotification::onRequestUserInfoSuccess() {
    FacebookHelper::getInstance()->requestFriendInfo();
}

void FacebookNotification::onRequestUserInfoFailed() {
    FacebookUtil::onLoginFailed();
}

void FacebookNotification::onRequestFriendInfoSuccess() {
    FacebookUtil::onLoginSuccess();
}

void FacebookNotification::onRequestFriendInfoFailed() {
    FacebookUtil::onLoginFailed();
}
