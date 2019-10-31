#ifndef MINI_MATH_NUMERIC_INC
#define MINI_MATH_NUMERIC_INC

namespace mini_math {

/**
 * @brief 计算x^y mode N
 *
 * @tparam Integer 整数
 * @param x 底数
 * @param y 指数
 * @param N 模数
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

template <typename Integer>
Integer gcd_euclid(Integer a, Integer b)
{
    if (b == 0) return a;
    return gcd_euclid(b, a%b);
}

template <typename Integer>
Integer gcd(Integer a, Integer b)
{
    if (a < b)
        return gcd_euclid(b, a);
    else
        return gcd_euclid(a, b);
}

}   // namespace mini_math


#endif
