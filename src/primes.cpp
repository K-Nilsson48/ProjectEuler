#include "eulerlib/primes.hpp"
#include <vector>


namespace eulerlib{

    //Implementation of a isprime number function
    bool isprime(long long n){

        //Cleaning Up Edge Cases
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;

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
    std::vector<long long> prime_factors(long long n){
        std::vector<long long> factors = {};

        for (long long i = 2; i*i <= n; i++){
            while (n % i == 0){
                factors.push_back(i);
                n = n/i;
            }
        }

        if (n > 1) {
            factors.push_back(n);
        }

        return factors;
    }


    //Implementation of the Sieve of Eratosthenes
    std::vector<long long> generate_primes(long long n){
        
        //Edge Case Catch
        if (n <= 1) return {};

        //Define vector of numbers
        std::vector<bool> index(n+1,true);
        index[0] = index[1] = 0;

        //Calculate primes
        for (long long i = 2; i*i <= n; i++){
            if (index[i]){
                for (long long num = i*i; num <= n; num += i){
                    index[num] = false;
                }
            }
        }

        //Collect the primes
        std::vector<long long> primes;
        for (long long p = 2; p <= n; p++){
            if (index[p]){
                primes.push_back(p);
            }
        }

        return primes;
    }
}