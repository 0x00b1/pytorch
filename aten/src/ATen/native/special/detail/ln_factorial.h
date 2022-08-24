#pragma once

#include <c10/util/numbers.h>
#include <ATen/native/special/detail/ln_gamma.h>

namespace at {
namespace native {
namespace special {
namespace detail {
template<typename T1>
constexpr T1
ln_factorial(unsigned int n) {
  if (n < c10::numbers::factorials_size<T1>()) {
    return c10::numbers::log_factorials_v[n];
  } else if (n < c10::numbers::double_factorials_size<T1>()) {
    return c10::numbers::log_double_factorials_v[n] + c10::numbers::log_double_factorials_v[n - 1];
  } else {
    return ln_gamma(T1(n + 1));
  }
}
}
}
}
}
