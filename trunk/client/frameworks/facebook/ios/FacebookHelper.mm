//
//  FacebookHelper.mm
//  Defender3
//
//  Created by lu lu on 13-5-23.
//
//

#include "FacebookHelper.h"
#include "FacebookSDK/FacebookSDK.h"

@interface ProtectedFunctions : NSObject

+ (void)sessionStateChanged:(FBSession *)session
                      state:(FBSessionState) state
                      error:(NSError *)error;

+ (void)sessionOpenedSuccess:(FBSession *)session;
+ (void)sessionCloseLoginFailed;
+ (void)sessionClosedSuccess;
+ (void)saveCurrentToken:(FBSession *)session;

@end

@implementation ProtectedFunctions

+ (void)sessionStateChanged:(FBSession *)session
                      state:(FBSessionState) state
                      error:(NSError *)error{
    switch (state) {
        case FBSessionStateOpen:
//            FacebookHelper::getInstance()->publishFeedDialog("Checkout my Friend Smash greatness!", "Come smash me back!", "Can you beat my score?", "https://www.friendsmash.com/challenge_brag_%llu", "http://www.friendsmash.com/images/logo_large.jpg");
//            FacebookHelper::getInstance()->requestUserInfo();
//            FacebookHelper::getInstance()->requestFriendInfo();
            NSLog(@"sessionstate open");
            [self sessionOpenedSuccess:session];
            break;
        case FBSessionStateClosed:
            NSLog(@"sessionstate closed");
            [self sessionClosedSuccess];
            break;
        case FBSessionStateClosedLoginFailed:
            NSLog(@"sessionstate closedLoginFailed");
            [self sessionCloseLoginFailed];
//            [[FBSession activeSession] closeAndClearTokenInformation];
//            [FBSession setActiveSession:nil];
//            FacebookHelper::getInstance()->createNewSession();
            break;
        default:
            break;
    }
}

+ (void)sessionOpenedSuccess:(FBSession *)session{
    if(FacebookHelper::getInstance()->getFacebookAction() == FacebookHelper::LOGIN){
        [self saveCurrentToken:session];
        FacebookHelper::getInstance()->getFacebookNotification()->onSessionLoginSuccess();
        FacebookHelper::getInstance()->setFacebookAction(FacebookHelper::NONE);
    }
    if(FacebookHelper::getInstance()->getFacebookAction() == FacebookHelper::TRY_LOGIN){
        [self saveCurrentToken:session];
        FacebookHelper::getInstance()->getFacebookNotification()->onSessionTryLoginSuccess();
        FacebookHelper::getInstance()->setFacebookAction(FacebookHelper::NONE);
    }
}

+ (void)sessionCloseLoginFailed{
    if (FacebookHelper::getInstance()->getFacebookAction() == FacebookHelper::LOGIN) {
       FacebookHelper::getInstance()->getFacebookNotification()->onSessionLoginFailed();
        FacebookHelper::getInstance()->setFacebookAction(FacebookHelper::NONE);
    }
    if (FacebookHelper::getInstance()->getFacebookAction() == FacebookHelper::TRY_LOGIN) {
        FacebookHelper::getInstance()->getFacebookNotification()->onSessionTryLoginFailed();
        FacebookHelper::getInstance()->setFacebookAction(FacebookHelper::NONE);
    }
    if (FacebookHelper::getInstance()->getFacebookAction() == FacebookHelper::LOGOUT) {
        FacebookHelper::getInstance()->getFacebookNotification()->onSessionClosedFailed();
        FacebookHelper::getInstance()->setFacebookAction(FacebookHelper::NONE);
    }
}

+ (void)sessionClosedSuccess{
    if (FacebookHelper::getInstance()->getFacebookAction() == FacebookHelper::LOGOUT) {
        FacebookHelper::getInstance()->getFacebookNotification()->onSessionClosed();
        FacebookHelper::getInstance()->setFacebookAction(FacebookHelper::NONE);
    }
}

+ (void)saveCurrentToken:(FBSession *)session{
    NSString* nsToken = [[session accessTokenData] accessToken];
    string token =[nsToken cStringUsingEncoding:NSUTF8StringEncoding];
    FacebookHelper::getInstance()->setToken(token);
}


@end

