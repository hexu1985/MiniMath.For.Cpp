#include <gtest/gtest.h>
#include <cstdint>
#include "numeric.hpp"

using namespace mini_math;

TEST(Numeric, modexp)
{
    EXPECT_EQ(36, modexp(3, 644, 645));
    EXPECT_EQ(2199, modexp<uint64_t>(1907, 29, 2633));
    EXPECT_EQ(1907, modexp<uint64_t>(2199, 2269, 2633));
}

TEST(Numeric, gcd)
{
    EXPECT_EQ(18, gcd(252, 198));
}
