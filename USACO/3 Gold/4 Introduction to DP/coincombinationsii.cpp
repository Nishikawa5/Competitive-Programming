#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    int mod = (int) 1e9 + 7;
    cin >> n >> target;

    vector<int> coins(n);
    for (int &c: coins) {
        cin >> c;
    }

    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    // first add every coin of one type to dont make duplicates
    // note that we not adding in a ordered way, but it works the same way
    // because we want only the number of ways
    for (int &curr_coin: coins) {
        for (int i = 1; i <= target; i++) {
            if (i - curr_coin >= 0) {
                dp[i] += dp[i - curr_coin];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[target] << endl;
}