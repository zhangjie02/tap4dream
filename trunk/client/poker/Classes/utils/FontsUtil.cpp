//
//  FontsUtil.cpp
//  slot
//
//  Created by 苏 汝杰 on 13-12-27.
//
//

#include "FontsUtil.h"
#include "ResourceName.h"



void FontsUtil::setFontsSize(string imageId,int size,CCLabelBMFont* lable){
    float originalSize=0;
    if (imageId==ResourceName::ARIAL_ROUNDED_MT_BOLD_40) {
        originalSize=40;
    }else if(imageId==ResourceName::ARIAL_ROUNDED_MT_BOLD_72){
        originalSize=72;
    }else if (imageId == ResourceName::ARIAL_ROUNDED_MT_32
              || imageId == ResourceName::ARIAL_ROUNDED_MT_BOLD_32) {
        originalSize = 32;
    }

    lable->setScale(size/originalSize);
    
}

ccColor3B FontsUtil::convertToColor3B(int color) {
    return ccc3((color & 0xff0000) >> 16, (color & 0xff00) >> 8, color & 0xff);
}

ccColor3B FontsUtil::convertToColor3B(string colorStr) {
    char* p;
    long n = strtol(colorStr.c_str(), & p, 16 );
    return convertToColor3B(n);
}