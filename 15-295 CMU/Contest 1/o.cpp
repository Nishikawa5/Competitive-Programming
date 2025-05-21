#include <bits/stdc++.h>
using namespace std;

void solve() {
    int letters;
    string s, t;
    cin >> letters;
    cin >> s >> t;
    
    bool theres_o = false;
    int diff = 0;
    for (int i = 0; i < letters; i++) {
        if (t[i] == 'o') {
            // we can reuse the o to change every s chars to be equal to t
            theres_o = true;
            break;
        }
    }

    if (theres_o) {
        // dont need to check if s == t since we must use at least one operation
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
