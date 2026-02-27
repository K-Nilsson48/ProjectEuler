#include "eulerlib/math_utils.hpp"
#include <iostream>

/**
 * Problem #1:
 * If we list all the natural numbers below  that are multiples of  or , we get  and . The sum of these multiples is .
 * Find the sum of all the multiples of  or  below .
 */


int main() {
    //Limit given in the question
    constexpr int limit = 999;
    
    //Find the sum of multiples for 3, 5 and 15
    long long sum3 = eulerlib::sum_of_multiples(3, limit);
    long long sum5 = eulerlib::sum_of_multiples(5, limit);
    long long sum15 = eulerlib::sum_of_multiples(15, limit);

    // Return the sum of multiples of 3 and 5 minus the ones double counted as 15
    long long total_sum = sum3 + sum5 - sum15;

    std::cout << "The sum of multiples of 3 or 5 below 1000 is: " << total_sum << std::endl;

    return 0;

}