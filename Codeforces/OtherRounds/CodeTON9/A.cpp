#include <bits/stdc++.h>
using namespace std;

void solve() {
    // mods: 1, 2, 3, 4, ...
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << i - 1 + i << " ";
    }
    cout << "\n";
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
