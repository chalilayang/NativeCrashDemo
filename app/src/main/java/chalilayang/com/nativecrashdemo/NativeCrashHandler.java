package chalilayang.com.nativecrashdemo;

/**
 * Created by chalilayang on 2018/3/2.
 */

public class NativeCrashHandler {
    public native boolean createNativeException();

    public native void initNativeHandler(int pid);
}
