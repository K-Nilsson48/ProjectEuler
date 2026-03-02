cmake_minimum_required(VERSION 3.10.0)
project(ProjectEuler VERSION 0.2.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(include)

file(GLOB LIB_SOURCES "src/*.cpp")
add_library(eulerlib STATIC ${LIB_SOURCES})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/problems/data
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


function(add_euler_problem PROBLEM_NAME FILE_PATH)
    add_executable(${PROBLEM_NAME} ${FILE_PATH})
    target_link_libraries(${PROBLEM_NAME} eulerlib)
endfunction()

add_euler_problem(p001_multiples3_5 problems/p001_multiples3_5.cpp)
add_euler_problem(p002_even_fib problems/p002_even_fib.cpp)
add_euler_problem(p003_largest_prime_factor problems/p003_largest_prime_factor.cpp)
add_euler_problem(p004_largest_palindrome problems/p004_largest_palindrome.cpp)
add_euler_problem(p005_smallest_multiple problems/p005_smallest_multiple.cpp)
add_euler_problem(p006_sum_square_difference problems/p006_sum_square_difference.cpp)
add_euler_problem(p007_10001_prime problems/p007_10001_prime.cpp)
add_euler_problem(p008_largest_prod_in_series problems/p008_largest_prod_in_series.cpp)
add_euler_problem(p009_special_triplet problems/p009_special_triplet.cpp)
add_euler_problem(p010_sum_of_primes problems/p010_sum_of_primes.cpp)
add_euler_problem(p011_grid_product problems/p011_grid_product.cpp)
add_euler_problem(p012_divisible_triangle problems/p012_divisible_triangle.cpp)
add_euler_problem(p013_large_sum problems/p013_large_sum.cpp)
add_euler_problem(p014_longest_collatz problems/p014_longest_collatz.cpp)
add_euler_problem(p015_lattice_paths problems/p015_lattice_paths.cpp)
add_euler_problem(p016_power_digit_sum problems/p016_power_digit_sum.cpp)
add_euler_problem(p017_number_letter_counts problems/p017_number_letter_counts.cpp)


# Compile your math functions into a library called 'euler_core'
add_library(euler_core src/primes.cpp src/math_utils.cpp)


# --- Unit Testing Setup ---
enable_testing()

# 1. Download Google Test automatically
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
# For Windows: Prevent GTest from overriding standard C++ runtime library settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 2. Create the test executable
add_executable(euler_tests tests/test_primes.cpp tests/test_math_utils.cpp)


# 3. Link your shared library AND GTest
# (Assuming your shared library is named 'euler_core' as we set up earlier)
target_link_libraries(euler_tests PRIVATE euler_core GTest::gtest_main)

# 4. Tell CMake to discover and run these tests
include(GoogleTest)
gtest_discover_tests(euler_tests)
