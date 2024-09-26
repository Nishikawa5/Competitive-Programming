#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, threshhold;
    cin >> n >> threshhold;

    // dont go back?
    int gold = 0;
    int ans = 0;
    while (n--) {
        int curr_gold;
        cin >> curr_gold;

        if (curr_gold >= threshhold) {
            gold += curr_gold;
        }

        if ((curr_gold == 0) && (gold > 0)) {
            ans++;
            gold--;
        }
    }

    cout << ans << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}