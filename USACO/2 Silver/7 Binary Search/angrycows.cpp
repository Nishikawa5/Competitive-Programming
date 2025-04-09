#include <bits/stdc++.h>
using namespace std;

double first_true(double lo, double hi, function<bool(double)> f) {

    while (hi - lo > 1e-2) {
        double mid = lo + (hi - lo) / 2;

        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return lo;
}


int main() {
    freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);

    /*
    binary search on radius

    store the positions in a set

    in function:
        copy the position set

        where should we place the bomb?
        dont need?
        check the distances between haybales
        put the bomb between the two haybales 
        most far apart
 
        store an interval of [min, max] covered by explosion
    */
    int haybales_num;
    cin >> haybales_num;

    vector<int> positions(haybales_num);
    
    for (auto &p: positions) {
        cin >> p;
    }

    sort(positions.begin(), positions.end());

    // the position we put the bomb
    int max_dist = positions[1] - positions[0];
    int left_idx = 0;

    for (int i = 2; i < haybales_num; i++) {
        int curr_dist = positions[i] - positions[i - 1];

        if (curr_dist > max_dist) {
            max_dist = curr_dist;
            left_idx = i - 1;
        }
    }

    double bomb_position = positions[left_idx] + max_dist / 2.0;


    double ans = first_true(0, 1e9/2, [&](double radius) {
        // try to explode everything to left

        int iterations;

        double min_interval = bomb_position - radius;
        int curr_left = left_idx;

        iterations = 0;
        while (curr_left != -1 && min_interval <= (double)positions[curr_left]) {

            while (curr_left != -1 && min_interval <= (double)positions[curr_left]) {
                // everything explodes
                curr_left--; 
            }
            iterations++;

            min_interval = positions[curr_left + 1] - (radius - iterations);
        }

        if (curr_left != -1) {
            return false;
        }

        double max_interval = bomb_position + radius;
        int curr_right = left_idx + 1;

        iterations = 0;
        while (curr_right != haybales_num && max_interval >= (double)positions[curr_right]) {
            
            while (curr_right != haybales_num && max_interval >= (double)positions[curr_right]) {
                // everything explodes
                curr_right++; 
            }
            iterations++;

            max_interval = positions[curr_right - 1] + (radius - iterations);
        }

        if (curr_right != haybales_num) {
            return false;
        }

        return true;
    });

    std::cout << std::fixed;
    std::cout << std::setprecision(1);
    cout << ans << endl;
}