#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    // find the sorted seq
    int sorted = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] > s[i-1]) {
            sorted++;
        } else {
            sorted = 1;
        }
    }
    cout << s.size() - sorted << endl;
}

int main() {
    solve();
}