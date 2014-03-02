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

class BonusGameStep(Table):
    FIELD_TYPE = {
        'bet': int,
        'rate': int,
        'step': lambda x: int(x) if x else None,
    }

    # choose 4 out of 12
    NUMBER_PER_STEP = 5
    MAX_STEP = 5
    # [bonus_num][step]
    #10, 50, 150, 250, 500
    #1: 5 30 /5
    #2: 5 50 /5
    #3: 20 80 /10
    #4: 50 120 /10
    #5:
    STEP_RATE = {1:(5, 15), 2:(30, 70), 3:(120, 170), 4:(200, 300), 5:(400, 600)} # 185 845 1350(45, 210, 335)
    STEP_TRAP_NUM = {1:0, 2:1, 3:2, 4:3, 5:4}
    BONUS_RATE = {3:1, 4:5, 5:8}
    TRAP = 0

    @classmethod
    def play(cls, para):
        if not checkPara(para, ['uid', 'machine_id']):
            return Error.INVALID_PARAM

        uid = para['uid']
        mid = para['machine_id']

        bonus = cls(uid, mid)
        ret = bonus.doPlay()

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

        cli = DB.Redis()
        bonus_rate = cls.BONUS_RATE[bonus_num]

        if bet <= 10:
            bonus_rate = int(bonus_rate * 1.5)

        for i in range(1, cls.MAX_STEP+1):
            (l, h) = cls.STEP_RATE[i]
            trap_num = cls.STEP_TRAP_NUM[i]
            seeds = range(l, h+1)
            seq = trap_num * [cls.TRAP]

            while len(seq) < cls.NUMBER_PER_STEP:
                s = random.choice(seeds)
                seq.append(int(s * bonus_rate))
                seeds.remove(s)

            random.shuffle(seq)

            seq_key = bonus.genRkey("seq:%s:%s:%s" % (uid, machine_id, i))

            # write db
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

    def doPlay(self):
        cur_step = self.step
        if self.step is None or cur_step >= self.MAX_STEP:
            return False

        cur_step += 1
        seq_key = self.genRkey("seq:%s:%s:%s" % (self.uid_, self.mid_, cur_step))
        seq = DB.get_list(seq_key)

        number = int(random.choice(list(seq)))

        # self.set('s_idx:%s'% cur_step, idx)
        # self.set('s_val:%s'% cur_step, number)

        # seq.remove(number)
        self.step = cur_step

        if number != self.TRAP:
            total_rate = self.rate + number
            self.rate = total_rate

        win = 0

        left = []
        for i in range(cur_step, self.MAX_STEP + 1):
            seq_key = self.genRkey("seq:%s:%s:%s" % (self.uid_, self.mid_, i))
            seq = DB.get_list(seq_key)
            left.append(list(seq))

        bet = self.bet
        if number == self.TRAP or cur_step >= self.MAX_STEP:
            win = self.rate * bet
            self.remove()

            share = UserShareGift(self.uid_)
            share.setFlag(UserShareGift.TYPE_BONUS)

        return (bet, number, win, left)

    def load(self):
        cur_step = self.step

        if cur_step is None:
            return None

        # different scence, no history needed
        """
        steps = []
        for i in range(1, cur_step + 1):
            seq_key = self.genRkey("seq:%s:%s:%s" % (self.uid_, self.mid_, i))
            seq = DB.get_list(seq_key)
            steps.append(list(seq))
        """

        return {'left': self.MAX_STEP - cur_step, 'total_win': self.bet * self.rate}

    def remove(self):
        super(BonusGameStep, self).remove()

        for i in range(1, self.MAX_STEP):
            seq_key = self.genRkey("seq:%s:%s:%s" % (self.uid_, self.mid_, i))
            DB.Redis().delete(seq_key)



if __name__ == '__main__':
    bonus_type = BonusGameStep
    c = bonus_type(1, 1)
    c.remove()
    bonus_type.create(1, 1, 3, 10)
    print c.doPlay()
    #for i in range(3, 7):
        #print c.doPlay(i)
        #print c.load()
    # para = {'uid': 377}
    # BonusGameStep.play()
