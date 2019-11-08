/** \example numeric/sample_gcd2.cpp
 * This is an example of how to use the gcd function.
 */
#include "numeric.hpp"
#include <iostream>
#include <string>
#include <stdint.h>

using namespace mini_math;

int main(int argc, char *argv[])
{
    if (argc != 3) {
        std::cout << "usage: " << argv[0] << " a b\n"
                    << "\tto calculate gcd(a, b)" << std::endl;
        return -1;
    }

    int a = std::stoul(argv[1]);
    int b = std::stoul(argv[2]);
    int x, y, d;
    d = gcd(a, b, x, y);

    std::cout << "gcd(" << a << ", " << b << ") = " << d << std::endl;
    std::cout << a << "*(" << x << ") + " << b << "*(" << y << ") = " << d << std::endl;

    std::cout << a << "*(" << x << "+" << (b/d) << "*k)+" << b << "*(" << y << "-" << (a/d) << "*k)=" << d << std::endl;

    return 0;
}
