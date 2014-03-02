//
//  Cloneable.cpp
//  xiyou
//
//  Created by zhouyan on 13-7-1.
//
//

#include "Cloneable.h"

Cloneable::Cloneable(const string& name) : _name(name) {
}

Cloneable::~Cloneable() {
}

const string& Cloneable::getName() {
    return _name;
}
