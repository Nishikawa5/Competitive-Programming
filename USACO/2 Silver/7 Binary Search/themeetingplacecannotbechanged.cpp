#include <bits/stdc++.h>
using namespace std;

#define ll long long

int first_true(int lo, int hi, function<bool(int)> f) {
    hi++;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

pair<ll, ll> calculate_interval(int friend_pos, int speed, int time) {
    pair<ll, ll> ans = {(ll)friend_pos - 1LL * speed * time, (ll)friend_pos + 1LL * speed * time};   
    return ans;
}

int main() {
    int n;

    cin >> n;

    vector<int> friends(n);
    vector<int> speeds(n);

    for (auto &f: friends) {
        cin >> f;
    }

    for (auto &s: speeds) {
        cin >> s;
    }

    int min_time = first_true(0, 1e9, [&](int time) {
        // check if is possible to meet at this time
        // how to check if everyone can meet
        // separe in intervals?
        ll left_bound = LLONG_MIN;
        ll right_bound = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            pair<ll, ll> interval = calculate_interval(friends[i], speeds[i], time);

            left_bound = max(left_bound, interval.first);
            right_bound = min(right_bound, interval.second);

            if (left_bound > right_bound) {
                return false;
            }
        }
        return true;
    });

    cout << min_time << endl;


}