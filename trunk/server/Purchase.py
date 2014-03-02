#!/usr/bin/env python

#from Crypto.Signature import PKCS1_v1_5
#from Crypto.Hash import SHA
#from Crypto.PublicKey import RSA
import base64
import json
from Logging import PayLog as Log
from Error import Error
from User import User
from CfgTable import CfgTable
from Stat import Stat


class Purchase:


    CERT = "-----BEGIN PUBLIC KEY-----\n" + \
    "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEArUis5x4is5Kv4lfjZNi7\n" + \
    "t+LpxvsfF/EYicxyMWz5qY8NsAPke71F3x+zhsGq3suAQGAsyZshdugWGaAHMVWj\n" + \
    "IwgJZPJfDyUAsZ0Mc/Udkfi1ehTDZqa3/nR+qIQXaWTKqw0Bt/HkKTRshqguTipi\n" + \
    "iGnbv2bSbYRIAc9UhK91nse4S4tjEtTBpO4o36uTRX+DDFvtv9KspJ+SeKwGQynX\n" + \
    "5hdJqJ9Hc4kLp/8Fy2SahwCVYBsEMUCwNep7wYib3NaZNymDSpdOX1A+irfmaTay\n" + \
    "awzfGBNKJcC3wg1FT4sS2Mx7tBi6Juw7hpXjJk0xswZ7BWj9QfIdlkxbrUoWb1ad\n" + \
    "OwIDAQAB\n" +\
    "-----END PUBLIC KEY-----"

    @classmethod
    def verifyPurchase(cls, para):

        signed_data = json.loads(para['signed_data'])
        uid = para['uid']

        product_id = signed_data['productId']

        cfg = CfgTable(CfgTable.CFG_STORE, product_id)

        if cfg.exists():
            user = User(uid)

            if user.level <= int(cfg.max_level):
                amount = int(int(cfg.amount) * (1 + int(cfg.extra) * 1.0 / 100))
                user.coin += amount
                Log.info('Purchased uid=%d product_id=%s buy_coin=%d' % (uid, product_id, amount))

                data = {'buy_coin': amount}
                Stat().incr(data)

                return {'coin': user.coin}
            else:
                Log.error('level execeeded')
                return Error.INVALID_PARAM
        else:
            Log.error('No such product id')
            return Error.INVALID_PARAM

        """
        Log.info('uid=%s signature=%s signed_data=%s' % (uid, signature, signed_data))

        if len(signature) == 0 or len(signed_data) == 0:
            Log.error('empty signature or signed_data');
            return Error.ret(Error.INVALID_PARAM)

        if not cls.verifySign(signature, signed_data):
            Log.error('verify sig error!')
            return Error.ret(Error.SIGNATURE_ERROR)

        order = json.loads(signed_data)

        purchase_state = int(order['purchaseState'])
        order_id = order['orderId']
        purchase_time = int(order['purchaseTime'])
        product_id = order['productId']
        real_uid = int(order['developerPayload'])
        pkg_name = order['packageName']
        purchase_token = ''

        if 'token' in order:
            purchase_token = order['token']
        elif 'purchaseToken' in order:
            purchase_token = order['purchaseToken']
        else:
            Log.error('no token in signed data')
            return Error.ret(Error.INVALID_PARAM)

        if purchase_state != 0:
            Log.error('purchaseState is not 0')
            return Error.ret(Error.INVALID_PARAM)
        """



    @classmethod
    def verifySign(cls, sign, data):
        pub_key = RSA.importKey(cls.CERT)
        verifier = PKCS1_v1_5.new(pub_key)

        return verifier.verify(SHA.new(data), base64.b64decode(sign))

if __name__ == '__main__':
    #print Purchase.CERT

    sign = "Lb7FlD2H9LoGzFiT5roBNucxhv1aIOf/Ld+cGu++LNEj3CdTNnzaR2Bdh+v/VaZGr1GoYeG003I4K/HpJt+ws7ydtaym0RC69+JoBKwsYaRGfBNuZ/Jr3vuFG6raveMtzNOoji5JQSiUorZKwA9uWvv+gTKeRtkZYwv99j22FYkZx7nbFDpn5+9Ei9tVA4KnmHN2Bi25Cve/Q1y/71VVD5F5mE3/F2B+I/fUMd2zqJvRle5tuoDjSH5T5CcIS9dVtncnHpKhFPTHs0RsLqHj0/03t7ZgFs+VEzLilIRDg1wmXCRbiRlq3CsvyyIYuKUL7umLGTch1AKfmSj8KPozhA=="
    data = '{"orderId":"12999763169054705758.1343201673080710","packageName":"com.somofun.fa","productId":"coin1","purchaseTime":1357622472000,"purchaseState":0,"developerPayload":"1087986","purchaseToken":"vmevepwdcoglztazaloeawkc.AO-J1OwWRixXaD0lHL8lVbuAA7w06EVwPBDWuo6ByULMHaZiBZDPRm39fE8PjZj62JP71onkavlQQdnnb2uO8fKCjNtYF1wo9vOR8ChG7TizRvAg6xFofCY"}'

    #print data

    para = {'uid':500, 'signed_data': json.dumps({'productId': 'coin1_1'})}
    print Purchase.verifyPurchase(para)
