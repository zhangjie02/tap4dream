//
//  Screen.h
//  Cocos2dDemo
//
//  Created by linzi on 13-1-6.
//
//

#ifndef __Cocos2dDemo__Screen__
#define __Cocos2dDemo__Screen__

class Screen {
public:
    static const float DESIGN_WIDTH;
    static const float DESIGN_HEIGHT;
    static const float MIN_ASPECT_RATIO;
    
    static Screen* init(float screenWidth, float screenHeight);
    static Screen* getCurrentScreen();
    
public:
    Screen(float screenWidth, float screenHeight);
    
    float getScreenWidth() const;
    float getScreenHeight() const;
    float getScaledDesignedWidth() const;
    float getScaledDesignedHeight() const;
    float getFitScreenScaleX() const;
    float getFitScreenScaleY() const;
    
private:
    float _realWidth;
    float _realHeight;
    float _scaledDesignWidth;
    float _scaledDesignHeight;
    float _fitScreenScaleX;
    float _fitScreenScaleY;
    
private:
    Screen(const Screen&);
    Screen& operator=(const Screen&);
};

#endif /* defined(__Cocos2dDemo__Screen__) */
