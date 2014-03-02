from BonusGame import BonusGame
from BonusGameStep import BonusGameStep
from Stat import Stat
from User import User
from UserShareGift import UserShareGift

TYPE_HUB = {2: BonusGameStep,
            3: BonusGameStep,
            4: BonusGameStep,}

def getBonusGameType(machine_id):
    game_type = BonusGame

    if machine_id in TYPE_HUB:
        game_type = TYPE_HUB[machine_id]
    return game_type

def play(para):
    machine_id = para['machine_id']
    uid = para['uid']

    game_type = getBonusGameType(machine_id)

    ret = game_type.play(para)

    win_info = User(uid).checkWinRec()
    if win_info:
        ret.update(win_info)

    if 'is_mega' in ret:
        share = UserShareGift(uid)
        share.setFlag(UserShareGift.TYPE_MEGA)

     #only for stat
    if ret['total_win'] > 0:
       data = {'bonus': ret['total_win']}
       Stat().incr(data)

    return ret
