#include "CrashlyticsMonitor.h"

#include <jni.h>
#include <android/log.h>
//#include <string.h>

extern "C" {
    const char *CLASS_NAME = "CrashlyticsMonitor";

    crashlytics_context_t *context;
    bool debug = false;

    jint JNI_OnLoad(JavaVM *vm, void *reserved) {
        return JNI_VERSION_1_6;
    }

    void initialize(const char *guid) {
        context = crashlytics_init();
        context->set_user_identifier(context, guid);

        if (debug) __android_log_print(ANDROID_LOG_INFO, CLASS_NAME, "CrashlyticsNdk has been initialized for [%s]", guid);
    }

    void dispose() {
        crashlytics_free(&context);
        if (debug) __android_log_print(ANDROID_LOG_INFO, CLASS_NAME, "CrashlyticsNdk has been disposed");
    }

    JNIEXPORT void JNICALL
    Java_com_shellware_crashlyticsmonitor_CrashlyticsMonitor_nInitialize(JNIEnv *env, jobject,
                                                                         jstring jguid, jboolean jdebug) {
        const char *guid = env->GetStringUTFChars(jguid, NULL);
        debug = (bool) jdebug;

        initialize(guid);
    }

    JNIEXPORT void JNICALL
    Java_com_shellware_crashlyticsmonitor_CrashlyticsMonitor_nSetEmailNameAndPicture(JNIEnv *env, jobject,
                                                                         jstring jemail, jstring jname, jstring jpicture) {
        const char *email = env->GetStringUTFChars(jemail, NULL);
        const char *name = env->GetStringUTFChars(jname, NULL);
        const char *picture = env->GetStringUTFChars(jpicture, NULL);

        context->set_user_email(context, email);
        context->set_user_name(context, name);
        context->set(context, "auth_picture_url", picture);

        if (debug) __android_log_print(ANDROID_LOG_INFO, CLASS_NAME, "CrashlyticsNdk name=[%s] email=[%s] picture=[%s]", name, email, picture);
    }

JNIEXPORT void JNICALL
    Java_com_shellware_crashlyticsmonitor_CrashlyticsMonitor_nDispose(JNIEnv *env, jobject) {
        dispose();
    }
}
