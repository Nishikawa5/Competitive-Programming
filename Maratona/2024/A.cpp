#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    // (k - x) / (x + 1) == n-1
    for (int x = k; x >= 1; x--) {
        if ((k - x) / (x + 1) >= n - 1) {
            cout << x << endl;
            return;
        }
    }
}

int main() {
    solve();
}