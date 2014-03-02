package com.game.facebook;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import android.app.Activity;
import android.content.Context;
import android.content.SharedPreferences;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.os.Handler;
import android.text.TextUtils;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Toast;

import com.facebook.AccessToken;
import com.facebook.FacebookException;
import com.facebook.FacebookOperationCanceledException;
import com.facebook.FacebookRequestError;
import com.facebook.Request;
import com.facebook.Request.Callback;
import com.facebook.Request.GraphUserListCallback;
import com.facebook.Response;
import com.facebook.Session;
import com.facebook.Session.Builder;
import com.facebook.Session.StatusCallback;
import com.facebook.SessionLoginBehavior;
import com.facebook.SessionState;
import com.facebook.internal.ServerProtocol;
import com.facebook.internal.Utility;
import com.facebook.model.GraphObject;
import com.facebook.model.GraphUser;
import com.facebook.widget.WebDialog;
import com.facebook.widget.WebDialog.OnCompleteListener;

/**
 * 使用新的facebook sdk的例子类，单例形式，提供了登入，登出，获取个人信息和好友等方法。
 * 原有的session保存工作没有放到该类中，因为facebook提供了UiLifecycleHelper的类来帮助开发者管理session，所以建议使用
 * 用法是在游戏的activity的onCreate, onPause, onResume, onDestroy, onActivityResult,
 * onSaveInstanceState中调用UiLifecycleHelper中的相应方法
 * 
 * @author lulu
 */
public class FacebookHelper {

	public static final int msgOnSessionLoginSuccess = 100;
	public static final int msgOnSessionClosedLoginFailed = 101;
	public static final int msgOnSessionClosed = 102;
	public static final int msgOnSessionClosedFailed = 103;
	public static final int msgOnSessionTryLoginSuccess = 104;
	public static final int msgOnSessionTryLoginFailed = 105;
	public static final int msgOnRequestUserInfoSuccess = 200;
	public static final int msgOnRequestUserInfoFailed = 201;
	public static final int msgOnRequestFriendsInfoSuccess = 300;
	public static final int msgOnRequestFriendsInfoFailed = 301;
	public static final String GRAPH_FACEBOOK_URL = "http://graph.facebook.com/";

	private String _token;
	private String _id;
	private String _name;
	private String _gender;
	private String _pictureUrl;
	private String _location;
	private Handler _handler;
	private StatusCallback _callback;
	private FacebookAction _facebookAction;
	private PendingAction _pendingAction;
	private Activity _activity;
	private Bitmap _bitmapToPost;
	private File _fileToPost;
	private FeedParams _feedToPost;
	private String _feedStringToPost;
	private String[] _friendIds;
	private String[] _friendNames;
	private String[] _friendGenders;
	private String[] _friendPictureUrls;
	private ArrayList<String> _friendIdsInstalled;
	private ArrayList<String> _friendIdsNotInstalled;
	private List<String> _mPermissions = Arrays.asList("publish_actions");

	private enum FacebookAction {
		NONE, LOGIN, LOGOUT, TRY_LOGIN
	}

	private enum PendingAction {
		ACTION_NONE, ACTION_POST_FEEDDIALOG, ACTION_POST_FEEDMESSAGE, ACTION_POST_PHOTOFILE, ACTION_POST_BITMAP
	}

	class FeedParams {
		String _name;
		String _caption;
		String _descrption;
		String _link;
		String _pic;
		String _toUserId;

		FeedParams(String name, String caption, String descrption, String link, String pic, String toUserId) {
			_name = name;
			_caption = caption;
			_descrption = descrption;
			_link = link;
			_pic = pic;
			_toUserId = toUserId;
		}
	}

	private static class FacebookManagerHolder {

		public static final FacebookHelper INSTANCE = new FacebookHelper();
	}

	public static FacebookHelper getInstance() {
		return FacebookManagerHolder.INSTANCE;
	}

	private FacebookHelper() {
	}

