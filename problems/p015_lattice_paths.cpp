#include <iostream>
#include <array>
#include <map>
#include <algorithm>


//Declare global variable
std::map<std::array<int,2>, long long> stored;

long long dist(std::array<int,2> grid){
    if (stored.contains(grid)){
        return stored[grid];
    }

    if (grid[0] == 0 || grid[1] == 0){
        return 1;
    }

    long long moves = 0;
    //Goes down
    if (grid[0] > 0){
        std::array<int,2> new_grid = {grid[0] - 1, grid[1]};
        std::sort(new_grid.begin(), new_grid.end());
        long long new_dist = dist(new_grid);
        stored[new_grid] = new_dist;
        moves += dist(new_grid);
    }

    //Goes right
    if (grid[1] > 0){
        std::array<int,2> new_grid = {grid[0], grid[1] - 1};
        std::sort(new_grid.begin(), new_grid.end());
        long long new_dist = dist(new_grid);
        stored[new_grid] = new_dist;
        moves += dist(new_grid);
    }

    return moves;

}

int main(){
    int grid_side = 20;
    std::array<int,2> grid = {0, 0};

    while (grid[0] <= grid_side && grid[1] <= grid_side){
        std::sort(grid.begin(), grid.end());
        stored[grid] = dist(grid);
        if (grid[0] > grid[1]){
            grid[1]++;
        }
        else{
            grid[0]++;
        }
    }

    long long num = stored[{grid_side, grid_side}];
    
    

    std::cout << "The number of ways to move through a 20x20 grid is: " << num << std::endl;
    return 0;
}