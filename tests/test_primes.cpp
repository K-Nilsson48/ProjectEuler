#include <gtest/gtest.h>
#include "eulerlib/primes.hpp"
#include <vector>

// Test suite name: PrimeTests, Test name: EdgeCases
TEST(PrimeTests, EdgeCases) {
    // EXPECT_FALSE means the test passes if the function returns false
    EXPECT_FALSE(eulerlib::isprime(-5LL));
    EXPECT_FALSE(eulerlib::isprime(0LL));
    EXPECT_FALSE(eulerlib::isprime(1LL));
}

TEST(PrimeTests, SmallPrimes) {
    // EXPECT_TRUE means the test passes if the function returns true
    EXPECT_TRUE(eulerlib::isprime(2LL));
    EXPECT_TRUE(eulerlib::isprime(3LL));
    EXPECT_TRUE(eulerlib::isprime(17LL));
    EXPECT_TRUE(eulerlib::isprime(97LL));
}

TEST(PrimeTests, SmallComposites) {
    EXPECT_FALSE(eulerlib::isprime(4LL));
    EXPECT_FALSE(eulerlib::isprime(9LL)); // The perfect square edge-case!
    EXPECT_FALSE(eulerlib::isprime(100LL));
}

TEST(PrimeFactorTests, PrimeCases) {
    EXPECT_EQ(eulerlib::prime_factors(2LL), std::vector<long long>({2LL}));
    EXPECT_EQ(eulerlib::prime_factors(13LL), std::vector<long long>({13LL}));
}

TEST(PrimeFactorTests, UniqueCases) {
    EXPECT_EQ(eulerlib::prime_factors(6LL), std::vector<long long>({2LL,3LL}));
    EXPECT_EQ(eulerlib::prime_factors(34LL), std::vector<long long>({2LL,17LL}));
}

TEST(PrimeFactorTests, RepeatedCases) {
    EXPECT_EQ(eulerlib::prime_factors(4LL), std::vector<long long>({2LL,2LL}));
    EXPECT_EQ(eulerlib::prime_factors(50LL), std::vector<long long>({2LL,5LL,5LL}));
    EXPECT_EQ(eulerlib::prime_factors(16LL), std::vector<long long>({2LL,2LL,2LL,2LL}));
}

TEST(GenerateTests, BasicCases){
    EXPECT_EQ(eulerlib::generate_primes(11LL), std::vector<long long>({2LL,3LL,5LL,7LL,11LL}));
    EXPECT_EQ(eulerlib::generate_primes(6LL), std::vector<long long>({2LL,3LL,5LL}));
}

TEST(GenerateTests, EdgeCases){
    EXPECT_EQ(eulerlib::generate_primes(0LL), std::vector<long long>({}));
    EXPECT_EQ(eulerlib::generate_primes(1LL), std::vector<long long>({}));
    EXPECT_EQ(eulerlib::generate_primes(2LL), std::vector<long long>({2LL}));
}