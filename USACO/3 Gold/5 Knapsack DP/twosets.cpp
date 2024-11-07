#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// mod pow
int mod_pow(int x, int y, int mod) {
    int result = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            result = (result * 1LL * x) % mod;
        }
        x = (x * 1LL * x) % mod;
        y /= 2;
    }
    return result;
}


// divide {1, ..., n} in two sets of equal sum
int main() {
    int n;
    cin >> n;

    // the two sets sum up to 1 + ... + n = n * (n + 1) / 2
    int sum = n * (n + 1) / 2;

    if (sum % 2) {
        // not possible
        cout << 0 << endl;
    } else {
        // how many ways can we sum sum / 2?
        int target = sum / 2;
        vector<int> dp(target + 1);

        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = target; j >= 0; j--) {
                // start from right to use just one time
                if (j - i >= 0) {
                    dp[j] += dp[j - i];
                    dp[j] %= MOD;
                }
            }
        }
        // note that it counts two times
        int result = (dp[target] * 1LL * mod_pow(2, MOD - 2, MOD)) % MOD;
        cout << result << endl;
    }
}