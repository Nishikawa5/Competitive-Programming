#include <bits/stdc++.h>
using namespace std;

void solve() {
    int nodes, edges;
    cin >> nodes >> edges;
    // keep a record of every node available
    vector<vector<int>> graph(nodes + 1);

    while (edges--) {
        int from, to;
        cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    // do bfs but with a set instead of queue?
    set<int> q;
    q.insert(1);

    vector<bool> visited(nodes + 1, false);
    visited[1] = true;

    while (!q.empty()) {
        auto smallest_element = q.begin();
        int curr_node = *smallest_element;
        q.erase(smallest_element);

        cout << curr_node << " ";

        for (auto neighbor: graph[curr_node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.insert(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;

    while (tc--) {
        solve();
    }
    return 0;
}
