#include <iostream>
#include <array>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <chrono> //Used for comparing approaches

int main(){

    //Read in Data
    std::array<std::vector<long long>, 15> tree;

    std::ifstream file("data/p018_triangle.txt");

    if (!file.is_open()) {
        std::cerr << "Error: Could not open p018_triangle.txt" << std::endl;
        return 1;
    }

    std::string line;
    for (int row = 0; row < 15; row++){
        std::getline(file, line);
        std::stringstream ss(line);
        tree[row].insert(tree[row].end(), std::istream_iterator<long long>(ss), std::istream_iterator<long long>());
    }

    auto start = std::chrono::high_resolution_clock::now();


    //Perform a backward search
    for (int row = 13; row >= 0; row--){
        for (size_t col = 0; col < tree[row].size(); ++col){
            tree[row][col] += std::max(tree[row+1][col], tree[row+1][col+1]);
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);


    std::cout << "The maximum sum is: " << tree[0][0] << std::endl;

    std::cout << "The amount of time was: " << duration << std::endl;

    return 0;
}