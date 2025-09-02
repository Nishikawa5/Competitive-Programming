#include <bits/stdc++.h>
using namespace std;

bool is_possible(int n, int k) {
    int y = n - 2*k;
    int x = (n - 3*y)/2;

    if (2*x + 3*y == n && x >= 0 && y >= 0) {
        while (x--) {
            cout << "X-";
        }
        while (y--) {
            cout << "-X-";
        }
        return true;
    }
    return false;
}

void solve() {
    int k, n;
    cin >> k >> n;

    // 2 6
    // - x - - x -

    // 2 type of moves:
    // - x -
    // x -
    // x iff last

    // can we sum
    // 2x + 3y = n, where x + y == k?
    // 2k + y = n
    // y = n - 2k

    // 2 cases:
    // matches the above
    // 1 for n-1, k-1 -> output X last
    if (is_possible(n, k)) {
        cout << endl;
        return;
    } else if (is_possible(n-1, k-1)) {
        cout << "X" << endl;
        return;
    } else {
        cout << "*\n";
    }
}

int main() {
    solve();
}