#!/usr/bin/env python

import traceback
from django.views.decorators.csrf import csrf_exempt
from django.http import HttpRequest, HttpResponseBadRequest, HttpResponse, HttpResponseServerError
import json
import time
from Logging import Log
import Config
from Login import Login
from Error import Error
from Session import Session
from SlotMachine import SlotMachine
import BonusGameType
from Lobby import Lobby
from SpecialBonus import SpecialBonus
from Tournament import Tournament
from UserRewardLog import UserRewardLog
from Purchase import Purchase
import ConfMgr
from Social import Social
from Notice import Notice
from FriendRequest import FriendRequest
from User import User
from UserGift import UserGift
from UserShareGift import UserShareGift
from Location import Location



API_ROUTER = {
              'login': Login.login,
              'spin': SlotMachine.spin,
              'load_config': ConfMgr.load,
              'load_machine': SlotMachine.load,
              'play_bonus': BonusGameType.play,
              #'ignore_bonus': BonusGame.ignore,
              'load_lobby': Lobby.load,
              'reclaim_special_bonus': SpecialBonus.reclaim,
              'load_tournaments': Tournament.load,
              'get_rank': Tournament.getRank,
              'reward_history': UserRewardLog.load,
              'verify_purchase': Purchase.verifyPurchase,
              'get_friends': Social.getFriends,
              'delete_friend': Social.deleteFriend,
              'send_friend_request': FriendRequest.send,
              'load_friend_request': FriendRequest.load,
              'confirm_friend_request': FriendRequest.confirm,
              'ignore_friend_request': FriendRequest.ignore,
              'set_name': User.setNameAPI,
              'search_name': User.search,
              'set_icon': User.setIcon,
              'load_gift': UserGift.load,
              'send_gift': UserGift.send,
              'reclaim_gift': UserGift.reclaim,
              'load_share_gift': UserShareGift.load,
              'share_gift': UserShareGift.share,
              'reclaim_share_gift': UserShareGift.reclaim,
              'recommend_user': Location.recommend,
              }

INT_PARA = ['uid', 'bet', 'lines', 'machine_id', 'level', 'is_free',
            'type',
            'version', 'data_version',
            'tid',
            ]

@csrf_exempt
def api(request):
    try:
        para = json.loads(request.body)

        Log.info('Request: %s' % (log_kv(para)))

        cmd = para['cmd']

        if cmd in API_ROUTER:
            processPara(para)

            if cmd == 'login':
              if request.META.has_key('HTTP_X_REAL_IP'):
                  para['ip'] = request.META['HTTP_X_REAL_IP']
              else:
                  para['ip'] = request.META['REMOTE_ADDR']

            if cmd != 'verify_purchase' and para['version'] < Config.MIN_VERSION:
                Log.info('unsupported version: %d' % para['version'])
                return HttpResponse(genResponse(Error.VERSION_TOO_LOW))

            if cmd != 'login' and cmd != 'verify_purchase':
                if not Session.is_valid(para['uid'], para['sid']):
                    Log.error('session invalid')
                    return HttpResponse(genResponse(Error.INVALID_SESSION))

            ret = API_ROUTER[cmd](para)

            response = genResponse(ret, para['uid'])

            Log.info('Request: %s, Response: %s' % (para, response))

            return HttpResponse(response, content_type="application/json")
        else:
            Log.error('unknown cmd')
            return HttpResponse(genResponse(Error.UNKNOWN_CMD))

    except Exception, e:
        traceback.print_exc()
        Log.error(traceback.format_exc())
        return HttpResponseServerError("Unknown error: %s" % str(e))

def processPara(para):
    for k, v in para.items():
        if k in INT_PARA:
            para[k] = int(v)

def genResponse(ret, uid=0):
    resp = {}
    if isinstance(ret, int):
        resp['error_code'] = ret
        resp['error_msg'] = Error.ERROR_MSG[ret]

        if ret == Error.VERSION_TOO_LOW:
            resp['update'] = Config.PKG_URL
    else:
        resp = ret

        notice = Notice(uid).get()
        if notice:
            resp['notice'] = notice

        resp['time'] = int(time.time())

        resp['error_code'] = Error.OK

    return json.dumps(resp, ensure_ascii=False)

def log_kv(a):
    s = ''
    for k, v in a.items():
        s += '%s=%s ' % (k, v)
    return s

if __name__ == '__main__':
    print genResponse({})
    para = {'cmd': 'login', 'version': 1, 'did': 'name-2136325413', 'type':0}
    class R:
        pass

    r = R()
    r.body = json.dumps(para)

    print api(r)
