package com.szmedchat.myjni;

import java.util.HashMap;

/**
 * Created by xubh on 2017/2/7.
 */

public class JNIUtil {
    static
    {
        System.loadLibrary("JNISample");
    }
    public native String test ();

    public native HashMap createHashMap (String key1, String value1, String key2, String value2);
}
