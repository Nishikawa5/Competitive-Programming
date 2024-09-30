#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> times(2 * n);
    for (int i = 0; i < times.size(); i += 2) {
        int start, end;
        cin >> start >> end;
        times[i]     = {start, 1};
        times[i + 1] = {end, -1};
    }
    sort(times.begin(), times.end());

    // coordinate compression
    vector<int> prefix(times.size() + 1);
    int curr_idx = 1;
    int last = times[0].first;
    for (int i = 0; i < times.size(); i++) {
        if (last != times[i].first) {
            last = times[i].first;
            curr_idx++;
        }
        prefix[curr_idx] += times[i].second;
    }

    int max_customers = 0;
    for (int i = 1; i < prefix.size(); i++) {
        prefix[i] += prefix[i - 1];
        max_customers = max(max_customers, prefix[i]);
    }
    cout << max_customers << endl;
}