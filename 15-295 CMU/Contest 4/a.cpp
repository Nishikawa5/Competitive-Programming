#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int MOD = 1e9+7;

    // there are 6 possible ways to increment: [1, 6]
    // we can reuse the same number
    vector<int> dp(n + 1);

    dp[0] = 1;

    for (int sum = 1; sum <= n; sum++) {
        for (int side = 1; side <= 6; side++) {
            if (sum - side >= 0) {
                dp[sum] += dp[sum - side];
                dp[sum] %= MOD;
            }
        }
    }
    cout << dp[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;

    while (tc--) {
        solve();
    }
    return 0;
}
