#include <iostream>
#include <vector>
#include <chrono> //Used for comparing approaches

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> num;
    num.push_back(1);
    int factorial = 100;

    for (int i = 2; i <= factorial; i++){
        int carry = 0;

        //Multiply each digit
        for (int digit = 0; digit < num.size(); digit++){
            int prod = num[digit] * i + carry;

            num[digit] = prod % 10;

            carry = prod / 10;
        }

        while (carry > 0){
            num.push_back(carry % 10);
            carry /= 10;
        }

    }

    long long total = 0;

    for (int digit : num){
        total += digit;
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);

    std::cout << "The sum of digits in 100! is: " << total << std::endl;
    std::cout << "The amount of time was: " << duration << std::endl;

    return 0;
}