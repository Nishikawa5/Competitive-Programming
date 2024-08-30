#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << fixed << setprecision(9);
    int t;
    cin >> t;

    while (t--) {
        int W, H;
        cin >> W >> H;
        // table
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // another
        int w, h;
        cin >> w >> h;

        // test if it fits in the room
        int ans = INT_MAX;
        if (x2 - x1 + w <= W) {
            // move to the right
            ans = min(ans, max(0, w - x1));
            // move to the left
            ans = min(ans, max(0, x2 - (W - w)));
        }
        if (y2 - y1 + h <= H) {
            // move up
            ans = min(ans, max(0, h - y1));
            // move down
            ans = min(ans, max(0, y2 - (H - h)));
        }
        if (ans == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << double(ans) << endl;
        }
    }
}