	/**
	 * onCreate的时候调用该方法初始化
	 * 
	 * @param handler
	 */
	public void init(Handler handler, Activity activity) {
		_handler = handler;
		_activity = activity;
		_facebookAction = FacebookAction.NONE;
		_callback = new StatusCallback() {

			@Override
			public void call(Session session, SessionState state, Exception exception) {
				onSessionStateChange(session, state, exception);
			}
		};

	}

	/**
	 * 处理sessionState变化的callback
	 * 
	 * @param session
	 * @param state
	 * @param exception
	 */
	private void onSessionStateChange(Session session, SessionState state, Exception exception) {
		switch (state) {
		case OPENED:
			sessionOpenedSuccess(session);
			System.err.println("session OPENED");
			break;

		case CLOSED_LOGIN_FAILED:
			sessionLoginFail();
			System.err.println("session CLOSED_LOGIN_FAILED");
			break;

		case CLOSED:
			sessionClosedSuccess();
			System.err.println("session CLOSED");
			break;

		case OPENED_TOKEN_UPDATED:
			handlePendingAction();
			break;

		default:
			System.err.println("deafault = " + state.toString() + " exception = " + exception);
			break;
		}

	}

	/**
	 * 申请publish权限
	 * 
	 * @param pendingAction
	 */
	private void requestPublishPermission(PendingAction pendingAction) {
		_pendingAction = pendingAction;
		Session session = Session.getActiveSession();
		if (session != null) {
			session.requestNewPublishPermissions(new Session.NewPermissionsRequest(_activity, _mPermissions));
		}
	}

	/**
	 * 是否已有publish权限
	 * 
	 * @return
	 */
	private boolean hasPublishPermission() {
		Session session = Session.getActiveSession();
		return session != null && session.getPermissions().contains("publish_actions");
	}

	/**
	 * 更新权限后，处理原先需要处理的事件
	 */
	private void handlePendingAction() {
		switch (_pendingAction) {
		case ACTION_POST_FEEDDIALOG:
			continuePostFeedDialog();
			break;

		case ACTION_POST_FEEDMESSAGE:

			break;

		case ACTION_POST_BITMAP:

			break;

		case ACTION_POST_PHOTOFILE:

			break;
		}
	}

	private void continuePostFeedDialog() {
		Bundle params = new Bundle();
		params.putString("name", _feedToPost._name);
		params.putString("caption", _feedToPost._caption);
		params.putString("description", _feedToPost._descrption);
		params.putString("link", _feedToPost._link);
		params.putString("picture", _feedToPost._pic);
		if (!"Me".equals(_feedToPost._toUserId)) {
			params.putString("to", _feedToPost._toUserId);
		}
		WebDialog feedDialog = (new WebDialog.FeedDialogBuilder(_activity, Session.getActiveSession(), params)).setOnCompleteListener(new OnCompleteListener() {

			@Override
			public void onComplete(Bundle values, FacebookException error) {
				if (error == null) {
					// When the story is posted, echo the success
					// and the post Id.
					final String postId = values.getString("post_id");
					if (postId != null) {
						Toast.makeText(_activity, "Post Success", Toast.LENGTH_SHORT).show();
					} else {
						// User clicked the Cancel button
						Toast.makeText(_activity.getApplicationContext(), "Publish cancelled", Toast.LENGTH_SHORT).show();
					}
				} else if (error instanceof FacebookOperationCanceledException) {
					// User clicked the "x" button
					Toast.makeText(_activity.getApplicationContext(), "Publish cancelled", Toast.LENGTH_SHORT).show();
				} else {
					// Generic, ex: network error
					Toast.makeText(_activity.getApplicationContext(), "Error posting story", Toast.LENGTH_SHORT).show();
				}
			}

		}).build();
		feedDialog.show();
	}

	private void cotinuePostFeedMessage() {
		Session session = Session.getActiveSession();
		if (session.isOpened()) {
			Request request = Request.newStatusUpdateRequest(session, _feedStringToPost, new Callback() {

				@Override
				public void onCompleted(Response response) {
					showFeedMessagePostResult(response.getGraphObject(), response.getError());
				}
			});
			request.executeAsync();
		}
	}

