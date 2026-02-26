#include <iostream>
#include <string>
using namespace std;

/**
 * Problem 4:
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two -digit numbers is   .
 * Find the largest palindrome made from the product of two -digit numbers.
 */


bool ispalindrome(int n){
    string str_n = to_string(n);
    int len_n = str_n.length();

    for (int i = 0; i < len_n/2; i++){
        char fist_num = str_n[i];
        char second_num = str_n[len_n - i-1];
        if (str_n[i] != str_n[len_n-i-1]){
            return false;
        }
    }
    return true;

}


int main(){
    
    long long limit = 999*999;
    long long largest = 0;

    for (int x1 = 100; x1 < 1000; x1++){
        for (int x2 = 100; x2 < 1000; x2++){
            if (x1*x2 > largest && ispalindrome(x1*x2)){
                largest = x1*x2;
            }
        }
    }

    std::cout << "The largest palindrome is: " << largest << std::endl;

}