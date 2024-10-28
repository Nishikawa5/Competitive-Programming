#include <bits/stdc++.h>
using namespace std;

#define ll long long

/*
given a, b and c, get the n-th number that is divisible by two of these 3 in asc order
*/

ll count_exactly_two(ll limit, ll a, ll b, ll c) {
    // least common multiples:
    ll ab = lcm(a, b);
    ll ac = lcm(a, c);
    ll bc = lcm(b, c);
    
    // to subtract
    ll abc = lcm(ab, c);

    // numbers divisible by in this limit
    ll count_ab = limit / ab;
    ll count_ac = limit / ac;
    ll count_bc = limit / bc;

    // div by all three
    ll count_abc = limit / abc;

    // sub by 3 * count_abc because multiples of these 3 are counted 3 times
    // ab | abc, ac | abc, bc | abc
    return count_ab + count_ac + count_bc - 3 * count_abc;
}

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

void solve() {
    ll a, b, c;
    ll n;
    cin >> a >> b >> c >> n;

    ll ans = first_true(1, 1e18, [&](ll limit) {
        return count_exactly_two(limit, a, b, c) >= n;
    });

    cout << ((ans > (ll)1e18) ? -1 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;

    while (tc--) {
        solve();
    }
    return 0;
}