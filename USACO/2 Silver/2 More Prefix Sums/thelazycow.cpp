#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("lazy.in", "r", stdin);
	freopen("lazy.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    int new_n = 2 * n - 1;
    vector<vector<int>> field(new_n, vector<int>(new_n, 0));

	// read input and store it rotated by 45 degrees
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
            cin >> field[i + j][n - i + j - 1];
        }
	}

    for (int i = 0; i < new_n; i++) {
        for (int j = 0; j < new_n; j++) {
            if (i) {
                field[i][j] += field[i - 1][j];
            }
            if (j) {
                field[i][j] += field[i][j - 1];
            }
            if (i && j) {
                field[i][j] -= field[i - 1][j - 1];
            }
        }
    }

    int64_t max_grass = 0;
    for (int i = k + 1; i < new_n - k; i++) {
        for (int j = k + 1; j < new_n - k; j++) {
            int64_t curr_grass = field[i + k][j + k] - field[i + k][j - k - 1] - 
                                 field[i - k - 1][j + k] + field[i - k - 1][j - k - 1];
            max_grass = max(max_grass, curr_grass);
        }
    }

    if (k >= n) {
        // can reach everything
        max_grass = field[new_n - 1][new_n - 1];
    }

    cout << max_grass << endl;
}