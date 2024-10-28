#include <bits/stdc++.h>
using namespace std;

/*
go from min to max

*/
#define ll long long

void solve() {
    int n;
    cin >> n;

    vector<pair<ll, int>> arr(n);
    int idx = 0;
    for (auto &a: arr) {
        cin >> a.first;
        a.first += idx;
        a.second = idx;
    }

    sort(arr.begin(), arr.end());

    vector<bool> lengths(1e6);
    lengths[n] = true;

    ll max_length = n;
    for (int i = n; i < lengths.size(); i++) {
        if (!lengths[i]) continue;

        auto it = lower_bound(arr.begin(), arr.end(), make_pair((ll)i, 0));
        if (it == arr.end() || (*it).first != i) continue;

        ll first = (*it).first;

        for (; (*it).first == first; it++) {
            lengths[i + (*it).second] = true;
            max_length = max(max_length, (*it).second + first);
        }
    }

    cout << max_length << endl;
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