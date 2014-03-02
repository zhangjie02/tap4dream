//
//  MathUtil.h
//  slot
//
//  Created by xiaoxiangzi on 13-12-4.
//
//

#ifndef slot_MathUtil_h
#define slot_MathUtil_h

#include <iostream>
#include <cmath>
#include <sstream>
#include "cocos2d.h"
using namespace cocos2d;

#define Gravity 10;
#define PI 3.14159265
#define PIR 0.31831
#define dis(x1,y1,x2,y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dis3d(x1,y1,z1,x2,y2,z2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define POSITIVE(x,y) ((((x) - (y))>0)? ((x)-(y)):((y)-(x)))
#ifndef MIN
#define MIN(x,y) (((x) > (y)) ? (y) : (x))
#endif  // MIN

#ifndef MAX
#define MAX(x,y) (((x) > (y)) ? (x) : (y))
#endif  // MAX

using namespace std;


class MathUtil {
public:
    static int rooff(float value);
    static float roundf(float value);
    static float floorfValue(float value);
    static float ceilfValue(float value);
	static bool largerOrEqual0(float value);
	static bool larger0(float value);
	static bool smaller0(float value);
	static bool smallerEqual0(float value);
	static bool equal0(float value);
    static float absf(float value);
    
    static float mod(float a,float b);
    static int64_t mod(int64_t a,int64_t b);
    
	static float getFormatFloat(float value);
    
	static float formatGameRoundAngle2ScreenRoundAngle(float angle);
	static float formatScreenRoundAngle2GameRoundAngle(float angle);
	//获取当前坐标系x，y坐标下的角度
	static float getRoundAnglebyPos(float x,float y);
    
	static float getFormatAngle(float angle);
    
	static float getAnglebyPos(float x,float y);
    
	static int getGridPosByGridPosf(float value);
    
	static bool reachPos(float spd,float deltaDis);
	
    static float getKByPoints(CCPoint start,CCPoint end);
private:
    MathUtil() {}
    MathUtil(const MathUtil&);
    MathUtil& operator= (const MathUtil&);
    
private:
	static float accuracy;
    
};


#endif
