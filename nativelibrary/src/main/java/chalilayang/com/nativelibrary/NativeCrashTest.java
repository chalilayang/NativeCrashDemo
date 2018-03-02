package chalilayang.com.nativelibrary;

/**
 * Created by chalilayang on 2018/3/2.
 */

public class NativeCrashTest {
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-crash");
    }
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
