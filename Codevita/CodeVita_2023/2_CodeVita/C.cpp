#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int m, n;

    scanf("%d %d", &m, &n);

    int grid[m][n];
    int dp[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
            dp[i][j] = 0;
        }
    }

    int s1, s2;
    int d1, d2;

    scanf("%d %d", &s1, &s2);
    scanf("%d %d", &d1, &d2);

    s1 -= 1;
    s2 -= 1;
    d1 -= 1;
    d2 -= 1;

    if (d1 < s1 || d2 < s2) {
        printf("-1\n");
    } else {
        dp[s1][s2] = grid[s1][s2];

        for (int i = s1 + 1; i <= d1; i++) {
            dp[i][s2] = grid[i][s2] + dp[i - 1][s2];
        }

        for (int j = s2 + 1; j <= d2; j++) {
            dp[s1][j] = grid[s1][j] + dp[s1][j - 1];
        }

        for (int i = s1 + 1; i <= d1; i++) {
            for (int j = s2 + 1; j <= d2; j++) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        printf("%d\n", dp[d1][d2]);
    }
}