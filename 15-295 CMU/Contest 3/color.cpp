#include <bits/stdc++.h>
using namespace std;

void solve() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector<int> graph[nodes];

    while (edges--) {
        int from, to;
        cin >> from >> to;

        graph[from-1].push_back(to-1);
        graph[to-1].push_back(from-1);
    }

    // just make a bfs and output the level after bob reaches n
    // start at 0, goal is n-1
    queue<int> q;
    q.push(0);
    vector<int> dist(nodes, INT_MAX);
    dist[0] = 0;

    while (!q.empty()) {
        int curr_node = q.front();
        q.pop();

        for (auto neighbor: graph[curr_node]) {
            if (dist[neighbor] >= INT_MAX) {
                dist[neighbor] = dist[curr_node] + 1;
                q.push(neighbor);
            }
        }
    }

    cout << dist[nodes-1] - 1 << endl;
}

int main() {
    solve();
}