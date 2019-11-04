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

    std::cout << d << " = gcd(" << a << ", " << b << ")" << ", " << d << " = (" << a << ")*(" << x << ") + (" << b << ")*(" << y << ")" << std::endl;

    return 0;
}
