#include <iostream>
#include "eulerlib/primes.hpp"


/**
 * What is the  10001st prime number?
 */

int main(){
    int count = 0;
    int num = 1;

    while (count != 10001){
        num++;
        if (eulerlib::isprime(num)){
            count++;
        }

    }

    std::cout << num << std::endl;

}