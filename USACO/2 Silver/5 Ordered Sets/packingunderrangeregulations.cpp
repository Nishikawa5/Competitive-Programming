#include <bits/stdc++.h>
using namespace std;

void solve() {
    int balls_num;
    cin >> balls_num;

    vector<pair<int, int>> interval(balls_num);
    for (auto &p: interval) {
        cin >> p.first >> p.second;
    }

    sort(interval.begin(), interval.end());
    int last_used = 0;

    for (int i = 0; i < interval.size(); i++) {
        if (last_used < interval[i].first) {
            last_used = interval[i].first;
        } else {
            last_used++;

            if (last_used > interval[i].second) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    };
}