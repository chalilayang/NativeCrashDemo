#include <jni.h>
#include "client/linux/handler/minidump_descriptor.h"
#include "client/linux/handler/exception_handler.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint
JNICALL
Java_com_chalilayang_breakpad_BreakpadWrapper_initBreakpad(JNIEnv *env, jobject thiz) {
    google_breakpad::MinidumpDescriptor rr;
}

#ifdef __cplusplus
}
#endif
