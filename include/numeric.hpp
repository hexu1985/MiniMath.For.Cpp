#ifndef MINI_MATH_NUMERIC_INC
#define MINI_MATH_NUMERIC_INC

namespace mini_math {

/**
 * @brief 模的指数运算: 计算x^y mode N
 *
 * @tparam Integer 整数类型
 * @param x 底数
 * @param y 指数
 * @param N 模数
 *
 * @warning: x, y, N必须是正整数
 *
 * @see 算法概论中文版: 章节1.2.2
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

/**
 * @brief 欧几里得的最大公因数算法
 *
 * @tparam Integer 整数类型
 * @param a 整数a
 * @param b 整数b
 *
 * @return (a, b): a和b的最大公因数
 *
 * @warning: a, b必须是正整数, 且a>b
 *
 * @see 算法概论中文版: 章节1.2.3
 */
template <typename Integer>
Integer gcd_euclid(Integer a, Integer b)
{
    if (b == 0) return a;
    return gcd_euclid(b, a%b);
}

/**
 * @brief 计算最大公因数
 *
 * @tparam Integer 整数类型
 * @param a 整数a
 * @param b 整数b
 *
 * @return (a, b): a和b的最大公因数
 *
 * @warning: a, b必须是正整数
 */
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
