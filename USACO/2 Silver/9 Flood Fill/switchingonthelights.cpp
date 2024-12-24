#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> steps = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void floodfill(int i, int j, int &litted, vector<vector<vector<pair<int, int>>>> &switches, vector<vector<bool>> &visited, vector<vector<int>> &grid) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid.size() || !grid[i][j] || visited[i][j]) {
        return;
    }

    visited[i][j] = true;

    // lit every light
    for (auto &s: switches[i][j]) {
        if (!grid[s.first][s.second]) {
            litted++;
            grid[s.first][s.second] = 1;

            for (int k = 0; k < 4; k++) {
                int x = s.first + steps[k].first;
                int y = s.second + steps[k].second;
                if (grid.size() > x && x >= 0 &&
                    grid.size() > y && y >= 0 &&
                    visited[x][y]) {
                    
                    // could have floodfilled s.first, s.second and break instead
                    visited[x][y] = false;
                    floodfill(x, y, litted, switches, visited, grid);
                }
            }
        }
    }

    floodfill(i + 1, j, litted, switches, visited, grid);
    floodfill(i - 1, j, litted, switches, visited, grid);
    floodfill(i, j + 1, litted, switches, visited, grid);
    floodfill(i, j - 1, litted, switches, visited, grid);
}



void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<bool>> visited(n, vector<bool>(n));
    vector<vector<vector<pair<int, int>>>> switches(n, vector<vector<pair<int, int>>>(n));

    grid[0][0] = 1;

    while (m--) {
        int from_a, from_b, to_a, to_b;
        cin >> from_a >> from_b >> to_a >> to_b;

        switches[from_a - 1][from_b - 1].push_back({to_a - 1, to_b - 1});
    }

    int litted = 1;
    
    floodfill(0, 0, litted, switches, visited, grid);

    cout << litted << endl;
}


int main() {
    freopen("lightson.in", "r", stdin);
	freopen("lightson.out", "w", stdout);

    int tc;
    tc = 1;

    while (tc--) {
        solve();
    }
}