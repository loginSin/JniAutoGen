
#include "jni_helpers.h"
#include "ref_count.h"
#include "../native_api/generated_native_api_jni/JniCommon_jni.h"

namespace RongCloud {
namespace jni {

static void JNI_JniCommon_AddRef(JNIEnv* jni,
                                 jlong j_native_ref_counted_pointer) {
  reinterpret_cast<RefCountInterface*>(j_native_ref_counted_pointer)->AddRef();
}

static void JNI_JniCommon_ReleaseRef(JNIEnv* jni,
                                     jlong j_native_ref_counted_pointer) {
  reinterpret_cast<RefCountInterface*>(j_native_ref_counted_pointer)->Release();
}

static ScopedJavaLocalRef<jobject> JNI_JniCommon_AllocateByteBuffer(JNIEnv* jni,
                                                                    jint size) {
  void* new_data = ::operator new(size);
  return NewDirectByteBuffer(jni, new_data, size);
}

static void JNI_JniCommon_FreeByteBuffer(
    JNIEnv* jni,
    const JavaParamRef<jobject>& byte_buffer) {
  void* data = jni->GetDirectBufferAddress(byte_buffer.obj());
  ::operator delete(data);
}

}  // namespace jni
}  // namespace RongCloud