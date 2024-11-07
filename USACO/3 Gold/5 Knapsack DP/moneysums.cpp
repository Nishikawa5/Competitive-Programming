#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);

    int sum = 0;
    for (auto &c: coins) {
        cin >> c;
        sum += c;
    }

    vector<int> dp(sum + 1);
    int sums = 0;
    dp[0] = 1;
    for (int i = 0; i < coins.size(); i++) {
        // can only use 1 coin of each
        for (int target = sum; target >= 1; target--) {
            // check if this target is possible (order doesnt matter)
            if (target - coins[i] >= 0 && !dp[target]) {
                if (dp[target - coins[i]]) {
                    sums++;
                }
                dp[target] |= dp[target - coins[i]];
            }
        }
    }

    cout << sums << endl;
    for (int i = 1; i <= sum; i++) {
        if (dp[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}