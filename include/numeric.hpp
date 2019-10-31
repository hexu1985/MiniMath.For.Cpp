#ifndef MINI_MATH_NUMERIC_INC
#define MINI_MATH_NUMERIC_INC

namespace mini_math {

/**
 * @brief 计算x^y mode N
 *
 * @tparam Integer 整数
 * @param x
 * @param y
 * @param N
 */
template <typename Integer>
Integer modexp(Integer x, Integer y, Integer N)
{
    if (y == 0)
        return 1;
    auto z = modexp(x, y/2, N);
    if (y % 2 == 0)
        return (z*z) % N;
    else
        return (x*z*z) % N;
}

}   // namespace mini_math


#endif
