#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> zero_coord;
    vector<int> one_coord;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if (y) {
            one_coord.push_back(x);
        } else {
            zero_coord.push_back(x);
        }
    }

    sort(one_coord.begin(), one_coord.end());
    sort(zero_coord.begin(), zero_coord.end());

    long long ans = 0;
    for (auto x: one_coord) {
        auto it = lower_bound(zero_coord.begin(), zero_coord.end(), x);

        if (it != zero_coord.end() && *it == x) {
            ans += n - 2;
        }
    }

    for (auto x: one_coord) {
        auto left = lower_bound(zero_coord.begin(), zero_coord.end(), x);
        auto right = upper_bound(zero_coord.begin(), zero_coord.end(), x);

        if (left != zero_coord.begin() && right != zero_coord.end() && 
            *prev(left) == x - 1 && *right == x + 1) {
            ans++;
        }
    }

    for (auto x: zero_coord) {
        auto left = lower_bound(one_coord.begin(), one_coord.end(), x);
        auto right = upper_bound(one_coord.begin(), one_coord.end(), x);

        if (left != one_coord.begin() && right != one_coord.end() && 
            *prev(left) == x - 1 && *right == x + 1) {
            ans++;
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