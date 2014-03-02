#!/usr/bin/env python

import redis
from redis_wrap import setup_system, get_hash, get_set, get_list
import Config


clients = {'default': redis.Redis(Config.REDIS_HOST, Config.REDIS_PORT)}
setup_system('default', Config.REDIS_HOST, Config.REDIS_PORT)

def Redis(k = 'default'):
    return clients[k]


if __name__ == '__main__':
    h = get_hash('test')
    print set(get_set('haha'))
    
    
    