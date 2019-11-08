/** \example numeric/sample_modexp1.cpp
 * This is an example of how to use the modexp function.
 */
#include "numeric.hpp"
#include <iostream>
#include <string>
#include <stdint.h>

using namespace mini_math;

int main(int argc, char *argv[])
{
    if (argc != 4) {
        std::cout << "usage: " << argv[0] << " x y N\n"
                    << "\tto calculate x^y mod N" << std::endl;
        return -1;
    }

    uint64_t x = std::stoul(argv[1]);
    uint64_t y = std::stoul(argv[2]);
    uint64_t N = std::stoul(argv[3]);

    std::cout << modexp(x, y, N) << std::endl;

    return 0;
}
