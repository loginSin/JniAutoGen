
#pragma once

#include "scoped_java_ref.h"

namespace RongCloud {
namespace jni {

// Holds a reference to a java object implementing the RefCounted interface, and
// calls its release() method from the destructor.
class ScopedJavaRefCounted {
 public:
  // Takes over the caller's reference.
  static ScopedJavaRefCounted Adopt(JNIEnv* env,
                                    const JavaRef<jobject>& j_object) {
    return ScopedJavaRefCounted(env, j_object);
  }
  // Retains the java object for the live time of this object.
  static ScopedJavaRefCounted Retain(JNIEnv* jni,
                                     const JavaRef<jobject>& j_object);

  ScopedJavaRefCounted(ScopedJavaRefCounted&& other) = default;

  ScopedJavaRefCounted(const ScopedJavaRefCounted& other) = delete;
  ScopedJavaRefCounted& operator=(const ScopedJavaRefCounted&) = delete;

  ~ScopedJavaRefCounted();

 private:
  // Adopts reference.
  ScopedJavaRefCounted(JNIEnv* env, const JavaRef<jobject>& j_object)
      : j_object_(env, j_object) {}

  ScopedJavaGlobalRef<jobject> j_object_;
};

}  // namespace jni
}  // namespace RongCloud