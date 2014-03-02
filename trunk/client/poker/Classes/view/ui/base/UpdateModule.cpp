//
//  UpdateModule.cpp
//  poker
//
//  Created by 苏 汝杰 on 13-11-25.
//
//

#include "UpdateModule.h"
#include "Constant.h"


UpdateModule::UpdateModule():
deltaframetime(0),
frametime(Constant::SINGLE_FRAME_TIME)
{
    
}

void UpdateModule::init(){
    deltaframetime=0;
}

void UpdateModule::setSpeedUp(float multi){
    frametime/=multi;
}

void UpdateModule::update(float dt){
    
    float totaltime=dt+deltaframetime;

    if (totaltime>frametime) {
        
        int updatetime=totaltime/frametime;
        
        for (int i=0; i<updatetime; i++) {
            
            updateFrame(frametime);
            
        }
        
        deltaframetime=0;
        
        totaltime-=updatetime*frametime;
        
    }
    if (totaltime>0) {
        
        deltaframetime+=totaltime;
        
    }
    
}
