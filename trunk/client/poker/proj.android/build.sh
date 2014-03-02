#!/bin/sh
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
# ... use paths relative to current directory
CLIENT_PATH="$DIR/../"
BUILD_NATIVE_PATH="$DIR/build_native.sh"
SO_NAME="libcocos2dlua.so"
SO_PATH="$DIR/libs/armeabi/$SO_NAME"
PACKAGE_NAME="com.game.slot"
UPDATE_PATH="$DIR/../breakpad/update"

echo "steps:"
echo "1. svn up"
echo "2. replace class info"
echo "3. build so"
echo "4. copy assets"
echo "5. package apk"

echo "params:"
echo "[param 1] 1: upload crash so"
echo "------------------ start build ---------------------"

echo "svn up client..."
cd $CLIENT_PATH
svn up
echo "building so ..."
cd $DIR

sh $BUILD_NATIVE_PATH

echo "check so ..."
if [ ! -e $SO_PATH ]; then
	echo "so build failed !"
	exit 0		
fi

echo "copy lib so"
revisionInfo=`svn info ${CLIENT_PATH} | grep Revision`
revision=${revisionInfo#* }
sofilename="$SO_NAME.r.$revision"
libsopath=$DIR/obj/local/armeabi/$SO_NAME
if [ -e $libsopath ]; then
	cp $libsopath $DIR/output/$sofilename
	echo "copy file:"$DIR/output/$sofilename
	if [ "$1" ]; then
		echo "upload breakpad so..."
		bpso=$CLIENT_PATH/breakpad/$sofilename
		echo "cp file to $bpso"
		cp $libsopath $bpso
		svn add $bpso
		svn ci $bpso -m "breakpad so"
		updateinfo="$revision,$PACKAGE_NAME,$SO_NAME,$sofilename,"
		echo "update bp info: $updateinfo"
		echo $updateinfo >> $UPDATE_PATH
		svn ci $UPDATE_PATH -m "breakpad update file"
	fi
else
	echo "*error*: lib so not exist !"
	exit 0
fi

echo "change apk version"
festFile=$DIR/AndroidManifest.xml
if [ -e $festFile ]; then
	sed -i "" "s/versionCode=\".*/versionCode=\"$revision\"/g" $festFile
	echo "change version code to "$revision
fi

echo "build apk ..."
cd $DIR
ant clean
ant debug

echo "copy apk to output"
cp $DIR/bin/slot-debug.apk $DIR/output/Slot_r$revision.apk

#echo "please enter 1: install 2: exit"
#read key
#if [ $key = "1" ]; then
#echo "install apk ..."
#ant debug install
#fi

echo "bye ..."

