#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> widths(102, 0);
    while (n--) {
        int h, w;
        cin >> h >> w;

        for (int i = 1; i <= h; i++) {
            widths[i] = max(widths[i], w);
        }
    }

    // calc per
    int perimeter = widths[1];
    for (int h = 1; h <= 100; h++) {
        if (widths[h]) {
            perimeter += 2;
        }
        perimeter += widths[h] - widths[h + 1];
    }
    cout << perimeter << endl;
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