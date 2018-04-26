package com.breakpad;

/**
 * Created by chalilayang on 2018/3/13.
 */

public class BreakpadWrapper {
    private BreakpadWrapper() {
    }
    private static class Holder {
        static {
            System.loadLibrary("breakpad");
        }
        private static final BreakpadWrapper instance = new BreakpadWrapper();
    }
    public static BreakpadWrapper getInstance() {
        return Holder.instance;
    }
    public native int initBreakpad();
    public native int createCrash();
}