	private void continuePostPhoto() throws FileNotFoundException {
		Session session = Session.getActiveSession();
		if (session.isOpened()) {
			Request request = Request.newUploadPhotoRequest(session, _fileToPost, new Callback() {

				@Override
				public void onCompleted(Response response) {
					showPhotoPostResult(response.getGraphObject(), response.getError());
				}
			});
			request.executeAsync();
		}
	}

	private void continuePostBitmap() {
		Session session = Session.getActiveSession();
		if (session.isOpened()) {
			Request request = Request.newUploadPhotoRequest(session, _bitmapToPost, new Callback() {

				@Override
				public void onCompleted(Response response) {
					showPhotoPostResult(response.getGraphObject(), response.getError());
				}
			});
			request.executeAsync();
		}
	}

	private void sessionLoginFail() {
		if (_facebookAction == FacebookAction.LOGIN) {
			_handler.sendEmptyMessage(msgOnSessionClosedLoginFailed);
			_facebookAction = FacebookAction.NONE;
		}
		if(_facebookAction == FacebookAction.TRY_LOGIN){
			_handler.sendEmptyMessage(msgOnSessionTryLoginFailed);
			_facebookAction = FacebookAction.NONE;
		}
		if(_facebookAction == FacebookAction.LOGOUT){
			_handler.sendEmptyMessage(msgOnSessionClosedFailed);
			_facebookAction = FacebookAction.NONE;
		}
	}
	

	private void sessionClosedSuccess() {
		if (_facebookAction == FacebookAction.LOGOUT) {
			_handler.sendEmptyMessage(msgOnSessionClosed);
			_facebookAction = FacebookAction.NONE;
		}
	}

	/**
	 * session open成功后，请求用户数据
	 * 
	 * @param session
	 */
	private void sessionOpenedSuccess(Session session) {
		if (_facebookAction == FacebookAction.LOGIN && session.isOpened()) {
			_token = session.getAccessToken();
			_handler.sendEmptyMessage(msgOnSessionLoginSuccess);
			_facebookAction = FacebookAction.NONE;
		}
		if(_facebookAction == FacebookAction.TRY_LOGIN && session.isOpened()){
			_token = session.getAccessToken();
			_handler.sendEmptyMessage(msgOnSessionTryLoginSuccess);
			_facebookAction = FacebookAction.NONE;
		}
	}

	/**
	 * 请求用户数据
	 */
	public void requestUserInfo() {
		Session currentSession = Session.getActiveSession();
		if (currentSession.isOpened()) {
			Request request = Request.newMeRequest(currentSession, new Request.GraphUserCallback() {

				@Override
				public void onCompleted(GraphUser me, Response response) {
					if (me != null) {
						resolveUserInfo(me);
					}
				}
			});
			Bundle parameters = new Bundle();
			// 请求用户信息时填入的字段，有其他需要可以自行添加
			parameters.putString("fields", "id, name, gender, picture, friends");
			request.setParameters(parameters);
			Request.executeBatchAsync(request);
		}
	}

	/**
	 * 解析保存返回的用户信息
	 * 
	 * @param me
	 */
	private void resolveUserInfo(GraphUser me) {
		_id = me.getId();
		_name = me.getName();
		_gender = (String) me.getProperty("gender");
		JSONObject picJsonObject = (JSONObject) me.getProperty("picture");
		JSONObject friendIdJsonObject = (JSONObject) me.getProperty("friends");
		try {
			if (picJsonObject != null && picJsonObject.has("data")) {
				JSONObject picDataObject = picJsonObject.getJSONObject("data");
				if (picDataObject.has("url")) {
					_pictureUrl = picDataObject.getString("url");
				}
			}

			if (friendIdJsonObject != null && friendIdJsonObject.has("data")) {
				JSONArray friendArray = friendIdJsonObject.getJSONArray("data");
				_friendIds = new String[friendArray.length()];
				for (int i = 0; i < friendArray.length(); ++i) {
					JSONObject friend = friendArray.getJSONObject(i);
					_friendIds[i] = friend.getString("id");
				}
			}
		} catch (JSONException e) {
			e.printStackTrace();
			_handler.sendEmptyMessage(msgOnRequestUserInfoFailed);
			return;
		}
		// 个人信息获取完毕，可以选择直接认为登陆成功，或者发起其他请求
		if (_handler != null) {
			_handler.sendEmptyMessage(msgOnRequestUserInfoSuccess);
		}
		// System.out.println("id = " + _id + " name = " + _name + " gender = "
		// + _gender + " pictureurl = " + _pictureUrl);
		// for (int i = 0; i < _friendIds.length; i++) {
		// System.out.println("friend " + i + " = " + _friendIds[i]);
		// }
	}

