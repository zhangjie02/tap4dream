#!/usr/bin/python
import random
from Logging import Log
from Table import Table
import DB
from Utils import checkPara
from Error import Error
from User import User
from Tournament import Tournament
from UserShareGift import UserShareGift

class BonusGame(Table):
    FIELD_TYPE = {
        'bet': int,
        'rate': int,
        'step': lambda x: int(x) if x else None,
    }

    # choose 4 out of 12
    TOTAL_NUMBER = 12
    MAX_STEP = 4
    BONUS_RATE = {3:(10, 80), 4:(150, 270), 5:(270, 395)} # 185 845 1350(45, 210, 335)

    @classmethod
    def play(cls, para):
        if not checkPara(para, ['uid', 'machine_id', 'idx']):
            return Error.INVALID_PARAM

        uid = para['uid']
        mid = para['machine_id']
        idx = para['idx']

        bonus = cls(uid, mid)
        ret = bonus.doPlay(idx)

        if ret is False:
            return Error.BONUS_NOT_EXIST

        (bet, rate, total_win, left) = ret

        user = User(uid)

        if total_win > 0:
            user.coin += total_win
            Tournament.compete(uid, mid, total_win)
            User(uid).addWinRec(total_win / bet)

        data = {'coin': user.coin, 'bet': bet, 'rate': rate, 'total_win': total_win, 'left': left}

        return data

    @classmethod
    def ignore(cls, para):
        if not checkPara(para, ['uid', 'machine_id']):
            return Error.INVALID_PARAM

        bonus = cls(para['uid'], para['machine_id'])
        bonus.remove()

        return Error.OK

    @classmethod
    def create(cls, uid, machine_id, bonus_num, bet):
        bonus = cls(uid, machine_id)
        bonus.remove()

        if bonus_num not in cls.BONUS_RATE:
            raise Exception("bonus num(%s) error" % bonus_num)

        boost = 1
        if bet <= 10:
            boost = 1.5

        (l, h) = cls.BONUS_RATE[bonus_num]
        seeds = range(int(l*boost), int(h*boost)+1)
        seq = []

        while len(seq) < cls.TOTAL_NUMBER:
            s = random.choice(seeds)
            seq.append(s)
            seeds.remove(s)

        seq_key = bonus.genRkey("seq:%s:%s" % (uid, machine_id))

        # write db
        cli = DB.Redis()
        cli.delete(seq_key)
        for s in seq:
            cli.rpush(seq_key, s)

        bonus.step = 0
        bonus.rate = 0
        bonus.bet = bet

    def __init__(self, uid, machine_id):
        self.uid_ = uid
        self.mid_ = machine_id

        Table.__init__(self, "%s:%s" % (uid, machine_id))

    def doPlay(self, idx):
        cur_step = self.step
        if self.step is None or cur_step >= self.MAX_STEP:
            return False

        seq_key = self.genRkey("seq:%s:%s" % (self.uid_, self.mid_))
        seq = DB.get_list(seq_key)

        number = int(random.choice(list(seq)))

        cur_step += 1
        self.set('s_idx:%s'% cur_step, idx)
        self.set('s_val:%s'% cur_step, number)

        seq.remove(number)
        self.step = cur_step

        total_rate = self.rate + number
        self.rate = total_rate

        left = list(seq)

        win = 0

        bet = self.bet
        if cur_step >= self.MAX_STEP:
            win = total_rate * bet
            self.remove()

            share = UserShareGift(self.uid_)
            share.setFlag(UserShareGift.TYPE_BONUS)

        return (bet, number, win, left)

    def load(self):
        cur_step = self.step

        if cur_step is None:
            return None

        steps = []
        for i in range(1, cur_step + 1):
            steps.append({'pos': self.get('s_idx:%s'%i), 'rate': self.get('s_val:%s'%i)})

        return {'left': self.MAX_STEP - cur_step, 'steps': steps}

    def remove(self):
        super(BonusGame, self).remove()

        seq_key = self.genRkey("seq:%s:%s" % (self.uid_, self.mid_))
        DB.Redis().delete(seq_key)



if __name__ == '__main__':
    c = BonusGame(1, 1)
    BonusGame.create(1, 1, 3, 10)
    for i in range(3, 7):
        print c.doPlay(i)
        #print c.load()
    # para = {'uid': 377}
    # BonusGame.play()
