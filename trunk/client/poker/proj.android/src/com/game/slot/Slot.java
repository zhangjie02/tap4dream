/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package com.game.slot;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.UUID;

import org.cocos2dx.lib.Cocos2dxGLSurfaceView;

import android.content.Context;
import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager.NameNotFoundException;
import android.os.Bundle;
import android.os.Environment;
import android.provider.Settings;
import android.view.KeyEvent;

import com.facebook.UiLifecycleHelper;
import com.game.billing.Base64;
import com.game.billing.Base64DecoderException;
import com.game.billing.PurchaseOnlineActivity;
import com.game.facebook.FacebookHelper;
import com.game.facebook.FacebookJNIHelper;

public class Slot extends PurchaseOnlineActivity{
	
	


	private String _uuid = null;
	private final String KEY = "uuid";
	private final String DATA_DIR = "/game/slot/";
	private final String DATA_FILE_NAME = "usys";
	
	private static final int RC_REQUEST = 10002;
	
	private UiLifecycleHelper uiHelper;
	
	public Slot() {
		super(RC_REQUEST);
	}
	
	protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		PreferencesHelper.init(this);
	
		setUUID(getUUID());
		
		PackageInfo packageInfo = null;
		try {
			final ApplicationInfo applicationInfo = getApplicationContext().getApplicationInfo();
			String packageName = applicationInfo.packageName;
			setPackageName(packageName);
			packageInfo = getApplicationContext().getPackageManager().getPackageInfo(packageName, 0);
			setVersion(String.valueOf(packageInfo.versionCode));
		} catch (NameNotFoundException ne) {
			System.out.println("set version error ...");
			ne.printStackTrace();
		}
		
		
		FacebookJNIHelper.init(this);
		uiHelper = new UiLifecycleHelper(this, FacebookHelper.getInstance().getCallback());
		uiHelper.onCreate(savedInstanceState);
		
	}
	
	@Override
	public Cocos2dxGLSurfaceView onCreateView() {
		Cocos2dxGLSurfaceView glSurfaceView = new LuaGLSurfaceView(this);
		glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);
		return glSurfaceView;
    }
	
	@Override
	protected void onStart() {
		super.onStart();
		CrashDumpUploader.getInstance().checkAndUpload(getApplicationContext());
	}
	
	@Override
	protected void onDestroy() {
		super.onDestroy();
		uiHelper.onDestroy();
	}
	
	@Override
	protected void onResume() {
		super.onResume();
		uiHelper.onResume();
	}
	
	@Override
	protected void onPause() {
		super.onPause();
		uiHelper.onPause();
	}
	
	@Override
	protected void onSaveInstanceState(Bundle outState){
		super.onSaveInstanceState(outState);
		uiHelper.onSaveInstanceState(outState);
	}
	
	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
//		if (requestCode == PurchaseRequestCode) {
//			super.onActivityResult(requestCode, resultCode, data);
//		}
		uiHelper.onActivityResult(requestCode, resultCode, data);
	}
	
	
    public String getUUID(){
   	 _uuid = PreferencesHelper.getStringForKey(KEY, "");
		if (_uuid.length() == 0) {
			String sdCardUUID = getDataFromSDCard();
			// ?????��??�????sdcard??��??�????
			if(sdCardUUID.length() == 0) {
				String aid = Settings.System.getString(getApplicationContext().getContentResolver(), Settings.Secure.ANDROID_ID);
				if (aid == null || aid.length() == 0) {
					aid = "DroidHen";
				}
				_uuid = aid + "-" + UUID.randomUUID().toString();
				
	 			PreferencesHelper.setStringForKey(KEY, _uuid);
	 			saveDataToSDCard(_uuid);
			}else {
				_uuid = sdCardUUID;
				PreferencesHelper.setStringForKey(KEY, _uuid);
			}
		} else {
			// �???????sd??��??
			saveDataToSDCard(_uuid);
		}
		return _uuid;
	}
    
    public native void setUUID(String uuid);
    public native void setVersion(String version);
    public native void setPackageName(String name);
    
	private String getDataFromSDCard() {
		StringBuilder sb = new StringBuilder();
		sb.append(Environment.getExternalStorageDirectory()).append(DATA_DIR).append(DATA_FILE_NAME);
		String path = sb.toString();
		String data = "";
		BufferedReader reader;
		try {
			reader = new BufferedReader(new FileReader(path));
			String line = reader.readLine();
			if (line != null) {
				data = new String(Base64.decode(line));
			}
			reader.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (Base64DecoderException e) {
			e.printStackTrace();
		}
		return data;
	}
	
	private void saveDataToSDCard(String data) {
		StringBuilder sb = new StringBuilder();
		sb.append(Environment.getExternalStorageDirectory()).append(DATA_DIR);
		
    	File d = new File(sb.toString());
    	if (!d.exists() && !d.mkdirs()) {
    		return;
    	}
    	sb.append(DATA_FILE_NAME);
    	byte[] source = getBytes(data);
    	String encodeUsersString = Base64.encode(source);
    	try {
    		File saveFile = new File(sb.toString());
    		saveFile.createNewFile();
    		BufferedWriter writer = new BufferedWriter(new FileWriter(saveFile));
    		writer.write(encodeUsersString);
			writer.newLine();
			writer.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private static byte[] getBytes(String data) {
		byte[] source;
		try {
			source = data.getBytes("UTF-8");
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
			source = data.getBytes();
		}
		return source;
	}
	
    static {
        System.loadLibrary("cocos2dlua");
    }
    
    private native void nativeBuyItemFinished(String originalJson, String signature);

	@Override
	protected void buyItemFinishedOnline(String originalJson, String signature) {
		nativeBuyItemFinished(originalJson, signature);
	}

	@Override
	protected ArrayList<String> getSkuListForPrice() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	protected void setSkuPrice(String sku, String price) {
		// TODO Auto-generated method stub
		
	}

	@Override
	protected void queryInventoryStarted() {
		// TODO Auto-generated method stub
		
	}

	@Override
	protected void queryInventoryFinished(boolean success) {
		// TODO Auto-generated method stub
		
	}

	@Override
	protected void logPurchase(String itemId, String orderId) {
		// TODO Auto-generated method stub
		
	}
}




class LuaGLSurfaceView extends Cocos2dxGLSurfaceView{
	
	public LuaGLSurfaceView(Context context){
		super(context);
	}
	
	public boolean onKeyDown(int keyCode, KeyEvent event) {
		//

        return super.onKeyDown(keyCode, event);
    }
}
