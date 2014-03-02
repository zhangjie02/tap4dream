#ifndef __PURCHASE_HELPER_JNI__
#define __PURCHASE_HELPER_JNI__

#include <jni.h>

extern "C"
{
	extern void purchaseItemJNI(const char* itemId);
	extern void purchaseItemWithDeveloperPayloadJNI(const char* itemId, const char* developerPayload);
	
	// for online purchase
	extern void initPurchaseJNI();
	extern void confirmPurchaseOnlineJNI(const char* sku, const char* token);
}

#endif // __PURCHASE_HELPER_JNI__
