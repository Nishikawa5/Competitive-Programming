#include <bits/stdc++.h>
using namespace std;

void solve() {
    // friend always kill easy
    // you always kill hard
    int n;
    cin >> n;

    vector<int> is_hard_boss(n);
    for (auto &i: is_hard_boss) {
        cin >> i;
    }

    vector<vector<long long>> dp(2, vector<long long>(n + 1, 1e9));
    // player 0 is friend;
    dp[0][0] = 0;
    dp[0][1] = is_hard_boss[0];
    if (n >= 2) {
        dp[1][2] = dp[0][1];
        dp[0][2] = is_hard_boss[0] + is_hard_boss[1];

        for (int session = 3; session <= n; session++) {
            // the session >= 3 is either our friend turn or our turn
            // we can either
            dp[1][session] = min(dp[0][session - 1], dp[0][session - 2]);
            dp[0][session] = min(dp[1][session - 1], dp[1][session - 2] + is_hard_boss[session - 2]) + is_hard_boss[session - 1];
        }
    }
    cout << min(dp[0][n], dp[1][n]) << endl;

}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}