#include <bits/stdc++.h>

using namespace std;

int main(void) {
    pair<int, int> t(1, 2);
    pair<int, int> ta(2, 3);
    pair<int, int> tb = t + ta;
    
    pr
}

// current, rule, destiny, dp, grid, sizes
int boardgames2(int x, int y, int r1, int r2, int d1, int d2, int **dp, int **grid, int M, int N) {
    if (x >= M || y >= N || x < 0 || y < 0) return INT_MAX;
    if (dp[x][y]) return dp[x][y];
    if (grid[x][y]) {
        dp[x][y] = INT_MAX;
    } else {
        dp[x][y] = min(min(boardgames2(x + r1, y + r2, r1, r2, d1, d2, dp, grid, M, N),
                        boardgames2(x + r2, y - r1, r1, r2, d1, d2, dp, grid, M, N)),
                    min(boardgames2(x - r1, y - r2, r1, r2, d1, d2, dp, grid, M, N),
                        boardgames2(x - r2, y + r1, r1, r2, d1, d2, dp, grid, M, N))) + 1;
    }

    return dp[x][y];
}