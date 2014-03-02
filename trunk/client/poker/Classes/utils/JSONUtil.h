#ifndef JSONUTIL_H_
#define JSONUTIL_H_

#include <string>
#include "libjson.h"

using namespace std;

class JSONUtil {
public :
    static bool hasKey(const JSONNode& node, const char* name);
	static JSONNode getNode(const JSONNode& node, const char* name);
	static JSONNode getNode(const JSONNode& node, string name);
	static int getInt(const JSONNode& node, const char* name);
    static float getFloat(const JSONNode& node, const char* name) ;
	static string getString(const JSONNode& node, const char* name);
};

#endif /* JSONUTIL_H_ */
