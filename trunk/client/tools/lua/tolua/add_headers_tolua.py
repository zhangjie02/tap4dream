import os

TOLUA_HEADER = './slot/LuaSlot.h'
TOLUA_CPP = './slot/LuaSlot.cpp'

def writeLinesToFile(lines, f):
    f.seek(0)
    f.truncate()
    for line in lines:
        f.write(line)

toLuaHeaderFile = open(TOLUA_HEADER, 'r+')
headerContent = []
hasAddInclude = False
for line in toLuaHeaderFile.readlines():
    stripLine = line.strip()
    if (stripLine.startswith('TOLUA_API') and not hasAddInclude):
        hasAddInclude = True
        headerContent.append('''
#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif
''')
    headerContent.append(line)

writeLinesToFile(headerContent, toLuaHeaderFile)
toLuaHeaderFile.close()

toLuaCppFile = open(TOLUA_CPP, 'r+')

cppContent = []
hasAddInclude = False
for line in toLuaCppFile.readlines():
    stripLine = line.strip()
    if (stripLine.startswith('#include "cocos2d.h"') and not hasAddInclude):
        hasAddInclude = True
        cppContent.append('''
#include "LuaSlotInclude.h"\n
''')
    cppContent.append(line)
writeLinesToFile(cppContent, toLuaCppFile)
toLuaCppFile.close()
