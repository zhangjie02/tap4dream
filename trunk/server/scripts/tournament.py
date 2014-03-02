import sys
import time
sys.path.append('..')
from Tournament import Tournament

if __name__ == '__main__':
    print 'now:', int(time.time())
    Tournament.refresh()
