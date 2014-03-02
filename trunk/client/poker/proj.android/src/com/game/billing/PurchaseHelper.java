package com.game.billing;

public class PurchaseHelper {
	private static PurchaseActivity sPurchaseActivity;
	
	public static void init(final PurchaseActivity purchaseActivity) {
		sPurchaseActivity = purchaseActivity;
	}
	
	public static void purchaseItem(final String itemId) {
		purchaseItem(itemId, "");
	}
	
	public static void purchaseItem(final String itemId, final String developerPayload) {
		if (sPurchaseActivity == null) {
			throw new RuntimeException("sPurchaseActivity is null");
		}
		sPurchaseActivity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				sPurchaseActivity.buyItemInMainThread(itemId, developerPayload);
			}
		});
	}
	
	// ----------------------------------------------------------------------------------
	// Below methods are for Online Purchase
	public static void initPurchase() {
		if (sPurchaseActivity == null) {
			throw new RuntimeException("sPurchaseActivity is null");
		}
		sPurchaseActivity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				sPurchaseActivity.initPurchase();
			}
		});
	}
	
	public static void confirmPurchaseOnline(final String sku, final String token) {
		if (sPurchaseActivity == null) {
			throw new RuntimeException("sPurchaseActivity is null");
		}
		sPurchaseActivity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				sPurchaseActivity.confirmPurchaseOnline(sku, token);
			}
		});
	}
	// Above methods are for Online Purchase
	// -----------------------------------------------------------------------------------
}
