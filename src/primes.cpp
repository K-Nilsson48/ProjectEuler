#include "eulerlib/primes.hpp"

namespace eulerprimes{

    //Implementation of a isprime number function
    bool isprime(int n){
        long long i = 2;
        while (i * i <= n){
            if (n % i == 0){
                return false;
            }

            i++;
        }

        return true;
    }

}