	/**
	 * 请求好友信息（可以用来显示好友列表之类的功能）
	 */
	public void requestFriendInfo() {
		Session session = Session.getActiveSession();
		if (session.isOpened()) {
			Request request = Request.newMyFriendsRequest(session, new GraphUserListCallback() {

				@Override
				public void onCompleted(List<GraphUser> users, Response response) {
					resolveFriendsInfo(users);
				}
			});
			Bundle parameters = new Bundle();
			parameters.putString("fields", "id, name, picture, installed");
			request.setParameters(parameters);
			Request.executeBatchAsync(request);

		}
	}

	/**
	 * 解析好友信息
	 * 
	 * @param users
	 */
	private void resolveFriendsInfo(List<GraphUser> users) {
		_friendNames = new String[users.size()];
		_friendIds = new String[users.size()];
		_friendGenders = new String[users.size()];
		_friendPictureUrls = new String[users.size()];
		_friendIdsNotInstalled = new ArrayList<String>();
		_friendIdsInstalled = new ArrayList<String>();

		for (int i = 0; i < users.size(); i++) {
			GraphUser user = users.get(i);
			_friendNames[i] = user.getName();
			_friendIds[i] = user.getId();
			_friendGenders[i] = (String) user.getProperty("gender");
			
			boolean installed = false;
			if(user.getProperty("installed") != null){
				installed = (Boolean) user.getProperty("installed");
			}
			if(!installed){
				_friendIdsNotInstalled.add(user.getId());
			} else {
				_friendIdsInstalled.add(user.getId());
			}

			JSONObject picJsonObject = (JSONObject) user.getProperty("picture");
			try {
				if (picJsonObject != null && picJsonObject.has("data")) {
					JSONObject picDataObject = picJsonObject.getJSONObject("data");
					if (picDataObject.has("url")) {
						_friendPictureUrls[i] = picDataObject.getString("url");
					}
				}
			} catch (JSONException e) {
				e.printStackTrace();
				_handler.sendEmptyMessage(msgOnRequestFriendsInfoFailed);
				return;
			}
		}
		// 好友信息获取完毕
		for (int i = 0; i < users.size(); i++) {
			System.out.println("friend " + i + " name = " + _friendNames[i] + " id = " + _friendIds[i] + " gender = " + _friendGenders[i] + " pictureUrl = " + _friendPictureUrls[i]);
		}
		_handler.sendEmptyMessage(msgOnRequestFriendsInfoSuccess);
	}

	/**
	 * FeedMessage上传返回
	 * 
	 * @param result
	 * @param error
	 */
	private void showFeedMessagePostResult(GraphObject result, FacebookRequestError error) {
		System.out.println(result.toString());
		if (error == null) {
			System.out.println("FeedMessage post success");
		} else {
			System.err.println(" error = " + error.getErrorMessage());
		}
	}

	/**
	 * 照片上传返回
	 * 
	 * @param result
	 * @param error
	 */
	private void showPhotoPostResult(GraphObject result, FacebookRequestError error) {
		System.out.println(result.toString());
		if (error == null) {
			System.out.println("Photo post success");
		} else {
			System.err.println(" error = " + error.getErrorMessage());
		}
	}

