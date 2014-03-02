#include "Command.h"
#include <vector>
#include <sstream>

int Command::id = 0;

Command::Command(std::string cmd, Callback* callback) {
	this->cmd = cmd;
	this->_callback = callback;
    cmdArgs=new CommandArgs();
	_cid = id++;
}

Command::~Command() {
    delete cmdArgs;

	if(_callback != NULL) {
		delete _callback;
		_callback = NULL;
	}
}

void Command::handleResponse(void* param) {
	if(_callback != NULL) {
		_callback->Execute(param);
	}
}

std::string Command::getId() {
	std::stringstream ss;
	ss << this->cmd << _cid;
	return std::string(ss.str());
}

JSONNode Command::toJson() {
    JSONNode node(JSON_NODE);
	node.push_back(JSONNode("cmd",cmd));
	//node.push_back(JSONNode("time",time));
    
    std::map<std::string, std::string>* params = cmdArgs->getParams();
    std::map<std::string, std::string>::iterator mapIter;
    for(mapIter = params->begin(); mapIter != params->end(); mapIter ++) {
        node.push_back(JSONNode((*mapIter).first,(*mapIter).second));
    }
    
    std::vector<JSONNode>* jsonParams = cmdArgs->getJsonParams();
    std::vector<JSONNode>::iterator jsonIter;
    for(jsonIter = jsonParams->begin(); jsonIter != jsonParams->end(); jsonIter ++) {
        node.push_back(*jsonIter);
    }


	return node;
}




