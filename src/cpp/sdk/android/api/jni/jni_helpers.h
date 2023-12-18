
// This file contain convenience functions and classes for JNI.
// Before using any of the methods, InitGlobalJniVariables must be called.

#pragma once

#include <jni.h>
#include <string>
#include "java_types.h"
#include "jvm.h"
#include "scoped_java_ref.h"

// Convenience macro defining JNI-accessible methods in the org.webrtc package.
// Eliminates unnecessary boilerplate and line-wraps, reducing visual clutter.
#if defined(WEBRTC_ARCH_X86)
// Dalvik JIT generated code doesn't guarantee 16-byte stack alignment on
// x86 - use force_align_arg_pointer to realign the stack at the JNI
// boundary. crbug.com/655248
#define JNI_FUNCTION_DECLARATION(rettype, name, ...)                    \
  __attribute__((force_align_arg_pointer)) extern "C" JNIEXPORT rettype \
      JNICALL Java_net_beem__##name(__VA_ARGS__)
#else
#define JNI_FUNCTION_DECLARATION(rettype, name, ...) \
  extern "C" JNIEXPORT rettype JNICALL Java_net_beem_##name(__VA_ARGS__)
#endif

namespace RongCloud {
namespace jni {

// Deprecated, use NativeToJavaPointer.
inline long jlongFromPointer(void* ptr) {
  return NativeToJavaPointer(ptr);
}

ScopedJavaLocalRef<jobject> NewDirectByteBuffer(JNIEnv* env,
                                                void* address,
                                                jlong capacity);

jobject NewGlobalRef(JNIEnv* jni, jobject o);

void DeleteGlobalRef(JNIEnv* jni, jobject o);

// Scope Java local references to the lifetime of this object.  Use in all C++
// callbacks (i.e. entry points that don't originate in a Java callstack
// through a "native" method call).
class ScopedLocalRefFrame {
 public:
  explicit ScopedLocalRefFrame(JNIEnv* jni);
  ~ScopedLocalRefFrame();

 private:
  JNIEnv* jni_;
};

}  // namespace jni
}  // namespace RongCloud

namespace RongCloud_jni {

using RongCloud::jni::AttachCurrentThreadIfNeeded;
using RongCloud::jni::InitGlobalJniVariables;

}  // namespace RongCloud_jni
