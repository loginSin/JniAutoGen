// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     io/rong/base/internal/JniCommon

#ifndef io_rong_base_internal_JniCommon_JNI
#define io_rong_base_internal_JniCommon_JNI

#include <jni.h>

#include "../../jni/jni_generator_helper.h"


// Step 1: Forward declarations.

JNI_REGISTRATION_EXPORT extern const char kClassPath_io_rong_base_internal_JniCommon[];
const char kClassPath_io_rong_base_internal_JniCommon[] = "io/rong/base/internal/JniCommon";
// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_REGISTRATION_EXPORT std::atomic<jclass> g_io_rong_base_internal_JniCommon_clazz(nullptr);
#ifndef io_rong_base_internal_JniCommon_clazz_defined
#define io_rong_base_internal_JniCommon_clazz_defined
inline jclass io_rong_base_internal_JniCommon_clazz(JNIEnv* env) {
  return base::android::LazyGetClass(env, kClassPath_io_rong_base_internal_JniCommon,
                                     &g_io_rong_base_internal_JniCommon_clazz);
}
#endif


// Step 2: Constants (optional).


// Step 3: Method stubs.
namespace RongCloud {
namespace jni {
    static void JNI_JniCommon_AddRef(JNIEnv *env, jlong refCountedPointer);

    JNI_GENERATOR_EXPORT

    void Java_io_rong_base_internal_JniCommon_nativeAddRef(
            JNIEnv *env,
            jclass jcaller,
            jlong refCountedPointer) {
        return JNI_JniCommon_AddRef(env, refCountedPointer);
    }

    static void JNI_JniCommon_ReleaseRef(JNIEnv *env, jlong refCountedPointer);

    JNI_GENERATOR_EXPORT

    void Java_io_rong_base_internal_JniCommon_nativeReleaseRef(
            JNIEnv *env,
            jclass jcaller,
            jlong refCountedPointer) {
        return JNI_JniCommon_ReleaseRef(env, refCountedPointer);
    }

    static base::android::ScopedJavaLocalRef<jobject>
    JNI_JniCommon_AllocateByteBuffer(JNIEnv *env, jint
    size);

    JNI_GENERATOR_EXPORT

    jobject Java_io_rong_base_internal_JniCommon_nativeAllocateByteBuffer(
            JNIEnv *env,
            jclass jcaller,
            jint size) {
        return JNI_JniCommon_AllocateByteBuffer(env, size).Release();
    }

    static void
    JNI_JniCommon_FreeByteBuffer(JNIEnv *env, const base::android::JavaParamRef<jobject> &
    buffer);

    JNI_GENERATOR_EXPORT

    void Java_io_rong_base_internal_JniCommon_nativeFreeByteBuffer(
            JNIEnv *env,
            jclass jcaller,
            jobject buffer) {
        return JNI_JniCommon_FreeByteBuffer(env, base::android::JavaParamRef<jobject>(env, buffer));
    }

}  // namespace jni

}  // namespace RongCloud

#endif  // io_rong_base_internal_JniCommon_JNI