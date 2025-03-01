#include <bits/stdc++.h>
using namespace std;

long long calculate_min_cost(int from, int to, vector<vector<int>> &connected, vector<int> &visited) {
    long long min_cost = LONG_LONG_MAX;

    for (auto &c: connected[from]) {

        // get the min diff from to to connected group
        auto it = lower_bound(connected[to].begin(), connected[to].end(), c);

        int closest;
        if (it == connected[to].end()) {
            // just pick the last
            closest = *prev(it);
        } else if (it == connected[to].begin()) {
            // just pick the first
            closest = *it;
        } else {
            // check both directions
            if (abs(*it - c) > abs(*prev(it) - c)) {
                closest = *prev(it);
            } else {
                closest = *it;
            }
        }
        min_cost = min(min_cost, 1LL * (closest - c) * (closest - c));
    }

    return min_cost;
}

void dfs(int vertice, int idx, vector<int> &visited, vector<vector<int>> &graph) {
    if (visited[vertice]) return;

    visited[vertice] = idx;

    for (auto &v: graph[vertice]) {
        dfs(v, idx, visited, graph);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(n);
    int conn = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, ++conn, visited, graph);
        }
    }

    vector<vector<int>> connected(conn);
    for (int i = 0; i < n; i++) {
        connected[visited[i] - 1].push_back(i);
    }

    long long min_cost = calculate_min_cost(visited[0] - 1, visited[n - 1] - 1, connected, visited);
    for (int group = 0; group < conn; group++) {
        // go through all groups
        // group of 0 -> group -> group of n - 1 O(n * n * lgn)
        // the same cost as group -> group of 0 + grop -> group of n - 1
        // which is O(lgn * n)
        min_cost = min(min_cost, calculate_min_cost(group, visited[0] - 1, connected, visited) + 
                                 calculate_min_cost(group, visited[n - 1] - 1, connected, visited));
    }
    
    cout << min_cost << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}