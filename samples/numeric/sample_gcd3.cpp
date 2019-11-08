/** \example numeric/sample_gcd3.cpp
 * This is an example of how to use the gcd function.
 */
#include "numeric.hpp"
#include <iostream>
#include <string>
#include <stdint.h>

using namespace mini_math;

int main(int argc, char *argv[])
{
    if (argc != 4) {
        std::cout << "usage: " << argv[0] << " a b c\n"
                    << "\tto calculate a*x+b*y=c" << std::endl;
        return -1;
    }

    // 解丢番图方程
    int a = std::stoul(argv[1]);
    int b = std::stoul(argv[2]);
    int c = std::stoul(argv[3]);
    int x, y, d;
    d = gcd(a, b, x, y);

    std::cout << "gcd(" << a << ", " << b << ") = " << d << std::endl;

    if (c % d != 0) {
        std::cout << "no solution set of " << a << "*x+" << b << "*y=" << c << std::endl;
        return 1;
    }

    int x0, y0;
    x0 = x*(c/d);
    y0 = y*(c/d);
    std::cout << a << "*(" << x0 << ")+" << b << "*(" << y0 << ")=" << a*x0+b*y0 << std::endl;

    std::cout << a << "*(" << x0 << "+" << (b/d) << "*k)+" << b << "*(" << y0 << "-" << (a/d) << "*k)=" << c << std::endl;

    return 0;
}
