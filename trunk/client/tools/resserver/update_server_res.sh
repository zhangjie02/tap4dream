#!/bin/sh

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
TOOL_RES_PATH="$DIR/../resources"

if [ -z "$1" ]; then
	echo "input stage id ..."
	exit 0
fi
STAGE_ID="$1"
echo "svn up $TOOL_RES_PATH/.."
svn up "$TOOL_RES_PATH/.."

RES_SERVER_DIR="$DIR/../../slot/ResourcesServer"
echo "gen resource $TOOL_RES_PATH"
cd $TOOL_RES_PATH
python gen_res_info.py -resPath="$RES_SERVER_DIR/icons" -md5
python gen_res_info.py -resPath="$RES_SERVER_DIR/stages/$STAGE_ID" -md5
python gen_res_info.py -resPath="$RES_SERVER_DIR/stages/$STAGE_ID/bonus"
python gen_res_info.py -resPath="$RES_SERVER_DIR/stages/$STAGE_ID/base"

STAGES_DIR="$DIR/../../slot/ResourcesServer/stages"
RES_SERVER_PATH="$STAGES_DIR/$STAGE_ID"
TARGET_PATH="$STAGES_DIR/$STAGE_ID.zip"
echo "zip : $TARGET_PATH $RES_SERVER_PATH"
cd "$RES_SERVER_PATH"
zip -r "$TARGET_PATH" * -x "*.svn*"

echo "check in server res ..."
cd $RES_SERVER_DIR
svn add --force .
svn ci . -m "update server res ..."

#第一关特殊处理
if [ "$1" = 1 ]; then
	echo "deal with machine 1 .."
	cp -r $TARGET_PATH "$DIR/../../slot/Resources/zip/"
	cd "$DIR/../../slot/Resources/zip"
	svn add --force .
	svn ci . -m "update 1st stage zip"
fi
