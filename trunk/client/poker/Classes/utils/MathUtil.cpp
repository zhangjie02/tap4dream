//
//  MathUtil.cpp
//  spacewar
//
//  Created by xiaoxiangzi on 12-10-26.
//
//

#include "MathUtil.h"
#include <cmath>
#include <stdlib.h>

float MathUtil::accuracy=0.0001f;

float MathUtil::roundf(float value) {
    return floorf(value + 0.5);
}

float MathUtil::ceilfValue(float value) {
    return ceilf(value);
}

float MathUtil::floorfValue(float value) {
    return floorf(value);
}

int MathUtil::rooff(float value) {
    int valueInt = (int) value;
    if (valueInt < value) {
        valueInt += 1;
    }
    
    return valueInt;
}

float MathUtil::mod(float a,float b){
    int t=a/b;
    float v=a-t*b;
    return v;
}

int64_t MathUtil::mod(int64_t a,int64_t b){
    int64_t t=a/b;
    int64_t v=a-t*b;
    return v;
}

bool MathUtil::largerOrEqual0(float value){
	return value>-accuracy;
}


bool MathUtil::larger0(float value){
	return value>=accuracy;
}

bool MathUtil::smaller0(float value){
	return value<=-accuracy;
}

bool MathUtil::smallerEqual0(float value){
	return value<accuracy;
}

bool MathUtil::equal0(float value){
	return std::abs(value)<accuracy;
}

float MathUtil::getFormatFloat(float value){
	stringstream ss;
	ss<<value;
	value=atof(ss.str().c_str());
	return value;
}


float MathUtil::getFormatAngle(float angle){
	int t=(angle+360)/360;
	angle=angle+360-t*360;
	return angle;
}


float MathUtil::formatGameRoundAngle2ScreenRoundAngle(float angle){
	return getFormatAngle(angle+45);
}

float MathUtil::formatScreenRoundAngle2GameRoundAngle(float angle){
	return getFormatAngle(angle-45);
}

float MathUtil::getRoundAnglebyPos(float x,float y){
	float angle=getAnglebyPos(x,y);
	return x<0?getFormatAngle(180-angle):getFormatAngle(angle+360);
}

float MathUtil::getAnglebyPos(float x,float y){
	float rdis=dis(0,0,x,y);
    if (rdis==0) {
        return 0;
    }
	return asin(y/rdis)*180*PIR;
}

float MathUtil::getKByPoints(CCPoint start,CCPoint end){
    return (end.y-start.y)/(end.x-start.x);
}


int MathUtil::getGridPosByGridPosf(float value){
	int intV=floorfValue(value);
	return intV;
}

bool MathUtil::reachPos(float spd,float deltaDis){
	return (MathUtil::larger0(spd)&&MathUtil::largerOrEqual0(deltaDis)) ||
		(MathUtil::smaller0(spd) && MathUtil::smallerEqual0(deltaDis)) ||
		(MathUtil::equal0(spd) && MathUtil::equal0(deltaDis));
}

float MathUtil::absf(float value) {
    if (value < 0) {
        return -value;
    }
    
    return value;
}


