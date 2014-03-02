//
//  FontConstants.h
//  spacewar
//
//  Created by xiaoxiangzi on 12-12-17.
//
//

#ifndef spacewar_FontConstants_h
#define spacewar_FontConstants_h

class FontConstants {
public:
    static const float BMFONT_BASE_SIZE;
    
//    static const char* ARIAL_FONT;
//    static const char* ARIAL_BLACK_TTF;
//    static const char* ARIAL_BOLD_TTF;
    static const char* ARIAL_ROUNDED_MT_BOLD_TTF;
    static const char* ARIAL_ROUNDED_MT_TTF;
private:
    FontConstants() {}
    FontConstants(const FontConstants&);
    FontConstants& operator=(const FontConstants&);
};

#endif
