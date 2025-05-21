#include <bits/stdc++.h>
using namespace std;

#define ll long long

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
    ll machines_num, teddy_num;
    cin >> machines_num >> teddy_num;

    // assume a time t, check if is possible to make teddy_num bears with the machines
    vector<ll> times(machines_num);

    for (auto &t: times) {
        cin >> t;
    }

    // maximum 1e9*1e9 = 1e18
    ll ans = first_true(1, 1e18, [&](ll min_time) {
        ll made_teddy = 0;

        for (auto t: times) {
            made_teddy += min_time / t;
            
            // careful with long overflow
            if (made_teddy >= teddy_num) {
                return true;
            }
        }
        return false;
    });

    cout << ans << endl;
}