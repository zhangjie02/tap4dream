//
//  TableView.cpp
//  spacewar
//
//  Created by xiaoxiangzi on 13-5-3.
//
//

#include "TableView.h"
#include "Node.h"
#include <cmath>

USING_NS_CC;
USING_NS_CC_EXT;

TableView::TableView() : _scrollable(true) {}

TableView* TableView::create(cocos2d::extension::CCTableViewDataSource *dataSource, cocos2d::CCSize size) {
    return create(dataSource, size, NULL);
}

TableView* TableView::create(cocos2d::extension::CCTableViewDataSource *dataSource, cocos2d::CCSize size, cocos2d::CCNode *container) {
    TableView *table = new TableView();
    
    if (container == NULL) {
        container = CCNodeExt::create();
        container->ignoreAnchorPointForPosition(false);
        container->setAnchorPoint(ccp(0.0f, 0.0f));
    }
    
    table->initWithViewSize(size, container);
    table->autorelease();
    table->setDataSource(dataSource);
    table->_updateCellPositions();
    table->_updateContentSize();
    table->setCellTouchable(true);
    table->setUITouchEnabled(true);
    table->ignoreAnchorPointForPosition(false);
    
    return table;
}

void TableView::setCellTouchable(bool touchable) {
    UITouchDelegate* containerDelegate = dynamic_cast<UITouchDelegate*>(m_pContainer);
    if (containerDelegate) {
        containerDelegate->setNeedTouchChildren(touchable);
    }
    this->setNeedTouchChildren(touchable);
}

void TableView::registerWithTouchDispatcher() {}

void TableView::setTableViewScrollable(bool scrollable) {
    _scrollable = scrollable;
}

void TableView::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
    if (_scrollable) {
        CCTableView::ccTouchMoved(pTouch, pEvent);
    }
}

void TableView::cancelTouch(cocos2d::CCTouch *pTouch) {
    if (m_pTouchedCell && m_pTableViewDelegate != NULL) {
            m_pTableViewDelegate->tableCellUnhighlight(this, m_pTouchedCell);
        m_pTouchedCell = NULL;
    }
    m_pTouches->removeObject(pTouch);
}

void TableView::checkOffset(float specialCellSize) {
    CCSize contentSize = getContentSize();
    CCSize viewSize = getViewSize();
    CCPoint currentOffset = getContentOffset();
    
    if (contentSize.height < viewSize.height) {
        setContentOffset(ccp(currentOffset.x, viewSize.height - contentSize.height));
        return;
    }
    
    CCTableViewCell* cell = NULL;
    unsigned int uCountOfItems = m_pDataSource->numberOfCellsInTableView(this);
    for (int i = 0; i < uCountOfItems; i++) {
        CCTableViewCell* item = this->cellAtIndex(i);
        if (item && (std::abs(item->getContentSize().height - specialCellSize) < 1)) {
            cell = item;
        }
    }

    float delta = 0;
    if (cell) {
        float originalCellPos = cell->getPositionY();
        if (originalCellPos < -currentOffset.y) {
            delta = (-currentOffset.y - originalCellPos);
        }
    }
    float targetPos = currentOffset.y + delta;
    if (targetPos > 0) {
        targetPos = 0;
    }

//    CCLog("targetPos: %f", targetPos);
    setContentOffset(ccp(currentOffset.x, targetPos));
}
