#include <iostream>
#include "eulerlib/primes.hpp"

int main(){
    int limit = 2000000;
    long long sum = 0;

    for (int i = 2; i < limit; i++){
        if (eulerlib::isprime(i)){
            sum += i;
        }
    }

    std::cout << sum << std::endl;
}