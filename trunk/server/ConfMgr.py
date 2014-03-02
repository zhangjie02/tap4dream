import Config
from CfgTable import CfgTable
import Version
import random

def load(para):
	ret = {}

	data_version = para['data_version']
	version = para['version']

	ret['data'] = CfgTable.loadAll(data_version, version)

	constants = {}
	constants['resource_prefix'] = Config.RESOURCE_PREFIX
	constants['data_version'] = Version.loadCurDataVersion()

	from UserShareGift import UserShareGift
	constants['levelup_share_coin'] = UserShareGift.SHARE_COIN[UserShareGift.TYPE_LEVELUP]
	constants['combo_share_coin'] = UserShareGift.SHARE_COIN[UserShareGift.TYPE_COMBO]
	constants['mega_share_coin'] = UserShareGift.SHARE_COIN[UserShareGift.TYPE_MEGA]
	constants['bonus_share_coin'] = UserShareGift.SHARE_COIN[UserShareGift.TYPE_BONUS]
	constants['share_friend_num'] = 5

	ret['constants'] = constants

	return ret

def isMachineLocked(game_id, lv):
	cfg = CfgTable(CfgTable.CFG_MACHINE_INFO, game_id)
	if cfg.is_featured:
		return lv >= cfg.featured_level
	else:
		return lv >= cfg.unlock_level

def isLineValid(game_id, lines):
	cfg = CfgTable(CfgTable.CFG_MACHINE_INFO, game_id)
	return lines <= cfg.max_line

def getMediumLineNum(game_id):
	cfg = CfgTable(CfgTable.CFG_MACHINE_INFO, game_id)
	return int(cfg.max_line) / 2

def isBetValid(lv, bet):
	data = CfgTable.load(CfgTable.CFG_LEVEL_BET)

	ok_bet = []
	for d in data:
		if lv >= int(d['level']):
			ok_bet.append(int(d['bet']))

	return bet in ok_bet

def getMaxBet(lv):
	data = CfgTable.load(CfgTable.CFG_LEVEL_BET)

	ok_bet = []
	for d in data:
		if lv >= int(d['level']):
			ok_bet.append(int(d['bet']))

	return max(ok_bet)

def getRandomBet(lv):
	data = CfgTable.load(CfgTable.CFG_LEVEL_BET)

	ok_bet = []
	for d in data:
		if lv >= int(d['level']):
			ok_bet.append(int(d['bet']))

	return random.choice(ok_bet)

def getMediumBet(lv):
	data = CfgTable.load(CfgTable.CFG_LEVEL_BET)

	ok_bet = []
	for d in data:
		if lv >= int(d['level']):
			ok_bet.append(int(d['bet']))

	i = len(ok_bet) / 2
	return ok_bet[i]

def getRandomMachineId(lv):
	data = CfgTable.load(CfgTable.CFG_MACHINE_INFO)

	pool = []
	for d in data:
		if lv >= int(d['unlock_level']):
			pool.append(int(d['id']))

	return random.choice(pool)


if __name__ == '__main__':
	print load({'data_version':0, 'version':1})
	#print isBetValid(1,  10)
    #print getRandomMachineId(10)
