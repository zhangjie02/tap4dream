package com.game.billing;

import java.util.ArrayList;
import java.util.Locale;

import org.cocos2dx.lib.Cocos2dxActivity;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;

import com.game.slot.R;

public abstract class PurchaseActivity extends Cocos2dxActivity {
	private final String _base64EncodedPublicKey;
	private final int _purchaseRequestCode;
	private boolean supportPurchase = true;
	private IabHelper mHelper;

	public PurchaseActivity(String base64EncodeKey, int purchaseRequestCode) {
		_base64EncodedPublicKey = base64EncodeKey;
		_purchaseRequestCode = purchaseRequestCode;
		
		PurchaseHelper.init(this);
	}

	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
//		initPurchase();
	}

	@Override
	protected void onDestroy() {
		if (mHelper != null) {
			mHelper.dispose();
			mHelper = null;
		}
		super.onDestroy();
	}

	protected abstract ArrayList<String> getSkuListForPrice();
	protected abstract void setSkuPrice(String sku, String price);
	protected abstract void buyItemFinished(final Purchase purchase);
	protected abstract void queryInventoryStarted();
	protected abstract void queryInventoryFinished(boolean success);
	
	protected abstract void logPurchase(String itemId,String orderId);
	
	protected void confirmPurchase(Purchase purchase) {
		mHelper.consumeAsync(purchase.getSku(),purchase.getToken());
	}
	public void confirmPurchaseOnline(String sku,String token) {
		mHelper.consumeAsync(sku,token);
	}
	
	//common
	protected void initPurchase() {
		DataProvider.init(this);
		mHelper = new IabHelper(this, _base64EncodedPublicKey);

		mHelper.startSetup(new IabHelper.OnIabSetupFinishedListener() {
			public void onIabSetupFinished(IabResult result) {
				if (!result.isSuccess()) {
					supportPurchase = false;
					return;
				}
				queryInventoryStarted();
				ArrayList<String> skuList = getSkuListForPrice();
				if (mHelper != null) {
					mHelper.queryInventoryAsync(skuList, mGotInventoryListener);
				}
			}
		});
	}

	// Listener that's called when we finish querying the items we own
	private IabHelper.QueryInventoryFinishedListener mGotInventoryListener = new IabHelper.QueryInventoryFinishedListener() {
		public void onQueryInventoryFinished(IabResult result,
				Inventory inventory) {
			try {
				if (result.isFailure()) {
					queryInventoryFinished(false);
					return;
				}
				for (Purchase purchase : inventory.getAllPurchases()) {
					buyItemFinished(purchase);
				}
				for (String sku : inventory.getAllSkus()) {
					SkuDetails details = inventory.getSkuDetails(sku);
					setSkuPrice(sku, details.getPrice());
				}
				queryInventoryFinished(true);
			} catch (Throwable t) {
				t.printStackTrace();
			}
		}
	};

	// Callback for when a purchase is finished
	private IabHelper.OnIabPurchaseFinishedListener mPurchaseFinishedListener = new IabHelper.OnIabPurchaseFinishedListener() {
		public void onIabPurchaseFinished(IabResult result, Purchase purchase) {
			if (result.isFailure()) {
				return;
			}
			buyItemFinished(purchase);
		}
	};
	
	public void buyItemInMainThread(String itemId, String developerPayload) {
		try {
			if (supportPurchase) {
				mHelper.launchPurchaseFlow(this, itemId, _purchaseRequestCode,
						mPurchaseFinishedListener, developerPayload);
			} else {
				alertBillingNotSupport();
			}
		} catch (Exception e) {

		}
	}

	void alertBillingNotSupport() {
		String helpUrl = replaceLanguageAndRegion(getString(R.string.help_url));
		final Uri helpUri = Uri.parse(helpUrl);

		AlertDialog.Builder bld = new AlertDialog.Builder(this);
		bld.setTitle(R.string.billing_not_supported_title);
		bld.setMessage(R.string.billing_not_supported_message);
		bld.setCancelable(false);
		bld.setPositiveButton(android.R.string.ok, null);
		bld.setNegativeButton(R.string.learn_more,
				new DialogInterface.OnClickListener() {
					public void onClick(DialogInterface dialog, int which) {
						Intent intent = new Intent(Intent.ACTION_VIEW, helpUri);
						startActivity(intent);
					}
				});
		bld.create().show();
	}

	private String replaceLanguageAndRegion(String str) {
		// Substitute language and or region if present in string
		if (str.contains("%lang%") || str.contains("%region%")) {
			Locale locale = Locale.getDefault();
			str = str.replace("%lang%", locale.getLanguage().toLowerCase());
			str = str.replace("%region%", locale.getCountry().toLowerCase());
		}
		return str;
	}

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		// Pass on the activity result to the helper for handling
		if (mHelper != null && !mHelper.handleActivityResult(requestCode, resultCode, data)) {
			super.onActivityResult(requestCode, resultCode, data);
		}
	}
}
