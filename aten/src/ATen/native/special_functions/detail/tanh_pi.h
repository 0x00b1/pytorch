#pragma once

#include <ATen/native/special_functions/detail/numeric_t.h>
#include <ATen/native/special_functions/detail/tan_pi.h>
#include <c10/util/numbers.h>

namespace at {
namespace native {
namespace special_functions {
namespace detail {
template<typename T1>
T1
tanh_pi(T1 z) {
  using T2 = T1;
  using T3 = numeric_t<T2>;

  return std::tanh(c10::numbers::pi_v<T3> * z);
}

template<typename T1>
c10::complex<T1>
tanh_pi(c10::complex<T1> z) {
  using T2 = T1;
  using T3 = numeric_t<T2>;

  return (std::tanh(c10::numbers::pi_v<T3> * std::real(z)) + c10::complex<T1>(0, 1) * tan_pi(std::imag(z))) / (T2(1) + c10::complex<T1>(0, 1) * std::tanh(c10::numbers::pi_v<T3> * std::real(z)) * tan_pi(std::imag(z)));
}
}
}
}
}
