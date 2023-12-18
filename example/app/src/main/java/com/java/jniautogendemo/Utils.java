package com.java.jniautogendemo;

import java.util.List;

/**
 * @author rongcloud
 * @date 2023/12/12
 */
public class Utils {
    public static String stringArrayToString(String[] arr) {
        int length = arr.length;
        String retStr = "{";
        for (int i=0;i<length;i++) {
            retStr += arr[i] + ",";
        }
        retStr += "}";
        return retStr;
    }

    public static String booleanArrayToString(boolean[] arr) {
        int length = arr.length;
        String retStr = "{";
        for (int i=0;i<length;i++) {
            retStr += arr[i] + ",";
        }
        retStr += "}";
        return retStr;
    }

    public static String longArrayToString(long[] arr) {
        int length = arr.length;
        String retStr = "{";
        for (int i=0;i<length;i++) {
            retStr += arr[i] + ",";
        }
        retStr += "}";
        return retStr;
    }

    public static String doubleArrayToString(double[] arr) {
        int length = arr.length;
        String retStr = "{";
        for (int i=0;i<length;i++) {
            retStr += arr[i] + ",";
        }
        retStr += "}";
        return retStr;
    }

    public static String intArrayToString(int[] arr) {
        int length = arr.length;
        String retStr = "{";
        for (int i=0;i<length;i++) {
            retStr += arr[i] + ",";
        }
        retStr += "}";
        return retStr;
    }

    public static String byteArrayToString(byte[] arr) {
        int length = arr.length;
        String retStr = "{";
        for (int i=0;i<length;i++) {
            retStr += arr[i] + ",";
        }
        retStr += "}";
        return retStr;
    }

    public static String userInfoArrayToString(NativeClass.UserInfo[] arr) {
        int length = arr.length;
        String retStr = "{";
        for (int i=0;i<length;i++) {
            retStr += arr[i] + ",";
        }
        retStr += "}";
        return retStr;
    }

    public static String userInfoListToString(List<NativeClass.UserInfo> userInfoList) {
        int length = userInfoList.size();
        String retStr = "{";
        for (int i=0;i<length;i++) {
            retStr += userInfoList.get(i) + ",";
        }
        retStr += "}";
        return retStr;
    }
}
