package com.breakpad;

/**
 * Created by chalilayang on 2018/3/13.
 */

public class BreakpadWrapper {
    static {
        System.loadLibrary("breakpad");
    }
    public native void initBreakpad();
}
