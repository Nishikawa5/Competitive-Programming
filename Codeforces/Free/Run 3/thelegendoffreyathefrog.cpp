#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;

    int min_x_moves = x / k + (x % k != 0);
    int min_y_moves = y / k + (y % k != 0);

    // x moves always >= y_moves
    cout << max(min_x_moves, min_y_moves) * 2 - (min_x_moves > min_y_moves) << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}