//
// Created by Qi on 2023/12/13.
//
#include <string>
#include "NativeClass_jni.h"
#include "sdk/android/api/jni/jni_int_wrapper.h"
#include "sdk/android/api/jni/jvm.h"
#include "sdk/android/api/jni/java_types.h"
namespace RongCloud {

    static jint JNI_NativeClass_GetInt(JNIEnv* env,
           const base::android::JavaParamRef<jobject>& jcaller,jint value) {
        return value + 123;
    }

    static base::android::ScopedJavaLocalRef<jintArray> JNI_NativeClass_GetIntArray(JNIEnv* env,
           const base::android::JavaParamRef<jobject>& jcaller,const base::android::JavaParamRef<jintArray>& value) {
        const jsize length = env->GetArrayLength(value.obj());
        jintArray newArray = env->NewIntArray(length+1);

        jint *oldArr = env->GetIntArrayElements(value.obj(), nullptr);
        jint *newArr = env->GetIntArrayElements(newArray, nullptr);

        for (int i=0;i<length;i++){
            newArr[i] = oldArr[i];
        }
        newArr[length] = 123;

        env->ReleaseIntArrayElements(value.obj(), oldArr, 0);
        env->ReleaseIntArrayElements(newArray, newArr, 0);
        return base::android::ScopedJavaLocalRef<jintArray>(env, newArray);
    }

    static jdouble JNI_NativeClass_GetDouble(JNIEnv* env,
           const base::android::JavaParamRef<jobject>& jcaller,jdouble value) {
        return value + 1000.0;
    }

    static base::android::ScopedJavaLocalRef<jdoubleArray> JNI_NativeClass_GetDoubleArray(JNIEnv* env,
           const base::android::JavaParamRef<jobject>& jcaller,const base::android::JavaParamRef<jdoubleArray>& value) {

        const jsize length = env->GetArrayLength(value.obj());
        jdoubleArray newArray = env->NewDoubleArray(length+1);

        jdouble *oldArr = env->GetDoubleArrayElements(value.obj(), nullptr);
        jdouble *newArr = env->GetDoubleArrayElements(newArray, nullptr);

        for (int i=0;i<length;i++){
            newArr[i] = oldArr[i];
        }
        newArr[length] = 987.789;

        env->ReleaseDoubleArrayElements(value.obj(), oldArr, 0);
        env->ReleaseDoubleArrayElements(newArray, newArr, 0);

        return base::android::ScopedJavaLocalRef<jdoubleArray>(env, newArray);
    }

    static jlong JNI_NativeClass_GetLong(JNIEnv* env,
           const base::android::JavaParamRef<jobject>& jcaller,jlong value) {
        return value + 100000;
    }

    static base::android::ScopedJavaLocalRef<jlongArray> JNI_NativeClass_GetLongArray(JNIEnv* env,
           const base::android::JavaParamRef<jobject>& jcaller,const base::android::JavaParamRef<jlongArray>& value) {
        const jsize length = env->GetArrayLength(value.obj());
        jlongArray newArray = env->NewLongArray(length+1);

        jlong *oldArr = env->GetLongArrayElements(value.obj(), nullptr);
        jlong *newArr = env->GetLongArrayElements(newArray, nullptr);

        for (int i=0;i<length;i++){
            newArr[i] = oldArr[i];
        }
        newArr[length] = 100000000;

        env->ReleaseLongArrayElements(value.obj(), oldArr, 0);
        env->ReleaseLongArrayElements(newArray, newArr, 0);

        return base::android::ScopedJavaLocalRef<jlongArray>(env, newArray);
    }

    static jboolean JNI_NativeClass_GetBoolean(JNIEnv* env,
           const base::android::JavaParamRef<jobject>& jcaller, jboolean value) {
        return !value;
    }

