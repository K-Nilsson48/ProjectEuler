#include <iostream>
#include "eulerlib/primes.hpp"


/**
 * What is the  10001st prime number?
 */

int main(){
    //Define Constants
    int count = 1;
    long long num = 1;

    //Loop over all values checking for primes
    while (count != 10'001){
        num += 2;
        if (eulerlib::isprime(num)){
            count++;
        }

    }

    std::cout << "The 10,001st prime is: " << num << std::endl;
    return 0;
}