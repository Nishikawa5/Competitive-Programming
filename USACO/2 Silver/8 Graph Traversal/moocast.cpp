#include <bits/stdc++.h>
using namespace std;

// check if x,y is inside the circle
bool insideCircle(int cx, int cy, int r, int x, int y) {
    return ((cx - x) * (cx - x) + (cy - y) * (cy - y)) <= r * r;
}

// bfs
int bfs(int curr_cow, vector<vector<int>> &graph) {
    int total_cows = 0;
    queue<int> to_visit;
    vector<bool> visited(graph.size(), false);
    to_visit.push(curr_cow);

    while (!to_visit.empty()) {
        int curr_visit = to_visit.front();
        to_visit.pop();
        if (!visited[curr_visit]) {
            total_cows++;
            visited[curr_visit] = true;

            for (int cow: graph[curr_visit]) {
                to_visit.push(cow);
            }
        }
    }
    return total_cows;
}

int main() {
    freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    vector<pair<pair<int, int>, int>> positions(n);
    for (auto &p: positions) {
        cin >> p.first.first >> p.first.second >> p.second;
    }

    // construct the graph of connected cows
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (insideCircle(positions[i].first.first , positions[i].first.second, positions[i].second,
                                 positions[j].first.first, positions[j].first.second)) {
                    graph[i].push_back(j);
                }
            }
        }
    }

    // count the cow with most connections
    int max_cows = 0;
    for (int i = 0; i < n; i++) {
        max_cows = max(max_cows, bfs(i, graph));
    }
    cout << max_cows << endl;
}