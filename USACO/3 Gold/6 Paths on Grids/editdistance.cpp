#include <bits/stdc++.h>
using namespace std;

int main() {
    string t1, t2;
    cin >> t1 >> t2;

    /*
    Interpret this vector as being a function that requires dp[i][j] number of moves to
    make the substring t1(0, i + 1) == t1(0, j + 1) 
    */
    vector<vector<int>> dp(t1.size() + 1, vector<int>(t2.size() + 1, INT_MAX));
    dp[0][0] = 0;
    for (int i = 0; i <= t1.size(); i++) {
        for (int j = 0; j <= t2.size(); j++) {
            if (i) {
                // delete the letter i from string t2
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            }
            if (j) {
                // delete the letter j from string t2
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
            if (i && j) {
                // make the letter i == letter j (by changing it or already is)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (t1[i - 1] != t2[j - 1]));
            }
        }
    }
    cout << dp[t1.size()][t2.size()] << endl;
}