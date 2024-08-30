#include <bits/stdc++.h>
using namespace std;

int main() {
    int large, small;
    while (cin >> large >> small && large && small) {
        getchar();
        vector<vector<bool>> large_polyomino(large, vector<bool>(large));
        for (int i = 0; i < large; i++) {
            for (int j = 0; j < large; j++) {
                large_polyomino[i][j] = (getchar() == '*');
            }
            getchar();
        }

        vector<pair<int, int>> differences;
        differences.push_back({0, 0});
        bool first = false;
        pair<int, int> first_idx;
        for (int i = 0; i < small; i++) {
            for (int j = 0; j < small; j++) {
                if (getchar() == '*') {
                    if (first) {
                        differences.push_back({i - first_idx.first, j - first_idx.second});
                    } else {
                        first_idx.first = i;
                        first_idx.second = j;
                        first = true;
                    }
                }
            }
            getchar();
        }
        int copies = 0;
        for (int i = 0; i < large; i++) {
            for (int j = 0; j < large; j++) {
                if (large_polyomino[i][j]) {
                    // try to compose
                    bool composable = true;
                    for (int k = 0; k < differences.size(); k++) {
                        int curr_i = i + differences[k].first;
                        int curr_j = j + differences[k].second;
                        if (curr_i < 0 || curr_i >= large || curr_j < 0 || curr_j >= large || 
                            !large_polyomino[curr_i][curr_j]) {
                            composable = false;
                            break;
                        }
                    }

                    if (composable) {
                        copies++;
                        for (int k = 0; k < differences.size(); k++) {
                            int curr_i = i + differences[k].first;
                            int curr_j = j + differences[k].second;
                            large_polyomino[curr_i][curr_j] = false;
                        }
                    }
                }
            }
        }

        bool isComposable = true;
        for (int i = 0; i < large; i++) {
            for (int j = 0; j < large; j++) {
                if (large_polyomino[i][j]) {
                    isComposable = false;
                }
            }
        }

        cout << (int) (isComposable && (copies == 2)) << endl;
    }
}