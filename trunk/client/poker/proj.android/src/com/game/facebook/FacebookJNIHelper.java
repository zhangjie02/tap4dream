package com.game.facebook;

import org.cocos2dx.lib.Cocos2dxActivity;

import android.os.Handler;
import android.os.Message;

public class FacebookJNIHelper {
	private static Cocos2dxActivity _activity;
	
	private static class FacebookJNIHelperHandler extends Handler {
		@Override
		public void handleMessage(Message msg) {
			System.out.println("handle msg: " + msg.toString());
			switch (msg.what) {
			case FacebookHelper.msgOnSessionLoginSuccess:
				FacebookHelper.getInstance().requestUserInfo();
				break;
			case FacebookHelper.msgOnSessionClosedLoginFailed:
				_activity.runOnGLThread(new Runnable() {
					@Override
					public void run() {
						nativeOnLoginFailed();
					}
				});
				break;
			case FacebookHelper.msgOnSessionClosed:
				_activity.runOnGLThread(new Runnable() {
					@Override
					public void run() {
						nativeOnSessionClosed();
					}
				});
				break;
			case FacebookHelper.msgOnRequestUserInfoSuccess:
				FacebookHelper.getInstance().requestFriendInfo();
				break;
			case FacebookHelper.msgOnRequestUserInfoFailed:
				_activity.runOnGLThread(new Runnable() {
					@Override
					public void run() {
						nativeOnLoginFailed();
					}
				});
				break;
			case FacebookHelper.msgOnRequestFriendsInfoSuccess:
				_activity.runOnGLThread(new Runnable() {
					@Override
					public void run() {
						nativeOnLoginSuccess();
					}
				});
				break;
			case FacebookHelper.msgOnRequestFriendsInfoFailed:
				_activity.runOnGLThread(new Runnable() {
					@Override
					public void run() {
						nativeOnLoginFailed();
					}
				});
				break;
			default:
			}
		}
	}
	
	public static void init(final Cocos2dxActivity activity) {
		_activity = activity;
		FacebookJNIHelperHandler handler = new FacebookJNIHelperHandler(); 
		FacebookHelper.getInstance().init(handler, activity);
	}
	
	public static void login() {
		_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				FacebookHelper.getInstance().facebookLoginForRead(_activity);
			}
		});
	}
	
	public static void logout() {
		_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				FacebookHelper.getInstance().facebookLogout();
			}
		});
	}
	
	private static void requestUserInfo() {
		_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				FacebookHelper.getInstance().requestUserInfo();
			}
		});
	}
	
	private static void requestFriendInfo() {
		_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				FacebookHelper.getInstance().requestFriendInfo();
			}
		});
	}
	
	public static boolean publishFeedDialog(final String name, final String caption, final String description, final String link, final String pic, final String toUserId) {
		_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				FacebookHelper.getInstance().publishFeedDialog(name, caption, description, link, pic, toUserId);
			}
		});
		return true;
	}
	
	public static String getRedirectedUrl(String fbId, boolean smallPic) {
		return FacebookHelper.getInstance().getRedirectedUrl(_activity, fbId, smallPic);
	}
	
	public static void postAppRequests(final String title, final String message, final String link) {
		_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				FacebookHelper.getInstance().postAppRequests(_activity, title, message, link);
			}
		});
	}
	
	public static void postAppRequestsToFriendsWithoutInstalled(final String title, final String message, final String link) {
		_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				FacebookHelper.getInstance().postAppRequestsToFriendsWithoutInstalled(_activity, title, message, link);
			}
		});
	}
	
	public static native void nativeOnLoginSuccess();
	public static native void nativeOnLoginFailed();
	public static native void nativeOnSessionClosed();
	
	public static String getToken() {
		return FacebookHelper.getInstance().getToken();
	}
	
	public static String getId() {
		return FacebookHelper.getInstance().getId();
	}
	
	public static String getName() {
		return FacebookHelper.getInstance().getName();
	}
	
	public static String getGender() {
		return FacebookHelper.getInstance().getGender();
	}
	
	public static String getPictureUrl() {
		return FacebookHelper.getInstance().getPictureUrl();
	}
	
	public static String[] getFriendIds() {
		return FacebookHelper.getInstance().getFriendIds();
	}
    
    public static String[] getFriendsInstalled() {
		return FacebookHelper.getInstance().getFriendsInstalled();
	}
	
	public static String[] getFriendNames() {
		return FacebookHelper.getInstance().getFriendNames();
	}
	
	public static String[] getFriendGenders() {
		return FacebookHelper.getInstance().getFriendGenders();
	}
	
	public static String[] getFriendPictureUrls() {
		return FacebookHelper.getInstance().getFriendPictureUrls();
	}
}
