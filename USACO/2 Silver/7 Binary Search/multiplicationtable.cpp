#include <bits/stdc++.h>
using namespace std;

/*
assume we have a number x

in a row we have elements:
r * 1, r * 2, r * 3, ..., r * n

x >= r * j iff x / r >= j

so to find how many elements in this row are less than x
just get the greatest j s.t. x / r >= j 

*/

#define ll long long
ll first_true(ll hi, ll lo, function<bool(ll)> f) {
    hi++;

    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;

        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main() {
    int n;
    cin >> n;

    ll ans = first_true(1LL * n * n, 1, [&](ll curr_num) {
        ll greater_than = 0;

        for (int r = 1; r <= n; r++) {
            greater_than += min((ll)n, curr_num / r);
        }

        return (n * n) / 2 <= greater_than;
    });

    cout << ans << endl;
}