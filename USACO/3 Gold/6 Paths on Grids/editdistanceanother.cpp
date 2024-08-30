#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string t1, t2;
    cin >> t1 >> t2;
 
    vector<vector<int>> dp(t1.size() + 1, vector<int>(t2.size() + 1));
 
    for (int i = 0; i <= t1.size(); i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= t2.size(); j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= t1.size(); i++) {
        for (int j = 1; j <= t2.size(); j++) {
            if (t1[i - 1] == t2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
    }
    cout << dp[t1.size()][t2.size()] << endl;
}