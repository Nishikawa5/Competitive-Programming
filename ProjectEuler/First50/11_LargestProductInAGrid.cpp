#include <bits/stdc++.h>

using namespace std;

/*
given start x, start y, x step, y step, a grid and number of adjacents, return the maximum product of these
adjacents by step
*/
long maxProdAdj(int startx, int starty, int xstep, int ystep, 
               vector<vector<int>> grid, int adjacent) {
    queue<int> prodMult;
    long maxProd = 0;
    long currProd = 1;

    int x = startx;
    int y = starty;
    while (0 <= x && x < grid.size() && 0 <= y && y < grid[0].size()) {
        if (grid[x][y] == 0) {
            // clear the queue
            while (!prodMult.empty()) {
                prodMult.pop();
            }
            currProd = 1;        
        } else {
            // push
            prodMult.push(grid[x][y]);
            currProd *= grid[x][y];

            if (prodMult.size() == adjacent) {
                maxProd = max(maxProd, currProd);

                currProd /= prodMult.front();
                prodMult.pop();
            }
        }
        x += xstep;
        y += ystep;
    }
    return maxProd;
}



int main(void) {
    int n = 20;
    int adjacent = 4;
    vector<vector<int>> grid(n,vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    long maxProd = 0;
    for (int i = 0; i < n; i++) {
        // check rows and diagonal(left to right)
        maxProd = max(maxProd, maxProdAdj(i,     0, 0,  1, grid, adjacent));
        maxProd = max(maxProd, maxProdAdj(i,     0, 1,  1, grid, adjacent));
        maxProd = max(maxProd, maxProdAdj(i, n - 1, 1, -1, grid, adjacent));
    }

    for (int j = 0; j < n; j++) {
        // check columns and diagonal(left to right) and diagonal(right to left)
        maxProd = max(maxProd, maxProdAdj(0, j, 1,  0, grid, adjacent));
        maxProd = max(maxProd, maxProdAdj(0, j, 1,  1, grid, adjacent));
        maxProd = max(maxProd, maxProdAdj(0, j, 1, -1, grid, adjacent));
    }
    printf("%ld\n", maxProd);
}