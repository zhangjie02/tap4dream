LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dlua_shared

LOCAL_MODULE_FILENAME := libcocos2dlua

LOCAL_CXXFLAGS += -std=gnu++11

#traverse all the directory and subdirectory
define walk
  $(wildcard $(1)) $(foreach e, $(wildcard $(1)/*), $(call walk, $(e)))
endef
 
#traverse Classes Directory
FILE_LIST := 
FILE_LIST += $(filter %.cpp, $(call walk, $(LOCAL_PATH)/../../Classes))
FILE_LIST += $(filter %.cpp, $(call walk, $(LOCAL_PATH)/hellolua))
FILE_LIST += $(filter %.cpp, $(call walk, $(LOCAL_PATH)/../../libs/Preferences/PreferencesJni.cpp))
FILE_LIST += $(filter %.cpp, $(call walk, $(LOCAL_PATH)/../../libs/Preferences/Preferences_android.cpp))
FILE_LIST += $(filter %.cpp, $(call walk, $(LOCAL_PATH)/../../libs/libjson))
FILE_LIST += $(filter %.c, $(call walk, $(LOCAL_PATH)/../../libs/cjson))
FILE_LIST += $(filter %.cpp, $(call walk, $(LOCAL_PATH)/../../libs/md5))
FILE_LIST += $(filter %.cpp, $(call walk, $(LOCAL_PATH)/../../libs/facebook/common))

FILE_INCLUDES :=
FILE_INCLUDES += $(shell find $(LOCAL_PATH)/../../Classes -type d)
FILE_INCLUDES += $(shell find $(LOCAL_PATH)/../../libs/libjson -type d)
FILE_INCLUDES += $(shell find $(LOCAL_PATH)/../../libs/cjson -type d)
FILE_INCLUDES += $(shell find $(LOCAL_PATH)/../../cocos2d-x-2.2/cocos2dx/support/tinyxml2 -type d)
FILE_INCLUDES += $(shell find $(LOCAL_PATH)/../../libs/Preferences -type d)
FILE_INCLUDES += $(shell find $(LOCAL_PATH)/hellolua -type d)
FILE_INCLUDES += $(shell find $(LOCAL_PATH)/../../libs/md5 -type d)
FILE_INCLUDES += $(shell find $(LOCAL_PATH)/../../libs/facebook/common -type d)

#source file will be compiled
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES := $(FILE_INCLUDES) \

LOCAL_STATIC_LIBRARIES := curl_static_prebuilt

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_lua_static
#LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static
LOCAL_WHOLE_STATIC_LIBRARIES += breakpad_client
#ffmpeg
LOCAL_WHOLE_STATIC_LIBRARIES += ffmpeg_avformat_static
LOCAL_WHOLE_STATIC_LIBRARIES += ffmpeg_avcodec_static
LOCAL_WHOLE_STATIC_LIBRARIES += ffmpeg_swscale_static
LOCAL_WHOLE_STATIC_LIBRARIES += ffmpeg_avutil_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx)
$(call import-module,CocosDenshion/android)
$(call import-module,scripting/lua/proj.android)
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,extensions)
#$(call import-module,external/Box2D)
$(call import-module,external/chipmunk)
#ffmpeg
$(call import-module,ffmpeg-2.1.1/android)
$(call import-module,android/google_breakpad)
