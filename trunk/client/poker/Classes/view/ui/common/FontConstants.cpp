//
//  FontConstants.cpp
//  spacewar
//
//  Created by xiaoxiangzi on 12-12-17.
//
//

#include "FontConstants.h"
#include "cocos2d.h"
using namespace cocos2d;
const float FontConstants::BMFONT_BASE_SIZE = 32.0f;

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
// custom ttf files are defined in info.plist
//const char* FontConstants::ARIAL_BLACK_TTF = "Arial Black";
//const char* FontConstants::ARIAL_BOLD_TTF = "Arial Bold Steamage";
const char* FontConstants::ARIAL_ROUNDED_MT_BOLD_TTF = "Arial Rounded MT Bold";
const char* FontConstants::ARIAL_ROUNDED_MT_TTF = "Arial Rounded MT";
#else
//const char* FontConstants::ARIAL_BLACK_TTF = "fonts/Arial Black.ttf";
//const char* FontConstants::ARIAL_BOLD_TTF = "fonts/Arial Bold Steamage.ttf";
const char* FontConstants::ARIAL_ROUNDED_MT_TTF = "fonts/Arial Rounded MT.ttf";
const char* FontConstants::ARIAL_ROUNDED_MT_BOLD_TTF = "fonts/Arial Rounded MT Bold.ttf";
#endif
//const char* FontConstants::ARIAL_FONT = "Arial";
