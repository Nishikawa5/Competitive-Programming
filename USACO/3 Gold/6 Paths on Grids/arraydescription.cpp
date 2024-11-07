#include <bits/stdc++.h>
using namespace std;

/*
dp[i][v]

the number of different arrays we can get
up to i with value v

dp[i] = dp[i - 1][v - 1] +
        dp[i - 1][v]     +
        dp[i - 1][v + 1]

2 0 2

dp[0][2] = 1
dp[1][0] = 0
dp[1][1] = 1
dp[1][2] = 1
dp[1][3] = 1
dp[1][4] = 0

note that
dp[i][v] can be placed beside
dp[i - 1][v - 1], dp[i - 1][v], dp[i - 1][v + 1]

so the number of possibilities for
dp[i][v] is the sum of those possibilities


1 2 3 4 5 6 7

1 2 0 4 0


*/

#define ll long long
int main() {
    ll MOD = 1e9 + 7;
    int n, ub;
    cin >> n >> ub;

    vector<int> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }

    vector<vector<ll>> dp(n, vector<ll>(ub + 1));

    if (arr[0] == 0) {
        for (int i = 1; i <= ub; i++) {
            dp[0][i] = 1;
        }
    } else {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        
        if (arr[i] == 0) {
            for (int j = 1; j <= ub; j++) {
                if (j - 1 >= 1) {
                    dp[i][j] += dp[i - 1][j - 1];            
                }

                dp[i][j] += dp[i - 1][j];

                if (j + 1 <= ub) {
                    dp[i][j] += dp[i - 1][j + 1];
                }
                dp[i][j] %= MOD;         
            }
        } else {
            if (arr[i] - 1 >= 1) {
                dp[i][arr[i]] += dp[i - 1][arr[i] - 1];            
            }

            dp[i][arr[i]] += dp[i - 1][arr[i]];

            if (arr[i] + 1 <= ub) {
                dp[i][arr[i]] += dp[i - 1][arr[i] + 1];
            }
            dp[i][arr[i]] %= MOD;
        }
    }

    ll ans = 0;
    for (int j = 1; j <= ub; j++) {
        ans += dp[n - 1][j];
        ans %= MOD;
    }
    cout << ans << endl;
}