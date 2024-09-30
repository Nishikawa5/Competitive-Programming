#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    if (k == 1) {
        cout << n << endl;
        return;
    }

    long long copy = n;
    long long max_power = 1;
    while (copy >= k) {
        max_power *= k;
        copy /= k;
    }

    int ans = 0;
    while (n) {
        ans += n / max_power;
        n %= max_power;
        max_power /= k;
    }
    cout << ans << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}