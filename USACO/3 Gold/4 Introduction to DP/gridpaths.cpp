#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    getchar();

    vector<vector<char>> grid(n, vector<char>(n));
    for (auto &vec: grid) {
        for (auto &c: vec) {
            c = getchar();
        }
        getchar();
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == '*') break;
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
        if (grid[0][j] == '*') break;
        dp[0][j] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] != '*') {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % ((int) 1e9 + 7);
            }
        }
    }
    cout << dp[n - 1][n - 1] << endl;
}