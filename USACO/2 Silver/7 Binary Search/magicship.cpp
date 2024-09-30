#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll first_true(ll lo, ll hi, function<bool(ll)> f) {
    hi++;

    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;

        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid +1;
        }
    }
    return lo;
}


void solve() {
    pair<ll, ll> start;
    pair<ll, ll> end;
    cin >> start.first >> start.second >> end.first >> end.second;

    int n;
    string moves;
    cin >> n >> moves;

    ll max_moves = LONG_LONG_MAX - 1;
    ll ans = first_true(0, max_moves, [&](ll curr_time) {
        // add the cycles
        ll add_eq = curr_time / moves.size();
        ll add_rest = curr_time % moves.size();
        pair<ll, ll> curr_coord = start;

        for (auto &c: moves) {
            if (c == 'U') {
                curr_coord.second += add_eq + (add_rest-- > 0);
            } else if (c == 'D') {
                curr_coord.second -= add_eq + (add_rest-- > 0);
            } else if (c == 'R') {
                curr_coord.first += add_eq + (add_rest-- > 0);
            } else {
                curr_coord.first -= add_eq + (add_rest-- > 0);
            }
        }

        return curr_time >= abs(curr_coord.first - end.first) + abs(curr_coord.second - end.second);
    });
    cout << ((ans == max_moves + 1) ? -1 : ans) << endl;
}

int main() {
    int tc;
    tc = 1;

    while (tc--) {
        solve();
    }
}