#include <iostream>
#include "eulerlib/primes.hpp"
#include <vector>
#include <numeric>

int main(){
    //Define Constants
    int limit = 2'000'000;

    //Add up all numbers that are prime
    std::vector<long long> primes = eulerlib::generate_primes(limit);

    long long sum = std::accumulate(primes.begin(), primes.end(),0LL);

    std::cout << "The sum of primes up to 2,000,000 is: " << sum << std::endl;

    return 0;
}