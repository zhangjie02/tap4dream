//
//  CellSprite.h
//  poker
//
//  Created by 苏 汝杰 on 13-12-9.
//
//

#ifndef __poker__CellSprite__
#define __poker__CellSprite__

#include "cocos2d.h"

using namespace std;
USING_NS_CC;


class CellSprite :public CCSprite{
    
public:
    
    CREATE_FUNC(CellSprite);
    
    CellSprite();
    
    virtual void init(int elemId,string path);
    
    virtual void play(void);
    
    virtual void reset();
    
    virtual bool hasFinishedPlay();
    
    int getId();
    
protected:
    
    virtual bool init();
    
protected:

    int _elemId;
    
private:
    
    
    
    
};


#endif /* defined(__poker__CellSprite__) */
