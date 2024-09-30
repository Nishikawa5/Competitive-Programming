#include <bits/stdc++.h>
using namespace std;

void solve() {
    int travelers, time;
    cin >> travelers >> time;

    vector<int> travelers_time(travelers);
    int min_travel = INT_MAX;
    for (auto &t: travelers_time) {
        cin >> t;
        min_travel = min(min_travel, t);
    }

    if (((long long) min_travel) * (2 * max((long long) travelers - 2, 0LL) + 1) <= (long long) time) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}