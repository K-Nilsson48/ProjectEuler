#include <iostream>
#include <vector>
#include <chrono> //Used for comparing approaches

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> num = {1};
    int exponent = 1000;

    for (int i = 1; i <= exponent; i++){
        int carry = 0;

        //multiple each digit by 2
        for (int digit = 0; digit < num.size(); digit++){
            int prod = num[digit] * 2 + carry;

            num[digit] = prod % 10;

            carry = prod / 10;

        }

        if (carry != 0){
            num.push_back(carry);
        }
    }

    //add up all digits
    long long total = 0;
    for (int digit : num){
        total += digit;
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);

    std::cout << "The sum of all digits is: " << total << std::endl;
    std::cout << "The amount of time was: " << duration << std::endl;

    return 0;
}