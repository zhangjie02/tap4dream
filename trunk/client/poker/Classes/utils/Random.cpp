//
//  Random.cpp
//  RandTest
//
//  Created by xiaoxiangzi on 12-8-30.
//  Updated by zhouyan on 13-1-25.
//  Copyright (c) 2012 Droidhen. All rights reserved.
//

#include <ctime>
#include <cmath>

#include "Random.h"

Random::Random() {
	init(time(NULL));
}

Random::Random(int64_t seedValue) {
	init(seedValue);
}

void Random::init(int64_t seedValue) {
	setSeed(seedValue);
	haveNextNextGaussian = false;
	nextNextGaussian = 0;
}

int32_t Random::next(int32_t bits) {
    seed = (seed * multiplier + 0xbL) & mask;
    return (int32_t) (((int64_t) seed) >> (48 - bits));
}

bool Random::nextBoolean() {
    return next(1) != 0;
}

void Random::nextBytes(int8_t *buf, size_t bufSize) {
    int32_t rand = 0;
    size_t count = 0, loop = 0;
    while (count < bufSize) {
        if (loop == 0) {
            rand = nextInt();
            loop = 3;
        } else {
            loop--;
        }
        buf[count++] = (int8_t) rand;
        rand >>= 8;
    }
}

double Random::nextDouble() {
    return ((((int64_t) next(26) << 27) + next(27)) / (double) ((int64_t)1L << 53));
}

float Random::nextFloat() {
    return (next(24) / 16777216.0f);
}

int32_t Random::nextInt() {
    return next(32);
}

int32_t Random::nextInt(int32_t n) {
    if ((n & -n) == n) {
        return (int32_t) ((n * (int64_t) next(31)) >> 31);
    }
    int32_t bits, val;
    do {
        bits = next(31);
        val = bits % n;
    } while (bits - val + (n - 1) < 0);

    return val;
}

int64_t Random::nextLong() {
    return ((int64_t) next(32) << 32) + next(32);
}

void Random::setSeed(int64_t seedValue) {
    seed = (seedValue ^ multiplier) & mask;
}

double Random::nextGaussian() {
	if (haveNextNextGaussian) {
		haveNextNextGaussian = false;
		return nextNextGaussian;
	} else {
		double v1, v2, s;
		do {
			v1 = 2 * nextDouble() - 1; // between -1 and 1
			v2 = 2 * nextDouble() - 1; // between -1 and 1
			s = v1 * v1 + v2 * v2;
		} while (s >= 1 || s == 0);
		double multiplier = sqrt(-2 * log(s)/s);
		nextNextGaussian = v2 * multiplier;
		haveNextNextGaussian = true;
		return v1 * multiplier;
	}
}
