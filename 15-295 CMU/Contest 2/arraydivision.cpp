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
    ll n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }


    // assume a number that is the max find first true
    ll ans = first_true(1, 2e14, [&](ll max_sum){
        
        ll subarray_sum = 0;
        ll overflow = 1;
        for (auto &a: arr) {

            if (a > max_sum || overflow > k) {
                return false;
            }

            subarray_sum += a;

            if (subarray_sum > max_sum) {
                overflow++;
                subarray_sum = a;
            }

        }

        return overflow <= k;
    });

    cout << ans << endl;
}