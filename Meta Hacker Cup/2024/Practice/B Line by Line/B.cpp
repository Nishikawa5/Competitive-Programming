#include <bits/stdc++.h>
using namespace std;

void solve() {
    int lines;
    double probability;
    cin >> lines >> probability;

    double ans = probability * (pow(probability / 100, -1 / (double) lines) - 1);
    cout << ans << endl;
}

int main() {
    int tc;
    cin >> tc;

    cout << fixed << setprecision(10);
    for (int i = 1; i <= tc; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}