    static base::android::ScopedJavaLocalRef<jbooleanArray> JNI_NativeClass_GetBooleanArray(JNIEnv* env,
           const base::android::JavaParamRef<jobject>& jcaller,const base::android::JavaParamRef<jbooleanArray>& value) {

        const jsize length = env->GetArrayLength(value.obj());
        jbooleanArray newArray = env->NewBooleanArray(length+1);

        jboolean *oldArr = env->GetBooleanArrayElements(value.obj(), nullptr);
        jboolean *newArr = env->GetBooleanArrayElements(newArray, nullptr);

        for (int i=0;i<length;i++){
            newArr[i] = oldArr[i];
        }
        newArr[length] = true;

        env->ReleaseBooleanArrayElements(value.obj(), oldArr, 0);
        env->ReleaseBooleanArrayElements(newArray, newArr, 0);

        return base::android::ScopedJavaLocalRef<jbooleanArray>(env, newArray);
    }

    static jbyte JNI_NativeClass_GetByte(JNIEnv* env,
           const base::android::JavaParamRef<jobject>& jcaller,jbyte value) {
        return value + 1;
    }

    static base::android::ScopedJavaLocalRef<jbyteArray> JNI_NativeClass_GetByteArray(JNIEnv* env,
           const base::android::JavaParamRef<jobject>& jcaller,const base::android::JavaParamRef<jbyteArray>& value) {
        const jsize length = env->GetArrayLength(value.obj());
        jbyteArray newArray = env->NewByteArray(length+1);

        jbyte *oldArr = env->GetByteArrayElements(value.obj(), nullptr);
        jbyte *newArr = env->GetByteArrayElements(newArray, nullptr);

        for (int i=0;i<length;i++){
            newArr[i] = oldArr[i];
        }
        newArr[length] = 12;

        env->ReleaseByteArrayElements(value.obj(), oldArr, 0);
        env->ReleaseByteArrayElements(newArray, newArr, 0);

        return base::android::ScopedJavaLocalRef<jbyteArray>(env, newArray);
    }

    static base::android::ScopedJavaLocalRef<jstring> JNI_NativeClass_GetString(JNIEnv* env,
           const base::android::JavaParamRef<jobject>& jcaller,const base::android::JavaParamRef<jstring>& value) {
        std::string valueStr = env->GetStringUTFChars(value.obj(), nullptr);
        std::string result = "JNI_NativeClass_GetString_" + valueStr;
        return base::android::ScopedJavaLocalRef<jstring>(env, env->NewStringUTF(result.c_str()));
    }

    static base::android::ScopedJavaLocalRef<jobjectArray> JNI_NativeClass_GetStringArray(JNIEnv* env,
           const base::android::JavaParamRef<jobject>& jcaller,const base::android::JavaParamRef<jobjectArray>& value) {
        const jsize length = env->GetArrayLength(value.obj());
        jobjectArray newArray = env->NewObjectArray(length+1, env->FindClass("java/lang/String"), nullptr);

        for (int i=0;i<length;i++){
            jstring str = (jstring)env->GetObjectArrayElement(value.obj(), i);
            env->SetObjectArrayElement(newArray, i, str);
        }

        jstring str = env->NewStringUTF("JNI_NativeClass_GetStringArray");
        env->SetObjectArrayElement(newArray, length, str);
        return base::android::ScopedJavaLocalRef<jobjectArray>(env, newArray);
    }

    static base::android::ScopedJavaLocalRef<jobject> JNI_NativeClass_GetUserInfoArrayList(JNIEnv* env,
           const base::android::JavaParamRef<jobject>& jcaller) {
        base::android::ScopedJavaLocalRef<jobject> user = Java_UserInfo_Constructor(env);

        std::string uidString = "uidStr";
        jstring jUidString = env->NewStringUTF(uidString.c_str());
        base::android::JavaParamRef<jstring> uidStrRef(jUidString);

        std::string nameString = "C++nameawefafds";
        jstring jNameString = env->NewStringUTF(nameString.c_str());
        base::android::JavaParamRef<jstring> nameStrRef(jNameString);

        Java_UserInfo_setUid(env, user, uidStrRef);
        Java_UserInfo_setName(env, user, nameStrRef);
        Java_UserInfo_setAge(env, user, 55);

        // 此处重要
        RongCloud::jni::JavaListBuilder builder = RongCloud::jni::JavaListBuilder(env);
        builder.add(user);

        return builder.java_list();
    }

