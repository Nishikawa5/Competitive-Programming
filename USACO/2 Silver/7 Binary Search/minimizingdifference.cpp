#include <bits/stdc++.h>
using namespace std;

#define ll long long
/*
diff <=
F F T T T T ...
*/
ll first_true(ll lo, ll hi, function<bool(ll)> f) {
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
    int n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    for (auto &e: arr) {
        cin >> e;
    }

    sort(arr.begin(), arr.end());
    ll ans = first_true(0, 1e9, [&](ll curr_diff) {
        // check if is possible to get this difference
        ll from_left = arr[0] + curr_diff;
        ll from_right = arr[arr.size() - 1] - curr_diff;

        ll diff_from_left = 0;
        ll diff_from_right = 0;
        for (int i = 0; i < arr.size(); i++) {
            diff_from_left 
        }
    });
}