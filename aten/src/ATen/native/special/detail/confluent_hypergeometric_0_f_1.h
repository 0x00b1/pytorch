#pragma once

#include <ATen/native/special/detail/is_integer.h>

namespace at {
namespace native {
namespace special {
namespace detail {
template<typename T1>
T1
confluent_hypergeometric_0_f_1(T1 c, T1 x) {
  if (std::isnan(c) || std::isnan(x)) {
    return std::numeric_limits<T1>::quiet_NaN();
  } else if (is_integer(c) && is_integer(c)() <= 0) {
    return std::numeric_limits<T1>::infinity();
  } else {
    auto p = T1(1);
    auto q = T1(1);

    for (unsigned int j = 0; j < 100000; j++) {
      p = p * (x / ((c + T1(j)) * T1(1 + j)));
      q = q + p;

      if (std::abs(p) < std::numeric_limits<T1>::epsilon()) {
        break;
      }
    }

    return q;
  }
}
}
}
}
}
