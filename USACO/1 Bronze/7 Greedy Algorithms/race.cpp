#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("race.in", "r", stdin);
	//freopen("race.out", "w", stdout);

    int dist;
    int diff;

    cin >> dist >> diff;
    int def_dist = 0;
    int def_times = 0;
    vector<int> def_spd;
    
    while (def_dist < dist) {
        def_dist += ++def_times;
        def_spd.push_back(def_times);
    }


    while (diff--) {
        int end;
        int peak = def_spd.size() - 1;
        int curr_dist = def_dist;
        vector<int> curr_spd = def_spd;
        cin >> end;

        // keep decreasing until curr_end == end
        while (curr_spd[curr_spd.size() - 1] > end || curr_dist < dist) {

            if (curr_dist < dist) {
                // add one more of the last
                curr_spd.insert(curr_spd.begin() + peak, curr_spd[peak]);
                curr_dist += curr_spd[peak];
            }
            // sub every last until curr_spd[curr_spd.size() - 1] == end or curr_dist < def_dist
            while (curr_spd[curr_spd.size() - 1] > end && curr_dist >= dist) {
                
            }
        }
        for (int i = 0; i < curr_spd.size(); i++) {
            cout << curr_spd[i] << " ";
        }
        cout << "\n\n";

        cout << curr_spd.size() << endl;
    }
}