#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> coowrdinate(n);
    vector<vector<int>> graph(n);

    for (auto &c: coowrdinate) {
        cin >> c.first >> c.second;
    }

    for (int i = 0; i < m; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        c1--; c2--;
        graph[c1].push_back(c2);
        graph[c2].push_back(c1);
    }

    vector<bool> visited(n, false);

    // bfs through cows
    long long min_perimeter = LONG_LONG_MAX;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        // calculate the smallest perimeter
        int x_low, x_high, y_low, y_high;
        x_low = coowrdinate[i].first;
        x_high = coowrdinate[i].first;
        y_low = coowrdinate[i].second;
        y_high = coowrdinate[i].second;

        queue<int> to_visit;
        to_visit.push(i);

        while (!to_visit.empty()) {
            int curr_cow = to_visit.front();
            to_visit.pop();

            visited[curr_cow] = true;
            x_low = min(x_low, coowrdinate[curr_cow].first);
            x_high = max(x_high, coowrdinate[curr_cow].first);
            y_low = min(y_low, coowrdinate[curr_cow].second);
            y_high = max(y_high, coowrdinate[curr_cow].second);

            for (int &c: graph[curr_cow]) {
                if (!visited[c]) {
                    to_visit.push(c);
                }
            }
        }

        min_perimeter = min(min_perimeter, (long long) (x_high - x_low) * 2 + (long long) (y_high - y_low) * 2);
    }
    cout << min_perimeter << endl;
}