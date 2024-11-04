#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    bool isPerfect = true;
    int last;
    int curr;
    cin >> last;
    for (int i = 1; i < n; i++) {
        cin >> curr;

        if (abs(curr - last) != 5 && abs(curr - last) != 7) {
            isPerfect = false;
        }
        last = curr;
    }

    if (isPerfect) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
