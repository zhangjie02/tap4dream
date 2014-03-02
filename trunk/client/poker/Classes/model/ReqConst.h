#ifndef REQCONST_H_
#define REQCONST_H_

#include <string>

class ReqConst {
public:
	static const std::string CMD_SPIN;
    static const std::string CMD_LOGIN;
    static const std::string CMD_LOAD_CONFIG;
    static const std::string CMD_LOAD_MACHINE;
    static const std::string CMD_PLAY_BONUS;
    static const std::string CMD_IGNORE_BONUS;
    static const std::string CMD_LOAD_LOBBY;
    static const std::string CMD_GAIN_SPECIAL_BONUS;
    static const std::string CMD_LOAD_TOURNAMENTS;
    static const std::string CMD_GET_RANK;
    static const std::string CMD_GET_REWARD_HISTORY;
    static const std::string CMD_PURCHASE;
    
    static const std::string CMD_GET_FRIENDS;
    static const std::string CMD_SEND_FREND_REQUEST;
    static const std::string CMD_LOAD_FRIEND_REQUEST;
    static const std::string CMD_CONFIRM_FRIEND_REQUEST;
    static const std::string CMD_IGNORE_FRIEND_REQUEST;
    static const std::string CMD_DELETE_FRIEND;
    static const std::string CMD_SEND_GIFT;
    static const std::string CMD_LOAD_GIFT;
    static const std::string CMD_LOAD_SHARE_GIFT;
    static const std::string CMD_RECLAIM_GIFT;
    static const std::string CMD_SHARE_GIFT;
    static const std::string CMD_RECLAIM_SHARE_GIFT;
    static const std::string CMD_RECOMMEND_USRE;
    static const std::string CMD_SEARCH_USER;
public:
	ReqConst();
};


#endif /* REQCONST_H_ */




