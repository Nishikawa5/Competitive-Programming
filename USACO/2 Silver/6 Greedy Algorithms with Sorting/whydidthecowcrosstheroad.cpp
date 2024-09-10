#include <bits/stdc++.h>
using namespace std;

/*
C chickens Ci help at time Ti
maximize the number of intervals that has a point

pick the smallest intervals?
*/
int main() {
    freopen("helpcross.in", "r", stdin);
	freopen("helpcross.out", "w", stdout);

    int num_chickens, num_cows;
    cin >> num_chickens >> num_cows;

    vector<int> chicken_times(num_chickens);
    vector<pair<int, int>> cow_intervals(num_cows);

    for (auto &c: chicken_times) {
        cin >> c;
    }
    for (auto &c: cow_intervals) {
        cin >> c.first >> c.second;
    }

    sort(chicken_times.begin(), chicken_times.end());
    sort(cow_intervals.begin(), cow_intervals.end());

    priority_queue<int> available_cows;
    int helped_cows = 0;
    int current_cow_idx = 0;
    for (int &c: chicken_times) {
        // put every possible cow this chicken can help
        while (current_cow_idx < num_cows && cow_intervals[current_cow_idx].first <= c) {
            available_cows.push(-cow_intervals[current_cow_idx++].second);
        }

        // exclude the cows that this chicken can't help
        while (!available_cows.empty() && -available_cows.top() < c) {
            available_cows.pop();
        }

        // chicken go with the best cow
        if (!available_cows.empty()) {
            // not empty so go with the first cow
            available_cows.pop();
            helped_cows++;
        }
    }
    cout << helped_cows << endl;
}