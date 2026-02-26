#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>


/**
 * The sum of the squares of the first ten natural numbers is,

The square of the sum of the first ten natural numbers is,

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is   .

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

int main(){

    /** Naive Way
    std::vector<int> numbers(100);

    std::iota(numbers.begin(), numbers.end(), 1);

    long long sum_of_squares = 0;
    long long sums = 0;

    for (int i : numbers){
        sums += i;
        sum_of_squares += i*i;
    }
    std::cout << sums * sums - sum_of_squares << std::endl;
    */

    //Faster Way
    long long num = 100;

    long long sum_of_squares = num * (num + 1) * (2*num + 1) / 6;
    long long square_of_sum = std::pow(num * (num + 1) / 2,2);

    std::cout << square_of_sum - sum_of_squares << std::endl;
}