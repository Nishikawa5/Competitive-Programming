#include <bits/stdc++.h>
using namespace std;

void solve() {
    string str;
    cin >> str;

    int n, m;
    cin >> n >> m;


    int zeros = 0;
    int ones = 0;
    // check if is a valid string
    for (auto c: str) {
        if (c != '0' && c != '1') {
            cout << "INVALID\n";
            return;
        }
        zeros += (c == '0');
        ones += (c == '1');
    }

    // the solution string is either
    // 1111...110...000 or 0000...000111...111
    if (!(zeros && ones)) {
        cout << "0\n";
    } else {
        int ans = 0;
        if (n > m) {
            // 111...11000...00
            for (int i = 0; i < ones; i++) {
                ans += (str[i] == '0');
            }

            for (int i = ones; i < (int)str.size(); i++) {
                ans += (str[i] == '1');
            }

        } else {
            // 00...0011...111
            for (int i = 0; i < zeros; i++) {
                ans += (str[i] == '1');
            }

            for (int i = zeros; i < (int)str.size(); i++) {
                ans += (str[i] == '0');
            }
        }
        cout << ans << "\n";
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
