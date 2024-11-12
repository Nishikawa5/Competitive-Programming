#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &n: nums) {
        cin >> n;
    }

    /*
    player takes one number and lose the next
    dp[i][j] == {max score of p1, max score of p2}


    two cases:
        player pick the coin at i:
            dp[i][j].first == dp[i + 1][j].second + nums[i]

        player pick the coin at j
            dp[i][j].first == dp[i][j - 1].second + nums[j]

    => dp[i][j].first == max(dp[i + 1][j].second + nums[i], dp[i][j - 1].second + nums[j])

    j > i: invalid
    i == j: dp[i][j] == {nums[i], 0}
    fill in right -> up ^
    */

    vector<vector<pair<long long, long long>>> max_scores(n, vector<pair<long long, long long>>(n));
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                max_scores[i][j] = {nums[i], 0};
            } else {
                max_scores[i][j].first = max(nums[i] + max_scores[i + 1][j].second,
                                             nums[j] + max_scores[i][j - 1].second);
                max_scores[i][j].second = max_scores[i + 1][j].first + max_scores[i + 1][j].second + nums[i] -
                                          max_scores[i][j].first;
            }
        }
    }
    cout << max_scores[0][n - 1].first << endl;
}