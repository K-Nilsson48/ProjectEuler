#include <iostream>
#include <vector>

int main(){
    std::vector<int> num = {1};
    int exponent = 1000;

    for (int i = 1; i <= exponent; i++){
        //multiple each digit by 2
        for (int digit = 0; digit < num.size(); digit++){
            num[digit] *= 2;
        }

        //Check to see which numbers are more than one digit
        for (int digit = 0; digit < num.size(); digit++){
            if (num[digit] >= 10){
                num[digit] = num[digit] % 10;
                if (digit + 1 < num.size()){
                    num[digit + 1]++;
                }else{
                    num.push_back(1);
                }
                
            }
        }
    }

    //add up all digits
    long long total = 0;
    for (int digit : num){
        total += digit;
    }


    std::cout << "The sum of all digits is: " << total << std::endl;

    return 0;
}