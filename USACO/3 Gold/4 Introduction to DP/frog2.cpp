#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> heights(n);
    for (auto &h: heights) {
        cin >> h;
    }

    int min_cost;
    vector<int> costs(n, INT_MAX);
    costs[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int jump = 1; jump <= k; jump++) {
            if (i - jump < 0) break;
            costs[i] = min(costs[i], abs(heights[i] - heights[i - jump]) + costs[i - jump]);
        }
    }
    cout << costs[n - 1] << endl;
}