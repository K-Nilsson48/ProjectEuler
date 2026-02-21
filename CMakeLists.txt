cmake_minimum_required(VERSION 3.10.0)
project(ProjectEuler VERSION 0.2.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(include)

file(GLOB LIB_SOURCES "src/*.cpp")
add_library(eulerlib STATIC ${LIB_SOURCES})


function(add_euler_problem PROBLEM_NAME FILE_PATH)
    add_executable(${PROBLEM_NAME} ${FILE_PATH})
    target_link_libraries(${PROBLEM_NAME} eulerlib)
endfunction()

add_euler_problem(p001_multiples3_5 problems/p001_multiples3_5.cpp)
add_euler_problem(p002_even_fib problems/p002_even_fib.cpp)
add_euler_problem(p003_largest_prime_factor problems/p003_largest_prime_factor.cpp)
add_euler_problem(p004_largest_palindrome problems/p004_largest_palindrome.cpp)
add_euler_problem(p005_smallest_multiple problems/p005_smallest_multiple.cpp)