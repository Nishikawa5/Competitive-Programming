#include <bits/stdc++.h>
using namespace std;

void solve() {
    int fruits, pib, bps;
    cin >> fruits >> pib >> bps;

    int ans = ceil(fruits / (double) min(pib, bps));
    cout << ans << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}