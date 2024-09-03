#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int maxN = 2500;

    // real coordinates
    vector<pair<int, int>> compressed(n);
    for (auto &c: compressed) {
        cin >> c.first >> c.second;
    }

    // compress the coordinates
    sort(compressed.begin(), compressed.end());
    for (int i = 0; i < n; i++) {
        compressed[i].first = i;
    }
    sort(compressed.begin(), compressed.end(), [&](pair<int, int> c1, pair<int, int> c2) {
        return c1.second < c2.second;
    });
    for (int i = 0; i < n; i++) {
        compressed[i].second = i;
    }

    // mark
    vector<vector<int>> compressed_cells(maxN + 1, vector<int>(maxN + 1));
    for (int i = 0; i < n; i++) {
        compressed_cells[compressed[i].first][compressed[i].second]++;
    }

    // prefix sum
    for (int i = 1; i <= maxN; i++) {
        for (int j = 1; j <= maxN; j++) {
            compressed_cells[i][j] += compressed_cells[i - 1][j - 1] - 
                                      compressed_cells[i - 1][j] - compressed_cells[i][j - 1];
        }
    }

    
}