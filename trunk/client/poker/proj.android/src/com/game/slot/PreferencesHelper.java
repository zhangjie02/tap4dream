package com.game.slot;

import android.content.Context;
import android.content.SharedPreferences;

public class PreferencesHelper {
	private static final String FILE_NAME = "default";
	private static SharedPreferences sSharedPreferences;
	
	public static void init(final Context context) {
		sSharedPreferences = context.getSharedPreferences(FILE_NAME, Context.MODE_PRIVATE);
	}
	
	public static boolean getBoolForKey(String key, boolean defaultValue) {
		return sSharedPreferences.getBoolean(key, defaultValue);
	}
	
	public static int getIntForKey(String key, int defaultValue) {
		return sSharedPreferences.getInt(key, defaultValue);
	}
	
	public static float getFloatForKey(String key, float defaultValue) {
		return sSharedPreferences.getFloat(key, defaultValue);
	}
	
	public static String getStringForKey(String key, String defaultValue) {
		return sSharedPreferences.getString(key, defaultValue);
	}
	
	public static void setBoolForKey(String key, boolean value) {
		SharedPreferences.Editor editor = sSharedPreferences.edit();
		editor.putBoolean(key, value);
		editor.commit();
	}
	
	public static void setIntForKey(String key, int value) {
		SharedPreferences.Editor editor = sSharedPreferences.edit();
		editor.putInt(key, value);
		editor.commit();
	}
	
	public static void setFloatForKey(String key, float value) {
		SharedPreferences.Editor editor = sSharedPreferences.edit();
		editor.putFloat(key, value);
		editor.commit();
	}
	
	public static void setStringForKey(String key, String value) {
		SharedPreferences.Editor editor = sSharedPreferences.edit();
		editor.putString(key, value);
		editor.commit();
	}
	
	public static void saveReferrerString(String referrerString) {
		setStringForKey("refer", referrerString);
	}
}
