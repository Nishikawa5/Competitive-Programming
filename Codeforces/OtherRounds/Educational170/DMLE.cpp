#include <bits/stdc++.h>
using namespace std;

void solve() {
    int records, points;
    cin >> records >> points;

    vector<vector<int>> dp(records, vector<int>(points + 1));
    
    int P = 1;  // total points - 1
    for (int i = 0; i < records; i++) {
        int r;
        cin >> r;

        if (r == 0) {
            // put the point in intelligence or strength
            P++;
            if (i) {
                for (int j = 0; j < P; j++) {
                    if (!j) {
                        dp[i][j] = dp[i - 1][j];
                    } else {
                        dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
                    }
                }
            }
        } else if (r > 0) {
            // intelligence
            if (i) {
                for (int j = 0; j < P; j++) {
                    dp[i][j] = dp[i - 1][j] + (j >= r);
                }
            }
        } else {
            // strength
            if (i) {
                for (int j = 0; j < P; j++) {
                    dp[i][j] = dp[i - 1][j] + (P - 1 - j >= -r);
                }
            }
        }
    }

    int max_points = 0;
    for (int i = 0; i < points; i++) {
        max_points = max(max_points, dp[records - 1][i]);
    }
    cout << max_points << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;

    while (tc--) {
        solve();
    }
}
