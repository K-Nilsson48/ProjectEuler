#include <iostream>
#include <array>
#include <fstream>

int main(){
    //Set up grid
    std::array<std::array<long long, 20>, 20> grid;

    std::ifstream file("data/p011_grid.txt");

    if (!file.is_open()) {
        std::cerr << "Error: Could not open grid.txt" << std::endl;
        return 1;
    }

    for (int row = 0; row < 20; row++){
        for (int col = 0; col < 20; ++col) {
            file >> grid[row][col];
        }
    }

    std::cout << "Grid successfully loaded into memory." << std::endl;

    //Traversing the Grid
    int window = 4;
    long long max_prod = 0;
    std::array<int,4> best_nums; 
    //Horizontal
    for (int row = 0; row < 20; row++){
        for (int col = 0; col < 20 - window; col++){
            long long current_prod = 1;
            for (int w = 0; w < window; w++){
                current_prod *= grid[row][col+w];
            }
            //Check if it is higher than the max
            if (current_prod > max_prod){
                max_prod = current_prod;
                for (int w = 0; w < window; w++){
                    best_nums[w] = grid[row][col+w];
                }
            }
        }
    }

    //Vertical
    for (int col = 0; col < 20; col++){
        for (int row = 0; row <= 20 - window; row++){
            long long current_prod = 1;
            for (int w = 0; w < window; w++){
                current_prod *= grid[row+w][col];
            }
            //Check if it is higher than the max
            if (current_prod > max_prod){
                max_prod = current_prod;
                for (int w = 0; w < window; w++){
                    best_nums[w] = grid[row+w][col];
                }
            }
        }
    }

    //Diagonal - Right
    for (int row = 0; row <= 20 - window; row++){
        for (int col = 0; col <= 20 - window; col++){
            long long current_prod = 1;
            for (int w = 0; w < window; w++){
                current_prod *= grid[row+w][col+w];
            }
            //Check if it is higher than the max
            if (current_prod > max_prod){
                max_prod = current_prod;
                for (int w = 0; w < window; w++){
                    best_nums[w] = grid[row+w][col+w];
                }
            }
        }
    }

    //Diagonal - Left
    for (int row = 0; row <= 20 - window; row++){
        for (int col = window-1; col < 20; col++){
            long long current_prod = 1;
            for (int w = 0; w < window; w++){
                current_prod *= grid[row+w][col-w];
            }
            //Check if it is higher than the max
            if (current_prod > max_prod){
                max_prod = current_prod;
                for (int w = 0; w < window; w++){
                    best_nums[w] = grid[row+w][col-w];
                }
            }
        }
    }



    
    std::cout << "The max Product is: " << max_prod << std::endl;
    std::cout << best_nums[0] << " " << best_nums[1] << " " << best_nums[2] << " " << best_nums[3] << std::endl;

    return 0;
}