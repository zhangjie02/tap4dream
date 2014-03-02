//
//  FontsUtil.h
//  slot
//
//  Created by 苏 汝杰 on 13-12-27.
//
//

#ifndef __slot__FontsUtil__
#define __slot__FontsUtil__

#include <iostream>
#include "cocos2d.h"
#include <string>

using namespace std;
USING_NS_CC;

class FontsUtil {
    
public:
    
    static void setFontsSize(string imageId,int size,CCLabelBMFont* lable);
    
    static ccColor3B convertToColor3B(int color);
    
    static ccColor3B convertToColor3B(string color);
};

#endif /* defined(__slot__FontsUtil__) */
