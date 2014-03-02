//
//  ScrollBarTableView.cpp
//  spacewar
//
//  Created by xiaoxiangzi on 13-4-15.
//
//

#include "ScrollBarTableView.h"
#include "ScrollBar.h"
#include "ResourceName.h"
#include "LayoutUtil.h"
#include "TableView.h"
#include "WaitingPane.h"
#include "ResourceKey.h"
using namespace cocos2d;
using namespace extension;
using namespace std;

ScrollBarTableView* ScrollBarTableView::create(const cocos2d::CCSize &tableSize, const cocos2d::CCSize &cellSize, cocos2d::extension::CCTableViewDataSource *dataSource, cocos2d::extension::CCTableViewDelegate *delegate) {
    ScrollBarTableView* view = new ScrollBarTableView();
    view->initScrollBarTableView(tableSize, cellSize, dataSource, delegate);
    view->autorelease();
    return view;
}

ScrollBarTableView::ScrollBarTableView() : _scrollBar(NULL), _tableView(NULL), _tableSize(CCSizeZero), _cellSize(CCSizeZero), _tableViewDelegate(NULL), _tableViewDataSource(NULL), _scrollBarOffset(10), _scrollBarVisible(true), _waitingPane(NULL), _scrollable(true) {}

void ScrollBarTableView::initScrollBarTableView(const cocos2d::CCSize &tableSize, const cocos2d::CCSize &cellSize, cocos2d::extension::CCTableViewDataSource *dataSource, cocos2d::extension::CCTableViewDelegate *delegate) {
    BaseUILayer::init();
    _tableSize = tableSize;
    _cellSize = cellSize;
    _tableViewDataSource = dataSource;
    _tableViewDelegate = delegate;
    
    this->setContentSize(_tableSize);
    this->setNeedTouchChildren(true);
    
    _tableView = TableView::create(this, tableSize);
    _tableView->ignoreAnchorPointForPosition(false);
    _tableView->setAnchorPoint(CCPointZero);
	_tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    _tableView->setDelegate(this);
    this->addChild(_tableView, TABLE_VIEW_ZORDER);
    LayoutUtil::layout(_tableView, 1, 0, this, 1, 0, true);
    
    _scrollBar = ScrollBar::create(_resKey->getCCSpriteFrame(ResourceName::SCROLLBAR_BG), _resKey->getCCSpriteFrame(ResourceName::SCROLLBAR_FG), _tableSize.height);
    this->addChild(_scrollBar);
    updateScrollbarPos();
    
    reloadTable();
}

void ScrollBarTableView::reloadTable() {
    updateScrollbarLength();
    _tableView->reloadData();
    jumpToCell(0);
    
    CCSize cellSize = cellSizeForTable(_tableView);
    unsigned int cellNum = numberOfCellsInTableView(_tableView);
    bool scrollable = true;
    if (_tableView->getDirection() == kCCScrollViewDirectionVertical) {
        scrollable = ((cellNum * cellSize.height) > this->getContentSize().height);
    } else {
        scrollable = ((cellNum * cellSize.height) > this->getContentSize().width);
    }
    _tableView->setTableViewScrollable(scrollable && _scrollable);
    _scrollBar->setVisible(scrollable && _scrollBarVisible && _scrollBar->needShowScrollBar());
    
    if (numberOfCellsInTableView(_tableView) > 0) {
        stopLoadingAnim();
    }
}

void ScrollBarTableView::jumpToCell(int cellIndex) {
    if (_tableView->getDirection() == kCCScrollViewDirectionHorizontal) {
        _tableView->setContentOffset(ccp(_tableView->getContainer()->getPositionX() - _cellSize.width * cellIndex,
                                         _tableView->getContainer()->getPositionY()));
    } else {
        _tableView->setContentOffset(ccp(_tableView->getContainer()->getPositionX(),
                                         _tableView->getContainer()->getPositionY() + _cellSize.height * cellIndex));
    }
}

unsigned int ScrollBarTableView::numberOfCellsInTableView(cocos2d::extension::CCTableView *table) {
    if (_tableViewDataSource) {
        return _tableViewDataSource->numberOfCellsInTableView(table);
    }
    
    return 0;
}

void ScrollBarTableView::tableCellTouched(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell) {
    if (_tableViewDelegate) {
        _tableViewDelegate->tableCellTouched(table, cell);
    }
}

