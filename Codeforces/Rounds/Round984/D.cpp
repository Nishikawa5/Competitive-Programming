#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> steps = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
string desired_str = "1543";

/*
be careful with 1-indexed and 0-indexed
*/
char get_cell_layer(int cell, int layer, vector<string> &carpet) {
    int rows = carpet.size() - layer * 2;
    int cols = carpet[0].size() - layer * 2;

    // 4 possibilities
    if (0 <= cell && cell < cols) {
        return carpet[layer][layer + cell];

    } else if (cols <= cell && cell < cols + rows - 1) {
        return carpet[layer + cell - cols + 1][layer + cols - 1];

    } else if (cols + rows - 1 <= cell && cell < 2 * cols + rows - 2) {
        return carpet[layer + rows - 1][layer + cols - 2 - (cell - cols - rows + 1)];

    } else {
        return carpet[layer + rows - 2 - (cell - 2 * cols - rows + 2)][layer];
    }
}


void solve() {
    int rows, cols;
    cin >> rows >> cols;

    vector<string> carpet(rows);
    for (auto &r: carpet) {
        cin >> r;
    }

    int rotations = min(rows, cols) / 2;
    int ans = 0;
    for (int i = 0; i < rotations; i++) {

        int cells = 2 * (rows - i * 2) + 2 * (cols - i * 2) - 4;

        for (int cell = 0; cell < cells; cell++) {
            bool is_desired = true;

            for (int j = cell; j < cell + desired_str.size(); j++) {
                char curr_cell = get_cell_layer(j % cells, i, carpet);

                if (desired_str[j - cell] != curr_cell) {
                    is_desired = false;
                    break;
                }
            }
            ans += is_desired;
        }
    }
    cout << ans << endl;
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
