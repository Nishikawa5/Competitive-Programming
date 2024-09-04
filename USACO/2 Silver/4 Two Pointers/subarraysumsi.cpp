#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }

    // sliding window
    long long sum = 0;
    int ans = 0;
    for (int l = 0, r = 0; r < n; r++) {
        sum += arr[r];
        while (sum > target) {
            sum -= arr[l++];
        } 

        if (sum == target) {
            ans++;
        }
    }
    cout << ans << endl;
}