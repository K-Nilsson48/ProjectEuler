#include <iostream>

/**
 * The sum of the squares of the first ten natural numbers is,

The square of the sum of the first ten natural numbers is,

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is   .

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

int main(){

    //Define constants
    constexpr long long num = 100;

    //Calculate the sum of squares and the square of sums
    long long sum_of_squares = num * (num + 1) * (2*num + 1) / 6;
    long long base_sum = num * (num + 1) / 2;
    long long square_of_sum = base_sum * base_sum;

    std::cout << "The square of sums minus the sum of squares is: " << square_of_sum - sum_of_squares << std::endl;

    return 0;
}