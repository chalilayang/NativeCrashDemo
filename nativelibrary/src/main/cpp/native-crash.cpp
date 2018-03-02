#include <jni.h>
#include <string>
#include <android/log.h>
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, "keymatch", __VA_ARGS__)
extern "C"
JNIEXPORT jstring

JNICALL
Java_chalilayang_com_nativelibrary_NativeCrashTest_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++ native";
    LOGD("NativeCrashTest_stringFromJNI");
    return env->NewStringUTF(hello.c_str());
}
