package io.rong.base.internal;

import androidx.annotation.Nullable;

class RongJniClassLoader {
    RongJniClassLoader() {}

    @Nullable
    @CalledByNative
    static Object getClassLoader() {
        return RongJniClassLoader.class.getClassLoader();
    }
}
