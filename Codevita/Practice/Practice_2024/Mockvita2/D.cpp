#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve() {
    int n, m, k;
    cin >> n >> m;

    vector<vector<int>> cells(n, vector<int>(m));
    vector<vector<ll>> scores(n, vector<ll>(m, 0));
    for (auto &r: cells) {
        for (auto &s: r) {
            cin >> s;
        }
    }
    cin >> k;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i && cells[i - 1][j] <= cells[i][j]) {
                // unique ways to go to cell (i - 1, j) + 1
                scores[i][j] += scores[i - 1][j] + 1;
            }
            if (j && cells[i][j - 1] <= cells[i][j]) {
                scores[i][j] += scores[i][j - 1] + 1;
            }
            
            if (scores[i][j] == k) {
                cout << i << " " << j << "\n";
                ans++;
            }
        }
    }
    if (!ans) {
        cout << "NO\n";
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
