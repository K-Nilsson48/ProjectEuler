#include "eulerlib/primes.hpp"

#include <vector>

namespace eulerlib{

    //Implementation of a isprime number function
    bool isprime(int n){

        //Cleaning Up Edge Cases
        if (n <= 1){
            return false;
        }
        long long i = 2;
        while (i * i <= n){
            if (n % i == 0){
                return false;
            }

            i++;
        }

        return true;
    }


    //Implmentation of the Prime Factors Function
    std::vector<int> prime_factors(int n){
        std::vector<int> factors = {};

        for (int i = 2; i <= n; i++){
            if (n % i == 0 && isprime(i)){
                factors.push_back(i);
                n = n/i;
                i--;
            }
        }

        return factors;
    }
}