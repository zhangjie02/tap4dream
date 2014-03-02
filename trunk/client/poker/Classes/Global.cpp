#include "Global.h"
#include <time.h>
#include "cocos2d.h"



std::string Global::uuid = "akira0004";
std::string Global::username = "akira0004";
std::string Global::clientVersion = "1";
std::string Global::packageName = "";


int Global::_serverLoginTime = 0;
int Global::_clientLoginTime = 0;
int Global::_serverTime 	 = 0;
int64_t Global::_serverTimeMills = 0;


int Global::getServerTime() {
	return _serverTime; 
}

int Global::getServerTimeWithUpdate() {
    update();
	return _serverTime;
}

int64_t Global::getServerTimeMills() {
	return _serverTimeMills;
}

int64_t Global::getServerTimeMillsWithUpdate() {
	update();
	return _serverTimeMills;
}

void Global::login(int serverTime) {
	_serverLoginTime = serverTime;
	_clientLoginTime = getLocalTime();
	update();
}


int Global::getLocalTime() {
	return static_cast<int>(time(NULL));
}

void Global::update() {
	_serverTime = _serverLoginTime + getLocalTime() - _clientLoginTime;

	struct cocos2d::cc_timeval currentTime;
	cocos2d::CCTime::gettimeofdayCocos2d(&currentTime, NULL);
	int64_t ms1 = ((int64_t) currentTime.tv_sec) * 1000LL;
	int64_t ms2 = ((int64_t) currentTime.tv_usec) / 1000LL;
	int64_t ms = ms1+ ms2;
	_serverTimeMills = ms + ((int64_t) (_serverLoginTime - _clientLoginTime)) * 1000LL;
}
