//
//  RandomManager.h
//  slot
//
//  Created by xiaoxiangzi on 13-11-21.
//
//

#ifndef __slot__RandomManager__
#define __slot__RandomManager__

#include <string>
using namespace std;

class Random;

class RandomManager {
    
public:
    static RandomManager* getInstance();
    
    Random* getGlobalRandom() const;
    string getRandomInt(string intStr);
private:
    RandomManager();
    ~RandomManager();
    RandomManager(const RandomManager&);
    RandomManager& operator=(const RandomManager&);
private:
    Random* _globalRandom;
};

#endif /* defined(__slot__RandomManager__) */
