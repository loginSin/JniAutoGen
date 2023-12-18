package com.java.jniautogendemo;

import androidx.annotation.NonNull;

import java.util.HashMap;
import java.util.List;

import io.rong.base.internal.CalledByNative;

/**
 * @author rongcloud
 * @date 2023/12/13
 */
public class NativeClass {

    // Used to load the 'jniautogendemo' library on application startup.
    static {
        System.loadLibrary("jniautogendemo");
    }

    public native int nativeGetInt(int value);
    public native int[] nativeGetIntArray(int[] value);

    public native double nativeGetDouble(double value);
    public native double[] nativeGetDoubleArray(double[] value);

    public native long nativeGetLong(long value);
    public native long[] nativeGetLongArray(long[] value);

    public native boolean nativeGetBoolean(boolean value);
    public native boolean[] nativeGetBooleanArray(boolean[] value);


    public native byte nativeGetByte(byte value);
    public native byte[] nativeGetByteArray(byte[] value);


    public native String nativeGetString(String value);
    public native String[] nativeGetStringArray(String[] value);


    public native List<UserInfo> nativeGetUserInfoArrayList();
    public native HashMap<String,String> nativeGetHashMap();


    public native UserInfo nativeGetUserInfo(String uid);
    public native UserInfo[] nativeGetUserInfoArray(UserInfo[] value);

    public interface JniUserInfoCallback {
        @CalledByNative("JniUserInfoCallback")
        void onCallback(UserInfo user);
    }
    public native void nativeFetchUserInfo(String uid, JniUserInfoCallback callback);

    public interface JniListener {
        @CalledByNative("JniListener")
        void onListener(int value);
    }

    public native void nativeSetListener(JniListener listener);

    public native void nativeCallListener();


    public static class UserInfo {
        private String uid;
        private String name;
        private int age;

        public UserInfo(String uid, String name, int age) {
            this.uid = uid;
            this.name = name;
            this.age = age;
        }

        @CalledByNative("UserInfo")
        public UserInfo() {
        }

        public String getUid() {
            return uid;
        }

        @CalledByNative("UserInfo")
        public void setUid(String uid) {
            this.uid = uid;
        }

        public String getName() {
            return name;
        }

        @CalledByNative("UserInfo")
        public void setName(String name) {
            this.name = name;
        }

        public int getAge() {
            return age;
        }

        @CalledByNative("UserInfo")
        public void setAge(int age) {
            this.age = age;
        }

        @NonNull
        @Override
        public String toString() {
            return "UserInfo[uid:" + getUid() + ",name:" + getName() + ",age:" + getAge() + "]";
        }
    }
}
