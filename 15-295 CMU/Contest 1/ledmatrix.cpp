#include <bits/stdc++.h>
using namespace std;

void solve() {
    int r, c1, c2;
    cin >> r >> c1 >> c2;

    // we just check if there's a led that needs to be activated and a broken led
    string p, m;
    bool is_possible = true;
    while (r--) {
        cin >> p >> m;
        // broken led in p?
        bool broken = false;
        for (auto l: p) {
            if (l == '-') {
                broken = true;
                break;
            }
        }

        // activated led in m?
        bool activated = false;
        for (auto l: m) {
            if (l == '*') {
                activated = true;
                break;
            }
        }

        if (broken && activated) {
            is_possible = false;
        }
    }
    
    if (is_possible) {
        cout << "Y\n";
    } else {
        cout << "N\n";
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
