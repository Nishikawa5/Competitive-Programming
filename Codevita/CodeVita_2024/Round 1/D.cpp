#include <bits/stdc++.h>
using namespace std;

/* AC */

const int INF = 1000000000;

vector<int> restore_path(int s, int t, vector<int> &p) {
    vector<int> path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    return path;
}

vector<vector<int>> dijkstra(int s, vector<vector<pair<int, int>>> &graph, vector<int> &d, vector<int> &p) {
    int n = graph.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;
    
        u[v] = true;
        for (auto edge : graph[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }

    // get the paths
    vector<vector<int>> all_paths(n);
    for (int i = 1; i < (int)graph.size(); i++) {
        all_paths[i] = restore_path(s, i, p);
    }

    return all_paths;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cost;
            cin >> cost;
            if (j == i) continue;

            graph[i].push_back({j, cost});
            graph[j].push_back({i, cost});
        }
    }

    vector<int> d(n);
    vector<int> p(n);

    vector<vector<int>> all_paths = dijkstra(0, graph, d, p);
    vector<int> people(n);
    for (int i = 1; i < n; i++) {
        int people_num;
        cin >> people_num;

        people[i] = people_num;
    }

    int bus_size;
    cin >> bus_size;

    int total_bus = 0;

    int done = 0;
    while (done != n - 1) {
        // mark the "root starts"
        // roots[i] == 1
        vector<int> roots(n);
        for (int i = 1; i < n; i++) {
            for (auto &loc: all_paths[i]) {
                roots[loc]++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (roots[i] == 1) {
                // start bus this root
                while (people[i] > 0) {
                    int curr_bus_size = bus_size;
                    for (auto &loc: all_paths[i]) {
                        if (curr_bus_size >= people[loc]) {
                            curr_bus_size -= people[loc];
                            people[loc] = 0;
                        } else {
                            people[loc] -= curr_bus_size;
                            curr_bus_size = 0;
                            break;
                        }
                    }
                    total_bus++;
                }
                all_paths[i] = {};
            }
        }

        done = 0;
        for (int i = 1; i < n; i++) {
            done += (people[i] == 0);
        }
    }
    cout << total_bus << endl;
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
