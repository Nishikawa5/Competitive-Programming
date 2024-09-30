#include <bits/stdc++.h>
using namespace std;

#define ll long long

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
    (sum + m) / (2 * n) > x[n / 2]
    =>
    m > x[n / 2] * 2 * n - sum
    and
    x[n / 2] * 2 * n - sum + 1 > x[n / 2] * 2 * n - sum
    =>
    min(m) = x[n / 2] * 2 * n - sum + 1
    */
    cout << max(0LL, money[n / 2] * 2 * n - total_sum + 1) << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}