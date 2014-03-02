//
//  LuaManager.h
//  poker
//
//  Created by xiaoxiangzi on 13-12-26.
//
//

#ifndef __poker__LuaManager__
#define __poker__LuaManager__

#include <vector>
#include <string>
using namespace std;

class LuaManager {
    
public:
    static LuaManager* getInstance();
    void init();
    void runLua(const string& path);
    void addCommonLuaSearchPath();
private:
    LuaManager();
    LuaManager(const LuaManager&);
    LuaManager& operator=(const LuaManager&);
    
    void addSearchPath(const string& path);
    string getDirPath(const string& fileFullpath) const;
    
    vector<string> _searchPath;
};

#endif /* defined(__poker__LuaManager__) */
