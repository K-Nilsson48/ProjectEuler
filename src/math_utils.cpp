#include "eulerlib/math_utils.hpp"

namespace eulerlib {

    //Implementation of function to calculate the sum of all multiples of A under a given limit
    long long sum_of_multiples(int A, int limit) {
        long long m = limit / A;
        return A * m * (m + 1) / 2;
    }
}