#include <bits/stdc++.h>
using namespace std;

/* AC */
void solve() {
    int n;
    cin >> n;

    vector<int> moves(n);
    for (int i = 0; i < n; i++) {
        string move;
        cin >> move;

        if (move[0] == 'u') {
            moves[i] = 0;
        } else if (move[0] == 'd') {
            moves[i] = 1;
        } else if (move[0] == 'l') {
            moves[i] = 2;
        } else {
            moves[i] = 3;
        }
    }

    // leg moves to get to this round
    vector<vector<vector<int>>> dp(4, vector<vector<int>>(4, vector<int>(n)));
    for (int i = 0; i < (int)moves.size(); i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (i) {
                    // keep
                    dp[j][k][i] = dp[j][k][i - 1];
                    for (int w = 0; w < 4; w++) {
                        // move right leg?
                        dp[j][k][i] = min(dp[j][w][i - 1] + 1, dp[j][k][i]);
                    }

                    for (int w = 0; w < 4; w++) {
                        // move left leg?
                        dp[j][k][i] = min(dp[w][k][i - 1] + 1, dp[j][k][i]);
                    }
                }

                if (j != moves[i] && k != moves[i]) {
                    dp[j][k][i] = 81;
                }
            }
        }
    }
    int ans = n;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            ans = min(ans, dp[i][j][n - 1]);
        }
    }
    cout << ans << endl;
}

int main() {
    int tc = 1;

    while (tc--) {
        solve();
    }
    return 0;
}
