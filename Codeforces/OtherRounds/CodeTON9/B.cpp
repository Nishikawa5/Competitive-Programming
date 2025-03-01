#include <bits/stdc++.h>
using namespace std;

#define ll long long



void solve() {
    string str;
    cin >> str;

    // substr of 3 different char or 2 equal char
    for (int i = 2; i < str.size(); i++) {
        // check if the 3 are diff
        if (str[i] != str[i - 1] && str[i] != str[i - 2] && str[i - 1] != str[i - 2]) {
            cout << str.substr(i - 2, 3) << endl;
            return;
        }
    }

    for (int i = 1; i < str.size(); i++) {
        if (str[i] == str[i - 1]) {
            cout << str.substr(i - 1, 2) << endl;
            return;
        }
    }
    cout << -1 << endl;
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
