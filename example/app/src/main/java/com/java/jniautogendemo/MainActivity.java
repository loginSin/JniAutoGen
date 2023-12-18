package com.java.jniautogendemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.java.jniautogendemo.databinding.ActivityMainBinding;

import java.util.HashMap;
import java.util.List;

public class MainActivity extends AppCompatActivity {


    private ActivityMainBinding binding;
    private NativeClass nativeClass = new NativeClass();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText("Jni Auto Gen Demo");


        // 测试 int 和 int[]
        testInt();

        // 测试 double 和 double[]
        testDouble();

        // 测试 long 和 long[]
        testLong();

        // 测试 boolean 和 boolean[]
        testBoolean();

        // 测试 byte 和 byte[]
        testByte();

        // 测试 String 和 String[]
        testString();

        // 测试 List<Object> 和 HashMap<String,String>
        testCollection();

        // 测试 UserInfo 和 UserInfo[]
        testUserInfo();

        // 测试 Callback
        testCallback();

        // 测试 Listener
        testListener();

    }

    private void testInt() {
        int valueInt = 100;
        int resultInt = nativeClass.nativeGetInt(valueInt);
        Log.e("QXB", "nativeGetInt\t value:" + valueInt + " \tresult:" + resultInt);

        int[] valueIntArr = {1,2,3};
        int[] resultIntArr = nativeClass.nativeGetIntArray(valueIntArr);
        Log.e("QXB", "nativeGetIntArray\t value:" + Utils.intArrayToString(valueIntArr) + " \tresult:" + Utils.intArrayToString(resultIntArr));
    }

    private void testDouble() {
        double valueDouble = 100.0;
        double resultDouble = nativeClass.nativeGetDouble(valueDouble);
        Log.e("QXB", "nativeGetDouble\t value:" + valueDouble + " \tresult:" + resultDouble);

        double[] valueDoubleArr = {1.1,2.2,3.3};
        double[] resultDoubleArr = nativeClass.nativeGetDoubleArray(valueDoubleArr);
        Log.e("QXB", "nativeGetDoubleArray\t value:" + Utils.doubleArrayToString(valueDoubleArr) + " \tresult:" + Utils.doubleArrayToString(resultDoubleArr));
    }

    private void testLong() {
        long valueLong = 2345;
        long resultLong = nativeClass.nativeGetLong(valueLong);
        Log.e("QXB", "nativeGetLong\t value:" + valueLong + " \tresult:" + resultLong);

        long[] valueLongArr = {987,654,321};
        long[] resultLongArr = nativeClass.nativeGetLongArray(valueLongArr);
        Log.e("QXB", "nativeGetLongArray\t value:" + Utils.longArrayToString(valueLongArr) + " \tresult:" + Utils.longArrayToString(resultLongArr));
    }

    private void testBoolean() {
        boolean valueBoolean = true;
        boolean resultBoolean = nativeClass.nativeGetBoolean(valueBoolean);
        Log.e("QXB", "nativeGetBoolean\t value:" + valueBoolean + " \tresult:" + resultBoolean);

        boolean[] valueBooleanArr = {true,false,true};
        boolean[] resultBooleanArr = nativeClass.nativeGetBooleanArray(valueBooleanArr);
        Log.e("QXB", "nativeGetBooleanArray\t value:" + Utils.booleanArrayToString(valueBooleanArr) + " \tresult:" + Utils.booleanArrayToString(resultBooleanArr));

    }

    private void testByte() {
        byte valueByte = 100;
        byte resultByte = nativeClass.nativeGetByte(valueByte);
        Log.e("QXB", "nativeGetByte\t value:" + valueByte + " \tresult:" + resultByte);

        byte[] valueByteArr = {1,2,3};
        byte[] resultByteArr = nativeClass.nativeGetByteArray(valueByteArr);
        Log.e("QXB", "nativeGetByteArray\t value:" + Utils.byteArrayToString(valueByteArr) + " \tresult:" + Utils.byteArrayToString(resultByteArr));
    }

    private void testString() {
        String valueString = "Hello World";
        String resultString = nativeClass.nativeGetString(valueString);
        Log.e("QXB", "nativeGetString\t value:" + valueString + " \tresult:" + resultString);

        String[] valueStringArr = {"Hello","World"};
        String[] resultStringArr = nativeClass.nativeGetStringArray(valueStringArr);
        Log.e("QXB", "nativeGetStringArray\t value:" + Utils.stringArrayToString(valueStringArr) + " \tresult:" + Utils.stringArrayToString(resultStringArr));
    }

    private void testCollection() {
        List<NativeClass.UserInfo> userInfoList = nativeClass.nativeGetUserInfoArrayList();
        Log.e("QXB", "nativeGetUserInfoArrayList\t result:" + Utils.userInfoListToString(userInfoList));

        HashMap<String,String> map = nativeClass.nativeGetHashMap();
        Log.e("QXB", "nativeGetHashMap\t result:" + map);
    }

    private void testUserInfo() {
        String uid = "asdf";
        NativeClass.UserInfo resultUser = nativeClass.nativeGetUserInfo(uid);
        Log.e("QXB", "nativeGetUserInfo\t value:" + uid + " \tresult:" + resultUser);

        NativeClass.UserInfo[] valueUserArr = {resultUser};
        NativeClass.UserInfo[] resultUserArr = nativeClass.nativeGetUserInfoArray(valueUserArr);
        Log.e("QXB", "nativeGetUserInfoArray\t value:" + Utils.userInfoArrayToString(valueUserArr) + " \tresult:" + Utils.userInfoArrayToString(resultUserArr));
    }

    private void testCallback() {
        String value = "userId";
        nativeClass.nativeFetchUserInfo("userId", new NativeClass.JniUserInfoCallback() {
            @Override
            public void onCallback(NativeClass.UserInfo user) {
                Log.e("QXB", "nativeFetchUserInfoCallback\t value:" + value + " \tresult:" + user);
            }
        });
    }

    private void testListener() {
        nativeClass.nativeSetListener(new NativeClass.JniListener() {
            @Override
            public void onListener(int value) {
                Log.e("QXB", "nativeSetListener\t value:" + value);
            }
        });
        nativeClass.nativeCallListener();
    }

}