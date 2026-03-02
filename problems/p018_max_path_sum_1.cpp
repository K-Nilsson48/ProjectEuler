#include <iostream>
#include <array>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>

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


    //Perform a backward search
    for (int row = 13; row >= 0; row--){
        for (int col = 0; col < tree[row].size(); col++){
            if (tree[row+1][col] > tree[row+1][col+1]){
                tree[row][col] += tree[row+1][col];
            }else{
                tree[row][col] += tree[row+1][col+1];
            }
        }
    }

    std::cout << "The maximum sum is: " << tree[0][0] << std::endl;

    return 0;
}