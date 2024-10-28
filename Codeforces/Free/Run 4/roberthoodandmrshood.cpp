#include <bits/stdc++.h>
using namespace std;

void solve() {
    int days_total, days_visit, jobs_num;
    cin >> days_total >> days_visit >> jobs_num;

    vector<int> prefix_start(days_total + 1);
    vector<int> prefix_end(days_total + 1);
    for (int i = 0; i < jobs_num; i++) {
        int start, end;
        cin >> start >> end;
        
        prefix_start[start]++;
        prefix_end[end]++;
    }

    for (int i = 1; i <= days_total; i++) {
        prefix_start[i] += prefix_start[i - 1];
        prefix_end[i] += prefix_end[i - 1];
    }

    int best_day_robert, best_day_mrs;
    int most_intersections = 0;
    int least_intersections = INT_MAX;
    
    for (int final_day = days_visit; final_day <= days_total; final_day++) {
        // every job that started till this day - the jobs that ended till the day of start
        // == the # of jobs running in this interval
        int intersections = prefix_start[final_day] - prefix_end[final_day - days_visit];

        if (intersections > most_intersections) {
            best_day_robert = final_day - days_visit + 1;
            most_intersections = intersections;
        }
        if (intersections < least_intersections) {
            best_day_mrs = final_day - days_visit + 1;
            least_intersections = intersections;
        }
    }

    cout << best_day_robert << " " << best_day_mrs << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}