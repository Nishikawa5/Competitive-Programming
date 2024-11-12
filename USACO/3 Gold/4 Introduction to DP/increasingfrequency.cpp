#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    int max_target_num = 0;
    for (auto &a: arr) {
        cin >> a;
        max_target_num += (a == target);
    }

    /*
    dp[i] == max(number of posterior c's, 
                 number of posterior c's before last a[i]) + 1 (consider this a[i])
    */
    vector<int> dp(5e5 + 1);

    int curr_target_num = 0;
    int max_freq = max_target_num;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            curr_target_num++;
        } else {
            // curr_target_num > dp[arr[i]] =>
            // dont change before i, since changing will give less than not
            // dp[arr[i]] > curr_target_num =>
            // change between the last time curr_target_num was > dp[arr[j]] ans this i
            dp[arr[i]] = max(curr_target_num, dp[arr[i]]) + 1;

            // every dp[i] == target after this i
            int after_target_num = max_target_num - curr_target_num;

            // we changed from j to i or not
            max_freq = max(max_freq, dp[arr[i]] + after_target_num);
        }
    }
    cout << max_freq << endl;
}