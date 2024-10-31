#include <bits/stdc++.h>
using namespace std;

void floodfill(int i, int j, char color, int k, int &count, vector<vector<bool>> &visited, vector<string> &colors) {
    if (i >= 0 && i < colors.size() && j >= 0 && j < 10 && !visited[i][j] && colors[i][j] == color) {
        visited[i][j] = true;
        count++;

        floodfill(i + 1, j, color, k, count, visited, colors);
        floodfill(i, j + 1, color, k, count, visited, colors);
        floodfill(i, j - 1, color, k, count, visited, colors);
        floodfill(i - 1, j, color, k, count, visited, colors);

        if (count >= k) {
            colors[i][j] = '0';
        }
    }
}

int main() {
    freopen("mooyomooyo.in", "r", stdin);
	freopen("mooyomooyo.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<string> colors(n);
    for (auto &c: colors) {
        cin >> c;
    }

    // n * 10 * n * 10 <= 1000000
    bool changed;
    do {
        changed = false;
        // at most n * 10?, can do that
        // while last vector != curr
        // starting visited
        vector<vector<bool>> visited(n, vector<bool>(10, false));

        // point
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {

                if (!visited[i][j] && colors[i][j] != '0') {
                    int count = 0;

                    floodfill(i, j, colors[i][j], k, count, visited, colors);
                    if (count >= k) {
                        changed = true;
                    }
                }
            }
        }

        // apply gravity
        if (changed) {
            for (int j = 0; j < 10; j++) {
                int last_row = n - 1;
                for (int i = n - 1; i >= 0; i--) {
                    if (colors[i][j] != '0') {
                        colors[last_row][j] = colors[i][j];
                        last_row--;
                    }
                }

                for (; last_row >= 0; last_row--) {
                    colors[last_row][j] = '0';
                }
            }
        }

    } while (changed);



    for (auto &c: colors) {
        cout << c << endl;
    }
}