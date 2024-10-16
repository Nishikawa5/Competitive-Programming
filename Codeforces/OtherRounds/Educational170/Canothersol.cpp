#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> cards(n);

    for (auto &c: cards) {
        cin >> c;
    }

    sort(cards.begin(), cards.end());

    int ans = 0;
    for (int l = 0, r = 0; l < n; l++) {
        // avoid recomputation
        r = max(l, r);

        // will the next card break the conditions?
        while (r + 1 < n && cards[r + 1] - cards[r] <= 1 && cards[r + 1] - cards[l] < k) {
            // dont break so consider the next
            r++;
        }
        ans = max(r - l + 1, ans);
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
