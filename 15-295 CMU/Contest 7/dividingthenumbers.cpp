#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n == 2) {
        cout << 1 << endl;
        cout << 1 << " " << 1;
        return;
    } else if (n % 2) {
        cout << n/2 + 1 << endl;
    } else {
        cout << 0 << endl;
    }

    cout << n/2;
    int idx = 1;
    for (int i = 1; i <= n / 2; i += 2) {
        cout << " " << idx;
        cout << " " << n - idx + 1;
    }
    cout << endl;
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
