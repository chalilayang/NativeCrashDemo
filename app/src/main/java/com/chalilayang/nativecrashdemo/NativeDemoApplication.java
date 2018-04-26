package com.chalilayang.nativecrashdemo;

import android.app.ActivityManager;
import android.app.Application;
import android.content.Context;
import android.util.Log;

import com.breakpad.BreakpadWrapper;

/**
 * Created by chalilayang on 2018/3/2.
 */

public class NativeDemoApplication extends Application {
    private static final String TAG = NativeDemoApplication.class.getSimpleName();

    private NativeCrashHandler crashHandler;

    /**
     * Called when the application is starting, before any activity, service,
     * or receiver objects (excluding content providers) have been created.
     * Implementations should be as quick as possible (for example using
     * lazy initialization of state) since the time spent in this function
     * directly impacts the performance of starting the first activity,
     * service, or receiver in a process.
     * If you override this method, be sure to call super.onCreate().
     */
    @Override
    public void onCreate() {
        super.onCreate();
        String processName = getCurrentProcessName();
//        crashHandler = new NativeCrashHandler();
//        crashHandler.initNativeHandler(android.os.Process.myPid());
        BreakpadWrapper.getInstance().initBreakpad();
        Log.i(TAG, "onCreate: " + processName);
    }

    /**
     * 当前进程名
     *
     * @return
     */
    private String getCurrentProcessName() {
        try {
            int pid = android.os.Process.myPid();
            String processName = "";
            ActivityManager manager = (ActivityManager) getSystemService(Context.ACTIVITY_SERVICE);
            for (ActivityManager.RunningAppProcessInfo processInfo
                    : manager.getRunningAppProcesses()) {
                if (processInfo.pid == pid) {
                    processName = processInfo.processName;
                }
            }
            return processName;
        } catch (Throwable t) {
            return "";
        }
    }
}
