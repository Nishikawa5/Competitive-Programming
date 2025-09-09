#include <bits/stdc++.h>
using namespace std;

int main() {
    int activities_num, interval;
    cin >> activities_num >> interval;

    vector<int> time(2e5+2, 0);
    
    while (activities_num--) {
        int start, duration;
        cin >> start >> duration;

        time[start]++;
        time[start + duration + 1]--;
    }
    
    for (int i = 1; i < time.size(); i++) {
        time[i] += time[i-1];
    }

    int optimal_time = -1;
    int overlaps = 2e6;
    for (int start = 0; start <= 8*60; start++) {
        // 8*60*2e5
        // O(1e8)
        int curr_overlaps = 0;
        int curr_time = start;
        while (curr_time < time.size()) {
            curr_overlaps += time[curr_time];
            curr_time += interval;
        }

        if (curr_overlaps < overlaps) {
            overlaps = curr_overlaps;
            optimal_time = start;
        }
    }
    cout << optimal_time << " " << overlaps << endl;
}