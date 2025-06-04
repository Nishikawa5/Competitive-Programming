#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> arr(n);

    for (auto &a: arr) {
        cin >> a;
    }

    long long sum = 0;

    // stores the number of sums from 0 to i that has the index sum%n
    // sum[0:i] - sum[0:j] == sum[j+1:i] for i>=j and
    // sum[0:i]%n - sum[0:j]%n == 0 iff sum[j+1:i]%n == 0
    vector<int> rest_prefix(n);
    rest_prefix[0] = 1;
    int ans = 0;
    for (auto &a: arr) {
        sum += a;
        ans += rest_prefix[((sum % n) + n) % n];
        rest_prefix[((sum % n) + n) % n]++;
    }
    cout << ans << endl;
}

int main() {
    solve();
}