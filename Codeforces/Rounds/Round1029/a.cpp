#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    bool activated = false;
    int total_time = 0;

    vector<int> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }

    for (int i = 0; i < n; i++) {
        int state = arr[i];

        if (state == 0) {
            // just pass
        } else if (state == 1 && x > 0) {
            // activate x
            activated = true;
        } else {
            cout << "NO\n";
            return;
        }

        if (activated) {
            x--;
        }
    }
    cout << "YES\n";
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
