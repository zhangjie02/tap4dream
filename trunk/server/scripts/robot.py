from sqlalchemy import *
from sqlalchemy.sql import column
import json
import sys, time
sys.path.append('..')

from SlotMachine import SlotMachine
from BonusGame import BonusGame
from User import User
import ConfMgr
from CfgTable import CfgTable

db=create_engine('mysql://droidhen:droidhen.hz@115.236.92.117/slot',echo=False)
metadata=MetaData(db)

table='user_bet'
t=Table(table, metadata, autoload=True)

# robot uid: 563-662
if __name__ == '__main__':
    N = 1000000000000000000000
    count = 0
    bonus_count = 0
    fs_count = 0
    machine_id = 1
    bet = 200
    lines = 9
    free_count = 0
    #uid = 563
    total_win = 0
    total_bet = 0

    uid = int(sys.argv[1])

    while count < N:
        is_freespin = 0

        user_level = User(uid).level
        #bet = ConfMgr.getMaxBet(user_level)
        para = {'uid':uid, 'machine_id':machine_id, 'lines':lines, 'bet':bet, 'is_free': 0}

        if free_count > 0:
            para['is_free'] = 1
            free_count -= 1
            is_freespin = 1

        resp = SlotMachine.spin(para)

        if resp == 103:
            bonus = CfgTable(CfgTable.CFG_LEVEL_INFO, user_level).special_bonus
            User(uid).coin += bonus * 100
            continue


        win = resp['win']
        coin = resp['coin']
        win_lines = ''
        bonus_win = 0
        is_bonus = 0

        if 'win_lines' in resp:
            win_lines = json.dumps(resp['win_lines'])

        if 'win_bonus' in resp:

            for i in range(4):
                bonus = BonusGame.play({'uid':uid, 'machine_id':machine_id, 'idx': 1})
                bonus_win += int(bonus['rate']) * bet

            is_bonus = 1
            bonus_count +=1

        if 'free_spin' in resp:
            free_count = int(resp['free_spin']['left'])

        if 'is_new_freespin' in resp:
            fs_count +=1

        count += 1

        coin /= 100
        win /= 100
        bonus_win /= 100

        #result = {'user_id':uid, 'balance': coin, 'bet_value': bet, 'win_lines':win_lines,
        #        'win_amount':win, 'bonus_win_amount':bonus_win, 'bet_lines':lines, 'is_bonus': is_bonus,
        #        'is_freespin': is_freespin, 'level': resp['level'], 'time': int(time.time())}
        #t.insert().values(result).execute()

        total_win += win
        total_win += bonus_win

        if not is_freespin:
            total_bet += bet * lines

        #sys.stdout.write("\rRate:%f Win:%d WinTotal:%d BetTotal:%d" % (total_win*100.0/total_bet, win+bonus_win, total_win, total_bet))
        #if bonus_win > 0:
        #    sys.stdout.write("\nbonus:%d\n"%bonus_win)

        sys.stdout.write("\rrate:%f, bonus_rate:%f, freespin_rate:%f" % (total_win*100.0/total_bet, bonus_count * 1.0 / count, fs_count * 1.0/ count))
        sys.stdout.flush()
