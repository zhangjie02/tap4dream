package com.game.net;

import java.io.IOException;
import java.net.URLEncoder;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

import android.util.Log;


public class SimplePostRequest extends AbstractPostRequest {
	private String url;
	private Map<String, String> params;
	
	public SimplePostRequest(String url, Map<String, String> params) {
		this.url = url;
		this.params = params;
	}

	@Override
	public String getUrl() {
		return this.url;
	}

	@Override
	public void writeData() throws IOException {
		if (params != null) {
			int i = 0;
			Set<Entry<String, String>> param = params.entrySet();
			for (Entry<String, String> p : param) {
				if (i != 0) {
					write("&");
				}
				if (p.getValue() == null) {
					Log.d("debug", p.getKey());
				}
				write(URLEncoder.encode(p.getKey(), "UTF-8"));
				write("=");
				write(URLEncoder.encode(p.getValue(), "UTF-8"));
				i++;
			}
		}
	}

	@Override
	protected String getContentType() {
		return "application/x-www-form-urlencoded";
	}

}
