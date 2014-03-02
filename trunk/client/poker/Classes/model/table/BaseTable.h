/*
 * BaseTable.h
 *
 *  Created on: 2013-1-31
 *      Author: droidhen58
 */

#ifndef BASETABLE_H_
#define BASETABLE_H_

#include "libjson.h"

class BaseTable {
public:
    virtual ~BaseTable() = 0;
	virtual void init(const JSONNode& data) = 0;
	virtual void update(const JSONNode& data) = 0;
	virtual void dump(JSONNode& node) const = 0;
};


#endif /* BASETABLE_H_ */
