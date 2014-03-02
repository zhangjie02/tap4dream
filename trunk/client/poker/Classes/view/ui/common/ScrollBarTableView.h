//
//  ScrollBarTableView.h
//  spacewar
//
//  Created by xiaoxiangzi on 13-4-15.
//
//

#ifndef __spacewar__ScrollBarTableView__
#define __spacewar__ScrollBarTableView__

#include <iostream>
#include "cocos-ext.h"
#include "BaseUILayer.h"

using namespace cocos2d;
using namespace extension;

class ScrollBar;
class TableView;
class WaitingPane;

class ScrollBarTableView : public BaseUILayer, public cocos2d::extension::CCTableViewDataSource, public cocos2d::extension::CCTableViewDelegate {
    
public:
    static ScrollBarTableView* create(const cocos2d::CCSize& tableSize, const cocos2d::CCSize& cellSize,
                                      cocos2d::extension::CCTableViewDataSource* dataSource, cocos2d::extension::CCTableViewDelegate* delegate);
    void reloadTable();
    virtual void setVisible(bool visible);
    void setVerticalFillOrder(cocos2d::extension::CCTableViewVerticalFillOrder order);
    void setDirection(cocos2d::extension::CCScrollViewDirection eDirection);
    void jumpToCell(int cellIndex);
    void setScrollbarOffset(float offset);
    void setNeedTouchCell(bool needTouchCell);
    void setScrollBarVisible(bool visible);
    void startLoadingAnim();
    void stopLoadingAnim();
    void setScrollable(bool scrollable);
private:
    ScrollBarTableView();
    void initScrollBarTableView(const cocos2d::CCSize& tableSize, const cocos2d::CCSize& cellSize,
                                cocos2d::extension::CCTableViewDataSource* dataSource, cocos2d::extension::CCTableViewDelegate* delegate);
    
    virtual cocos2d::CCSize cellSizeForTable(cocos2d::extension::CCTableView *table);
    virtual cocos2d::extension::CCTableViewCell* tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
    virtual unsigned int numberOfCellsInTableView(cocos2d::extension::CCTableView *table);
    virtual void tableCellTouched(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);
    virtual void scrollViewDidScroll(cocos2d::extension::CCScrollView* view);
    virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView* view);
    void updateScrollbarOffset();
    void updateScrollbarPos();
    void updateScrollbarLength();
private:
    static const int WAITING_CIRCLE_ZORDER = 2;
    static const int TABLE_VIEW_ZORDER = 1;
    TableView* _tableView;
    ScrollBar* _scrollBar;
    cocos2d::CCSize _tableSize;
    cocos2d::CCSize _cellSize;
    cocos2d::extension::CCTableViewDelegate* _tableViewDelegate;
    cocos2d::extension::CCTableViewDataSource* _tableViewDataSource;
    float _scrollBarOffset;
    bool _scrollBarVisible;
    WaitingPane* _waitingPane;
    bool _scrollable;
};

#endif /* defined(__spacewar__ScrollBarTableView__) */
