//
//  TableView.h
//  spacewar
//
//  Created by xiaoxiangzi on 13-5-3.
//
//

#ifndef __spacewar__TableView__
#define __spacewar__TableView__

#include <iostream>
#include "cocos-ext.h"
#include "UITouchDelegate.h"

class TableView : public cocos2d::extension::CCTableView, public UITouchDelegate {

public:
    static TableView* create(cocos2d::extension::CCTableViewDataSource* dataSource, cocos2d::CCSize size);
    static TableView* create(cocos2d::extension::CCTableViewDataSource* dataSource, cocos2d::CCSize size, CCNode *container);
    void setCellTouchable(bool touchable);
    void setTableViewScrollable(bool scrollable);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

    void cancelTouch(cocos2d::CCTouch *pTouch);
    TableView();
    
    void checkOffset(float specialCellSize);
private:
    virtual void registerWithTouchDispatcher();
private:
    bool _scrollable;
};

#endif /* defined(__spacewar__TableView__) */
