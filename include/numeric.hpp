/**
 * @file numeric.hpp
 * @brief 数论相关函数
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2019-11-04
 */
#ifndef MINI_MATH_NUMERIC_INC
#define MINI_MATH_NUMERIC_INC

#include <tuple>

namespace mini_math {

/**
 * @brief 模的指数运算: 计算\f$x^y mod N\f$
 *
 * @tparam Integer 整数类型
 * @param x 底数
 * @param y 指数
 * @param N 模数
 *
 * @warning x, y, N必须是正整数
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
 * @warning a, b必须是正整数, 且a>b
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
 * @warning a, b必须是正整数
 */
template <typename Integer>
Integer gcd(Integer a, Integer b)
{
    if (a < b)
        return gcd_euclid(b, a);
    else
        return gcd_euclid(a, b);
}

/**
 * @brief Euclid算法的一种扩展: 用线性组合的方式来表示最大公因子: \n
 *          即如果x, y, d = gcd_euclid_ext(a, b), 那么d = (a, b), \n
 *          并且\f$d = a \times x+b \times y\f$
 *
 * @tparam Integer 整数类型
 * @param a 整数a
 * @param b 整数b
 *
 * @return x, y, d, 其中d=(a, b), 并且\f$d = a \times x+b \times y\f$
 *
 * @warning a, b必须是正整数, 且a>b
 *
 * @see 算法概论中文版: 章节1.2.4
 */
template <typename Integer>
std::tuple<Integer, Integer, Integer> gcd_euclid_ext(Integer a, Integer b)
{
    if (b == 0) return std::make_tuple(Integer(1), Integer(0), a);
    Integer x, y, d;
    std::tie(x, y, d) = gcd_euclid_ext(b, a%b);
    return std::make_tuple(y, x - (a/b)*y, d);
}

/**
 * @brief Euclid算法的一种扩展: 用线性组合的方式来表示最大公因子: \n
 *          即如果d = gcd(a, b, x, y), 那么d = (a, b), \n
 *          并且\f$d = a \times x+b \times y\f$
 *
 * @tparam Integer 整数类型
 * @param a 整数a
 * @param b 整数b
 * @param [out] x 整数x
 * @param [out] y 整数y
 *
 * @return (a, b): a和b的最大公因数, 并且\f$d = a \times x+b \times y\f$
 *
 * @warning a, b必须是正整数
 */
template <typename Integer>
Integer gcd(Integer a, Integer b, Integer &x, Integer &y)
{
    Integer d;
    if (a < b)
        std::tie(x, y, d) = gcd_euclid_ext(b, a);
    else
        std::tie(x, y, d) = gcd_euclid_ext(a, b);
    return d;
}

}   // namespace mini_math


#endif
