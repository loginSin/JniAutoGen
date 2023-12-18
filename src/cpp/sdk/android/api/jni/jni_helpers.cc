
#include <vector>
#include "java_types.h"
#include "jni_helpers.h"

namespace RongCloud {
namespace jni {

ScopedJavaLocalRef<jobject> NewDirectByteBuffer(JNIEnv* env,
                                                void* address,
                                                jlong capacity) {
  ScopedJavaLocalRef<jobject> buffer(
      env, env->NewDirectByteBuffer(address, capacity));
  // CHECK_EXCEPTION(env) << "error NewDirectByteBuffer";
  return buffer;
}

jobject NewGlobalRef(JNIEnv* jni, jobject o) {
  jobject ret = jni->NewGlobalRef(o);
  // CHECK_EXCEPTION(jni) << "error during NewGlobalRef";
  // RTC_CHECK(ret);
  return ret;
}

void DeleteGlobalRef(JNIEnv* jni, jobject o) {
  jni->DeleteGlobalRef(o);
  // CHECK_EXCEPTION(jni) << "error during DeleteGlobalRef";
}

// Scope Java local references to the lifetime of this object.  Use in all C++
// callbacks (i.e. entry points that don't originate in a Java callstack
// through a "native" method call).
ScopedLocalRefFrame::ScopedLocalRefFrame(JNIEnv* jni) : jni_(jni) {
  // RTC_CHECK(!jni_->PushLocalFrame(0)) << "Failed to PushLocalFrame";
}
ScopedLocalRefFrame::~ScopedLocalRefFrame() {
  jni_->PopLocalFrame(nullptr);
}

}  // namespace jni
}  // namespace RongCloud
