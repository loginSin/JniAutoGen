
#include "scoped_java_ref_counted.h"
#include "../native_api/generated_native_api_jni/RefCounted_jni.h"

namespace RongCloud {
namespace jni {

ScopedJavaRefCounted ScopedJavaRefCounted::Retain(
    JNIEnv* jni,
    const JavaRef<jobject>& j_object) {
  Java_RefCounted_retain(jni, j_object);
  return Adopt(jni, j_object);
}

ScopedJavaRefCounted::~ScopedJavaRefCounted() {
  if (!j_object_.is_null()) {
    JNIEnv* jni = AttachCurrentThreadIfNeeded();
    Java_RefCounted_release(jni, j_object_);
  }
}

}  // namespace jni
}  // namespace RongCloud
