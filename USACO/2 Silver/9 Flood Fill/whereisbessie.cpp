#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> steps = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void floodfill(int i, int j, char c1, char c2, bool &c1_covered, bool &c2_covered, vector<vector<bool>> &visited, vector<string> &grid) {
    if (i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size() && 
        (grid[i][j] == c1 || grid[i][j] == c2) && !visited[i][j]) {

        if (grid[i][j] == c1) {
            c1_covered = true;
        } else {
            c2_covered = true;
        }

        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int curr_i = i + steps[k].first;
            int curr_j = j + steps[k].second;
            
            floodfill(curr_i, curr_j, c1, c2, c1_covered, c2_covered, visited, grid);
        }
    }
}

int main() {
    int n;
    vector<char> colors(26);
    for (int i = 0; i < 26; i++) {
        colors[i] = i + 'A';
    }

    vector<string> grid(n);

    for (auto &g: grid) {
        cin >> g;
    }

    // make every combination and see if it forms a thing
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            // check if this combination form a rectangle
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    // how to check if we have a rectangle?
                    // most left, most right, most up, most down -> 
                    // count the number of visited
                    if (!visited[k][l]) {
                        bool c1_covered = false;
                        bool c2_covered = false;
                        floodfill(k, l, colors[i], colors[j], visited, grid);

                        // check if there's a square formed with this coordinate
                        if (c1_covered && c2_covered) {
                            for (int )
                        }
                    }
                }
            }


        }
    }
}