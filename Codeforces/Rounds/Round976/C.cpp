#include <bits/stdc++.h>
using namespace std;

long long first_true(long long lo, long long hi, function<bool(long long)> f) {
    hi++;

    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;

        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

void solve() {
    long long b, c, d;
    cin >> b >> c >> d;
    // increasing

    if ((0 | b) - (0 & c) != d) {
        long long ans = first_true(1, 2305843009213693952 + 1, [&](long long a) {
            return (a | b) - (a & c) >= d;
        });
        cout << (((ans | b) - (ans & c) == d) ? ans : -1) << endl;
    } else {
        cout << 0 << endl;
    }
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}