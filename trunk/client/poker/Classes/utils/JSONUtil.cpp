#include "JSONUtil.h"

bool JSONUtil::hasKey(const JSONNode& node, const char* name){
    JSONNode::const_iterator iter = node.find(name);
    return (iter != node.end());
}


JSONNode JSONUtil::getNode(const JSONNode& node, const char* name) {
    JSONNode::const_iterator iter = node.find(name);
    if (iter == node.end()) {
        return JSONNode(JSON_NULL);
    }
    if(iter->type() == JSON_NODE) {
    	return iter->as_node();
    }
    else if(iter->type() == JSON_ARRAY) {
    	return iter->as_array();
    }
    return JSONNode(JSON_NULL);
}

JSONNode JSONUtil::getNode(const JSONNode& node, string name) {
	return getNode(node, name.c_str());
}

int JSONUtil::getInt(const JSONNode& node, const char* name) {
    JSONNode::const_iterator iter = node.find(name);
    if (iter == node.end()) {
        return 0;
    }
    return iter->as_int();
}


float JSONUtil::getFloat(const JSONNode& node, const char* name) {
    JSONNode::const_iterator iter = node.find(name);
    if (iter == node.end()) {
        return 0;
    }
    return iter->as_float();
}


string JSONUtil::getString(const JSONNode& node, const char* name) {
    JSONNode::const_iterator iter = node.find(name);
    if (iter == node.end()) {
        return "";
    }
    return iter->as_string();
}
