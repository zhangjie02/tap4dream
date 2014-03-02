#server
REDIS_HOST = '115.236.92.117'
REDIS_PORT = 6379

# versions
MIN_VERSION = 1
LATEST_VERSION = 1

RESOURCE_PREFIX = 'http://115.236.92.117/static/'
PKG_NAME = 'com.vegas.slot'
PKG_URL = 'https://play.google.com/store/apps/details?id=%s' % PKG_NAME

# init user property
INIT_USER_COIN = 60000
INIT_USER_LEVEL = 1
INIT_USER_EXP = 0

MAX_LEVEL = 200

BIG_WIN_RATE = 30
MEGA_WIN_RATE = 200

# (person count, weight per person)
PRIZE = [(1, 200),
        (1, 100),
        (3, 50),
        (5, 30),
        (5, 16),
        (5, 12),
        (5, 9),
        (5, 7),
        (8, 6),
        (8, 4.5),
        (24, 3.5),
        (40, 2)
        ]
# % of person can share the prize pool
WIN_PRIZE_RATE = 0.2

