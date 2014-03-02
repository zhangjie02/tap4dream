package com.game.billing;

import android.os.Bundle;



public abstract class PurchaseOfflineActivity extends PurchaseActivity {
	
	public PurchaseOfflineActivity(String base64EncodeKey, int purchaseRequestCode) {
		super(base64EncodeKey,purchaseRequestCode);
	}
	
	
		
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		initPurchase();
	}

	@Override
	public void buyItemFinished(final Purchase purchase) {
		Runnable runnable = new Runnable() {
			@Override
			public void run() {
				String orderId = purchase.getOrderId();
				if (DataProvider.getDP().checkBillID(orderId)) {
					String sku = purchase.getSku();
					
					buyItemFinished(sku, orderId, purchase.getDeveloperPayload());
					logPurchase(sku, orderId);
				}
				confirmPurchase(purchase);
			}
		};
		
		runOnGLThread(runnable);
	}

	protected abstract void buyItemFinished(String itemId, String orderId, String developerPayload);
}
