//
//  Cloneable.h
//  xiyou
//
//  Created by zhouyan on 13-7-1.
//
//

#ifndef __xiyou__Cloneable__
#define __xiyou__Cloneable__

#include <string>
using std::string;

class Cloneable {
public:
    Cloneable(const string& name);
    virtual ~Cloneable() = 0;
    virtual Cloneable* clone() = 0;
    
    const string& getName();
    
private:
    const string _name;
};

#endif /* defined(__xiyou__Cloneable__) */