	/**
	 * 初始化弹框参数
	 * 
	 * @param params
	 */
	private void initParams(Bundle params) {
		Session session = Session.getActiveSession();

		if (session != null && session.isOpened()) {
			params.putString("app_id", session.getApplicationId());
			params.putString("access_token", session.getAccessToken());
		}

		if (!params.containsKey(ServerProtocol.DIALOG_PARAM_REDIRECT_URI)) {
			params.putString(ServerProtocol.DIALOG_PARAM_REDIRECT_URI, "fbconnect://success");
		}
	}

	public String getToken() {
		return _token;
	}

	public String getId() {
		return _id;
	}

	public String getName() {
		return _name;
	}

	public String getGender() {
		return _gender;
	}

	public String getPictureUrl() {
		return _pictureUrl;
	}

	public String getLocation() {
		return _location;
	}

	public StatusCallback getCallback() {
		return _callback;
	}

	public String[] getFriendIds() {
		return _friendIds;
	}

	public String[] getFriendNames() {
		return _friendNames;
	}

	public String[] getFriendGenders() {
		return _friendGenders;
	}

	public String[] getFriendPictureUrls() {
		return _friendPictureUrls;
	}
	
	public String[] getFriendsInstalled(){
		return _friendIdsInstalled.toArray(new String[_friendIdsInstalled.size()]);
	}

	/**
	 * 登陆facebook, 只需要只读权限, 在callback里可以获取到当前状态。 如果需要上传权限，请使用
	 * {@link #facebookLoginForPublish(Activity)}方法
	 * 部分permission可以考虑在用户需要的时候再次请求权限。
	 * 比如在登陆的时候只有读取用户信息权限，在用户需要上传照片的时候，请求PUBLISH权限。
	 * 
	 * @param activity
	 */
	public void facebookLoginForRead(Activity activity) {
		_facebookAction = FacebookAction.LOGIN;
		Session session = Session.getActiveSession();
		if (!session.isOpened() && !session.isClosed()) {
			session.openForRead(new Session.OpenRequest(activity));
		} else {
			Session.openActiveSession(activity, true, _callback);
		}
	}
	
	/**
	 * facebook login, 不弹出loginUI
	 * @param activity
	 */
	public void facebookLoginWithoutUI(Activity activity){
		_facebookAction = FacebookAction.TRY_LOGIN;
		Session.openActiveSession(activity, false, _callback);
	}

	/**
	 * 登陆facebook，请求publish权限，如果希望在登陆的时候就得到上传权限，请使用此方法
	 * openRequest的参数设置均为默认，有需要可以改动
	 * 
	 * @param activity
	 */
	public void facebookLoginForPublish(Activity activity) {
		_facebookAction = FacebookAction.LOGIN;
		Session session = Session.getActiveSession();
		Session.OpenRequest openRequest = new Session.OpenRequest(activity).setPermissions(_mPermissions).setLoginBehavior(SessionLoginBehavior.SSO_WITH_FALLBACK).setRequestCode(Session.DEFAULT_AUTHORIZE_ACTIVITY_CODE)
				.setCallback(_callback);
		if (!session.isOpened() && !session.isClosed()) {
			session.openForPublish(openRequest);
		} else {
			Session sessionNew = new Builder(activity).build();
			Session.setActiveSession(sessionNew);
			sessionNew.openForPublish(openRequest);
		}
	}

	/**
	 * 登出facebook
	 */
	public void facebookLogout() {
		_facebookAction = FacebookAction.LOGOUT;
		Session session = Session.getActiveSession();
		if (!session.isClosed()) {
			session.closeAndClearTokenInformation();
		} else {
			_handler.sendEmptyMessage(msgOnSessionClosedFailed);
			_facebookAction = FacebookAction.NONE;
		}
	}

	/**
	 * 发送图片到相册
	 * 
	 * @param bitmap
	 */
	public void postPhoto(Bitmap bitmap) {
		_bitmapToPost = bitmap;
		if (hasPublishPermission()) {
			continuePostBitmap();
		} else {
			requestPublishPermission(PendingAction.ACTION_POST_FEEDDIALOG);
		}
	}

