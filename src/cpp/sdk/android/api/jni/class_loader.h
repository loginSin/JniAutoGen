
#pragma once

#include "scoped_java_ref.h"

namespace RongCloud {
namespace jni {

void InitClassLoader(JNIEnv* env);

ScopedJavaLocalRef<jclass> GetClass(JNIEnv* env, const char* name);

}  // namespace jni
}  // namespace RongCloud
