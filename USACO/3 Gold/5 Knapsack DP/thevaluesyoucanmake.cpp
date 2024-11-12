#include <bits/stdc++.h>
using namespace std;

int main() {
    int coins_num, target;
    cin >> coins_num >> target;

    vector<int> coins(coins_num);
    for (auto &c: coins) {
        cin >> c;
    }

    // identify the subset that makes == target
    // coins - this subset => verify


    // get the subset => make every sum w/ this subset
    // store
    // how do we get every subset?
    // dp -> dfs works, better way?
    /*
    dp[i][j][k] == true <=> there exists a subset of 
    first i coins with sum j, that has subset with sum k

    */


    vector<int> dp(target + 1);
    dp[0] = 1;
    
    for (auto c: coins) {
        for (int curr_target = target; curr_target >= 1; curr_target--) {
            if (curr_target - c >= 0) {
                dp[curr_target] += dp[curr_target - c];
            }
        }
    }

    cout << dp[target] << endl;

    for (int i = 0; i <= target; i++) {
        if (dp[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}