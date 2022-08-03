#pragma once

namespace at {
namespace native {
namespace special_functions {
namespace detail {
template<typename T1>
inline constexpr
promote_t<T1>
sinhc(T1 x) {
  if (std::isnan(x)) {
    return std::numeric_limits<T1>::quiet_NaN();
  } else if (std::abs(x) < T1{4} * std::sqrt(std::numeric_limits<T1>::min())) {
    return T1{1} + x * x / T1{6};
  } else {
    return std::sinh(x) / x;
  }
} // promote_t<T1> sinhc(T1 x)
} // namespace detail
} // namespace special_functions
} // namespace native
} // namespace at
