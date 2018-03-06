package chalilayang.com.nativecrashdemo;

import android.util.Log;

/**
 * Created by chalilayang on 2018/3/2.
 */

public class NativeCrashHandler {
    private static final String TAG = NativeCrashHandler.class.getSimpleName();
    static {
        System.loadLibrary("coffeecatch");
        System.loadLibrary("native-crash-handler");
    }

    public void onNativeCrash() {
        Log.i(TAG, "onNativeCrash: ");
    }

    public native boolean createNativeException();

    public native void initNativeHandler(int pid);
}
