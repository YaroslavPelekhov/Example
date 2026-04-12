



#include <array>
#include <cmath>
#include <utility>
#include <complex>
#include <vector>
#include <limits>

namespace Equations {

constexpr int COUNT = 3;

template <typename T>
std::pair<bool, std::vector<std::complex<T>>> quadratic(
    const std::array<std::complex<T>, COUNT>& input_arr)
{
    constexpr T EPS_VAL = T(32) * std::numeric_limits<T>::epsilon();
    constexpr T T_SECOND = T(2);
    constexpr T T_FOURTH = T(4);

    std::complex<T> arg_a = input_arr[0];
    std::complex<T> arg_b = input_arr[1];
    std::complex<T> arg_c = input_arr[2];

    if (std::norm(arg_a) < EPS_VAL) {
        if (std::norm(arg_b) < EPS_VAL) {
            return {false, {}};
        }
        std::complex<T> root_val = -arg_c / arg_b;
        return {true, {root_val}};
    }

    std::complex<T> disc_val = arg_b * arg_b - T_FOURTH * arg_a * arg_c;
    std::complex<T> sqrt_val = std::sqrt(disc_val);

    std::complex<T> root_first = (-arg_b + sqrt_val) / (T_SECOND * arg_a);
    std::complex<T> root_second = (-arg_b - sqrt_val) / (T_SECOND * arg_a);

    if (std::norm(root_first - root_second) < EPS_VAL)
        return {true, {root_first}};

    return {true, {root_first, root_second}};
}

} // namespace Equations
