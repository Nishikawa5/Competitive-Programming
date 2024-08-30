#include <bits/stdc++.h>

using namespace std;



int maxSubArraySum(int *a, int n) {
    
}












/*
score = n

different ways to reach n
n - a +
n - b +
n - c +
...




*/

int waysToScore(int n, vector<int> values) {
    int arr[n + 1] = {0};

    arr[0] = 1;

    arr[13] -= 1; // with (10, 3) = (3, 10)

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < values.size(); j++) {
            if (i - values[j] >= 0) {
                arr[i] += arr[i - values[j]];
            }
        }

    }
}



int main(void) {

}













int tiles(int N) {
    if (N <= 0) return 0;
    if (N % 2) return 0;

    if (N == 4) return 11;
    if (N == 2) return 3;
    

    return 3 * tiles(N - 2) + 2 * tiles(N - 4);
}


int minPathCost(int x, int y, int cost[4][5], int M, int N) {
    if (x == 0 && y == 0) return cost[0][0];
    if (x == 0) return cost[0][y] + minPathCost(0, y - 1, cost, M, N);
    if (y == 0) return cost[x][0] + minPathCost(x - 1, 0, cost, M, N);

    return min(min(minPathCost(x - 1, y, cost, M, N),       // left to right
                  minPathCost(x - 1, y - 1, cost, M, N)),   // diagonal
                  minPathCost(x, y - 1, cost, M, N)) + cost[x][y];
}


int MEMO[4][5] = {0};
int minPathCostMEMO(int x, int y, int cost[4][5], int M, int N) {
    if (MEMO[x][y]) return MEMO[x][y];
    if (x == 0 && y == 0) MEMO[0][0] = cost[0][0];
    else if (x == 0) MEMO[0][y] = minPathCostMEMO(0, y - 1, cost, M, N) + cost[0][y];
    else if (y == 0) MEMO[x][0] = minPathCostMEMO(x - 1, 0, cost, M, N) + cost[x][0];
    else MEMO[x][y] = min(min(minPathCostMEMO(x - 1, y, cost, M, N),       // left to right
                              minPathCostMEMO(x - 1, y - 1, cost, M, N)),   // diagonal
                              minPathCostMEMO(x, y - 1, cost, M, N)) + cost[x][y];

    return MEMO[x][y];
}

int minPathCostBOTTOMUP(int x, int y, int cost[4][5], int M, int N) {
    int memo[M][N];

    memo[0][0] = cost[0][0];

    for (int i = 1; i < M; i++) {
        memo[i][0] = memo[i - 1][0] + cost[i][0];
    }
    for (int j = 1; j < N; j++) {
        memo[0][j] = memo[0][j - 1] + cost[0][j];
    }

    for (int i = 1; i < M; i++) {
        for (int j = 1; j < N; j++) {
            memo[i][j] = min(min(memo[i - 1][j],
                                 memo[i][j - 1]),
                                 memo[i - 1][j - 1]) + cost[i][j];
        }
    }
    return memo[M - 1][N - 1];
}

int minpathtest(void) {
    int cost[4][5] = {
        {1, 9, 1, 9, 9},
        {0, 1, 1, 9, 9},
        {0, 9, 9, 2, 9},
        {0, 9, 0, 0, 1}
    };

    printf("%d\n", minPathCostBOTTOMUP(3, 4, cost, 4, 5));

    return 0;
}
