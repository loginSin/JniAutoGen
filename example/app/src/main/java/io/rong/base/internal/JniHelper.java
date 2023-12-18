package io.rong.base.internal;

import java.io.UnsupportedEncodingException;
import java.util.Map;

class JniHelper {
  JniHelper() {}

  @CalledByNative
  static byte[] getStringBytes(String s) {
    try {
      return s.getBytes("UTF-8");
    } catch (UnsupportedEncodingException e) {
      throw new RuntimeException("UTF-8 is unsupported");
    }
  }

  @CalledByNative
  static Object getStringClass() {
    return String.class;
  }

  @CalledByNative
  static Object getKey(Map.Entry entry) {
    return entry.getKey();
  }

  @CalledByNative
  static Object getValue(Map.Entry entry) {
    return entry.getValue();
  }
}
