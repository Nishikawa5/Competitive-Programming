#include <bits/stdc++.h>

using namespace std;

int boardgames(int r1, int r2, int s1, int s2, int d1, int d2, int **dp, int **grid, int M, int N) {
    int moves[4][2] = {{r1, r2}, {r2, -r1}, {-r1, -r2}, {-r2, r1}};
    

    pair<int, int> curr(s1, s2);

    queue<pair<int,int>> bfs;
    bfs.push(pair(s1, s2));

    while (dp[d1][d2] == 0 && !bfs.empty()) {
        curr = bfs.front();
        bfs.pop();

        for (int i = 0; i < 4; i++) {
            if (0 <= curr.first + moves[i][0] && curr.first + moves[i][0] < M &&
                0 <= curr.second + moves[i][1] && curr.second + moves[i][1] < N &&
                grid[curr.first + moves[i][0]][curr.second + moves[i][1]] != 1 &&
                dp[curr.first + moves[i][0]][curr.second + moves[i][1]] == 0) {
                
                bfs.push(pair(curr.first + moves[i][0], curr.second + moves[i][1]));
                dp[curr.first + moves[i][0]][curr.second + moves[i][1]] = dp[curr.first][curr.second] + 1;
            }
        }
    }

    return dp[d1][d2];
}


int main(void) {
    int M, N;
    scanf("%d %d", &M, &N);

    int **dp = (int **) malloc(sizeof(int *) * M);
    int **grid = (int **) malloc(sizeof(int *) * M);

    for (int i = 0; i < M; i++) {
        dp[i] = (int *) malloc(sizeof(int) * N);
        grid[i] = (int *) malloc(sizeof(int) * N);
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
            dp[i][j] = 0;
        }
    }

    int s1, s2;
    int d1, d2;
    int r1, r2;

    scanf("%d %d", &s1, &s2);
    scanf("%d %d", &d1, &d2);
    scanf("%d %d", &r1, &r2);

    dp[s1][s2] = 1;
    printf("%d\n", boardgames(r1, r2, s1, s2, d1, d2, dp, grid, M, N) - 1);
}