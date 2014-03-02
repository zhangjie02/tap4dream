
class Error:
    OK = 0
    ERROR = 1

    INVALID_PARAM = 2
    SIGNATURE_ERROR = 3
    INVALID_SESSION = 4
    UNKNOWN_CMD = 5
    VERSION_TOO_LOW = 6

    # user
    NO_SUCH_USER = 7

    #spin
    MACHINE_LOCKED = 100
    LINE_EXCEEDED = 101
    BET_EXCEEDED = 102
    NO_COIN = 103
    NO_FREE_SPIN = 104

    # bonus
    BONUS_NOT_EXIST = 300

    # tournament
    TOUR_NOT_OPEN = 400

    LV_NOT_READY = 9

    REQUEST_SENT = 500
    REQUEST_NOT_EXIST = 501
    FRIEND_FULL = 502

    GIFT_NOT_EXIST = 600
    GIFT_SENT = 601

    ERROR_MSG = {
                 OK: 'OK',
                 ERROR: 'Error',
                 INVALID_PARAM: 'Invalid Parameters',
                 INVALID_SESSION: 'Session invalid',
                 UNKNOWN_CMD: 'Unknow command',
                 NO_SUCH_USER: 'No such user',
                 MACHINE_LOCKED: 'Machine locked',
                 LINE_EXCEEDED: 'line exceeded',
                 BET_EXCEEDED: 'bet exceeded',
                 NO_COIN: 'not enough coin',
                 BONUS_NOT_EXIST: 'bonus not exists',
                 REQUEST_SENT: 'request already sent',
                 REQUEST_NOT_EXIST: 'request not exist',
                 FRIEND_FULL: 'friend already full',
                 GIFT_NOT_EXIST: 'gift not exist',
                 GIFT_SENT: 'gift sent',
                 }

if __name__ == '__main__':
    print Error.ERROR_MSG
