#include <bits/stdc++.h>
using namespace std;

struct Circle {
    int x, y, r;
};

bool is_intersecting(Circle a, Circle b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    long long r_sum = a.r + b.r;
    return dx * dx + dy * dy <= r_sum * r_sum; 
}

void dfs(int v, vector<bool> &visited, vector<vector<int>> &graph, vector<Circle> &sensors,
    bool &touches_left, bool &touches_right, bool &touches_up, bool &touches_down, int m, int n) 
    {
    visited[v] = true;

    if (sensors[v].r + sensors[v].x >= m) touches_right = true; 
    if (sensors[v].r + sensors[v].y >= n) touches_down = true; 
    if (-sensors[v].r + sensors[v].x <= 0) touches_left = true; 
    if (-sensors[v].r + sensors[v].y <= 0) touches_up = true; 

    for (auto neighbor: graph[v]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph, sensors, touches_left, touches_right, touches_up, touches_down, m, n);
        }
    }
}

void solve() {
    // is going from 0,0 to m, n possible?
    // connect all the circles, if there is connected circles that connects
    // (l r), (r d), (u d), (l, u) wall => not possible
    int m, n, sensor_num;
    cin >> m >> n >> sensor_num;

    vector<Circle> sensors(sensor_num);
    for (auto &s: sensors) {
        cin >> s.x >> s.y >> s.r;
    }

    vector<vector<int>> graph(sensor_num);
    for (int i = 0; i < sensor_num; i++) {
        for (int j = i + 1; j < sensor_num; j++) {

            if (is_intersecting(sensors[i], sensors[j])) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    vector<bool> visited(sensor_num);
    bool is_possible = true;
    for (int i = 0; i < sensor_num; i++) {

        if (!visited[i]) {
            // right, down, left, up
            bool touches_up = false;
            bool touches_down = false;
            bool touches_left = false;
            bool touches_right = false;

            dfs(i, visited, graph, sensors, touches_left, touches_right, touches_up, touches_down, m, n);
            // check if dists connect the walls
            // (l r), (r d), (u d), (l, u) wall => not possible
            if ((touches_left && touches_right) || 
               (touches_right && touches_down) || 
               (touches_up && touches_down) || 
               (touches_left && touches_up)) {

                is_possible = false;
                break;
            }

        }
    }

    if (is_possible) {
        cout << "S\n";
    } else {
        cout << "N\n";
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
