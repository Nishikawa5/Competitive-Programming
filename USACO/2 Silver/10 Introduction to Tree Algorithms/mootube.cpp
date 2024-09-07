#include <bits/stdc++.h>
using namespace std;

void dfs(int &ans, int curr_vertice, vector<vector<pair<int, int>>> &graph, vector<bool> &visited, int min_relevance) {
    visited[curr_vertice] = true;

    for (auto &vertice: graph[curr_vertice]) {
        if (!visited[vertice.first] && min_relevance <= vertice.second) {
            ans++;
            dfs(ans, vertice.first, graph, visited, min_relevance);
        }
    }
}

int main() {
    freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);

    int n, q;
    cin >> n >> q;

    vector<vector<pair<int, int>>> videos(n);
    for (int i = 1; i < n; i++) {
        int v1, v2, relevance;
        cin >> v1 >> v2 >> relevance;
        v1--; v2--;
        videos[v1].push_back({v2, relevance});
        videos[v2].push_back({v1, relevance});
    }

    while (q--) {
        int ans = 0;
        int min_relevance, v;
        cin >> min_relevance >> v;
        v--;
        
        vector<bool> visited(n);
        dfs(ans, v, videos, visited, min_relevance);

        cout << ans << endl;
    }
}