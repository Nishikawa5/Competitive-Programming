#include <bits/stdc++.h>
using namespace std;

#define ll long long

void dfs (ll length, set<ll> &visited, map<ll, vector<ll>> &graph) {
    if (visited.count(length)) {
        return;
    }
    visited.insert(length);

    for (auto curr_length: graph[length]) {
        dfs(curr_length, visited, graph);
    }
}

void solve() {
    int n;
    cin >> n;

    map<ll, vector<ll>> graph;

    for (int i = 0; i < n; i++) {
        ll a_i;
        cin >> a_i;
        if (i) graph[a_i + i].push_back(a_i + i + i);
    }

    set<ll> visited;
    dfs(n, visited, graph);

    cout << *visited.rbegin() << endl;
}

int main(void) {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}