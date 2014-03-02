package com.game.net;

import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.ProtocolException;
import java.net.URL;

public abstract class AbstractPostRequest {
	private static final int DEFAULT_TIMEOUT = 8000;
	private static final int DEFAULT_SO_TIMEOUT = 15000;
	
	private HttpURLConnection urlc = null;
	private DataOutputStream dos = null;
	private int timeout = DEFAULT_TIMEOUT;

	public String sendRequest() throws IOException {
		InputStream in = null;
		ByteArrayOutputStream out = null;
		try {
			urlc = createConnection(getUrl());
			dos = new DataOutputStream(urlc.getOutputStream());
			
			writeData();
			
			in = urlc.getInputStream();
			out = new ByteArrayOutputStream();
			int b;
			while ((b = in.read()) != -1) {
				out.write(b);
			}
			String temp = out.toString().replace("\ufeff", "");
			String result = temp.trim();
			return result;
		} finally {
			if (urlc != null) {
				urlc.disconnect();
			}
			if (dos != null) {
				try {
					dos.close();
				} catch (IOException e) {
				}
			}
			if (in != null) {
				try {
					in.close();
				} catch (IOException e) {
				}
			}
			if (out != null) {
				try {
					out.close();
				} catch (IOException e) {
				}
			}
		}
	}

	public abstract String getUrl();
	public abstract void writeData() throws IOException;
	
	public void setTimeout(int timeout) {
		this.timeout = timeout;
	}
	
	protected void write(byte[] data) throws IOException {
		dos.write(data);
	}
	
	protected void write(String value) throws IOException {
		dos.writeBytes(value);
	}
	
	private HttpURLConnection createConnection(String url)
			throws MalformedURLException, IOException, ProtocolException {
		HttpURLConnection urlc;
		URL request = new URL(url);
		urlc = (HttpURLConnection) request.openConnection();
		urlc.setConnectTimeout(timeout);
		urlc.setReadTimeout(DEFAULT_SO_TIMEOUT);
		urlc.setRequestMethod("POST");
		urlc.setDoOutput(true);
		urlc.setDoInput(true);
		urlc.setUseCaches(false);
		urlc.setAllowUserInteraction(false);
		urlc.setRequestProperty("Cache-Control", "no-cache");
		urlc.setRequestProperty("Connection", "Keep-Alive");
		urlc.setRequestProperty("Content-Type",	getContentType());
		urlc.setRequestProperty(
				"Accept",
				"image/gif, image/x-xbitmap, image/jpeg, image/pjpeg, application/vnd.ms-excel, application/vnd.ms-powerpoint, application/msword, */*");
		urlc.setRequestProperty("Accept-Encoding", "gzip, deflate");
		urlc.setRequestProperty("Accept-Language", "en-au");
		urlc.setRequestProperty("Host", "rookie");
		urlc.setRequestProperty(
				"User-Agent",
				"Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; .NET CLR 1.0.3215; .NET CLR 1.0.3705)");
		return urlc;
	}
	
	protected abstract String getContentType();
}
