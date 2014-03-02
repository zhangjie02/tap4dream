//
//  LuaCocoStudio.h
//  slot
//
//  Created by xiaoxiangzi on 14-2-13.
//
//

#ifndef slot_LuaCocoStudio_h
#define slot_LuaCocoStudio_h

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

TOLUA_API int tolua_CocoStudio_open(lua_State* tolua_S);

#endif
