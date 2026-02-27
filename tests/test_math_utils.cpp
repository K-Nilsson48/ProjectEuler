#include <gtest/gtest.h>
#include "eulerlib/math_utils.hpp"
#include <vector>

TEST(SumMultTests, BasicCases) {
    EXPECT_EQ(eulerlib::sum_of_multiples(5,15), 30LL);
}

TEST(DivisorsTests, BasicCases) {
    EXPECT_EQ(eulerlib::divisors(20), std::vector<long long>({1LL, 2LL, 4LL, 5LL, 10LL, 20LL}));
    EXPECT_EQ(eulerlib::divisors(19), std::vector<long long>({1LL, 19LL}));
    EXPECT_EQ(eulerlib::divisors(8), std::vector<long long>({1LL, 2LL, 4LL, 8LL}));
    EXPECT_EQ(eulerlib::divisors(9), std::vector<long long>({1LL, 3LL, 9LL}));
}