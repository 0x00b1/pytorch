#pragma once

#include <complex>

#include <ATen/native/special/detail/spherical_legendre_y.h>

namespace at {
namespace native {
namespace special {
namespace detail {
template<typename T1>
c10::complex<T1>
spherical_harmonic_y(unsigned int l, int m, T1 theta, T1 phi) {
  if (std::isnan(theta) || std::isnan(phi)) {
    return {std::numeric_limits<T1>::quiet_NaN(), std::numeric_limits<T1>::quiet_NaN()};
  } else if (std::abs(m) > l) {
    return {0, 0};
  } else {
    return spherical_legendre_y(l, std::abs(m), theta) * std::polar(T1(1), T1(m) * phi);
  }
}
}
}
}
}
