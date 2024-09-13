#include <bits/stdc++.h>
using namespace std;

void dfs(int curr_v, vector<vector<int>> &graph, vector<bool> &visited) {
    visited[curr_v] = true;

    for (auto &v: graph[curr_v]) {
        if (!visited[v]) {
            dfs(v, graph, visited);
        }
    }
}

/*
one vertex can reach and be reached by all others
=> every vertex can reach all other


*/
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> from_to(n);
    vector<vector<int>> to_from(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        from_to[a].push_back(b);
        to_from[b].push_back(a);
    }

    vector<bool> visited(n, false);
    dfs(0, from_to, visited);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "NO\n";
            cout << 1 << " " << i + 1 << endl;
            return 0;
        }
    }

    visited = vector<bool>(n, false);
    dfs(0, to_from, visited);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "NO\n";
            cout << i + 1 << " " << 1 << endl;
            return 0;
        }
    }
    cout << "YES\n";
}