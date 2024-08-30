#include <bits/stdc++.h>
using namespace std;

// keeping speed up until slow down
int main() {
    freopen("race.in", "r", stdin);
	freopen("race.out", "w", stdout);

    int dist;
    int diff;

    cin >> dist >> diff;
    
    while (diff--) {
        int last_dist;
        cin >> last_dist;
        
        int curr_spd = 1;
        int speedup_dist = 0;
        int slowdown_dist = 0;
        int time = 0;

        while (speedup_dist + slowdown_dist < dist) {
            speedup_dist += curr_spd;
            time++;
            // 1 in the peak
            if (speedup_dist + slowdown_dist >= dist) {
                break;
            }

            if (curr_spd >= last_dist) {
                // 2 in the peak
                slowdown_dist += curr_spd;
                time++;
            }
            curr_spd++;
        }

        cout << time << endl;
    }
}