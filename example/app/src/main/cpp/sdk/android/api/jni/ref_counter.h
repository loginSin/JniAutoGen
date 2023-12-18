
#pragma once

#include <atomic>
#include "ref_count.h"

namespace RongCloud {
namespace jni {

class RefCounter {
 public:
  explicit RefCounter(int ref_count) : ref_count_(ref_count) {}
  RefCounter() = delete;

  void IncRef() { ref_count_.fetch_add(1, std::memory_order_relaxed); }

  RefCountReleaseStatus DecRef() {
    int ref_count_after_subtract =
        ref_count_.fetch_sub(1, std::memory_order_acq_rel) - 1;
    return ref_count_after_subtract == 0
               ? RefCountReleaseStatus::kDroppedLastRef
               : RefCountReleaseStatus::kOtherRefsRemained;
  }

  bool HasOneRef() const {
    return ref_count_.load(std::memory_order_acquire) == 1;
  }

 private:
  std::atomic<int> ref_count_;
};

}  // namespace jni
}  // namespace RongCloud