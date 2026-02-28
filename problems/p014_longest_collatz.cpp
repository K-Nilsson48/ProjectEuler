#include <iostream>
#include <vector>

/**
 * Which starting number, under one million, produces the longest chain?
 */

long long collatz_next(long long num){
    if (num % 2 == 0){
        num /= 2;
    }else{
        num = 3 * num + 1;
    }

    return num;
}

int main(){
    std::vector<int> dist(1'000'001,0);
    int longest_dist = 0;
    int longest_num = 0;

    for (int i = 1; i < dist.size(); i++){
        int count = 0;
        long long num = i;

        while (num > 1){
            if (num <= 1'000'000 && dist[num] != 0){
                count += dist[num];
                num = 1;
            }else{
                count++;
                num = collatz_next(num);
            }
        }

        dist[i] = count;

        if (count > longest_dist){
            longest_dist = count;
            longest_num = i;
        }
        
    }

    std::cout << "The number under one million with the longest collatz path is: " << longest_num << std::endl;
    return 0;
}