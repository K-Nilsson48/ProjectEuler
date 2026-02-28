#include <iostream>

/**
 * A Pythagorean triplet is a set of three natural numbers,   , for which,

For example,      .

There exists exactly one Pythagorean triplet for which    .
Find the product .
 */

int main(){
    int target = 1000;
    int half_target = target / 2;
    //Generate using Euclid's Formula
    for (int m = 1; m * m < half_target; m++){
        //Check if this m is a valid solution
        if (half_target % m == 0){
            int n = half_target / m - m;
            
            //Check to make sure n is valid
            if (n > 0 && n < m){
                long long a = m*m - n*n;
                int b = 2 * m * n;
                int c = m*m + n*n;

                long long output = a * b * c;

                std::cout << "The product of the special triple is: " << output << std::endl;
                return 0;
            }
        }
    }
}