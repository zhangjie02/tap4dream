//
//  ArrayUtil.h
//  poker
//
//  Created by jayson on 14-3-3.
//
//

#ifndef poker_ArrayUtil_h
#define poker_ArrayUtil_h

#include <string>
#include <map>
#include <list>
#include <vector>

using namespace std;

class ArrayUtil {
public:
    /*static void btrace() {
     int j, nptrs;
     void *buffer[100];
     char **strings;
     nptrs = backtrace(buffer, 100);
     printf("backtrace() returned %d addresses\n", nptrs);
     
     strings = backtrace_symbols(buffer, nptrs);
     if (strings == NULL) {
     perror("backtrace_symbols");
     }
     
     for (j = 0; j < nptrs; j++)
     printf("%s\n", strings[j]);
     free(strings);
     }*/
    
	template<typename T>
	static void clearList(list<T*>* rlist) {
		if(!rlist->empty()){
			typename list<T*>::iterator itr=rlist->begin();
			while(itr!=rlist->end()){
				delete *itr;
				itr=rlist->erase(itr);
			}
			rlist->clear();
		}
	}
    
	template<typename T>
	static void clearVector(vector<T*>* rvector) {
		if(!rvector->empty()){
			typename vector<T*>::iterator itr=rvector->begin();
			while(itr!=rvector->end()){
				delete *itr;
				itr=rvector->erase(itr);
			}
			rvector->clear();
		}
	}
};
#endif
