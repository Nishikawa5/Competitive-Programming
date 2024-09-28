#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    // get the maximum
    // check if it is in odd pos
    int max_a = 0;
    int pos;
    int ans;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (max_a < a) {
            max_a = a;
            pos = i;
        } else if (max_a == a) {
            if (i % 2 == 0) {
                // even position
                pos = i;
            }
        }
    }

    if (n % 2) {
        // odd number
        if (pos % 2) {
            ans = max_a + n / 2;
        } else {
            ans = max_a + n / 2 + 1;
        }
    } else {
        ans = max_a + n / 2;
    }
    cout << ans << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}