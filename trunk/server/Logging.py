import logging
from logging.handlers import SysLogHandler

SLOT_LOG = 'local5'

def getLogger(facility='local5', loglevel=logging.DEBUG, tag='slot'):
    logger = logging.getLogger(tag)
    logger.setLevel(loglevel)
    #syslog = SysLogHandler(address=(RSYSLOG_HOST, RSYSLOG_PORT), facility=facility)
    syslog = SysLogHandler(facility=facility)

    f = '%s: '%tag + '%(asctime)-15s %(filename)s [%(levelname)s] %(message)s'
    formatter = logging.Formatter(f)
    syslog.setFormatter(formatter)
    logger.addHandler(syslog)

    sh = logging.StreamHandler()
    sh.setLevel(loglevel)
    logger.addHandler(sh)
    return logger


Log = getLogger()
PayLog = getLogger(SLOT_LOG, logging.DEBUG, 'slot_pay')

if __name__ == '__main__':
    Log.info('a=1 b=2')
