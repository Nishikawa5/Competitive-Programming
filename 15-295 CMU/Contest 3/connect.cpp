#include <bits/stdc++.h>
using namespace std;

void solve() {
    // traverse at most 2 roads
    // minimum number of roads

    // n/2 > m => we have at least one node that won't have restriction (tricky)
    // n => m < n/2 => max(m) = n/2-1 and (n/2-1) * 2 = n-2 < n
    int n, m;
    cin >> n >> m;

    vector<bool> blocked(n, false);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        blocked[from-1] = true;
        blocked[to-1] = true;
    }

    int center = -1;
    for (int i = 0; i < n; i++) {
        if (!blocked[i]) {
            center = i;
            break;
        }
    }

    cout << n-1 << endl;
    for (int i = 0; i < n; i++) {
        if (i != center) {
            cout << center+1 << " " << i+1 << endl;
        }
    }
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
