#!/bin/sh
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
GEN_OUTPUT_DIR='./poker'
COCOS_TOLUA_DIR='../../../frameworks/cocos2d-x-2.2/tools/tolua++'
SLOT_TOLUA_DIR=$COCOS_TOLUA_DIR'/poker'
TARGET_DIR='../../../poker/Classes/lua'
mkdir $GEN_OUTPUT_DIR
mkdir $SLOT_TOLUA_DIR
echo 'clear old pkg and header file'
rm $GEN_OUTPUT_DIR/*.pkg
rm $GEN_OUTPUT_DIR/*.h
rm $GEN_OUTPUT_DIR/*.cpp
rm $SLOT_TOLUA_DIR/*.pkg
rm $SLOT_TOLUA_DIR/*.h
rm $SLOT_TOLUA_DIR/*.cpp

#gen pkgs and header file
echo 'gen pkg files'
python ./gen_pkgs.py 

#gen c++ to lua code
echo 'gen tolua bind code'
cp $GEN_OUTPUT_DIR/*.pkg $SLOT_TOLUA_DIR
cp $GEN_OUTPUT_DIR/*.h $SLOT_TOLUA_DIR
cp $GEN_OUTPUT_DIR/*.cpp $SLOT_TOLUA_DIR

cd $COCOS_TOLUA_DIR
sh build.sh

cd $DIR

#copy header to target path
echo 'copy header file to output'
cp $GEN_OUTPUT_DIR/LuaSlotInclude.h $TARGET_DIR
