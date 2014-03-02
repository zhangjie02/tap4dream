#include "CommandArgs.h"
#include <sstream>
using namespace std;

CommandArgs::CommandArgs() {
	params = new map<string, string>();
	jsonParams = new vector<JSONNode>();
}

CommandArgs::~CommandArgs() {
	delete params;
    delete jsonParams;
}

CommandArgs::CommandArgs(const CommandArgs& commandArgs) {
	this->params = new map<string, string>();
	for(map<string, string>::iterator iter = commandArgs.params->begin(); iter != commandArgs.params->end(); iter++) {
		this->params->insert(pair<string,string>((*iter).first,(*iter).second));
	}

	this->jsonParams = new vector<JSONNode>();
	for(vector<JSONNode>::iterator jsonIter = commandArgs.jsonParams->begin(); jsonIter != commandArgs.jsonParams->end(); jsonIter++) {
		this->jsonParams->push_back((*jsonIter).duplicate());
	}
}

void CommandArgs::addParam(string key, string value) {
	(*params)[key] = value;
}

void CommandArgs::addParam(string key, int value) {
	stringstream ss;
	ss << value;
	addParam(key, ss.str());
}

void CommandArgs::addParam(JSONNode node) {
	jsonParams->push_back(node);
}

map<string, string>* CommandArgs::getParams() {
	return params;
}

vector<JSONNode>* CommandArgs::getJsonParams() {
	return jsonParams;
}




