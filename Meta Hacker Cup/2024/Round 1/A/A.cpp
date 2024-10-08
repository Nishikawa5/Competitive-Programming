#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    double min_speed = 0;
    double max_speed = DBL_MAX;
    int min_time = 0;
    bool is_possible = true;
    for (int i = 1; i <= n; i++) {
        double l, r;
        double curr_left = DBL_MAX;
        double curr_right;
        cin >> l >> r;

        if (min_time >= (int)r) {
            is_possible = false;
        } else {
            min_time = max(min_time, (int)l);
        }

        if (l) {
            curr_left = i / l;
        }
        curr_right = i / r;

        // decrease max
        // increase min
        min_speed = max(curr_right, min_speed);
        max_speed = min(curr_left, max_speed);
    }
    if (!is_possible || min_speed < max_speed) {
        cout << -1 << endl;
    } else {
        cout << min_speed << endl;
    }
}

int main() {
    int tc;
    cin >> tc;
    cout << fixed << setprecision(7);

    for (int i = 1; i <= tc; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}