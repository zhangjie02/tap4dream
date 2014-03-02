#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <string>
#include "stdint.h"


#ifndef RANDOM_NAME
#define RANDOM_NAME 0
#endif


class Global {
public:
	static std::string uuid;
	static std::string username;
	static std::string clientVersion;
    static std::string packageName;

private:
	static int _serverLoginTime;
	static int _clientLoginTime;

	static int _serverTime;
	static int64_t _serverTimeMills;

public:
	static void update();

	static int getServerTime();
	static int getServerTimeWithUpdate();
	static int64_t getServerTimeMills();
	static int64_t getServerTimeMillsWithUpdate();
	static int getLocalTime();
	static void login(int serverTime);
};


#endif /* GLOBAL_H_ */




