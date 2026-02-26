#include <gtest/gtest.h>
#include "eulerlib/primes.hpp"
#include <vector>

// Test suite name: PrimeTests, Test name: EdgeCases
TEST(PrimeTests, EdgeCases) {
    // EXPECT_FALSE means the test passes if the function returns false
    EXPECT_FALSE(eulerlib::isprime(-5));
    EXPECT_FALSE(eulerlib::isprime(0));
    EXPECT_FALSE(eulerlib::isprime(1));
}

TEST(PrimeTests, SmallPrimes) {
    // EXPECT_TRUE means the test passes if the function returns true
    EXPECT_TRUE(eulerlib::isprime(2));
    EXPECT_TRUE(eulerlib::isprime(3));
    EXPECT_TRUE(eulerlib::isprime(17));
    EXPECT_TRUE(eulerlib::isprime(97));
}

TEST(PrimeTests, SmallComposites) {
    EXPECT_FALSE(eulerlib::isprime(4));
    EXPECT_FALSE(eulerlib::isprime(9)); // The perfect square edge-case!
    EXPECT_FALSE(eulerlib::isprime(100));
}

TEST(PrimeFactorTests, PrimeCases) {
    EXPECT_EQ(eulerlib::prime_factors(2), std::vector<int>({2}));
    EXPECT_EQ(eulerlib::prime_factors(13), std::vector<int>({13}));
}

TEST(PrimeFactorTests, UniqueCases) {
    EXPECT_EQ(eulerlib::prime_factors(6), std::vector<int>({2,3}));
    EXPECT_EQ(eulerlib::prime_factors(34), std::vector<int>({2,17}));
}

TEST(PrimeFactorTests, RepeatedCases) {
    EXPECT_EQ(eulerlib::prime_factors(4), std::vector<int>({2,2}));
    EXPECT_EQ(eulerlib::prime_factors(50), std::vector<int>({2,5,5}));
    EXPECT_EQ(eulerlib::prime_factors(16), std::vector<int>({2,2,2,2}));
}