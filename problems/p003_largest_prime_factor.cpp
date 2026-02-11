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

    for (long long i = 2; i*i <= num;i++){
        while (num % i == 0){
            lpf = i;
            num /= i;
        }
    }

    if (num > 1){
        lpf = num;
    }

    std::cout << "The largest prime factor is: " << lpf << std::endl;


 }