	/**
	 * 发送图片文件到相册
	 * 
	 * @param file
	 * @throws FileNotFoundException
	 */
	public void postPhoto(File file) throws FileNotFoundException {
		_fileToPost = file;
		if (hasPublishPermission()) {
			continuePostPhoto();
		} else {
			requestPublishPermission(PendingAction.ACTION_POST_FEEDDIALOG);
		}
	}

	/**
	 * 发送更新状态消息
	 * 
	 * @param message
	 */
	public void postFeedMessage(String message) {
		_feedStringToPost = message;
		if (hasPublishPermission()) {
			cotinuePostFeedMessage();
		} else {
			requestPublishPermission(PendingAction.ACTION_POST_FEEDDIALOG);
		}
	}

	/**
	 * 通过弹框来发送更新状态的消息，传入的Bundle和老的facebookUtil里传入的一样
	 * 
	 * @param activity
	 * @param params
	 */
	public void postFeedMessageThroughDialog(Activity activity, Bundle params) {
		initParams(params);
		WebDialog dialog = new WebDialog(activity, "feed", params, WebDialog.DEFAULT_THEME, new OnCompleteListener() {

			@Override
			public void onComplete(Bundle values, FacebookException error) {
				System.out.println("values = " + (values == null ? "null" : values.toString()) + " error = " + (error == null ? "null" : error.toString()));
			}
		});
		dialog.show();
	}

	/**
	 * 创建apprequests dialog
	 * 
	 * @param activity
	 * @param message
	 */
	public void postAppRequests(Activity activity, String title, String message,String link) {
		Bundle params = new Bundle();
		params.putString("title", title);
		params.putString("message", message);
		params.putString("link", link);
		showDialogWithoutNotificationBar(activity, "apprequests", params);
	}
	
	/**
	 * 创建apprequest dialog，对象是没有安装过我们app的用户
	 * @param activity
	 * @param message
	 */
	public void postAppRequestsToFriendsWithoutInstalled(Activity activity, String title, String message,String link){
		Bundle params = new Bundle();
		params.putString("title", title);
		params.putString("message", message);
		params.putString("link", link);
		String [] suggestedFriends = _friendIdsNotInstalled.toArray(new String[0]);
		params.putString("suggestions", TextUtils.join(",", suggestedFriends));		
		showDialogWithoutNotificationBar(activity, "apprequests", params);
	}

	/**
	 * 创建webDialog
	 * @param activity
	 * @param action
	 * @param params
	 */
	public void showDialogWithoutNotificationBar(Activity activity, String action, Bundle params) {
		WebDialog dialog = new WebDialog.Builder(activity, Session.getActiveSession(), action, params).setOnCompleteListener(new WebDialog.OnCompleteListener() {
			@Override
			public void onComplete(Bundle values, FacebookException error) {
				System.out.println("values = " + (values == null ? "null" : values.toString()) + " error = " + (error == null ? "null" : error.toString()));
			}
		}).build();

		Window dialog_window = dialog.getWindow();
		dialog_window.setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
		dialog.show();
	}

	/**
	 * 简易使用版的FeedDialog构建方法，toUserId传Me将会把Feed发送在自己的wall上
	 * 
	 * @param name
	 * @param caption
	 * @param descrption
	 * @param link
	 * @param pic
	 * @param toUserId
	 */
	public void publishFeedDialog(String name, String caption, String descrption, String link, String pic, String toUserId) {
		_feedToPost = new FeedParams(name, caption, descrption, link, pic, toUserId);
		if (hasPublishPermission()) {
			continuePostFeedDialog();
		} else {
			requestPublishPermission(PendingAction.ACTION_POST_FEEDDIALOG);
		}

	}

