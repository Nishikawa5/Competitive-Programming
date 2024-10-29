#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, total_time;
    cin >> n >> total_time;

    vector<int> times(n);
    vector<int> sorted_times(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        times[i] = t;
        sorted_times[i] = t;
    }

    sort(sorted_times.begin(), sorted_times.end());
    int max_wins = 0;
    int max_time = 0;
    while (max_wins < n && total_time - sorted_times[max_wins] >= 0) {
        max_time = max(max_time, sorted_times[max_wins]);
        total_time -= sorted_times[max_wins++];
    }
    
    // get max wins
    // then check if we can win vs the one who wins
    // the same as you

    // check if you are in the same place as maxwins-th player
    if (max_wins != n &&
        max_time + total_time >= times[max_wins]) {
        // can win vs him
        cout << max(n - max_wins, 1) << endl;
    } else {
        // cant win vs him
        cout << max(n - max_wins + 1, 1) << endl;
    }

}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}