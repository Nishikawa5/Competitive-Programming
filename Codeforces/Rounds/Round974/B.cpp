#include <bits/stdc++.h>
using namespace std;

void solve() {
    int year, lasts;
    cin >> year >> lasts;

    // year odd => i^i odd
    // odd even/even odd
    
    int start = year - lasts + 1;
    int end = year;

    // 1 4 27 64

    // starts at odd => odd pairs
    //          even => even pairs

    if (start % 2) {
        int diff = end - start + 1;
        diff -= 3;

        if (diff >= 0 && (diff % 4 == 0 || diff % 4 == 1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        int diff = end - start + 1;

        if ((diff % 4 == 0 || diff % 4 == 1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}