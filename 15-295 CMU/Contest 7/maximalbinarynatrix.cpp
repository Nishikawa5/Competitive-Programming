#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    if (k > n*n) {
        cout << -1 << endl;
        return;
    }
    if (k == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << 0 << " ";
            }
            cout << endl;
        }
        return;
    }


    vector<vector<int>> matrix(n, vector<int>(n));
    // fill the rows
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                k--;
                matrix[i][j] = 1;
            } else {
                k -= 2;
                matrix[i][j] = 1;
                matrix[j][i] = 1;
            }

            if (k == -1 || k == 0) {
                if (k == -1) {
                    // erase last middle (i, i) or
                    // put in the position
                    if (i != n-1) {
                        matrix[j][i] = 0;
                        matrix[i][j] = 0;
                        matrix[i+1][i+1] = 1;
                    } else {
                        matrix[i][i] = 0;
                    }
                }

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        cout << matrix[i][j] << " ";
                    }
                    cout << endl;
                }
                return;
            }
        }
    }
    cout << -1 << endl;
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
