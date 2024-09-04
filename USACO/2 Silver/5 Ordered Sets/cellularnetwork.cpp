#include <bits/stdc++.h>
using namespace std;

/*
put cellular towers in a set
get the closest cellular tower fo each
city by lowerbound
*/
int main() {
    int n, m;
    cin >> n >> m;

    vector<int> city(n);
    for (auto &c: city) {
        cin >> c;
    }

    set<int> cellular_towers;
    for (int i = 0; i < m; i++) {
        int curr_tower;
        cin >> curr_tower;

        cellular_towers.insert(curr_tower);
    }

    // get the closest ct for each city
    int max_distance = 0;
    for (auto c: city) {
        auto it = cellular_towers.lower_bound(c);
        int dr, dl, curr_dist;

        if (it == cellular_towers.end()) {
            curr_dist = c - *(--it);
        } else if (it == cellular_towers.begin()) {
            curr_dist = *it - c;
        } else {
            dr = *it - c;
            dl = c - *(--it);
            curr_dist = min(dr, dl);
        }

        max_distance = max(max_distance, curr_dist);
    }
    cout << max_distance << endl;
}