const int FacebookHelper::ACTION_NONE = 0;
const int FacebookHelper::ACTION_POST_FEEDDIALOG = 1;

const int FacebookHelper::NONE = 0;
const int FacebookHelper::LOGIN = 1;
const int FacebookHelper::LOGOUT = 2;
const int FacebookHelper::TRY_LOGIN = 3;


FacebookHelper::FacebookHelper(){
    _feedDialogParams = NULL;
    _pendingAction = ACTION_NONE;
    _facebookAction = NONE;
}

FacebookHelper::~FacebookHelper(){
    CC_SAFE_RELEASE_NULL(_feedDialogParams);
}

string FacebookHelper::getUserId(){
    return _userID;
}

string FacebookHelper::getUserName(){
    return _userName;
}

string FacebookHelper::getUserPicUrl(){
    return _userPicUrl;
}

string FacebookHelper::getUserGender(){
    return _userGender;
}

string FacebookHelper::getToken(){
    return _token;
}

vector<string> FacebookHelper::getFriendIds(){
    return _friendIds;
}

vector<string> FacebookHelper::getFriendIdsInstalled(){
    return _friendIdsInstalled;
}

vector<string> FacebookHelper::getFriendNames(){
    return _friendNames;
}

vector<string> FacebookHelper::getFriendGenders() {
    return _friendGenders;
}

vector<string> FacebookHelper::getFriendPictureUrls() {
    return _friendPictureUrls;
}

int FacebookHelper::getFacebookAction(){
    return _facebookAction;
}

void FacebookHelper::setFacebookAction(int action){
    _facebookAction = action;
}

void FacebookHelper::setToken(string token){
    _token = token;
}

void FacebookHelper::setFacebookNotification(FacebookNotification *facebookNotification){
    _facebookNotification = facebookNotification;
}

FacebookNotification* FacebookHelper::getFacebookNotification(){
    return _facebookNotification;
}

void FacebookHelper::createNewSession(){
    FBSession* session = [[FBSession alloc] init];
    [FBSession setActiveSession: session];
}

void FacebookHelper::facebookLogin(){
    NSLog(@"facebooklogin");
    _facebookAction = LOGIN;
    [FBSession openActiveSessionWithReadPermissions:nil
                                       allowLoginUI:true
                                  completionHandler:^(FBSession *session,
                                                      FBSessionState status,
                                                      NSError *error)
    {
        [ProtectedFunctions sessionStateChanged:session state:status error:error];
    }];
}

void FacebookHelper::facebookLoginWithoutUI(){
    NSLog(@"facebookloginWithoutUI");
    _facebookAction = TRY_LOGIN;
    [FBSession openActiveSessionWithReadPermissions:nil
                                       allowLoginUI:false
                                  completionHandler:^(FBSession *session,
                                                      FBSessionState status,
                                                      NSError *error)
     {
         [ProtectedFunctions sessionStateChanged:session state:status error:error];
     }];

}

void FacebookHelper::facebookLogout(){
    _facebookAction = LOGOUT;
    [FBSession.activeSession closeAndClearTokenInformation];
    [FBSession.activeSession close];
    [FBSession setActiveSession:nil];
}

//只获取id，name的获取个人信息的方法
void FacebookHelper::requestForMe(){
    if (FBSession.activeSession.isOpen) {
        [[FBRequest requestForMe] startWithCompletionHandler:
         ^(FBRequestConnection *connection,
           NSDictionary<FBGraphUser> *user,
           NSError *error) {
             if (!error && user){
                 NSLog(@"user name = %@", user.name);
                 NSLog(@"user id = %@", user.id);
                 FacebookHelper::getInstance()->getFacebookNotification()->onRequestUserInfoSuccess();
             } else {
                 FacebookHelper::getInstance()->getFacebookNotification()->onRequestUserInfoFailed();
             }
         }];
    }
}

