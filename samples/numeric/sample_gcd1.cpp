/** \example numeric/sample_gcd1.cpp
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

    auto a = std::stoul(argv[1]);
    auto b = std::stoul(argv[2]);

    std::cout << gcd(a, b) << std::endl;

    return 0;
}
