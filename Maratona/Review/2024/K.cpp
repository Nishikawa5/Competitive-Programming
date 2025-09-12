#include <bits/stdc++.h>
using namespace std;

int main() {
    // possible iff the sum is even
    // and sum / 2 is possible
    int n;
    cin >> n;

    vector<int> arr(n);
    int sum = 0;
    for (auto &a: arr) {
        cin >> a;
        sum += a;
    }

    if (sum % 2) {
        cout << -1 << endl;
        return 0;
    }

    // check if it is possible
    int target = sum/2;

    vector<int> dp(target+1);
    dp[0] = 1;
    for (auto &c: arr) {
        for (int i = target; i >= c; i--) {
            dp[i] += dp[i - c];
        }
    }

    if (!dp[target]) {
        cout << -1 << endl;
        return 0;
    }

    // now find the set that results in this sum
    vector<int> sum_set;
    int curr_sum = 0;
    while (curr_sum != target) {
        int curr_target = target - curr_sum;
        vector<int> dp(curr_target+1);


        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            int c = arr[i];
            for (int i = curr_target; i >= c; i--) {
                dp[i] += dp[i - c];
            }

            if (dp[curr_target]) {
                sum_set.push_back(c);
                arr[i] = 0;
                curr_sum += c;
                break;
            }
        }
    }

    int total_sum = 0;
    int i1 = 0;
    int i2 = 0;

    int alice = 0;
    int bob = 0;
    while (alice + bob != target*2) {
        if (alice <= bob) {
            alice += sum_set[i1];
            cout << sum_set[i1++] << " ";
        } else {
            if (arr[i2]) {
                bob += arr[i2];
                cout << arr[i2++] << " ";
            } else {
                i2++;
            }
        }
    }
    cout << endl;
}