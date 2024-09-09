#include <bits/stdc++.h>
using namespace std;

/*
~15
*/
void solve() {
    int n;
    cin >> n;

    vector<long long> cells(n + 1);
    cells[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> cells[i];
        cells[i] += cells[i - 1];
    }
    string lrs;
    cin >> lrs;

    long long total_sum = 0;
    for (int l = 0, r = n - 1; l < r;) {
        if (lrs[l] != 'L') {
            l++;
        }
        if (lrs[r] != 'R') {
            r--;
        }

        if (lrs[l] == 'L' && lrs[r] == 'R') {
            total_sum += cells[r + 1] - cells[l];
            l++;
            r--;
        }
    }
    cout << total_sum << endl;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}