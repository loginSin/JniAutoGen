
#include <jni.h>
#include "class_loader.h"
#include "jni_helpers.h"

#undef JNIEXPORT
#define JNIEXPORT __attribute__((visibility("default")))


namespace RongCloud {
namespace jni {

extern "C" jint JNIEXPORT JNICALL JNI_OnLoad(JavaVM* jvm, void* reserved) {
  jint ret = InitGlobalJniVariables(jvm);
  if (ret < 0)
    return -1;
  InitClassLoader(GetEnv());
  return ret;
}

extern "C" void JNIEXPORT JNICALL JNI_OnUnLoad(JavaVM* jvm, void* reserved) {}

}  // namespace jni
}  // namespace RongCloud
