#ifndef ENHANCEDCCHTTPREQUEST_H_
#define ENHANCEDCCHTTPREQUEST_H_

#include "cocos-ext.h"
#include "Request.h"

USING_NS_CC_EXT;

class EnhancedCCHttpRequest : public CCHttpRequest {
public:
	EnhancedCCHttpRequest(Request* reqCmd);
	~EnhancedCCHttpRequest();

	Request* getReqCmd();
private:
	Request* _reqCmd;
};


#endif /* ENHANCEDCCHTTPREQUEST_H_ */
