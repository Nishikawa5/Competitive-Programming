#include <bits/stdc++.h>
using namespace std;

int main() {
    int coins_num, target;
    cin >> coins_num >> target;

    vector<int> coins(coins_num);
    for (auto &c: coins) {
        cin >> c;
    }

    vector<int> dp(target + 1);
    dp[0] = 1;
    for (auto c: coins) {
        for (int curr = 1; curr <= target; curr++) {            
            if (curr - c >= 0) {
                dp[curr] += dp[curr - c];
                dp[curr] %= (int)1e9 + 7;
            }
        }
    }
    cout << dp[target] << endl;
}