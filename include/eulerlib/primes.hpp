#ifndef EULER_PRIMES_HPP
#define EULER_PRIMES_HPP

#include <vector>

namespace eulerlib{

    //Declaration of prime number function
    bool isprime(int n);

    //Declaration of Prime Factors Function
    std::vector<int> prime_factors(int n);
}
#endif