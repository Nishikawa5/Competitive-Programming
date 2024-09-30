#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll first_true(ll hi, ll lo, function<bool(ll)> f) {
    hi++;

    while (hi > lo) {
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
    int n;
    cin >> n;

    vector<ll> money(n);
    ll total_sum = 0;
    for (auto &m: money) {
        cin >> m;
        total_sum += m;
    }

    if (n <= 2) {
        cout << -1 << endl;
        return;
    }

    sort(money.begin(), money.end());

    /*
    max wealth == 1e6 => (1e6 * 2 + 1) * 2e5 is the max ((max(a) * 2 + 1) * n)
    */
    cout << first_true((money[money.size() - 1] * 2 + 1) * n, 0, [&](ll min_money) {
        /* (x1 + ... + xn + m) / 2n > x1, x2, ..., xn/2 */

        if (total_sum + min_money > money[n / 2] * 2 * n) {
            return true;
        } else {
            return false;
        }
    }) << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}