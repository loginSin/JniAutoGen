
#pragma once
namespace RongCloud {
namespace jni {

enum class RefCountReleaseStatus { kDroppedLastRef, kOtherRefsRemained };
class RefCountInterface {
 public:
  virtual void AddRef() const = 0;
  virtual RefCountReleaseStatus Release() = 0;

  // Non-public destructor, because Release() has exclusive responsibility for
  // destroying the object.
 protected:
  virtual ~RefCountInterface() {}
};

}  // namespace jni
}  // namespace RongCloud