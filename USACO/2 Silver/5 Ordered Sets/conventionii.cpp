#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);

    int num_cows;
    cin >> num_cows;

    vector<pair<pair<int, int>, int>> cows(num_cows);
    int i = 0;
    for (auto &c: cows) {
        cin >> c.first.first >> c.first.second;
        c.second = i++;
    }
    // sort by arrival time
    sort(cows.begin(), cows.end());

    // available cows by seniority
    // seniority | duration
    priority_queue<pair<int, pair<int, int>>> available_cows;
    int waiting_time = 0;

    int curr_time = 0;
    int last_cow = 0;
    while (last_cow < cows.size() || !available_cows.empty()) {
        while (last_cow < cows.size() && (available_cows.empty() || cows[last_cow].first.first <= curr_time)) {
            // add another cow
            pair<int, pair<int, int>> seniority_cow;
            seniority_cow = {-cows[last_cow].second, cows[last_cow].first};
            available_cows.push(seniority_cow);

            last_cow++;
        }
        if (!available_cows.empty()) {
            // most senior cow eat
            pair<int, pair<int, int>> eating_cow = available_cows.top();
            available_cows.pop();

            curr_time = max(eating_cow.second.first, curr_time);

            // change the waiting time
            waiting_time = max(waiting_time, curr_time - eating_cow.second.first);
            curr_time += eating_cow.second.second;
        }
    }
    cout << waiting_time << endl;
}