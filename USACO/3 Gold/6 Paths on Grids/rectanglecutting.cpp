#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> n >> m;

    /*
    cut the square ->
    get the min with cutted

    0 1 2 3 4 5 6 7 8 9
    1 0 2 1 3 2 4
    2 2 0 3 
    3
    4
    5
    6

    example for 3 4:
    cut 3 3 -> 1 3 -> +=dp[1][3]
    */

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }

            // consider every vertical cut
            for (int k = 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
            }

            // consider every horizontal cut
            for (int k = 1; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
            }
        }
    }
    cout << dp[n][m] << endl;
}