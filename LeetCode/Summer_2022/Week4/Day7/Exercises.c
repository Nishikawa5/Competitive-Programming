#include <stdio.h>
#include <stdlib.h>


void bfsIsland (char** grid, int gridSize, int gridColSize, int i, int j);

// given a grid of 1's and 0's, for 1 representing a part of an island, return the number of islands the grid have
int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int count = 0;
    /*
       search for 1's in the grid
       if it's found, turn all adjacend ones into zeros
       and add 1 to count
    */
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < *gridColSize; j++)
        {
            if (grid[i][j] == '1') 
            {
                bfsIsland(grid, gridSize, *gridColSize, i, j);
                count++;
            }
        }
    }
    return count;
}

// depth first search
void bfsIsland (char** grid, int gridSize, int gridColSize, int i, int j)
{
    // its inside the grid and it is a one, so change the one to zero and check for every other direction
    if (i >= 0 && i < gridSize && j >= 0 && j < gridColSize && grid[i][j] == '1')
    {
        grid[i][j] = '0';

        bfsIsland(grid, gridSize, gridColSize, i + 1, j);
        bfsIsland(grid, gridSize, gridColSize, i, j + 1);
        bfsIsland(grid, gridSize, gridColSize, i - 1, j);
        bfsIsland(grid, gridSize, gridColSize, i, j - 1);
    }
    return;
}





// given a matrix of connected cities by its index (for example: [0][1] the city 0 is connected to the city 1)
int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize)
{
    int count = 0;
    for (int i = 0; i < isConnectedSize; i++)
    {
        for (int j = 0; j < *isConnectedColSize; j++)
        {
            // if the city is connected to something, verify every connections of this city and turn the already checked cities to 0
            if (isConnected[i][j])
            {
                bfsIsConnected(isConnected, isConnectedSize, *isConnectedColSize, i, j);
                count++;
            }
        }
    }
    return count;
}

// depth first search
void bfsIsConnected(int** isConnected, int numRows, int numCols, int i, int j)
{
    // is in the grid
    if (i >= 0 && i < numRows && j >= 0 && j < numCols)
    {
        // change the 1 to 0
        isConnected[i][j] = 0;

        // verify all other connected cities to this i-th city
        for (int k = 0; k < numCols; k++)
        {
            if (isConnected[i][k])
            {
                // already verified, so turn into zero
                isConnected[i][k] = 0;
                bfsIsConnected(isConnected, numRows, numCols, k, i);
            }
        }
    }
    return;
}




// given the size of a matrix, return the number of ways we can go from [0][0] to [m - 1][n - 1]
int uniquePaths(int m, int n)
{
    /*
       permutations of down movements and right movements (for example: D D D D D D D R R R)
    */

    int dividedfactorial = (m > n ? m:n);
    unsigned long int total = 1;

    for (unsigned int maxmul = m + n - 2, otherfactorial = 1; dividedfactorial <= maxmul; dividedfactorial++, otherfactorial++)
    {
        total *= dividedfactorial;
        total /= otherfactorial;
    }

    return total;
}