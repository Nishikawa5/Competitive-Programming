#include <bits/stdc++.h>
using namespace std;

bool compare(string &a, string &b, int i) {
    int j = 0;
    for (auto &c: a) {
        if (b[i + j++] == c) {
            return false;
        }
    }
    return true;
}

void solve() {
    string cip, crib;
    cin >> cip >> crib;

    int ans = 0;
    for (int i = 0; i < cip.size() - crib.size() + 1; i++) {
        if (compare(crib, cip, i)) {
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    solve();
}