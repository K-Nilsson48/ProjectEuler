#include <iostream>
#include <array>
#include <map>
#include <algorithm>
#include <chrono> //Used for comparing approaches

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    // 1. Allocate the 21x21 grid directly on the stack and zero-initialize it
    std::array<std::array<long long, 21>, 21> grid{};

    // 2. Base Cases: The top edge (row 0) and left edge (col 0) all have exactly 1 path
    for (int i = 0; i < 21; i++) {
        grid[i][0] = 1;
        grid[0][i] = 1;
    }

    // 3. Bottom-Up Traversal: Fill the interior of the grid
    for (int row = 1; row < 21; row++) {
        for (int col = 1; col < 21; col++) {
            // The paths to the current point = paths from the left + paths from above
            grid[row][col] = grid[row][col - 1] + grid[row - 1][col];
        }
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);

    //std::cout << "The number of ways to move through a 20x20 grid is: " << num << std::endl;
    std::cout << "The number of ways to move through a 20x20 grid is: " << grid[20][20] << std::endl;
    std::cout << "The amount of time was: " << duration << std::endl;

    return 0;
}