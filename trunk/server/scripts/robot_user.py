from sqlalchemy import *
from sqlalchemy.sql import column
import json
import sys, time, random
sys.path.append('..')

from SlotMachine import SlotMachine
from BonusGame import BonusGame
from User import User
import ConfMgr
from CfgTable import CfgTable


# robot uid: 563-662
if __name__ == '__main__':
    N = 1000
    count = 0
    machine_id = int(sys.argv[2])
    bet = 200
    lines = 9
    free_count = 0
    #uid = 563
    total_win = 0
    total_bet = 0

    uid = int(sys.argv[1])

    while 1:
        is_freespin = 0

        user_level = User(uid).level
        bet = ConfMgr.getRandomBet(user_level)
        para = {'uid':uid, 'machine_id':machine_id, 'lines':lines, 'bet':bet, 'is_free': 0}

        if free_count > 0:
            para['is_free'] = 1
            free_count -= 1
            is_freespin = 1

        resp = SlotMachine.spin(para)

        if resp == 103:
            User(uid).coin += 1000000
            continue


        win = resp['win']
        coin = resp['coin']
        win_lines = ''
        bonus_win = 0
        is_bonus = 0

        if 'win_lines' in resp:
            win_lines = json.dumps(resp['win_lines'])

        """
        if 'win_bonus' in resp:

            for i in range(4):
                bonus = BonusGame.play({'uid':uid, 'machine_id':machine_id, 'idx': 1})
                bonus_win += int(bonus['rate']) * bet

            is_bonus = 1
        """

        if 'free_spin' in resp:
            free_count = int(resp['free_spin']['left'])


        count += 1

        coin /= 100
        win /= 100
        bonus_win /= 100


        total_win += win
        total_win += bonus_win

        if not is_freespin:
            total_bet += bet * lines

        sys.stdout.write("\rRate:%f Win:%d WinTotal:%d BetTotal:%d" % (total_win*100.0/total_bet, win+bonus_win, total_win, total_bet))
        if bonus_win > 0:
            sys.stdout.write("\nbonus:%d\n"%bonus_win)

        sys.stdout.flush()

        time.sleep(random.randint(5, 300))
