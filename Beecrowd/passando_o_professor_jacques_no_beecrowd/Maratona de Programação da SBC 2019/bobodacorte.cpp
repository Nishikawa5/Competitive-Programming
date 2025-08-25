#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int carlos;
    bool elected = true;
    cin >> carlos;
    for (int i = 1; i < n; i++) {
        int votes;
        cin >> votes;

        if (votes > carlos) {
            elected = false;
        }
    }
    if (elected) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;

    while (tc--) {
        solve();
    }
    return 0;
}
