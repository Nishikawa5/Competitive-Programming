#include <bits/stdc++.h>
using namespace std;

/*
we lose a point for every day in every task not completed. So we can just finish the
easiest first to not lose too much points
*/
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> dur_dead(n);

    for (auto &p: dur_dead) {
        cin >> p.first >> p.second;
    }
    sort(dur_dead.begin(), dur_dead.end());

    long long int max_score = 0;
    long long int curr_day = 0;
    for (int i = 0; i < n; i++) {
        curr_day += dur_dead[i].first;
        max_score += dur_dead[i].second - curr_day;
    }
    cout << max_score << endl;
}