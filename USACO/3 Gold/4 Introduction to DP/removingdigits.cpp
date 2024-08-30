#include <bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, INT_MAX - 1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int curr_target = i;
        while (curr_target) {
            int digit = curr_target % 10;
            curr_target /= 10;

            if (i - digit >= 0) {
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
        }
    }
    cout << dp[n] << endl;
}