    static base::android::ScopedJavaLocalRef<jobject> JNI_NativeClass_GetHashMap(JNIEnv* env,
           const base::android::JavaParamRef<jobject>& jcaller) {
        RongCloud::jni::JavaMapBuilder builder = RongCloud::jni::JavaMapBuilder(env);

        std::string keyString = "keyStr";
        jstring jKeyString = env->NewStringUTF(keyString.c_str());
        base::android::JavaParamRef<jstring> keyStrRef(jKeyString);

        std::string valueString = "valueStr";
        jstring jValueString = env->NewStringUTF(valueString.c_str());
        base::android::JavaParamRef<jstring> valueStrRef(jValueString);

        builder.put(keyStrRef,valueStrRef);

        return builder.GetJavaMap();
    }

    static base::android::ScopedJavaLocalRef<jobject> JNI_NativeClass_GetUserInfo(JNIEnv* env,
           const base::android::JavaParamRef<jobject>& jcaller,const base::android::JavaParamRef<jstring>& uid) {
        std::string str = "C++name";
        jstring jStr = env->NewStringUTF(str.c_str());
        base::android::JavaParamRef<jstring> nameStr(jStr);
        base::android::ScopedJavaLocalRef<jobject> user = Java_UserInfo_Constructor(env);
        Java_UserInfo_setUid(env, user, uid);
        Java_UserInfo_setName(env, user, nameStr);
        Java_UserInfo_setAge(env, user, 18);
        return user;
    }

    static base::android::ScopedJavaLocalRef<jobjectArray> JNI_NativeClass_GetUserInfoArray(JNIEnv* env,
           const base::android::JavaParamRef<jobject>& jcaller,const base::android::JavaParamRef<jobjectArray>& value) {
        const jsize length = env->GetArrayLength(value.obj());
        jobjectArray newArray = env->NewObjectArray(length+1, env->FindClass("com/java/jniautogendemo/NativeClass$UserInfo"), nullptr);

        for (int i=0;i<length;i++){
            jobject obj = (jobject)env->GetObjectArrayElement(value.obj(), i);
            env->SetObjectArrayElement(newArray, i, obj);
        }

        std::string uidString = "uidString";
        jstring jUidString = env->NewStringUTF(uidString.c_str());
        base::android::JavaParamRef<jstring> uidStrRef(jUidString);

        std::string nameString = "C++name2143";
        jstring jNameString = env->NewStringUTF(nameString.c_str());
        base::android::JavaParamRef<jstring> nameStrRef(jNameString);

        base::android::ScopedJavaLocalRef<jobject> user = Java_UserInfo_Constructor(env);
        Java_UserInfo_setUid(env, user, uidStrRef);
        Java_UserInfo_setName(env, user, nameStrRef);
        Java_UserInfo_setAge(env, user, 29);

        env->SetObjectArrayElement(newArray, length, user.obj());

        return base::android::ScopedJavaLocalRef<jobjectArray>(env, newArray);
    }

    static void JNI_NativeClass_FetchUserInfo(JNIEnv* env,
           const base::android::JavaParamRef<jobject>& jcaller,
           const base::android::JavaParamRef<jstring>& uid,
           const base::android::JavaParamRef<jobject>& callback) {
        if (callback.is_null()) {
            return;
        }
        base::android::ScopedJavaLocalRef<jobject> user = Java_UserInfo_Constructor(env);
        Java_UserInfo_setUid(env, user, uid);
        std::string str = "C++nameFetchUserInfo";
        jstring jStr = env->NewStringUTF(str.c_str());
        base::android::JavaParamRef<jstring> nameStr(jStr);
        Java_UserInfo_setName(env, user, nameStr);
        Java_UserInfo_setAge(env, user, 47);
        Java_JniUserInfoCallback_onCallback(env,callback, user);
    }

    static jobject g_Listener = nullptr;
    static void JNI_NativeClass_SetListener(JNIEnv* env,
           const base::android::JavaParamRef<jobject>& jcaller,
           const base::android::JavaParamRef<jobject>& listener) {
        if (listener.is_null()) {
            return;
        }
        g_Listener = env->NewGlobalRef(listener.obj());
    }

    static void JNI_NativeClass_CallListener(JNIEnv* env,
           const base::android::JavaParamRef<jobject>& jcaller) {
        const base::android::JavaParamRef<jobject> listener = base::android::JavaParamRef<jobject>(env, g_Listener);
        Java_JniListener_onListener(env, listener,456);
    }
} // namespace RongCloud