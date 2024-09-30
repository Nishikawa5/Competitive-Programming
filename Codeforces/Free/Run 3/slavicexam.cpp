#include <bits/stdc++.h>
using namespace std;

void solve() {
    string str, substr;
    cin >> str >> substr;

    int curr_sub = 0;
    for (char &c: str) {
        if (substr[curr_sub] == c) {
            curr_sub++;
        } else if (c == '?') {
            if (curr_sub < substr.size()) {
                c = substr[curr_sub++];
            } else {
                c = 'a';
            }
        }
    }

    if (curr_sub >= substr.size()) {
        cout << "YES\n";
        cout << str << endl;
    } else {
        cout << "NO\n";
    }
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}