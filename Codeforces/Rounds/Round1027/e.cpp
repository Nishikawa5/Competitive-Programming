#include <bits/stdc++.h>
using namespace std;



void solve() {
    int nodes;
    cin >> nodes;

    vector<int> values(nodes);
    vector<vector<int>> graph(nodes);
    for (auto &v: values) {
        cin >> v;
    }

    for (int i = 0; i < nodes-1; i++) {
        int from, to;
        cin >> from >> to;
        graph[from-1].push_back(to-1);
        graph[to-1].push_back(from-1);
    }

    queue<int> paths;
    vector<long long> max_threat_values(nodes, LONG_LONG_MIN);
    vector<long long> min_threat_values(nodes, LONG_LONG_MAX);

    paths.push(0);
    max_threat_values[0] = values[0];
    min_threat_values[0] = values[0];

    while (!paths.empty()) {
        int curr_node = paths.front();

        paths.pop();

        for (auto neighbor: graph[curr_node]) {
            if (max_threat_values[neighbor] == LONG_LONG_MIN) {
                paths.push(neighbor);
                

                max_threat_values[neighbor] = max(
                    (long long)values[neighbor], 
                    values[neighbor] - min_threat_values[curr_node]
                );

                min_threat_values[neighbor] = min(
                    (long long)values[neighbor], 
                    values[neighbor] - max_threat_values[curr_node]
                );

            }
        }
    }

    for (auto t: max_threat_values) {
        cout << t << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
    return 0;
}
