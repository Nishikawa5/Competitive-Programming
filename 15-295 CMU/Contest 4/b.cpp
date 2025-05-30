#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    for (auto &s: grid) {
        cin >> s;
    }

    vector<vector<int>> count(n, vector<int>(m));
    int max_cells = 0;
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == '#') break;
        count[i][0] = i+1;
        max_cells = max(max_cells, count[i][0]);
    }

    for (int i = 0; i < m; i++) {
        if (grid[0][i] == '#') break;
        count[0][i] = i+1;
        max_cells = max(max_cells, count[0][i]);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (grid[i][j] == '.' && (count[i-1][j] || count[i][j-1])) {
                count[i][j] = max(count[i - 1][j], count[i][j - 1]) + 1;
                max_cells = max(max_cells, count[i][j]);
            }
        }
    }
    cout << max_cells << endl;
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
