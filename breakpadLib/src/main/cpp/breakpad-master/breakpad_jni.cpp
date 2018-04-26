#include <jni.h>
#include "client/linux/handler/exception_handler.h"
#include "client/linux/handler/minidump_descriptor.h"
#include "../customlog.h"

#ifdef __cplusplus
extern "C" {
#endif

void Crash() {
    volatile int* a = reinterpret_cast<volatile int*>(NULL);
    *a = 1;
}

bool DumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
                  void* context,
                  bool succeeded) {
    LOGP("Dump path: %s\n", descriptor.path());
    if (succeeded) {
        LOG("Dump path: success\n");
    } else {
        LOG("Dump path: failed\n");
    }
    return succeeded;
}

bool FilterCallback(void *context) {
    LOG("FilterCallback");
    return true;
}

JNIEXPORT jint
JNICALL
Java_com_breakpad_BreakpadWrapper_createCrash(JNIEnv *env, jobject thiz) {
    LOG("createCrash");
    Crash();
    return 0;
}

google_breakpad::MinidumpDescriptor * descriptor;
google_breakpad::ExceptionHandler * eh;

JNIEXPORT jint
JNICALL
Java_com_breakpad_BreakpadWrapper_initBreakpad(JNIEnv *env, jobject thiz) {
    LOG("initBreakpad");
    if (descriptor == nullptr) {
        descriptor = new google_breakpad::MinidumpDescriptor("./breakpad");
    }
    if (eh == nullptr) {
        eh = new google_breakpad::ExceptionHandler(*descriptor, FilterCallback, DumpCallback, NULL, true, 1);
    }
    return 0;
}

#ifdef __cplusplus
}
#endif
