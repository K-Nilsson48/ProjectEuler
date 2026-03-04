#include <iostream>
#include "eulerlib/math_utils.hpp"
#include <chrono> //Used for comparing approaches

/**
 * What is the value of the first triangle number to have over five hundred divisors?
 */


int main(){

    auto start = std::chrono::high_resolution_clock::now();

    //define constants
    int limit = 500;
    int index = 1;
    int total = 0;
    int num_div = 0;

    while (num_div < limit){
        total += index;
        num_div = eulerlib::count_divisors(total);
        index++;
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);

    std::cout << "The first triangle number with over 500 divisors is: " << total << std::endl;
    std::cout << "The amount of time was: " << duration << std::endl;

    return 0;
}