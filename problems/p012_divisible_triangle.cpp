#include <iostream>
#include "eulerlib/math_utils.hpp"

/**
 * What is the value of the first triangle number to have over five hundred divisors?
 */


int main(){
    //define constants
    int limit = 500;
    int index = 1;
    int total = 0;
    int num_div = 0;

    while (num_div < limit){
        total += index;
        num_div = eulerlib::divisors(total).size();
        index++;
    }

    std::cout << "The first triangle number with over 500 divisors is: " << total << std::endl;

    return 0;
}