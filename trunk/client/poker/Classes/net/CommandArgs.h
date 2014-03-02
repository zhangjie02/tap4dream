#ifndef COMMANDARGS_H_
#define COMMANDARGS_H_

#include "libjson.h"
#include <string>
#include <map>
#include <vector>

using namespace std;

class CommandArgs {
public:
	CommandArgs();
	CommandArgs(const CommandArgs&);
	~CommandArgs();	

	void addParam(std::string key, std::string value);
	void addParam(std::string key, int value);
	void addParam(JSONNode node);

	std::map<std::string, std::string>* getParams();
	std::vector<JSONNode>* getJsonParams();

private:
	std::map<std::string, std::string>* params;
	std::vector<JSONNode>* jsonParams;
};


#endif /* COMMANDARGS_H_ */




