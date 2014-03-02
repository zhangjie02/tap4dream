package com.game.slot;

import java.io.BufferedInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.MalformedURLException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.zip.GZIPOutputStream;

import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager.NameNotFoundException;
import android.os.Build;

import com.game.net.AbstractPostRequest;
import com.game.net.FileUploadRequest;


public class CrashDumpUploader {
	private static final String CRASH_DUMP_EXT = ".dmp";
	private static final String CRASH_DUMP_ZIP_EXT = ".zip";
	private static final String CRASH_DUMP_SERVER_ADDRESS = "http://clog.droidhen.com/clog/up/log.php";
	
	private static class CrashDumpUploaderHolder {
		public static final CrashDumpUploader INSTANCE = new CrashDumpUploader();
	};
	public static CrashDumpUploader getInstance() {
		return CrashDumpUploaderHolder.INSTANCE;
	}
	
	private final ExecutorService _pool = Executors.newSingleThreadExecutor();
	private boolean _isInited = false;
	private String _searchDir;
	private HashMap<String, String> _params;
	
	
	public synchronized void checkAndUpload(Context context) {
		try {
			if (!_isInited) {
				final ApplicationInfo applicationInfo = context.getApplicationInfo();
				_searchDir = applicationInfo.dataDir + "/files";
				String packageName = applicationInfo.packageName;
				PackageInfo packageInfo = null;
				try {
					packageInfo = context.getPackageManager().getPackageInfo(packageName, 0);
				} catch (NameNotFoundException ne) {
					
				}
				if (_params == null) {
					_params = new HashMap<String, String>();
				} else {
					_params.clear();
				}
				_params.put("project", packageName);
				if (packageInfo != null) {
					_params.put("versionCode", String.valueOf(packageInfo.versionCode));
					_params.put("versionName", packageInfo.versionName);
				}
				_params.put("brand", Build.BRAND);
				_params.put("manufacturer", Build.MANUFACTURER);
				_params.put("model", Build.MODEL);
				_params.put("androidSdkInt", String.valueOf(Build.VERSION.SDK_INT));
				
				_isInited = true;
			}
			_pool.execute(new CheckAndUploadService());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private class CheckAndUploadService implements Runnable {
		private static final int BUF_SIZE = 4096;
		
		@Override
		public void run() {
			try {
				File dir = new File(_searchDir);
				File[] files = dir.listFiles();
				ArrayList<File> dumpFiles = new ArrayList<File>();
				for (int i = 0; i < files.length; i++) {
					File f = files[i];
					if (f.getName().endsWith(CRASH_DUMP_EXT)) {
						dumpFiles.add(f);
					}
				}
				for (int i = 0; i < dumpFiles.size(); i++) {
					File f = dumpFiles.get(i);
					byte[] content = readFile(f);
					if (content != null) {
						byte[] compressed = compress(content);
						String fileName = f.getName();
						fileName = fileName.substring(0, fileName.length() - 4) + CrashDumpUploader.CRASH_DUMP_ZIP_EXT;
						AbstractPostRequest request = new FileUploadRequest(CRASH_DUMP_SERVER_ADDRESS, fileName, compressed, _params);
						try {
							request.sendRequest();
							f.delete();
						} catch (MalformedURLException e) {
							e.printStackTrace();
						} catch (IOException e) {
							e.printStackTrace();
						}
					}
				}
			} catch (Exception e) {
				
			}
		}
		
		private byte[] readFile(File f) {
			BufferedInputStream bis = null;
			try {
				byte[] buf = new byte[BUF_SIZE];
				bis = new BufferedInputStream(new FileInputStream(f));
				ByteArrayOutputStream baos = new ByteArrayOutputStream();
				for (int read = bis.read(buf); read != -1; read = bis.read(buf)) {
					baos.write(buf, 0, read);
				}
				
				return baos.toByteArray();
			} catch (IOException e) {
				e.printStackTrace();
			} finally {
				if (bis != null) {
					try {
						bis.close();
					} catch (IOException e) {
						e.printStackTrace();
					}
				}
			}
			
			return null;
		}
		
		private byte[] compress(byte[] content) {
			try {
				ByteArrayOutputStream baos = new ByteArrayOutputStream();
				GZIPOutputStream gzout = new GZIPOutputStream(baos);
				gzout.write(content);
				gzout.close();
				
				return baos.toByteArray();
			} catch (IOException e) {
				e.printStackTrace();
			}
			
			return null;
		}
	}
}
