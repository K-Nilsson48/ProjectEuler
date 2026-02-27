#include "eulerlib/primes.hpp"
#include <iostream>
#include <numeric>
#include <vector>

int main(){
    /**
     * Problem 5:
     *  is the smallest number that can be divided by each of the numbers from  to  without any remainder.
     *  What is the smallest positive number that is evenly divisible by all of the numbers from  to ?
     */

    //Define starting numbers
    int num_factors = 20;

    long long output = 1;

    //Loop over all factors
    for (int i = 2; i <= num_factors; i++){
        //If the factor is prime it needs to be included
        if (eulerlib::isprime(i)){
            int mult = i;
            //Find the largest exponent that can be applied to i when i < largest_factor
            while (mult <= num_factors/i){
                mult *= i;
            }
            output *= mult;
        }
    }

    std::cout << "The smallest multiple is: " << output << std::endl;

    return 0;

}