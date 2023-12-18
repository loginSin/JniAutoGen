# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

project("jniautogendemo")
set(CMAKE_CXX_STANDARD 17)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        jniautogendemo

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        NativeClass_jni.h
        NativeClass_jni.cpp

        # jni 自动生成核心代码 开始
        sdk/android/api/jni/class_loader.cc
        sdk/android/api/jni/java_types.cc
        sdk/android/api/jni/jni_common.cc
        sdk/android/api/jni/jni_generator_helper.cc
        sdk/android/api/jni/jni_helpers.cc
        sdk/android/api/jni/jni_onload.cc
        sdk/android/api/jni/jvm.cc
        sdk/android/api/jni/scoped_java_ref_counted.cc
        sdk/android/api/jni/scoped_java_ref.h
        # jni 自动生成核心代码 结束

        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)


# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        jniautogendemo

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})