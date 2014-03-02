//
//  RandomManager.cpp
//  slot
//
//  Created by xiaoxiangzi on 13-11-21.
//
//

#include "RandomManager.h"
#include "Random.h"
#include "StringConverter.h"

RandomManager* RandomManager::getInstance() {
    static RandomManager manager;
    return &manager;
}

RandomManager::RandomManager() {
    //_globalRandom = new Random(CurrentTimeMillis::get());
}

RandomManager::~RandomManager() {
    delete _globalRandom;
}

Random* RandomManager::getGlobalRandom() const {
    return _globalRandom;
}

string RandomManager::getRandomInt(string intStr) {
    int32_t result = getGlobalRandom()->nextInt(StringConverter::toInt32(intStr));
    return StringConverter::toString(result);
}
