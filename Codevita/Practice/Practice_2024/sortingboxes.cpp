#include <bits/stdc++.h>
using namespace std;

void solve() {
    string alphabet;
    string str;
    cin >> alphabet >> str;

    unordered_map<int, int> alphabet_order;
    for (int i = 0; i < alphabet.size(); i++) {
        alphabet_order[alphabet[i]] = i;
    }

    sort(str.begin(), str.end(), [&](char ch1, char ch2) {
        return alphabet_order[ch1] < alphabet_order[ch2];
    });
    cout << str << endl;
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
