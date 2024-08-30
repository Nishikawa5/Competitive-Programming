#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> prefix_sum_2d(1001, vector<int>(1001, 0));
    while (n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        prefix_sum_2d[x1][y1]++;
        prefix_sum_2d[x2][y2]++;
        prefix_sum_2d[x1][y2]--;
        prefix_sum_2d[x2][y1]--;
    }

    // compute the sum of every element in the block we are
    // then see how many coats there are
    int total_k_coats = 0;
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            // assume the left and above elements of prefix array
            // are correctly summed
            if (i) {
                // we can add the sum above
                prefix_sum_2d[i][j] += prefix_sum_2d[i - 1][j];
            }
            if (j) {
                // we can add the sum left
                prefix_sum_2d[i][j] += prefix_sum_2d[i][j - 1];
            }
            if (i && j) {
                // two of same sums have been added
                prefix_sum_2d[i][j] -= prefix_sum_2d[i - 1][j - 1];
            }
            if (prefix_sum_2d[i][j] == k) {
                total_k_coats++;
            }
        }
    }
    cout << total_k_coats << endl;
}