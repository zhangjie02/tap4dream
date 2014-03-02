#include "FacebookController.h"
#include "FacebookUtil.h"


#include "JSONUtil.h"
#include "FacebookEventDef.h"
#include "Preferences.h"

#include "GameService.h"
#include "EventDef.h"

const char* FacebookController::login_key="login";

FacebookController* FacebookController::getInstance(){
    static FacebookController instance;
    return &instance;
}


FacebookController::FacebookController() : action(ActionNone),loginOK(false), myFid(""), iconUrlCache(), iconPathCache(), friends()
{
//	this->retain();
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(FacebookController::onLoginSuccess), FacebookEventDef::SLOT_FACEBOOK_ONLOGIN_SUCCESS, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(FacebookController::onLoginFailed), FacebookEventDef::SLOT_FACEBOOK_ONLOGIN_FAILED, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(FacebookController::onSessionClosed), FacebookEventDef::SLOT_FACEBOOK_ONSESSION_CLOSED, NULL);
    
}

bool FacebookController::checklogin() {
    bool haslogin=Preferences::sharedPreferences()->getBoolForKey(login_key,false);
    if (haslogin) {
        action=ActionAutoLogin;
        doLogin();
    }
    return haslogin;
}


bool FacebookController::isLoginOK() {
	return loginOK;
}

string FacebookController::getFid() {
	return myFid;
}

void FacebookController::setFid(string fid) {
	this->myFid = fid;
}

void FacebookController::tryBind() {
	if (!loginOK) {
        CCLOG("tryBind");
		action = ActionTryBind;

        doLogin();
	}
}

void FacebookController::doLogin() {
    CCLOG("do login");
	FacebookUtil::getInstance()->login();
}

void FacebookController::logout() {
    if (!loginOK) {
        return;
    }
    CCLOG("facebook logout");
    action=ActionLogout;
    FacebookUtil::getInstance()->logout();
}

void FacebookController::resetAction(){
    action=ActionNone;
}


void FacebookController::onLoginSuccess(CCObject* obj){
	if (!loginOK) {
        loginOK = true;
        Preferences::sharedPreferences()->setBoolForKey(login_key,true);
		string fid = FacebookUtil::getInstance()->getId();
		string name = FacebookUtil::getInstance()->getName();
        string icon = FacebookUtil::getInstance()->getPictureUrl();
        vector<string> friendsids=FacebookUtil::getInstance()->getFriendsInstalled();
        GameService::getInstance()->fblogin(fid, name, icon, friendsids,action==ActionAutoLogin);
        CCNotificationCenter::sharedNotificationCenter()->postNotification(EventDef::SLOT_FACEBOOK_CONNECTED_STATE_UPDATE);
	}
    resetAction();
}



void FacebookController::onLoginFailed(CCObject* obj){
    loginOK = false;
	if (action == ActionAutoLogin) {
        GameService::getInstance()->login();
	}
    Preferences::sharedPreferences()->setBoolForKey(login_key,false);
    resetAction();
    showFail();
    CCNotificationCenter::sharedNotificationCenter()->postNotification(EventDef::SLOT_FACEBOOK_CONNECTED_STATE_UPDATE);
}



void FacebookController::onSessionClosed(CCObject* obj){
    loginOK = false;
	if (action == ActionAutoLogin) {
        GameService::getInstance()->login();
	}
    Preferences::sharedPreferences()->setBoolForKey(login_key,false);
    resetAction();
    showFail();
    CCNotificationCenter::sharedNotificationCenter()->postNotification(EventDef::SLOT_FACEBOOK_CONNECTED_STATE_UPDATE);
}


//void FacebookController::handle(PhpFatalErrorEvent* event, void* data) {
//	CCLOG("PhpFatalErrorEvent");
//	if (action == ActionTryBind) {
//		showFail();
//	}
//}

