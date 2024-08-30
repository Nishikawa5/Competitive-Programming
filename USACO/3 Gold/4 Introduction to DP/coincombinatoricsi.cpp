#include <bits/stdc++.h>
using namespace std;

int main() {
    int num_coins, target;
    cin >> num_coins >> target;

    vector<int> coins(num_coins);
    for (int &c: coins) {
        cin >> c;
    }

    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++) {
        for (int c: coins) {
            if (i - c >= 0) {
                dp[i] += dp[i - c];
                dp[i] %= (int) (1e9 + 7);
            }
        }
    }
    cout << dp[target] << endl;
}