APP_STL := gnustl_static

APP_PLATFORM := android-8

APP_CPPFLAGS := -frtti # -DCC_ENABLE_CHIPMUNK_INTEGRATION=1
APP_CPPFLAGS += -fexceptions
APP_CPPFLAGS += -DCOCOS2D_DEBUG=1
APP_CPPFLAGS += -Wno-error=format-security
APP_CPPFLAGS += -Wno-literal-suffix
APP_CPPFLAGS += -std=gnu++11
APP_CFLAGS += -DNDEBUG

#NDK_TOOLCHAIN_VERSION=4.8

#for ndk-gdb debug
# The ARMv7 is significanly faster due to the use of the hardware FPU
#APP_CPPFLAGS += -g # enable debugging
#APP_ABI := armeabi armeabi-v7a
#command for ndk-gdb
#NDK_MODULE_PATH=../cocos2d-x-2.1.5/:../cocos2d-x-2.1.5/cocos2dx/platform/third_party/android/prebuilt/:../libs/:../../../../../public/Cocos2dDemo/breakpad/  ndk-gdb --verbose --force --launch=com.game.slot.slot --nowait --delay=0