	/**
	 * 通过弹框来添加好友
	 * 
	 * @param activity
	 * @param userId
	 */
	public void addFacebookFriendRequest(Activity activity, String userId) {
		Bundle params = new Bundle();
		params.putString("id", userId);
		initParams(params);
		WebDialog dialog = new WebDialog(activity, "friends", params, WebDialog.DEFAULT_THEME, new OnCompleteListener() {

			@Override
			public void onComplete(Bundle values, FacebookException error) {
				System.out.println("values = " + (values == null ? "null" : values.toString()) + " error = " + (error == null ? "null" : error.toString()));
			}
		});
		dialog.show();
	}

	/**
	 * 打开老的token，这样可以免去老用户的登陆操作
	 * 
	 * @param context
	 */
	public boolean openOldToken(Context context) {
		SharedPreferences mPrefs = context.getSharedPreferences("facebook-session", Context.MODE_PRIVATE);
		String access_token = mPrefs.getString("access_token", null);

		Session session = Session.getActiveSession();
		if (session != null) {
			// Check if there is an existing token to be migrated
			if (access_token != null) {
				// Clear the token info
				SharedPreferences.Editor editor = mPrefs.edit();
				editor.putString("access_token", null);
				editor.commit();
				// Create an AccessToken object for importing
				// just pass in the access token and take the
				// defaults on other values
				AccessToken accessToken = AccessToken.createFromExistingAccessToken(access_token, null, null, null, null);
				// statusCallback: Session.StatusCallback implementation
				_facebookAction = FacebookAction.LOGIN;
				session.open(accessToken, _callback);
				Session.setActiveSession(session);
				return true;
			}
		}
		return false;
	}

	/**
	 * 获取重定向后的用户图片URL,同步阻塞，需要在非UI线程调用
	 * 
	 * @param context
	 * @param fbId
	 * @param smallPic
	 * @return
	 */
	public String getRedirectedUrl(Context context, String fbId, boolean smallPic) {
		String url = "";

		StringBuilder sb = new StringBuilder();
		sb.append(GRAPH_FACEBOOK_URL);
		sb.append(fbId);
		sb.append("/picture?type=");
		sb.append(smallPic ? "small" : "normal");

		HttpURLConnection connection = null;

		try {
			URL httpUrl = new URL(sb.toString());
			connection = (HttpURLConnection) httpUrl.openConnection();
			connection.setInstanceFollowRedirects(false);

			switch (connection.getResponseCode()) {
			case HttpURLConnection.HTTP_MOVED_PERM:
			case HttpURLConnection.HTTP_MOVED_TEMP:
				// redirect. So we need to perform further requests
				String redirectLocation = connection.getHeaderField("location");
				if (!Utility.isNullOrEmpty(redirectLocation)) {
					URL redirectUrl = new URL(redirectLocation);
					url = redirectUrl.toString();
				}
				break;
			}
		} catch (IOException e) {

		} finally {
			Utility.disconnectQuietly(connection);
		}
		return url;
	}
	
	public String getRedirectedUrl(Context context, String fbId, int width, int height) {
		String url = "";

		StringBuilder sb = new StringBuilder();
		sb.append(GRAPH_FACEBOOK_URL);
		sb.append(fbId);
		sb.append("/picture?width=");
		sb.append(width);
		sb.append("&");
		sb.append("height=");
		sb.append(height);

		HttpURLConnection connection = null;

		try {
			URL httpUrl = new URL(sb.toString());
			connection = (HttpURLConnection) httpUrl.openConnection();
			connection.setInstanceFollowRedirects(false);

			switch (connection.getResponseCode()) {
			case HttpURLConnection.HTTP_MOVED_PERM:
			case HttpURLConnection.HTTP_MOVED_TEMP:
				// redirect. So we need to perform further requests
				String redirectLocation = connection.getHeaderField("location");
				if (!Utility.isNullOrEmpty(redirectLocation)) {
					URL redirectUrl = new URL(redirectLocation);
					url = redirectUrl.toString();
				}
				break;
			}
		} catch (IOException e) {

		} finally {
			Utility.disconnectQuietly(connection);
		}
		return url;
	}
}
