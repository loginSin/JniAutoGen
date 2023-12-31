// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     io/rong/base/internal/RefCounted

#ifndef io_rong_base_internal_RefCounted_JNI
#define io_rong_base_internal_RefCounted_JNI

#include <jni.h>

#include "../../jni/jni_generator_helper.h"


// Step 1: Forward declarations.

JNI_REGISTRATION_EXPORT extern const char kClassPath_io_rong_base_internal_RefCounted[];
const char kClassPath_io_rong_base_internal_RefCounted[] = "io/rong/base/internal/RefCounted";
// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_REGISTRATION_EXPORT std::atomic<jclass> g_io_rong_base_internal_RefCounted_clazz(nullptr);
#ifndef io_rong_base_internal_RefCounted_clazz_defined
#define io_rong_base_internal_RefCounted_clazz_defined
inline jclass io_rong_base_internal_RefCounted_clazz(JNIEnv* env) {
  return base::android::LazyGetClass(env, kClassPath_io_rong_base_internal_RefCounted,
                                     &g_io_rong_base_internal_RefCounted_clazz);
}
#endif


// Step 2: Constants (optional).


// Step 3: Method stubs.
namespace RongCloud {
namespace jni {

    static std::atomic<jmethodID> g_io_rong_base_internal_RefCounted_retain(nullptr);
    static void Java_RefCounted_retain(JNIEnv* env, const base::android::JavaRef<jobject>& obj) {
      jclass clazz = io_rong_base_internal_RefCounted_clazz(env);
      CHECK_CLAZZ(env, obj.obj(),
                  io_rong_base_internal_RefCounted_clazz(env));

      jni_generator::JniJavaCallContextChecked call_context;
      call_context.Init<
              base::android::MethodID::TYPE_INSTANCE>(
              env,
              clazz,
              "retain",
              "()V",
              &g_io_rong_base_internal_RefCounted_retain);

      env->CallVoidMethod(obj.obj(),
                          call_context.base.method_id);
    }

    static std::atomic<jmethodID> g_io_rong_base_internal_RefCounted_release(nullptr);
    static void Java_RefCounted_release(JNIEnv* env, const base::android::JavaRef<jobject>& obj) {
      jclass clazz = io_rong_base_internal_RefCounted_clazz(env);
      CHECK_CLAZZ(env, obj.obj(),
                  io_rong_base_internal_RefCounted_clazz(env));

      jni_generator::JniJavaCallContextChecked call_context;
      call_context.Init<
              base::android::MethodID::TYPE_INSTANCE>(
              env,
              clazz,
              "release",
              "()V",
              &g_io_rong_base_internal_RefCounted_release);

      env->CallVoidMethod(obj.obj(),
                          call_context.base.method_id);
    }
}  // namespace jni
}  // namespace RongCloud

#endif  // io_rong_base_internal_RefCounted_JNI