//如果需要个人信息里的id，那么以外的方法，调用改方法。param的填法和gender，picture一样。
void FacebookHelper::requestUserInfo(){
    if (FBSession.activeSession.isOpen) {
        NSDictionary* params = [NSDictionary dictionaryWithObject:@"id,gender,name,picture" forKey:@"fields"];
        [[FBRequest requestWithGraphPath:@"me" parameters:params HTTPMethod:nil] startWithCompletionHandler:
                                                                                ^(FBRequestConnection *connection,
                                                                                  id result,
                                                                                  NSError *error){
            if (!error && result){
                NSString *userID = [result objectForKey:@"id"];
                NSString *name = [result objectForKey:@"name"];
                NSString *gender = [result objectForKey:@"gender"];
                NSString *url =  [[[result objectForKey:@"picture"] objectForKey:@"data"] objectForKey:@"url"];
                NSLog(@"uesr Id = %@", userID);
                NSLog(@"name = %@", name);
                NSLog(@"gender = %@", gender);
                NSLog(@"url = %@", url);
                _userID=[userID cStringUsingEncoding:NSUTF8StringEncoding];
                _userName=[name cStringUsingEncoding:NSUTF8StringEncoding];
                _userGender=[gender cStringUsingEncoding:NSUTF8StringEncoding];
                _userPicUrl=[url cStringUsingEncoding:NSUTF8StringEncoding];
                CCLog("CC ID = %s", _userID.c_str());
                CCLog("CC NAME = %s", _userName.c_str());
                CCLog("CC GENDER = %s", _userGender.c_str());
                CCLog("CC URL = %s", _userPicUrl.c_str());
                FacebookHelper::getInstance()->getFacebookNotification()->onRequestUserInfoSuccess();
            } else {
                FacebookHelper::getInstance()->getFacebookNotification()->onRequestUserInfoFailed();
            }
        }];

    }
}

//直接获取好友信息的方法
void FacebookHelper::requestForMyFriend(){
    if(FBSession.activeSession.isOpen){
        [FBRequestConnection startForMyFriendsWithCompletionHandler:^(FBRequestConnection *connection,
                                                                      id result,
                                                                      NSError *error){
            if (!error && result){
                NSArray *fetchedFriendData = [[NSArray alloc] initWithArray:[result objectForKey:@"data"]];
                _friendIds.clear();
                _friendNames.clear();
                for (int i = 0; i < [fetchedFriendData count]; i++) {
                    NSDictionary *friendData = [fetchedFriendData objectAtIndex:i];
                    NSString *friendId = [friendData objectForKey:@"id"];
                    NSString *friendName = [friendData objectForKey:@"name"];
                    NSLog(@"firend id = %@", friendId);
                    NSLog(@"firend name = %@", friendName);
                    string ccFriendid = [friendId cStringUsingEncoding:NSUTF8StringEncoding];
                    string ccFriendName = [friendName cStringUsingEncoding:NSUTF8StringEncoding];
                    _friendIds.push_back(ccFriendid);
                    _friendNames.push_back(ccFriendName);
                    FacebookHelper::getInstance()->getFacebookNotification()->onRequestFriendInfoSuccess();
                }
            } else {
                FacebookHelper::getInstance()->getFacebookNotification()->onRequestFriendInfoFailed();
            }
        }];
    }
}

//如果需要朋友的id，name之外的信息，可以试用这个方法，param就按照gender，picture的填法。
void FacebookHelper::requestFriendInfo(){
    if(FBSession.activeSession.isOpen){
        NSDictionary* params = [NSDictionary dictionaryWithObject:@"id,gender,name,picture,installed" forKey:@"fields"];
        [[FBRequest requestWithGraphPath:@"me/friends" parameters:params HTTPMethod:nil] startWithCompletionHandler:^(FBRequestConnection *connection,id result,NSError *error){
            NSLog(@"result = %@", [result objectForKey:@"data"]);
            _friendIds.clear();
            _friendIdsInstalled.clear();
            _friendNames.clear();
            _friendPictureUrls.clear();
            _friendGenders.clear();
            if (!error && result){
                NSArray *fetchedFriendData = [[NSArray alloc] initWithArray:[result objectForKey:@"data"]];
                for (int i = 0; i < [fetchedFriendData count]; i++) {
                    NSDictionary *friendData = [fetchedFriendData objectAtIndex:i];
                    NSString *friendId = [friendData objectForKey:@"id"];
                    NSString *friendName = [friendData objectForKey:@"name"];
                    NSString *installed = [friendData objectForKey:@"installed"];
                    NSLog(@"friend id = %@", friendId);
                    NSLog(@"friend name = %@", friendName);
                    
                    string ccFriendid = [friendId cStringUsingEncoding:NSUTF8StringEncoding];
                    string ccFriendName = [friendName cStringUsingEncoding:NSUTF8StringEncoding];
                    if(installed!=nil && [installed boolValue]){
                        _friendIdsInstalled.push_back(ccFriendid);
                    }
                    _friendIds.push_back(ccFriendid);
                    _friendNames.push_back(ccFriendName);
                    _friendGenders.push_back("");
                    _friendPictureUrls.push_back("");
                }
                FacebookHelper::getInstance()->getFacebookNotification()->onRequestFriendInfoSuccess();
            } else {
                FacebookHelper::getInstance()->getFacebookNotification()->onRequestFriendInfoFailed();
            }
        }];
    }
}

