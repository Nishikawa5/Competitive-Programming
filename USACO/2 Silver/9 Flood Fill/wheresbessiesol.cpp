#include <bits/stdc++.h>
using namespace std;

void floodfill(int i, int j, int i_min, int i_max, int j_min, int j_max, 
               char color, vector<vector<bool>> &visited, vector<vector<char>> &grid) {
    // bounded since it can go out of bounds then in bound after
    if (i >= i_min && j >= j_min && i <= i_max && j <= j_max && grid[i][j] == color && !visited[i][j]) {
        visited[i][j] = true;

        floodfill(i + 1, j, i_min, i_max, j_min, j_max, color, visited, grid);
        floodfill(i - 1, j, i_min, i_max, j_min, j_max, color, visited, grid);
        floodfill(i, j + 1, i_min, i_max, j_min, j_max, color, visited, grid);
        floodfill(i, j - 1, i_min, i_max, j_min, j_max, color, visited, grid);
    }
}

bool is_pcl(int x1, int y1, int x2, int y2, vector<vector<char>> &grid) {
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size()));
    vector<int> count_colors(26, 0);

    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (!visited[i][j]) {
                // get the colors of this square
                char curr_color = grid[i][j];
                count_colors[curr_color - 'A']++;
                floodfill(i, j, x1, x2, y1, y2, curr_color, visited, grid);
            }
        }
    }

    int colors_present = 0;
    bool one_contiguous_region = false;
    bool two_or_more_contiguous_region = false;
    for (int i = 0; i < 26; i++) {
        if (count_colors[i] > 0) {
            // this color is present
            colors_present++;
        }
        if (count_colors[i] == 1) {
            // this color forms one_contiguous_region
            one_contiguous_region = true;
        }
        if (count_colors[i] > 1) {
            // this color forms two_or_more_contiguous_region
            two_or_more_contiguous_region = true;
        }
    }
    return colors_present == 2 && one_contiguous_region && two_or_more_contiguous_region;
}

int main() {
    freopen("where.in", "r", stdin);
	freopen("where.out", "w", stdout);    

    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // every possible rectangle
    vector<pair<pair<int, int>, pair<int, int>>> pcls;
    for (int x1 = 0; x1 < n; x1++) {
        for (int x2 = x1; x2 < n; x2++) {
            for (int y1 = 0; y1 < n; y1++) {
                for (int y2 = y1; y2 < n; y2++) {
                    if (is_pcl(x1, y1, x2, y2, grid)) {
                        pcls.push_back({{x1, y1}, {x2, y2}});
                    }
                }
            }
        }
    }

    // check if this pcl is not subpcl of any pcl
    int ans = 0;
    for (int i = 0; i < pcls.size(); i++) {
        bool is_inside = true;
        for (int j = 0; j < pcls.size(); j++) {
            if (i == j) continue;
            if (pcls[j].first.first <= pcls[i].first.first && pcls[i].second.first <= pcls[j].second.first &&
                pcls[j].first.second <= pcls[i].first.second && pcls[i].second.second <= pcls[j].second.second) {
            
                is_inside = false;
                break;
            }
        }
        ans += is_inside;
    }
    cout << ans << endl;
}