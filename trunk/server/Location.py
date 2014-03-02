#!/usr/bin/env python

from User import User
from DB import Redis
from Social import Social

class Location:
    CLI = Redis()
    COUNTRY_KEY = 'loc:country'
    REGION_KEY = 'loc:region'

    REC_NUM = 5

    @classmethod
    def recommend(cls, para):
        uid = para['uid']

        uid_list = cls.getNearby(uid, cls.REC_NUM)

        ret = []
        for u in uid_list:
            if Social.isFriend(uid, u):
                continue

            user = User(u)
            data = {'uid':u, 'name':user.getName(), 'icon':user.getIcon(), 'level':user.level}

            if user.country is not None:
                data['country'] = user.country

            if user.region is not None:
                data['region'] = user.region

            ret.append(data)

        return {'users': ret}

    @classmethod
    def update(cls, uid, country, region):
        if country is not None:
            user = User(uid)
            old_country = user.country

            if old_country != country:
                if old_country is not None:
                    cls.CLI.srem('%s:%s'%(cls.COUNTRY_KEY, old_country), uid)

                cls.CLI.sadd('%s:%s'%(cls.COUNTRY_KEY, country), uid)

                user.country = country

            if country == 'US' and region is not None:
                old_region = user.region

                if old_region != region:
                    if old_region is not None:
                        cls.CLI.srem('%s:%s'%(cls.REGION_KEY, old_region), uid)

                    cls.CLI.sadd('%s:%s'%(cls.REGION_KEY, region), uid)

                    user.region = region


    @classmethod
    def getNearby(cls, uid, num):
        ret = []
        batch = 50

        user = User(uid)

        country = user.country
        region = user.region

        if country is None:
            return []

        if country == 'US' and region is not None:
            ret = cls.CLI.srandmember('%s:%s'%(cls.REGION_KEY, region), batch)

        if len(ret) < num:
            ret.extend(cls.CLI.srandmember('%s:%s'%(cls.COUNTRY_KEY, country), batch))

        if len(ret) < num:
            ret.extend(cls.CLI.srandmember('%s:%s'%(cls.COUNTRY_KEY, 'US'), batch))

        s = set(ret)
        uid = str(uid)
        if uid in s:
            s.remove(uid)

        return list(s)[:num]


if __name__ == '__main__':
    Location.update(1, 'US', 'CA')
    Location.update(2, 'JP', '02')

    print Location.getNearby(2, 5)

    print Location.recommend({'uid':2})
