#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    string cowpaths;
    cin >> cowpaths;

    int ans = 0;
    // since low constraints, we can check every possible crossing pair
    for (int a1 = 0; a1 < cowpaths.size(); a1++) {
        for (int b1 = a1 + 1; b1 < cowpaths.size(); b1++) {
            for (int a2 = b1 + 1; a2 < cowpaths.size(); a2++) {
                for (int b2 = a2 + 1; b2 < cowpaths.size(); b2++) {
                    // crosspath?
                    ans += (cowpaths[a1] == cowpaths[a2] && cowpaths[b1] == cowpaths[b2]);
                }
            }
        }
    }

    cout << ans << endl;
}