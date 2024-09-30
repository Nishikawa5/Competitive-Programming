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

    int curr_customers = 0;
    int max_customers = 0;
    for (int i = 0; i < times.size(); i++) {
        curr_customers += times[i].second;
        max_customers = max(max_customers, curr_customers);
    }
    cout << max_customers << endl;
}