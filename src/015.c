// 015: Lattice Paths
// src: https://projecteuler.net/problem=15

#include <stdint.h>
#include <stdio.h>

// One more because for example in a "2 by 2 grid" there are in fact three
// columns and rows
#define NUMROWS 20 + 1
#define NUMCOLS 20 + 1

int main(void)
{
    uint64_t grid_paths[NUMROWS][NUMCOLS] = { 0UL };

    // Initialize the top and left edges of the grid to 1
    for (size_t row = 0; row < NUMROWS; row++) {
        grid_paths[row][0] = 1;
    }

    for (size_t col = 0; col < NUMCOLS; col++) {
        grid_paths[0][col] = 1;
    }

    // Count of routes to each grid point is the sum of routes to grids above
    // and left of it.
    for (size_t row = 1; row < NUMROWS; row++) {
        for (size_t col = 1; col < NUMCOLS; col++) {
            grid_paths[row][col]
                = grid_paths[row - 1][col] + grid_paths[row][col - 1];
        }
    }

    // The bottom right cell contains the number of paths
    uint64_t bottom_right_paths = grid_paths[NUMCOLS - 1][NUMROWS - 1];

    printf("Problem 015: %lld\n", bottom_right_paths);

    return 0;
}
