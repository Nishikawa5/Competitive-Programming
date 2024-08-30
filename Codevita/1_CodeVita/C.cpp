#include <bits/stdc++.h>

using namespace std;

void getIsland(int **grid, int x, int y, int m, int n, int k) {
    if (x >= m || x < 0 || y >= n || y < 0 || grid[x][y] == -1 || grid[x][y] != k) return;

    grid[x][y] = -1;

    getIsland(grid, x + 1, y, m, n, k);
    getIsland(grid, x - 1, y, m, n, k);
    getIsland(grid, x, y + 1, m, n, k);
    getIsland(grid, x, y - 1, m, n, k);
}

void fillWater(int **grid, int x, int y, int m, int n, int power) {
    if (x >= m || x < 0 || y >= n || y < 0 || grid[x][y] > power || grid[x][y] == -1) return;

    grid[x][y] = -1;

    fillWater(grid, x + 1, y, m, n, power);
    fillWater(grid, x - 1, y, m, n, power);
    fillWater(grid, x, y + 1, m, n, power);
    fillWater(grid, x, y - 1, m, n, power);
}

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);

    int **grid = (int **) malloc(sizeof(int *) * m);
    int **tempgrid = (int **) malloc(sizeof(int *) * m);
    int height;
    for (int i = 0; i < m; i++) {
        grid[i] = (int *) malloc(sizeof(int) * n);
        tempgrid[i] = (int *) malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &height);
            getchar();
            grid[i][j] = height;
            tempgrid[i][j] = height;
        }
    }

    int x, y;
    scanf("%d %d", &x, &y);
    int power;
    scanf("%d", &power);

    if (grid[x][y] != 0) {
        printf("NONE\n");
        return 0;
    }

    int countstart = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (tempgrid[i][j] != -1 && tempgrid[i][j] != 0) {
                getIsland(tempgrid, i, j, m, n, tempgrid[i][j]);
                countstart++;
            }
        }
    }

    fillWater(grid, x, y, m, n, power);

    int countend = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != -1 && grid[i][j] != 0) {
                getIsland(grid, i, j, m, n, grid[i][j]);
                countend++;
            }
        }
    }

    if (countstart > countend) printf("%d\n", countstart - countend);
    else printf("NONE\n");
}