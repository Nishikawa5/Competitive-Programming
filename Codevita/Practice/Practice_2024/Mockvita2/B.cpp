#include <bits/stdc++.h>
using namespace std;

/*
fails idk why
*/
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
    if (!(zeros && ones) || (m == 0 && n == 0)) {
        cout << "0\n";
    } else {
        string best_str;
        string ones_str(ones, '1');
        string zeros_str(zeros, '0');
        int ans = 0;

        if (n > m) {
            // 111...11000...00
            best_str = ones_str + zeros_str;
        } else {
            // 00...0011...111
            best_str = zeros_str + ones_str;
        }
        
        for (int i = 0; i < (int)str.size(); i++) {
            if (str[i] != best_str[i]) {
                ans++;
            }
        }
        cout << ans << endl;
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
