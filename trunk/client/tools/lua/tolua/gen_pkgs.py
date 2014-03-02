import os
import re

BASE_DIR = '../../../poker/Classes'
RELATIVE_DIRS = 'model/EventDef.h,model/StageModel.h,view/resource,view/layout,utils,view/ui/common,view/ui/base,view/ui/touch,view/SlotResourceManager.h,model/service/MachineService.h,model/UserModel.h,model/FreeSpinRecord.h,utils/FormatUtil.h,localization'
EXCEPT_FILES = 'JSONUtil.h,StringConverter.h,ResourceConfigCache.h,UITouchEventDispatcher.h'
OUTPUT_DIR = './poker'

SCAN_PATH_LIST = []
EXCEPT_FILE_LIST = []
PROJ_PKG_FILE = 'poker.pkg'
PROJ_TOLUA_INCLUDE_FILE = 'LuaSlotInclude.h'
PROJ_PKG_LINES = []
PROJ_TOLUA_INCLUDE_LINES = []
CLASS_PKG_INFO_DICT = {}
PKG_CLASSES_INFO_DICT = {}

def genScanPathList():
    subdirNames = RELATIVE_DIRS.split(',')
    print 'gen scan path...'
    for subdirName in subdirNames:
        path = os.path.join(BASE_DIR, subdirName)
        if os.path.exists(path):
            print path
            SCAN_PATH_LIST.append(path)

def genExceptFileNameList():
    files = []
    names = EXCEPT_FILES.split(',')
    print 'gen except file...'
    for name in names:
        name = name.strip()
        print name
        EXCEPT_FILE_LIST.append(name)

def isHiddenDeclare(line):
    return line.startswith('private:') or line.startswith('protected:')

def isPublicDeclare(line):
    return line.startswith('public:')

def isClassDeclareStart(line):
    m = re.search('class \w+.*{', line)
    return m != None

def isNamespaceDeclareStart(line):
    m = re.search('namespace \w+.*{', line)
    return m != None

def isIncludeDeclare(line):
    return line.startswith('#include')

def isForwardDeclare(line):
    m = re.search('(class|struct)[ ]+\w+;', line)
    return m != None

def getClassInfo(line):

    stripLine = line.strip()
    m = re.search('(class|module)[ ]+(\w+)[ ]*(:.*)?{', stripLine)
    className = m.group(2)
    baseStr = m.group(3)
    classInfo = {}
    classInfo['class'] = className
    classInfo['bases'] = []
    if (baseStr != None):
        baseStr = baseStr.replace(':', '')
        baseStr = baseStr.replace('public', '')
        baseStr = baseStr.replace('private', '')
        baseStr = baseStr.replace('protected', '')
        bases = baseStr.split(',')
        for base in bases:
            base = base.strip()
            classInfo['bases'].append(base)

    return classInfo

def getFormattedAppendLine(line):
    line = line.replace('cocos2d::extension::', '')
    line = line.replace('cocos2d::', '')
    line = line.replace('std::', '')

    stripLine = line.strip()
    if (stripLine.startswith('#ifndef')):
        return ''

    if (stripLine.startswith('#define')):
        return ''

    if (stripLine.startswith('#endif')):
        return ''

    if (stripLine.startswith('using namespace')):
        return ''

    if (stripLine.startswith('USING_NS_CC')):
        return ''

    if (stripLine.startswith('USING_NS_CC_EXT')):
        return ''
   
    line = line.replace('&', '')
    line = line.replace('int luaHandler', 'LUA_FUNCTION')
    m = re.search('namespace (\w+).*{', line)
    if m != None:
        namespaceName = m.group(1).strip()
        line = '$using namespace {0};\n'.format(namespaceName)
        line = line + 'module ' + namespaceName + ' {\n'
        return line

    m = re.search('^CREATE_FUNC\((.*)\)(;)?$', stripLine)
    if m != None:
        className = m.group(1).strip()
        line = '\tstatic ' + className + '* create();\n'
        return line

    m = re.search('^CC_SYNTHESIZE_READONLY\((.*),.*,(.*)\)(;)?', stripLine)
    if m != None:
        typeName = m.group(1).strip()
        getterName = m.group(2).strip()
        line = '{0} get{1}();\n'.format(typeName, getterName)
        return line

    m = re.search('^CC_PROPERTY\((.*),.*,(.*)\)(;)?', stripLine)
    if m != None:
        typeName = m.group(1).strip()
        postfix = m.group(2).strip()
        line = '{0} get{1}();\n'.format(typeName, postfix)
        line = line + 'void set{0}({1} var);\n'.format(postfix, typeName)
        return line

    m = re.search('^CC_SYNTHESIZE\((.*),.*,(.*)\)(;)?', stripLine)
    if m != None:
        typeName = m.group(1).strip()
        postfix = m.group(2).strip()
        line = '{0} get{1}();\n'.format(typeName, postfix)
        line = line + 'void set{0}({1} var);\n'.format(postfix, typeName)
        return line
    
    m = re.search('^CC_PROPERTY_PASS_BY_REF\((.*),.*,(.*)\)(;)?', stripLine)
    if m != None:
        typeName = m.group(1).strip()
        postfix = m.group(2).strip()
        line = '{0} get{1}();\n'.format(typeName, postfix)
        line = line + 'void set{0}({1} var);\n'.format(postfix, typeName)
        return line

    return line

