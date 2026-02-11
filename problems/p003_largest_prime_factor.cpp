#include "eulerlib/primes.hpp"
#include <iostream>

/**
 * Problem 3:
 * The prime factors of  are  and .
 * What is the largest prime factor of the number ?
 */


 int main(){
    long long lpf = 1;
    long long num = 600851475143;
    long long i = 2;

    while (i <= num){
        if (num % i == 0 && eulerprimes::isprime(i)){
            lpf = i;
            num = num/i;
        }
        else{
            i++;
        }
    }

    std::cout << "The largest prime factor is: " << lpf << std::endl;


 }