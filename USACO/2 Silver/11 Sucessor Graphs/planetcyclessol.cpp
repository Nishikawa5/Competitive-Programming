#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int &len, queue<int> &curr_planets, vector<int> &dist, vector<bool> &visited, vector<int> &planets) {
    curr_planets.push(i);
    if (visited[i]) {
        // found the cycle or distance that has been already calculated
        // if it has been calculated already add it to the len, else just add 0
        len += dist[i];
        return;
    }

    visited[i] = true;
    len++;
    dfs(planets[i], len, curr_planets, dist, visited, planets);
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
    vector<bool> visited(planets_num, false);
    vector<int> dist(planets_num);
    queue<int> curr_planets; 

    int len;
    int decrement;
    for (int i = 0; i < planets_num; i++) {
        
        if (!visited[i]) {
            len = 0;
            decrement = 1;
            dfs(i, len, curr_planets, dist, visited, planets);
            while (!curr_planets.empty()) {
                if (curr_planets.front() == curr_planets.back()) {
                    // start of cycle, so no more decrements
                    decrement = 0;
                }

                dist[curr_planets.front()] = len;
                len -= decrement;
                curr_planets.pop();
            }
        }
        cout << dist[i] << " ";
    }
    cout << "\n";
}