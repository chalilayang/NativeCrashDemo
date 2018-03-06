//
// Created by 杨勇 on 2018/3/2.
//

#include <jni.h>
#include <signal.h>
#include <unistd.h>
#include <sstream>
#include <string.h>
#include "coffeecatch/coffeecatch.h"
#include "customlog.h"

jint call_dangerous_function(JNIEnv *env, jobject object) {
    // ... do dangerous things!
    int *dd = NULL;
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
    if (coffeecatch_inside()) {
        LOG("coffeecatch_inside");
        call_dangerous_function(env, thiz);
    } else if (coffeecatch_setup() == 0 && sigsetjmp(*coffeecatch_get_ctx(), 1) == 0) {
        LOG("coffeecatch_setup");
        call_dangerous_function(env, thiz);
    }
    return 5;

}

#ifdef __cplusplus
}
#endif