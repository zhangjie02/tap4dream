//
//  Random.h
//  RandTest
//
//  Created by xiaoxiangzi on 12-8-30.
//  Updated by zhouyan on 13-1-25.
//  Copyright (c) 2012 Droidhen. All rights reserved.
//

#ifndef __RANDOM_H__
#define __RANDOM_H__

#ifdef __APPLE__
#include "TargetConditionals.h"
#include "sys/types.h"
#else
#include "stdint.h"
#endif

class Random {
public:
    Random(int64_t seedValue);
	bool nextBoolean();
	void nextBytes(int8_t* buf, size_t bufSize);
	
	double nextDouble();
	float nextFloat();
	
	int32_t nextInt();
	/**
	 * Returns a pseudo-random uniformly distributed
	 * in the half-open range [0, n).
	 */
	int32_t nextInt(int32_t n);
	int64_t nextLong();
    
    /**
     * Returns the next pseudo-random, Gaussian ("normally") distributed.
	 *
	 * It generates one double value, chosen from (approximately) the usual
	 * normal distribution with mean 0.0 and standard deviation 1.0.
	 * Use result = result * V + E to adjust the mean(E) and variance(V).
	 *
	 * Note: this function is NOT thread-safe.
	 */
	double nextGaussian();
    
	void setSeed(int64_t seedValue);
	
protected:
	int32_t next(int32_t bits);
    
private:
	Random();
    Random(const Random&);
    Random& operator=(const Random&);
    
	static const int64_t multiplier = 0x5deece66dL;
	static const int64_t mask = ((int64_t) 1l << 48) - 1;
    
	int64_t seed;
	bool haveNextNextGaussian;
	double nextNextGaussian;
    
	void init(int64_t seedValue);
};

#endif  // __RANDOM_H__
