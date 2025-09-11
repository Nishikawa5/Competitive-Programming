#include <bits/stdc++.h>
using namespace std;

void solve() {

    // dp[i][j]: number of valid password suffixes
    // of length N-i, 
    // starting with keys [0, j]

    // so
    // dp[N-1] with k keys we can make
    // k valid passwords

    // the number of N-char password suffixes
    // depends only on the number of
    // valid (N-1)-char suffixes

    int MOD = 1e9 + 7;

    int t, latency;
    cin >> t >> latency;

    vector<vector<int>> delays(t, vector<int>(t));

    for (auto &v: delays) {
        for (auto &d: v) {
            cin >> d;
        }
    }

    int n;
    cin >> n;

    vector<int> password_delays(n-1);
    for (auto &p: password_delays) {
        cin >> p;
    }

    vector<vector<int>> dp(n, vector<int>(t));
    for (int i = 0; i < t; i++) {
        dp[n-1][i] = i+1;
    }

    for (int i = n-2; i >= 0; i--) {

        int hi = password_delays[i] + latency;
        int lo = password_delays[i] - latency;
        
        for (int j = 0; j < t; j++) {
            // from key j, how many ways
            // can we make a valid starting
            // with N-i keys?
            int from = lower_bound(delays[j].begin(), delays[j].end(), lo) - delays[j].begin();
            int to = upper_bound(delays[j].begin(), delays[j].end(), hi) - delays[j].begin();

            if (from != 0) {
                from = dp[i+1][from-1];
            }
            if (to != 0) {
                to = dp[i+1][to-1];
            }
            dp[i][j] = (to-from + MOD)%MOD;
        }

        for (int j = 0; j < t; j++) {
            if (j) dp[i][j] += dp[i][j-1];

            dp[i][j] %= MOD;
        }
    }

    cout << dp[0][t-1] << endl;
}

int main() {
    solve();
}