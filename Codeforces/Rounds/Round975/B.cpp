#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, q;
    cin >> n >> q;

    unordered_map<long long, long long> segments_points;
    vector<int> segments(n);
    for (auto &s: segments) {
        cin >> s;
    }

    /*
    careful with start and end of segments. since [xi, xj] we should treat (xi, xj) and {xi, xj} different.
    example

    for (xi, xj): new_intervals + last_intervals - k
    for xi:       new_intervals + last_intervals
    x1      x2      x3      x4 ... xi
    

    */
    segments_points[n - 1]++;
    long long curr_intervals = n - 1;
    long long last_intervals = 0;
    long long new_intervals = n - 1;
    for (int i = 0; i < n - 1; i++) {
        curr_intervals = new_intervals + last_intervals - i;

        segments_points[new_intervals + last_intervals]++;
        segments_points[new_intervals + last_intervals - i] += (long long) segments[i + 1] - (long long) segments[i] - 1;

        last_intervals = curr_intervals;
        new_intervals--;
    }

    for (int i = 0; i < q; i++) {
        long long querry;
        cin >> querry;
        cout << segments_points[querry] << " ";
    }
    cout << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}