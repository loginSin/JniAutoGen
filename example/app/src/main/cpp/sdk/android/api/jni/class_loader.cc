
#include <algorithm>
#include <string>
#include "class_loader.h"
#include "java_types.h"
#include "scoped_java_ref.h"
#include "../native_api/generated_native_api_jni/RongJniClassLoader_jni.h"

namespace RongCloud {
namespace jni {

namespace {

class ClassLoader {
 public:
  explicit ClassLoader(JNIEnv* env)
      : class_loader_(RongCloud::jni::Java_RongJniClassLoader_getClassLoader(env)) {
    class_loader_class_ = reinterpret_cast<jclass>(
        env->NewGlobalRef(env->FindClass("java/lang/ClassLoader")));
    load_class_method_ =
        env->GetMethodID(class_loader_class_, "loadClass",
                         "(Ljava/lang/String;)Ljava/lang/Class;");
  }

  ScopedJavaLocalRef<jclass> FindClass(JNIEnv* env, const char* c_name) {
    // ClassLoader.loadClass expects a classname with components separated by
    // dots instead of the slashes that JNIEnv::FindClass expects.
    std::string name(c_name);
    std::replace(name.begin(), name.end(), '/', '.');
    ScopedJavaLocalRef<jstring> j_name = NativeToJavaString(env, name);
    const jclass clazz = static_cast<jclass>(env->CallObjectMethod(
        class_loader_.obj(), load_class_method_, j_name.obj()));
    return ScopedJavaLocalRef<jclass>(env, clazz);
  }

 private:
  ScopedJavaGlobalRef<jobject> class_loader_;
  jclass class_loader_class_;
  jmethodID load_class_method_;
};

static ClassLoader* g_class_loader = nullptr;

}  // namespace

void InitClassLoader(JNIEnv* env) {
  g_class_loader = new ClassLoader(env);
}

ScopedJavaLocalRef<jclass> GetClass(JNIEnv* env, const char* name) {
  // The class loader will be null in the JNI code called from the ClassLoader
  // ctor when we are bootstrapping ourself.
  return (g_class_loader == nullptr)
             ? ScopedJavaLocalRef<jclass>(env, env->FindClass(name))
             : g_class_loader->FindClass(env, name);
}
}  // namespace jni
}  // namespace RongCloud
