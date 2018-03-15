//
// Created by 杨勇 on 2018/3/6.
//

#ifndef NATIVECRASHDEMO_CUSTOMLOG_H
#define NATIVECRASHDEMO_CUSTOMLOG_H

#include <android/log.h>
#define TAG "BreakpadLib"
#define LOGP(str,value) __android_log_print(ANDROID_LOG_DEBUG,TAG,str,value)
#define LOG(str) __android_log_print(ANDROID_LOG_DEBUG,TAG,str)

#endif //NATIVECRASHDEMO_CUSTOMLOG_H
