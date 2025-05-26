#include <bits/stdc++.h>
using namespace std;

void solve() {
    int year;
    cin >> year;

    int sqrty = sqrt(year);
    if (sqrty*sqrty == year) {
        cout << sqrty << " " << 0 << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
    return 0;
}
