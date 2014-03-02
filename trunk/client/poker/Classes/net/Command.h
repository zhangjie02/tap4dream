#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
#include <vector>
#include "libjson.h"
#include "CommandArgs.h"
#include <map>
#include "Callback.h"

class Command {
public:
	Command(std::string cmd, Callback* callback = NULL);
	/**
	 * 处理请求对应的返回数据
	 */
	void handleResponse(void* param);

	JSONNode toJson();
	std::string getId();

	~Command();

public:
	std::string cmd;
	int time;
//	std::vector<CommandArgs*>* cmdArgsList;
    
    CommandArgs* cmdArgs;

private:
	int _cid;
	Callback* _callback;

	static int id;
};


#endif /* COMMAND_H_ */




