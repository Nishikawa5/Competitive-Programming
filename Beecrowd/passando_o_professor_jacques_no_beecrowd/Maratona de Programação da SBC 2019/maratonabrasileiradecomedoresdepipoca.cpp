#include <bits/stdc++.h>
using namespace std;

int first_true(int lo, int hi, function<bool(int)> f) {
    hi++;

    while (hi > lo) {
        int mid = lo + (hi - lo) / 2;

        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    
    return lo;
}

void solve() {
    int bags, competitors, pps;
    cin >> bags >> competitors >> pps;

    vector<int> popcorns(bags);
    for (auto &p: popcorns) {
        cin >> p;
    }

    // nlogn works
    // binary search on time

    int ans = first_true(1, 1e9 + 5, [&](int max_time) {


        // competitors needed to eat every bag in max_time seconds
        int comp = 1;

        int prefix = 0;
        for (int i = 0; i < bags; i++) {
            if ((popcorns[i] + pps - 1) / pps > max_time) {
                // not possible to eat that bag
                return false;
            }

            prefix += popcorns[i];

            if ((prefix + pps-1) / pps > max_time) {
                // need one more competitpr
                comp++;
                prefix = popcorns[i];
            }
        }

        return comp <= competitors;
    });

    cout << ans << endl;
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
