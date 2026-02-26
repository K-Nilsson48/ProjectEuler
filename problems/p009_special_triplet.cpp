#include <iostream>


int main(){
    for (int a = 1; a <= 1000; a++){
        //std::cout << a << std::endl;
        for (int b = a; b <= 1000 - a; b++){
            for (int c = b; c <= 1000 - a - b; c++){
                if (a*a + b*b == c*c && a + b + c == 1000){
                    std::cout << a * b * c << std::endl;
                }
            }
        }
    }
}