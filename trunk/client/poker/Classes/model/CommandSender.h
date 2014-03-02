#ifndef COMMANDSENDER_H_
#define COMMANDSENDER_H_

#include "Command.h"
#include "Callback.h"
#include "Request.h"
#include <vector>
#include <string>

using namespace std;

class CommandSender {
public:
	static const int HTTP_TYPE_REQ;
	static const int HTTP_TYPE_RES;

	static const char* URI_LOGIN;
	static const char* URI_MONMAND;
	static const char* URI_BATCH_MONMAND;

public:
	CommandSender();
	~CommandSender();

protected:
	virtual void sendCommand(Command* cmd);

	void requestAsync(string url, ReqType type, Command* cmd, Callback* callback = NULL, bool isZlib = false);

protected:
	int getReqId();

private:
	static int reqId;
};

#endif /* COMMANDSENDER_H_ */
