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
    int i = 0;
    for (auto &a: arr) {
        cin >> a.first;
        a.first += i;
        a.second = i;
    }

    sort(arr.begin(), arr.end());

    set<int> lengths;
    lengths.insert(n);

    ll max_length = n;
    set<int> curr_lengths;
    curr_lengths.insert(n);
    while(!curr_lengths.empty()) {


        auto it = lower_bound(arr.begin(), arr.end(), make_pair((ll)n, INT_MIN));
        if ((*it).first != i) continue;

        if (it != arr.end()) {
            ll first = (*it).first;

            for (; (*it).second == first; it++) {
                lengths[i + (*it).first] = true;
                max_length = max(max_length, i + (*it).first);
            }
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