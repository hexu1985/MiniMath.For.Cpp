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
    EXPECT_EQ(6, gcd(72, 30));
    EXPECT_EQ(18, gcd(252, 198));
    EXPECT_EQ(1, gcd(34, 55));

    int a, b, x, y, d, k;
    a = 252; b = 198;
    d = gcd(a, b, x, y);
    EXPECT_EQ(18, d);
    EXPECT_EQ(d, a*x+b*y);
    for (k = 1; k < 10; k++) {
        EXPECT_EQ(d, a*(x+k*(b/d))+b*(y-k*(a/d)));
    }

    a = 25; b = 11;
    d = gcd(a, b, x, y);
    EXPECT_EQ(1, d);
    EXPECT_EQ(d, a*x+b*y);
    for (k = 1; k < 10; k++) {
        EXPECT_EQ(d, a*(x+k*(b/d))+b*(y-k*(a/d)));
    }
}
