#include "eulerlib/primes.hpp"
#include <iostream>
#include <array>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    /**
     * Problem 5:
     *  is the smallest number that can be divided by each of the numbers from  to  without any remainder.
     *  What is the smallest positive number that is evenly divisible by all of the numbers from  to ?
     */

    // Naive Solution
    /**
    long long start_num = 2*3*5*7*11*13*17*19;  //You can start at the multiple of all prime numbers
    int factors[] = {11,12,13,14,15,16,17,18,19,20};

    long long num = start_num;
    while (true){
        bool all_mult = true;

        for (int factor : factors){
            if (num % factor != 0){
                all_mult = false;
            }
        }

        if (all_mult){
            break;
        }

        num++;
    }

    std::cout << "The smallest multiple is: " << num << std::endl;
    */

    //Better Solution 

    std::vector<int> factors(20);

    std::iota(std::begin(factors), std::end(factors), 1);

    std::vector<int> prime_factors;
    std::vector<int> difference;
    int output = 1;

    for (int i : factors){
        std::vector<int> p_factors = eulerlib::prime_factors(i);
        std::set_difference(p_factors.begin(), p_factors.end(), prime_factors.begin(), prime_factors.end(), std::inserter(difference, difference.begin()));

        prime_factors.insert(prime_factors.end(), difference.begin(), difference.end());
        std::sort(prime_factors.begin(), prime_factors.end());

        difference.clear();
    }

    for (int num : prime_factors){
        output *= num;
    }
   

    std::cout << "The smallest multiple is: " << output << std::endl;

}