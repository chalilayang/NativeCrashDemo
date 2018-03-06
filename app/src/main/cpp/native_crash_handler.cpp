//
// Created by 杨勇 on 2018/3/2.
//

#include <jni.h>
#include <android/log.h>
#include <signal.h>
#include <unistd.h>
#include <sstream>
#include <string.h>
#include "coffeecatch/coffeejni.h"
#include "coffeecatch/coffeecatch.h"

#define TAG "native-crash-activity.cpp"
#define LOG(str) __android_log_print(ANDROID_LOG_DEBUG,TAG,str)

jint call_dangerous_function(JNIEnv* env, jobject object) {
    // ... do dangerous things!
    int * dd = NULL;
    *dd = 0;
    return 42;
}


#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint
JNICALL
Java_chalilayang_com_nativecrashdemo_NativeCrashHandler_createNativeException(JNIEnv *env,
                                                                              jobject thiz) {
    COFFEE_TRY() {
        LOG("COFFEE");
        int e = 8;
        int r = 0;
        e / r;
        LOG("COFFEE end");
    } COFFEE_CATCH() {
        coffeecatch_throw_exception(env);
//        coffeecatch_cancel_pending_alarm();
    } COFFEE_END();
//    coffeecatch_throw_exception(env);
    return 5;

}

#ifdef __cplusplus
}
#endif