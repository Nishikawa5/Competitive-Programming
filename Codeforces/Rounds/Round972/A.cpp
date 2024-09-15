#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string vowels = "aeiou";
    int each = n / 5;
    int rest = n % 5;

    for (int i = 0; i < 5; i++) {
        int total = each + (rest-- > 0);
        for (int j = 0; j < total; j++) {
            cout << vowels[i];
        }
    }

    cout << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}