#include <iostream>
#include <vector>

int main(){
    std::vector<int> num;
    num.push_back(1);
    int factorial = 100;

    for (int i = 2; i <= factorial; i++){
        //Multiply each digit
        for (int digit = 0; digit < num.size(); digit++){
            num[digit] *= i;
        }

        //Carry the extra digits
        for (int digit = 0; digit < num.size(); digit++){
            if (num[digit] >= 10){
                int tens = (num[digit] - (num[digit] % 10)) / 10;
                num[digit] = num[digit] % 10;
                if (digit < num.size() - 1){
                    num[digit + 1] += tens;
                }else{
                    num.push_back(tens);
                }
            }
        }
    }

    long long total = 0;

    for (int digit : num){
        total += digit;
    }

    std::cout << "The sum of digits in 100! is: " << total << std::endl;
    return 0;
}