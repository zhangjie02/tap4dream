package com.game.billing;


public abstract class PurchaseOnlineActivity extends PurchaseActivity {
	public PurchaseOnlineActivity(int purchaseRequestCode) {
		super(null, purchaseRequestCode);
	}
	
	@Override
	public void buyItemFinished(final Purchase purchase) {
		//server will do repeat check.
		buyItemFinishedOnline(purchase.getOriginalJson(),purchase.getSignature());
		
		if (DataProvider.getDP().checkBillID(purchase.getOrderId())) {
			logPurchase(purchase.getSku(), purchase.getOrderId());
		}
		//do not confirm here. Server will ask you to confirm later; 
		//confirmPurchase(purchase);
	}

	//for online
	protected abstract void buyItemFinishedOnline(String originalJson, String signature);
}
