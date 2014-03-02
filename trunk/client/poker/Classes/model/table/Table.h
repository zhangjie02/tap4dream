#ifndef TABLE_H_
#define TABLE_H_
#include <vector>
#include "JSONUtil.h"
#include "BaseTable.h"
#include <algorithm>

using namespace std;

template <class T>
class Table : public BaseTable{
public:
    ~Table() {
        for(typename vector<T*>::iterator iter = _items.begin(); iter != _items.end(); iter++) {
            delete *iter;
        }
        _items.clear();
    }

	vector<T*>* getData() {
		return &_items;
	}

	void init(const JSONNode& data) {
		clearItems();

		for(JSONNode::const_iterator iter = data.begin(); iter != data.end(); iter++) {
			T* item = new T();
			item->parse(iter->as_node());
			_items.push_back(item);
		}
        
        sortItems();
	}

	void update(const JSONNode& data) {
		for(JSONNode::const_iterator iter = data.begin(); iter != data.end(); iter++) {
			JSONNode node = iter->as_node();
			int validate = JSONUtil::getInt(node,"validate");

			T* toFindItem = new T();
			toFindItem->parse(node);

			deleteEqualItem(toFindItem);

			if(validate > 0) {
				_items.push_back(toFindItem);
			}else {
				delete toFindItem;
			}
		}
        
        sortItems();
	}

	void dump(JSONNode& node) const {
		for(typename vector<T*>::const_iterator iter = _items.begin(); iter != _items.end(); iter++) {
			JSONNode item = JSONNode(JSON_NODE);
			(*iter)->dump(item);
			node.push_back(item);
		}
	}

	
private:
	void clearItems() {
		typename vector<T*>::iterator iter = _items.begin();
		while(!_items.empty()) {
			T* t = _items.back();
			delete t;
			_items.pop_back();

			iter ++;
		}
	}
    
    void sortItems() {
        sort(_items.begin(), _items.end(), compareItem);
    }

	T* getEqualItem(T* item) {
		for(typename vector<T*>::iterator iter = _items.begin(); iter != _items.end(); iter++) {
			if((*iter)->equals(item)) {
				return (*iter);
			}
		}
		return NULL;
	}

	void deleteEqualItem(T* item) {
		for(typename vector<T*>::iterator iter = _items.begin(); iter != _items.end(); iter++) {
			if((*iter)->equals(item)) {
				T* item = *iter;
                delete item;
				_items.erase(iter);
				return;
			}
		}
	}
             
    static bool compareItem(T* instA, T* instB) {
        return (*instA) < (*instB);
    }

private:
	vector<T*> _items;
};

#endif /* TABLE_H_ */
