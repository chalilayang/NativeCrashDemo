#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring JNICALL Java_chalilayang_com_nativecrashdemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {

    std::string hello = "modified Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