void FacebookController::processFacebookLoginResult(JSONNode resultItem) {
//	CCLOG("processFacebookLoginResult");
//	int errCode = JSONUtil::getInt(resultItem, "errCode");
//	if (errCode != 0) {
//		if (errCode == ACCOUNT_BINDED_YET && action == ActionTryBind) {
//			showSwitchNotify();
//			return;
//		}
//		showFail();
//		return;
//	}
//
//	string passport = JSONUtil::getString(resultItem, "passport");
//	string password = JSONUtil::getString(resultItem, "password");
//
//	if (action == ActionTryBind) {
//		string fid = FacebookUtil::getInstance()->getId();
//		Singletons::getPlayer()->setFid(fid);
//		this->setFid(fid);
//		bindOK = true;
//		loadFacebookData();
//		setNameAndIcon();
//		action = ActionNone;
//		showBindOK();
//		return;
//	} else if (action == ActionTrySwitch) {
//		Singletons::getPlayer()->setFid(FacebookUtil::getInstance()->getId());
//		bindOK = true;
//		if (passport != "" && password != "") {
//			loadFacebookData();
//			SaveFileManager::getInstance()->switchAccount(passport, password);
//			Singletons::getLoginInfo()->reset();
//			Singletons::getPhpPingSender()->setEnabled(false);
//			Singletons::getRequestResponseManager()->reset();
//			Singletons::getPlayer()->setId("");
//			Singletons::getPlayer()->setFid("");
//			Singletons::getPlayer()->setGid("");
//			setNameAndIcon();
//			CCScene* scene = CCDirector::sharedDirector()->getRunningScene();
//			if (scene->getTag() == Tag::HallScene) {
//				CCDirector::sharedDirector()->replaceScene(CoverLayer::scene());
//			} else {
//				CCDirector::sharedDirector()->end();
//			}
//		}
//		showSwitchOK();
//		action = ActionNone;
//		return;
//	}
}

void FacebookController::setNameAndIcon() {
//	string name = FacebookUtil::getInstance()->getName();
//	CCLOG("change facebook name: %s", name.c_str());
//	if (name != Singletons::getPlayer()->getName()) {
//		Singletons::getPlayer()->setName(name);
//		SaveFileManager::getInstance()->setName(name);
//		PhpCommandSendHelper::sendModifyName(name);
//	}
//
//	int iconId = Singletons::getPlayer()->getIconId();
//	iconId = 10000 + iconId % 10000;
//	CCLOG("change facebook iconId: %d", iconId);
//	if (iconId != Singletons::getPlayer()->getIconId()) {
//		Singletons::getPlayer()->setIconId(iconId);
//		SaveFileManager::getInstance()->setIconId(iconId);
//
//		IconChangeData* icd = new IconChangeData();
//		icd->iconId = iconId;
//		icd->fid = "";
//		icd->path = "";
//		icd->autorelease();
//		IconChangeEvent::get()->fire(icd);
//
//		PhpCommandSendHelper::sendModifyIconId(iconId);
//	}
//
//	UpdateUserInfoEvent::get()->fire(NULL);
//	loadIconAndShow(myFid);
}

void FacebookController::showFail() {
//	CCLOG("showFail");
//	Singletons::getPopupWindowManager()->hidePopup(PopupWindowManager::PopupFacebookWaitNotice);
//	if (action == ActionTryBind) {
//		Singletons::getPopupWindowManager()->createAndShowPopup<FacebookNotifyOkButtonClickEvent>(
//			PopupWindowManager::PopupFacebookInfo, R::text::facebook_bind_failed, R::image::Popup::frame_ok);
//	}
//
}


void FacebookController::showSwitchNotify() {
	CCLOG("showSwitchNotify");
}

void FacebookController::showBindOK() {
//	CCLOG("showBindOK");
//	Singletons::getPopupWindowManager()->hidePopup(PopupWindowManager::PopupFacebookWaitNotice);
//	Singletons::getPopupWindowManager()->createAndShowPopup<FacebookNotifyOkButtonClickEvent>(
//		PopupWindowManager::PopupFacebookInfo, R::text::facebook_bind_ok, R::image::Popup::frame_ok);
}

