#ifndef EULER_PRIMES_HPP
#define EULER_PRIMES_HPP

#include <vector>

namespace eulerlib{

    //Declaration of prime number function
    bool isprime(long long n);

    //Declaration of Prime Factors Function
    std::vector<long long> prime_factors(long long n);

    //Declaration of Sieve of Eratosthenes
    std::vector<long long> generate_primes(long long n);
}
#endif