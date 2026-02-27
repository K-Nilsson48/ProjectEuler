#include "eulerlib/math_utils.hpp"
#include <vector>
#include <algorithm> //used for sort function

namespace eulerlib {

    //Implementation of function to calculate the sum of all multiples of A under a given limit
    long long sum_of_multiples(int A, int limit) {
        long long m = limit / A;
        return A * m * (m + 1) / 2;
    }

    //Implementation of a divisors function
    std::vector<long long> divisors(long long n){
        if (n <= 0) return {};

        std::vector<long long> divs;

        for (int i = 1; i*i <= n; i++){
            if (n % i == 0){
                divs.push_back(i);
                if (n/i != i) divs.push_back(n/i);
            }
        }
        std::sort(divs.begin(), divs.end());
        return divs;
    }
}