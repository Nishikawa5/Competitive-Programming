#include <bits/stdc++.h>
using namespace std;

/* not finished WA */
int move_diff(int curr_diff, int target) {
    return abs(curr_diff - target);
}

void solve() {
    int hour, minute;
    char dummy;
    cin >> hour >> dummy >> minute;

    int queries;
    cin >> queries;

    int clockwise_cost, anticlockwise_cost, hour_cost, minute_cost;
    cin >> clockwise_cost >> anticlockwise_cost >> hour_cost >> minute_cost;

    int minute_angle, hour_angle;
    minute_angle = minute * 6;
    hour_angle = hour * 30;

    int curr_diff = abs(minute_angle - hour_angle);
    for (int i = 0; i < queries; i++) {

        // all four possibilities
        int target;
        cin >> target;

        int new_minute_angle;
        int new_hour_angle;
        int cost = INT_MAX;
        if (minute_angle > hour_angle) {
            // mintue moves clockwise
            int clockwise_ang = 360 - minute_angle + hour_angle;
            int anticlockwise_angle = 360 - clockwise_ang;

            // minute clockwise
            // move only mintue
            int curr_cost = 0;

            // how much do we need to move minute?
            // the min diff
            if (target - clockwise_ang < 0) {
                // move minute anticlockwise
                curr_cost += anticlockwise_cost;
                curr_cost += (clockwise_ang - target) * minute_cost;
            } else if (target - clockwise_ang > 0) {
                // move minute clockwise
                curr_cost += clockwise_cost;
                curr_cost += (target - clockwise_ang) * minute_cost;
            }
            
            if (curr_cost < cost) {
                new_minute_angle = target;
                new_hour_angle = hour_angle;
            }

            // move only hour
            // how much do we need to move hour?
            // the min diff iff 30|
            // move hour the closest and complete with minutes

            curr_cost = 0;
            if (target - clockwise_ang < 0) {
                // move hour anticlockwise
                int hour_moved = ((clockwise_ang - target) / 30) * 30;
                curr_cost += anticlockwise_cost;
                curr_cost += ((clockwise_ang - target) / 30) * 30 * hour_cost;

                int minutes_moved = (target - clockwise_ang) % 30;
                curr_cost += clockwise_ang;
                curr_cost += minutes_moved * minute_cost;

                clockwise_ang
            } else if (target - clockwise_ang > 0 && (target - clockwise_ang) % 30 == 0) {
                // move minute clockwise
                curr_cost += clockwise_cost;
                curr_cost += ((target - clockwise_ang) / 30) * 30 * hour_cost;

                int minutes_moved = (target - clockwise_ang) % 30;
                curr_cost += anticlockwise_angle;
                curr_cost += minutes_moved * minute_cost;
            }
            
            if (curr_cost < cost) {
                new_minute_angle = minute_angle;
                new_hour_angle = target;
            }

            // move both
            curr_cost = 0;

            // move hour the closest and complete with minutes


        } else {
            int clockwise_ang = 360 - hour_angle + minute_angle;
            int anticlockwise_angle = 360 - clockwise_ang;
        }

        // hour clockwise, minute anti
    }
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
