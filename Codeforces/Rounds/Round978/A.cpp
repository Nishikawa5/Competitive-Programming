#include <bits/stdc++.h>
using namespace std;

void solve() {
    int members, rows;
    cin >> members >> rows;

    // max pairs

    int ans = 0;

    int total_rows_occupied = 0;
    int rest = 0;
    int total_members = 0;
    for (int i = 0; i < members; i++) {
        int mem;
        cin >> mem;
        total_members += mem;
        int rows_occupied = mem / 2;
        ans += rows_occupied * 2;
        total_rows_occupied += rows_occupied;
        rest += mem % 2;
    }

    // put everyone in the rows and then separe
    total_rows_occupied += rest / 2 + rest % 2;
    ans += rest % 2;
    ans += (rows - total_rows_occupied) * 2;

    cout << min(ans, total_members) << endl;
}


int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}