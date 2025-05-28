#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> arr;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    // dp[number of numbers we are summing][sum] = quantity of this sum
    vector<unordered_map<int, long long>> dp(5);
    dp[0][0] = 1;
    for (int x: arr) {
        // we use this number
        // note that we are not considering different x positions

        for (int k = 3; k >= 0; k--) {
            // and add it to the sum of k numbers

            for (auto &[sum, possible_sums]: dp[k]) {
                // for every sum we currently have
                dp[k + 1][sum + x] += possible_sums;
            }
        }
    }


    
    int num;
    cin >> num;

    while (num--) {
        int target;
        cin >> target;
        cout << dp[4][target] << endl;
    }
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
