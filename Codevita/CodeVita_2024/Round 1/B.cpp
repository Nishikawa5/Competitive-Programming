#include <bits/stdc++.h>
using namespace std;

/* WA? */
void solve() {
    int n;
    cin >> n;

    vector<char> moves(n);
    for (int i = 0; i < n; i++) {
        string move;
        cin >> move;

        moves[i] = move[0];
    }

    // find first different move
    char legs[2];
    legs[0] = moves[0];
    
    int idx = 1;
    while (idx < (int)moves.size() && moves[idx] == legs[0]) {
        idx++;
    }

    if (idx == (int)moves.size()) {
        cout << 0 << endl;
        return;
    }

    // found the move
    legs[1] = moves[idx];
    int count = 0;
    for (int i = idx + 1; i < (int)moves.size(); i++) {
        cout << legs[0] << " " << legs[1] << endl;
        if (moves[i] == legs[0] || moves[i] == legs[1]) continue;

        // which leg should go for this move?
        // count till the next change
        int l1 = 0;
        int l2 = 0;
        for (int j = i + 1; j < (int)moves.size(); j++) {
            if (moves[j] == legs[0]) {
                l1++;
            } else if (moves[j] == legs[1]) {
                l2++;
            } else {
                break;
            }
        }
        if (l1 > l2) {
            // change leg 2
            legs[1] = moves[i];
        } else if (l1 < l2) {
            legs[0] = moves[i];
        } else {
            // which appears more
            l1 = 0;
            l2 = 0;
            for (int j = i + 1; j < (int)moves.size(); j++) {
                l1 += (moves[j] == legs[0]);
                l2 += (moves[j] == legs[1]);
            }
            if (l1 > l2) {
                // change leg 2
                legs[1] = moves[i];
            } else {
                legs[0] = moves[i];
            }
        }
        count++;
    }
    cout << count << endl;
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