void FacebookHelper::continuePostFeedDialog(){
    NSString* nsName = [NSString stringWithCString:_feedDialogParams->_name.c_str()
                                          encoding:[NSString defaultCStringEncoding]];
    NSString* nsCaption = [NSString stringWithCString:_feedDialogParams->_caption.c_str()
                                             encoding:[NSString defaultCStringEncoding]];
    NSString* nsDescription = [NSString stringWithCString:_feedDialogParams->_description.c_str()
                                                 encoding:[NSString defaultCStringEncoding]];
    NSString* nsPicture = [NSString stringWithCString:_feedDialogParams->_pic.c_str()
                                             encoding:[NSString defaultCStringEncoding]];
    NSString* nsLink = [NSString stringWithCString:_feedDialogParams->_link.c_str()
                                          encoding:[NSString defaultCStringEncoding]];

    // Prepare the native share dialog parameters
    FBShareDialogParams *shareParams = [[FBShareDialogParams alloc] init];
    shareParams.link = [NSURL URLWithString:nsLink];
    shareParams.name = nsName;
    shareParams.caption= nsCaption;
    shareParams.picture= [NSURL URLWithString:nsPicture];
    shareParams.description = nsDescription;
    
    // Prepare the web dialog parameters
    NSDictionary *params = @{
                             @"name" : shareParams.name,
                             @"caption" : shareParams.caption,
                             @"description" : shareParams.description,
                             @"picture" : nsPicture,
                             @"link" : nsLink
                             };
    
    // Invoke the dialog
    [FBWebDialogs presentFeedDialogModallyWithSession:nil
                                           parameters:params
                                              handler:
     ^(FBWebDialogResult result, NSURL *resultURL, NSError *error) {
         if (error) {
             NSLog(@"Error publishing story.");
         } else {
             if (result == FBWebDialogResultDialogNotCompleted) {
                 NSLog(@"User canceled story publishing.");
             } else {
                 NSLog(@"Story published.");
             }
         }}];

}

void FacebookHelper::handlePendingAction(){
    switch (_pendingAction) {
        case ACTION_POST_FEEDDIALOG:
            continuePostFeedDialog();
            break;
        default:
            break;
    }
}

void FacebookHelper::publishFeedDialog(string name, string caption, string description, string link, string pic){
    _pendingAction = ACTION_POST_FEEDDIALOG;
    _feedDialogParams = FeedDialogParams::createfeedDialogParams(name, caption, description, link, pic);
    _feedDialogParams->retain();
    if(!hasPublishPermission()){
        requestPublishPermission();
    } else {
        continuePostFeedDialog();
     }
}

void FacebookHelper::requestPublishPermission(){
    NSLog(@"requestPublishPermission");
    [FBSession.activeSession requestNewPublishPermissions:@[@"publish_actions"]
                                          defaultAudience:FBSessionDefaultAudienceFriends
                                        completionHandler:^(FBSession *session, NSError *error) {
                                            handlePendingAction();
                                        }];
}

bool FacebookHelper::hasPublishPermission(){
    return [FBSession.activeSession.permissions containsObject:@"publish_actions"];
}


FeedDialogParams* FeedDialogParams::createfeedDialogParams(string name, string caption, string description, string link, string pic){
    FeedDialogParams* param = new FeedDialogParams(name, caption, description, link, pic);
	if (param)
	{
		param->autorelease();
		return param;
	}
	CC_SAFE_DELETE(param);
	return NULL;
}

FeedDialogParams::FeedDialogParams(string name, string caption, string description, string link, string pic){
    _name = name;
    _caption = caption;
    _description = description;
    _link = link;
    _pic = pic;
}
