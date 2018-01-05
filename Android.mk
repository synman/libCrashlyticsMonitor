LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := crashlytics_monitor
LOCAL_LDFLAGS := -Wl,--build-id
LOCAL_LDLIBS := \
	-llog \

LOCAL_SRC_FILES := \
	src/main/jni/CrashlyticsMonitor.cpp \

LOCAL_C_INCLUDES += src/main/jni
LOCAL_C_INCLUDES += src/release/jni

include $(BUILD_SHARED_LIBRARY)