def genPkgFile(hFilePath):
    hFileName = os.path.basename(hFilePath)
    pkgFileName = hFileName.replace('.h', '.pkg')
    pkgFilePath = os.path.join(OUTPUT_DIR, pkgFileName)
    
    PROJ_TOLUA_INCLUDE_LINES.append('#include "{0}"\n'.format(hFileName))

    headerFile = open(hFilePath, 'r')
    pkgFile = open(pkgFilePath, 'w')
    
    pkgLines = []
    classStarted = False
    hiddenBlockStart = False
    for line in headerFile.readlines():
        stripLine = line.strip()

        if isIncludeDeclare(stripLine):
            continue
        
        if isForwardDeclare(stripLine):
            continue

        isClassLine = isClassDeclareStart(stripLine) or isNamespaceDeclareStart(stripLine)
        if isClassLine:
            if classStarted and hiddenBlockStart:
                hiddenBlockStart = False
                pkgLines.append('};\n')
            classStarted = True

        if isHiddenDeclare(stripLine):
            hiddenBlockStart = True

        if hiddenBlockStart and isPublicDeclare(stripLine):
            hiddenBlockStart = False
        
        if not hiddenBlockStart:
            formattedLine = getFormattedAppendLine(line)
            if isClassLine:
                classInfo = getClassInfo(formattedLine)
                pkgInfo = {}
                pkgInfo['pkg'] = pkgFileName
                pkgInfo['class'] = classInfo
                className = classInfo['class']
                CLASS_PKG_INFO_DICT[className] = pkgInfo  
                
                pkgClassInfo = PKG_CLASSES_INFO_DICT.get(pkgFileName, None)
                if pkgClassInfo == None:
                    pkgClassInfo = []
                    PKG_CLASSES_INFO_DICT[pkgFileName] = pkgClassInfo
                pkgClassInfo.append(pkgInfo)

            pkgLines.append(formattedLine)
        
    if classStarted and hiddenBlockStart:
        pkgLines.append('};\n')
    
    for line in pkgLines:
        pkgFile.write(line)

    pkgFile.close()
    headerFile.close()
    print 'gen pkg ' + pkgFilePath + ' finished'
def isExceptFile(filename):
    for exceptFile in EXCEPT_FILE_LIST:
        if (filename == exceptFile):
            return True

    return False

def isHeaderFile(filename):
    return filename.endswith('.h')

def scanPath(path):
    if (not os.path.isdir(path)) and isHeaderFile(path):
        genPkgFile(path)

    for root, subdirs, files in os.walk(path):
        for filename in files:
            if isExceptFile(filename):
                continue
            if isHeaderFile(filename):
                genPkgFile(os.path.join(root, filename))

def hasPkgAdded(pkgName):
    for pkg in PROJ_PKG_LINES:
        if (pkg == pkgName):
            return True
    return False

def addPkgLine(pkgName):
    line = '$pfile "./slot/{0}"\n'.format(pkgName)
    if hasPkgAdded(line):
        return

    PROJ_PKG_LINES.append(line)

HANDLING_PKGS = {}
def addClassPkgLine(pkgInfo):
    pkgName = pkgInfo['pkg']

    classesInPkg = PKG_CLASSES_INFO_DICT.get(pkgName, [])
    HANDLING_PKGS[pkgName] = True

    for classInfo in classesInPkg:
        bases = classInfo['class']['bases']
        for base in bases:
            basePkgInfo = CLASS_PKG_INFO_DICT.get(base)
            if basePkgInfo != None and not HANDLING_PKGS.get(basePkgInfo['pkg'], False):
                addClassPkgLine(basePkgInfo)
    
    addPkgLine(pkgName)


def genProjPkgLines():
    for className, pkgInfo in CLASS_PKG_INFO_DICT.items():
        addClassPkgLine(pkgInfo)

def genProjPkgFile():
    genProjPkgLines()

    path = os.path.join(OUTPUT_DIR, PROJ_PKG_FILE)
    print 'gen proj pkg file ' + path
    f = open(path, 'w')
    for line in PROJ_PKG_LINES:
        f.write(line)
    f.close()

def genProjToLuaIncludeFile():
    path = os.path.join(OUTPUT_DIR, PROJ_TOLUA_INCLUDE_FILE)
    print 'gen proj to lua include file ' + path
    f = open(path, 'w')
    f.write('#ifndef __slot__LuaSlot_h__\n')
    f.write('#define __slot_LuaSlot_h__\n')
    for line in PROJ_TOLUA_INCLUDE_LINES:
        f.write(line)
    f.write('#endif\n')
    f.close

def scanDirs():
    genScanPathList()
    genExceptFileNameList()
    for path in SCAN_PATH_LIST:
        scanPath(path)
    genProjPkgFile()
    genProjToLuaIncludeFile()

scanDirs()
