#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> graph[26], vector<bool> &visited) {
    visited[node] = true;

    for (auto neighbor: graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}


bool can_connect(string &w1, string &w2, vector<int> graph[26]) {
    for (int i = 0; i < w1.size(); i++) {
        // try to connect this letter to another

        if (w1[i] != w2[i]) {
            vector<bool> visited(26, false);

            dfs(w1[i] - 'a', graph, visited);

            if (!visited[w2[i] - 'a']) {
                return false;
            }            
        }
    }
    return true;
}


void solve() {
    int edges, words;
    cin >> edges >> words;

    vector<int> graph[26];

    while (edges--) {
        char from, to;
        cin >> from >> to;

        graph[from - 'a'].push_back(to - 'a');
    }

    while (words--) {
        string w1, w2;
        cin >> w1 >> w2;

        bool is_possible = true;

        if (w1.size() != w2.size()) {
            is_possible = false;
        } else {
            is_possible = can_connect(w1, w2, graph);
        }

        if (is_possible) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }

    }
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