void ScrollBarTableView::scrollViewDidScroll(cocos2d::extension::CCScrollView* view) {
    updateScrollbarOffset();
    
    if (_tableViewDelegate) {
        _tableViewDelegate->scrollViewDidScroll(view);
    }
}

void ScrollBarTableView::scrollViewDidZoom(cocos2d::extension::CCScrollView* view) {
    if (_tableViewDelegate) {
        _tableViewDelegate->scrollViewDidZoom(view);
    }
}

cocos2d::extension::CCTableViewCell* ScrollBarTableView::tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx) {
    if (_tableView) {
        _tableView->dequeueCell();
    }
    
    return _tableViewDataSource->tableCellAtIndex(table, idx);
}

cocos2d::CCSize ScrollBarTableView::cellSizeForTable(cocos2d::extension::CCTableView *table) {
    if (_tableViewDataSource) {
        return _tableViewDataSource->cellSizeForTable(table);
    }
    
    return _cellSize;
}

void ScrollBarTableView::setVisible(bool visible) {
    CCNode::setVisible(visible);
    _tableView->setVisible(visible);
    _scrollBar->setVisible(visible);
}

void ScrollBarTableView::setVerticalFillOrder(cocos2d::extension::CCTableViewVerticalFillOrder order) {
    _tableView->setVerticalFillOrder(order);
}

void ScrollBarTableView::setDirection(cocos2d::extension::CCScrollViewDirection eDirection) {
    _tableView->setDirection(eDirection);
    updateScrollbarLength();
    updateScrollbarOffset();
    updateScrollbarPos();
}

void ScrollBarTableView::updateScrollbarOffset() {
    if (_tableView->getDirection() == kCCScrollViewDirectionHorizontal) {
        _scrollBar->setOffset(_tableView->getContentOffset().x);
    } else {
        _scrollBar->setOffset(_tableView->getContentOffset().y);
    }
}

void ScrollBarTableView::updateScrollbarPos() {
    if (_tableView->getDirection() == kCCScrollViewDirectionHorizontal) {
        _scrollBar->setRotation(0);
        LayoutUtil::layout(_scrollBar, 0, 0, _tableView, 0, 1, false, 0, _scrollBarOffset);
    } else {
        _scrollBar->setRotation(-90);
        LayoutUtil::layout(_scrollBar, 0, 0, _tableView, 1, 0, false, _scrollBarOffset);
    }
}

void ScrollBarTableView::updateScrollbarLength() {
    int cellsNum = _tableView->getDataSource()->numberOfCellsInTableView(_tableView);
    if (_tableView->getDirection() == kCCScrollViewDirectionHorizontal) {
        _scrollBar->setMaxLength(_tableSize.width);
        _scrollBar->setScrollableLength(cellsNum * _cellSize.width);
    } else {
        _scrollBar->setMaxLength(_tableSize.height);
        _scrollBar->setScrollableLength(cellsNum * _cellSize.height);
    }
    _scrollBar->setVisible(_scrollBarVisible && _scrollBar->needShowScrollBar());
}

void ScrollBarTableView::setScrollbarOffset(float offset) {
    _scrollBarOffset = offset;
    updateScrollbarPos();
}

void ScrollBarTableView::setNeedTouchCell(bool needTouchCell) {
    _tableView->setCellTouchable(needTouchCell);
}

void ScrollBarTableView::setScrollBarVisible(bool visible) {
    _scrollBarVisible = visible;
    _scrollBar->setVisible(visible && _scrollBar->needShowScrollBar());
}

void ScrollBarTableView::startLoadingAnim() {
    if (_waitingPane == NULL) {
        _waitingPane = WaitingPane::create();
        this->addChild(_waitingPane, WAITING_CIRCLE_ZORDER);
        LayoutUtil::layoutParentCenter(_waitingPane);
    }
    _waitingPane->setVisible(true);
    _waitingPane->startWaiting();
}

void ScrollBarTableView::stopLoadingAnim() {
    if (_waitingPane) {
        _waitingPane->stopWaiting();
        _waitingPane->setVisible(false);
    }
}

void ScrollBarTableView::setScrollable(bool scrollable) {
    _scrollable = scrollable;
    _tableView->setTableViewScrollable(_scrollable);
    setScrollBarVisible(scrollable && _scrollBarVisible);
}
