#pragma once

#include <ATen/native/special_functions/detail/complex.h>
#include <ATen/native/special_functions/detail/numeric_t.h>
#include <c10/util/complex.h>
#include <c10/util/numbers.h>

namespace at {
namespace native {
namespace special_functions {
namespace detail {
template<typename T1>
T1
cos_pi(T1 z);

template<typename T1>
c10::complex<T1>
cos_pi(c10::complex<T1> z);

template<typename T1>
T1
sin_pi(T1 z) {
  using T2 = numeric_t<T1>;

  if (std::isnan(z)) {
    return std::numeric_limits<T1>::quiet_NaN();
  } else if (z < T1(0)) {
    return -sin_pi(-z);
  } else if (z < T1(0.5L)) {
    return std::sin(z * c10::numbers::pi_v<T2>);
  } else if (z < T1(1)) {
    return std::sin((T1(1) - z) * c10::numbers::pi_v<T2>);
  } else {
    if ((int(std::floor(z)) & 1) == 1) {
      if (z - std::floor(z) < T1(0.5L)) {
        return -1 * sin_pi(z - std::floor(z));
      } else {
        return -1 * sin_pi(T1(1) - (z - std::floor(z)));
      }
    } else {
      if (z - std::floor(z) < T1(0.5L)) {
        return 1 * sin_pi(z - std::floor(z));
      } else {
        return 1 * sin_pi(T1(1) - (z - std::floor(z)));
      }
    }
  }
}

template<typename T1>
c10::complex<T1>
sin_pi(c10::complex<T1> z) {
  using T2 = T1;
  using T3 = numeric_t<T2>;

  return sin_pi(std::real(z)) * std::cosh(c10::numbers::pi_v<T3> * std::imag(z)) + c10::complex<T1>(0, 1) * cos_pi(std::real(z)) * std::sinh(c10::numbers::pi_v<T3> * std::imag(z));
}
}
}
}
}
