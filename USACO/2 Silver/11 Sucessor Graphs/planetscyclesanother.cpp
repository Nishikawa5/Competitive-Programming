#include <bits/stdc++.h>
using namespace std;

void dfs(int i, bool &is_cycle, vector<int> &dist, vector<int> &planets) {
    if (dist[i] != -2) {

        if (dist[i] == -1) {
            is_cycle = true;
            // count the number of planets in this cycle
            int ptr = planets[i];
            int planets_num = 1;
            
            while (ptr != i) {
                ptr = planets[ptr];
                planets_num++;
            }
            dist[i] = planets_num;
        }
        return;
    }

    // visited
    dist[i] = -1;
    dfs(planets[i], is_cycle, dist, planets);

    if (dist[i] == -1) {
        dist[i] = (is_cycle ? dist[planets[i]] : dist[planets[i]] + 1);
    } else {
        is_cycle = false;
    }
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int planets_num;
    cin >> planets_num;

    vector<int> planets(planets_num);

    for (int i = 0; i < planets_num; i++) {
        int a;
        cin >> a;
        planets[i] = a - 1;
    }

    // distances
    vector<int> dist(planets_num, -2);

    for (int i = 0; i < planets_num; i++) {
        if (dist[i] == -2) {
            bool is_cycle = false;
            dfs(i, is_cycle, dist, planets);
        }

        cout << dist[i] << " ";
    }
    cout << "\n";
}