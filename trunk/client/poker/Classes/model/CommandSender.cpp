#include "CommandSender.h"
#include "Constant.h"
#include "HttpMgr.h"
#include "Global.h"


const int CommandSender::HTTP_TYPE_REQ = 0;
const int CommandSender::HTTP_TYPE_RES = 1;

const char* CommandSender::URI_LOGIN = "Login.processLogin";
const char* CommandSender::URI_MONMAND = "Command.sendCommand";
const char* CommandSender::URI_BATCH_MONMAND = "BatchCommand.sendCommand";

int CommandSender::reqId = 0;

CommandSender::CommandSender() {

}

CommandSender::~CommandSender() {

}

int CommandSender::getReqId() {
	return reqId++;
}

void CommandSender::requestAsync(string url, ReqType type, Command* cmd, Callback* callback, bool isZlib) {
	HttpMgr::getInstance()->requestAsync(url,type,cmd, callback, isZlib);
}

void CommandSender::sendCommand(Command* cmd) {
    CommandArgs* cmdArgs=cmd->cmdArgs;
    //UserModel* userModel = UserModel::getInstance();
    cmdArgs->addParam("version",std::string(Global::clientVersion));
    //cmdArgs->addParam("uid",userModel->userId);
    //cmdArgs->addParam("sid",userModel->sessionId);
	//requestAsync(Constant::URL_REQUEST, ReqType_POST, cmd, NULL);
}
