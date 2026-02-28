#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <cmath>

/**
 * Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
 */


int main(){
    //Read in numbers
    std::array<std::string, 100> nums_str;

    std::ifstream file("data/p013_nums.txt");

    if (!file.is_open()) {
        std::cerr << "Error: Could not open nums.txt" << std::endl;
        return 1;
    }

    for (int i = 0; i < 100; i++){
        file >> nums_str[i];
    }

    std::cout << "Numbers successfully loaded into memory." << std::endl;

    //Define constants
    int digits = 10;
    std::array<long long, 100> nums;


    //Shorten numbers to keep size down, and make longs
    for (int i = 0; i < 100; i++){
       nums[i] = std::stoll(nums_str[i].substr(0,digits+2));
    }

    //Add up the numbers
    long long total = 0;

    for (long long i : nums){
        total += i;
    }

    //Shorten to 10 digits
    int num_digits = static_cast<int>(std::floor(std::log10(std::abs(static_cast<double>(total)))) + 1);
    
    while (num_digits > 10){
        total /= 10;
        num_digits--;
    }


    std::cout << "The first 10 digits of the sum are: " << total << std::endl;

    return 0;
}