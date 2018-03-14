package com.chalilayang.nativecrashdemo;

/**
 * Created by chalilayang on 2018/3/2.
 */

public class NativeCrashHandler {
    private static final String TAG = NativeCrashHandler.class.getSimpleName();
    static {
        System.loadLibrary("coffeecatch");
        System.loadLibrary("native-crash-handler");
    }
    public native int createNativeException();
}
