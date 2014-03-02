//
//  UpdateModule.h
//  poker
//
//  Created by 苏 汝杰 on 13-11-25.
//
//

#ifndef __poker__UpdateModule__
#define __poker__UpdateModule__

#include <iostream>

class UpdateModule{
    
    
public:
    virtual ~UpdateModule() {}
    
    void update(float dt);
    
    void setSpeedUp(float multi);
    
protected:
    
    void init();
    
    virtual void updateFrame(float dt)=0;
    UpdateModule();
    
private:
    
    
    float deltaframetime;
    
    float frametime;
    
    
};

#endif /* defined(__poker__UpdateModule__) */
