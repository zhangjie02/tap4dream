package com.game.net;

import java.io.IOException;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

public class FileUploadRequest extends AbstractPostRequest {
	private String strBoundary;
	private String url;
	private String fileName;
	private byte[] data;
	private Map<String, String> params;
	
	public FileUploadRequest(String url, String fileName, byte[] data, Map<String, String> params) {
		this.url = url;
		this.fileName = fileName;
		this.data = data;
		this.params = params;
		newBoundary();
	}
	
	@Override
	public String getUrl() {
		return this.url;
	}

	@Override
	public void writeData() throws IOException {
		write("-----------------------------" + strBoundary);
		if (params != null) {
			Set<Entry<String, String>> param = params.entrySet();
			for (Entry<String, String> p : param) {
				writeParam(p.getKey(), p.getValue());
			}
		}
		if (data != null) {
			writeFile(data);
		}
		write("--");
	}
	
	private void newBoundary() {
		strBoundary = new String(""
				+ (Math.random() + Math.random())).substring(2);
	}

	protected void writeParam(String key, String value) throws IOException {
		write("\r\nContent-Disposition: form-data; name=\"");
		write(key);
		write("\"\r\n\r\n" + value);
		write("\r\n-----------------------------" + strBoundary);
	}
	
	protected void writeBinary(byte[] data) throws IOException {
		write("\r\nContent-Type: application/octet-stream");
		write("\r\n\r\n");
		write(data);
		write("\r\n-----------------------------" + strBoundary);
	}
	
	protected void writeFile(byte[] data) throws IOException {
		write("\r\nContent-Disposition: form-data; name=\"file\"; filename=\"" + fileName + "\"");
		writeBinary(data);
	}

	@Override
	protected String getContentType() {
		return "multipart/form-data; boundary=---------------------------" + strBoundary;
	}
}
