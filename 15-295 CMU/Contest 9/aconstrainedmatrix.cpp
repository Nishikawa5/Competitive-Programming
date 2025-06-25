#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return;
    } else if (n == 2) {
        cout << -1 << endl;
        return;
    }

    vector<vector<int>> board(n, vector<int>(n));
    int least = 1;
    int greatest = n*n;
    for (int i = 0; i < n*n; i++) {
        if (i % 2 == 0) {
            board[i/n][i%n] = least++;
        } else {
            board[i/n][i%n] = greatest--;
        }
    }

    swap(board[0][0], board[n-1][n-1]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
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