void FacebookController::showSwitchOK() {
	CCLOG("showSwitchOK");
}

//void FacebookController::processRedirectResult(InterThreadMessage* message) {
//	CCLOG("processRedirectResult");
//	string fid = message->getParam(Parameters::FacebookId);
//	string iconUrl = message->getParam(Parameters::RedirectedUrl);
//	CCLOG("fid: %s, iconUrl: %s", fid.c_str(), iconUrl.c_str());
//	if (fid != "" && iconUrl != "") {
//		iconUrlCache[fid] = iconUrl;
//		tryLoadIcon(fid, iconUrl);
//	}
//}

void FacebookController::tryLoadIcon(string fid, string iconUrl) {
//	CCLOG("tryLoadIcon");
//	string iconPath = iconPathCache[iconUrl];
//	if (iconPath == "") {
//		string path = Constants::getExternalPath() + ".avatar/f_";
//		path += fid;
//		path += ".avatar";
//
//		InterThreadMessage* send = InterThreadMessage::create(Messages::DownloadFile);
//		send->addParam(Parameters::ServerFileUrl, iconUrl);
//		send->addParam(Parameters::LocalFilePath, path);
//		send->addParam(Parameters::DownloadTag, "FacebookController:" + fid);
//		Singletons::getThreadManager()->sendMessageFromGLThread(ThreadName::Download, send);
//	} else {
//		CCLOG("load icon path from cache of fid: %s", fid.c_str());
//		IconChangeData* icd = new IconChangeData();
//		icd->iconId = -1;
//		icd->fid = fid;
//		icd->path = iconPath;
//		icd->autorelease();
//		IconChangeEvent::get()->fire(icd);
//	}
}
//
//void FacebookController::processDownloadFileSuccess(InterThreadMessage* message) {
//	string serverFileUrl = message->getParam(Parameters::ServerFileUrl);
//	string localFilePath = message->getParam(Parameters::LocalFilePath);
//	string downloadTag = message->getParam(Parameters::DownloadTag);
//
//	iconPathCache[serverFileUrl] = localFilePath;
//
//	string fid = downloadTag.substr(19);
//	CCLOG("download success of fid: %s", fid.c_str());
//	IconChangeData* icd = new IconChangeData();
//	icd->iconId = -1;
//	icd->fid = fid;
//	icd->path = localFilePath;
//	icd->autorelease();
//	IconChangeEvent::get()->fire(icd);
//}

string FacebookController::getLocalCachedIconFile(string fid) {
	string url = iconUrlCache[fid];
	if (url != "") {
		string path = iconPathCache[url];
		return path;
	} else {
		return "";
	}
}

void FacebookController::loadIconAndShow(string fid) {
//	string iconUrl = iconUrlCache[fid];
//	if (iconUrl == "") {
//		InterThreadMessage* send = InterThreadMessage::create(Messages::Redirect);
//		send->addParam(Parameters::FacebookId, fid);
//		send->addParam(Parameters::IsSmallPic, "false");
//		Singletons::getThreadManager()->sendMessageFromGLThread(ThreadName::Redirect, send);
//	} else {
//		tryLoadIcon(fid, iconUrl);
//	}
}



JSONNode FacebookController::getFriendIdsJson() {
	JSONNode friendListNode(JSON_ARRAY);
	for (map<string, string>::iterator it = friends.begin(); it != friends.end(); it++) {
		string id = it->first;
		friendListNode.push_back(JSONNode("id", id));
	}
	return friendListNode;
}



const map<string, string>& FacebookController::getFriends() {
	return friends;
}

void FacebookController::postInvite(string friendFid) {
//    CCLOG("post facebook invite");
//	FacebookUtil::getInstance()->publishFeedDialog(
//		R::text::invite_name,
//		R::text::invite_caption,
//		R::text::invite_description,
//		Constants::marketLinkAddress,
//		Constants::marketIconAddress,
//		friendFid);
}

void FacebookController::postShare() {

}
