package io.rong.base.internal;

import java.nio.ByteBuffer;

public class JniCommon {
  public static native void nativeAddRef(long refCountedPointer);
  public static native void nativeReleaseRef(long refCountedPointer);

  public static native ByteBuffer nativeAllocateByteBuffer(int size);
  public static native void nativeFreeByteBuffer(ByteBuffer buffer);
}
