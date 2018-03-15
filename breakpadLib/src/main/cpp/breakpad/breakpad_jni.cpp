#include <jni.h>
#include "client/linux/handler/exception_handler.h"
#include "client/linux/handler/minidump_descriptor.h"

#ifdef __cplusplus
extern "C" {
#endif

bool DumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
                  void* context,
                  bool succeeded) {
    printf("Dump path: %s\n", descriptor.path());
    return succeeded;
}

JNIEXPORT jint
JNICALL
Java_com_breakpad_BreakpadWrapper_initBreakpad(JNIEnv *env, jobject thiz) {
    google_breakpad::MinidumpDescriptor descriptor(".");
    google_breakpad::ExceptionHandler eh(descriptor, NULL, DumpCallback,
                                         NULL, true, -1);
    return 0;
}

#ifdef __cplusplus
}
#endif
