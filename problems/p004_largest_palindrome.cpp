#include <iostream>

/**
 * Problem 4:
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two -digit numbers is   .
 * Find the largest palindrome made from the product of two -digit numbers.
 */


 //Helper function to test if a string is a palindrome
bool ispalindrome(int n){

    int orig = n;
    int reversed = 0;

    //Reverse the integer
    while (n > 0){
        reversed = (reversed * 10) + (n % 10);
        n /= 10;
    }

    return orig == reversed;

}


int main(){
    //Define Constants
    long long largest = 0;

    //Loop over all possible options checking
    for (int x1 = 999; x1 >= 100; x1--){
        for (int x2 = x1; x2 >= 100; x2--){

            if (x1 * x2 <= largest) break;

            if (ispalindrome(x1*x2)){
                largest = x1*x2;
            }
        }
    }

    std::cout << "The largest palindrome is: " << largest << std::endl;

    return 0;
}