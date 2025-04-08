#include <bits/stdc++.h>
using namespace std;

double first_true(double hi, double lo, function<bool(double)> f) {

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
    int max_dist = 0;
    int left_idx = 0;
    for (int i = 1; i < haybales_num; i++) {
        int curr_dist = positions[i] - positions[i - 1];
        if (curr_dist > max_dist) {
            max_dist = max(max_dist, curr_dist);
            left_idx = i - 1;
        }
    }

    double bomb_position = positions[left_idx] + max_dist / 2.0;

    double ans = first_true(0, 1e9/2, [&](double radius) {
        double left;
        double right;

        

        return true;
    });
}