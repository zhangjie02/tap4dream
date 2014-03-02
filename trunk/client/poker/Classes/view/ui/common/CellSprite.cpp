//
//  CellSprite.cpp
//  poker
//
//  Created by 苏 汝杰 on 13-12-9.
//
//

#include "CellSprite.h"
#include "LayoutUtil.h"

CellSprite::CellSprite():
_elemId(0)
{

}

bool CellSprite::init(){
    this->setAnchorPoint(LayoutUtil::getAnchorPoint(CENTER));
    return true;
}

void CellSprite::init(int elemId,string path){
    _elemId=elemId;
}

void CellSprite::play(void){
    
}

void CellSprite::reset(){
    
}


int CellSprite::getId(){
    return _elemId;
}

bool CellSprite::hasFinishedPlay(){
    return true;
}


