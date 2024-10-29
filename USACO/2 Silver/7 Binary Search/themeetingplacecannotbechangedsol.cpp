#include <bits/stdc++.h>
using namespace std;

#define ll long long

double first_true(double lo, double hi, function<bool(double)> f) {

    while (hi - lo > 1e-6) {
        double mid = lo + (hi - lo) / 2;

        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return lo;
}

pair<double, double> calculate_interval(double friend_pos, double speed, double time) {
    pair<double, double> ans = {friend_pos - 1LL * speed * time, friend_pos + 1LL * speed * time};   
    return ans;
}

int main() {
    int n;

    cin >> n;

    vector<double> friends(n);
    vector<double> speeds(n);

    for (auto &f: friends) {
        cin >> f;
    }

    for (auto &s: speeds) {
        cin >> s;
    }

    double min_time = first_true(0, 1e9, [&](double time) {
        // check if is possible to meet at this time
        // how to check if everyone can meet
        // separe in intervals?
        double left_bound = 0;
        double right_bound = 1e9;

        for (int i = 0; i < n; i++) {
            pair<double, double> interval = calculate_interval(friends[i], speeds[i], time);

            left_bound = max(left_bound, interval.first);
            right_bound = min(right_bound, interval.second);

            if (left_bound > right_bound) {
                return false;
            }
        }
        return true;
    });

    cout << setprecision(12) << min_time << endl;


}