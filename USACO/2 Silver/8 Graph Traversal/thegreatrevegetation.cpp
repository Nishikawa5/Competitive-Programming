#include <bits/stdc++.h>
using namespace std;


bool dfs(int vertice, vector<int> &colors, vector<vector<pair<char, int>>> &graph) {
    // assume colors[vertice] is always colored
    for (auto curr_vertice: graph[vertice]) {
        if (colors[curr_vertice.second] != 0) {
            // visited, so check if it makes sense
            if (curr_vertice.first == 'S') {
                // must be the same
                if (colors[curr_vertice.second] != colors[vertice]) {
                    return false;
                }
            } else {
                // must be different
                if (colors[curr_vertice.second] == colors[vertice]) {
                    return false;
                }
            }
        } else {
            // neighbor not visited yet, so color and visit
            if (curr_vertice.first == 'S') {
                // must be the same
                colors[curr_vertice.second] = colors[vertice];
            } else {
                // must be different
                colors[curr_vertice.second] = colors[vertice] == 1 ? 2 : 1; 
            }
            if (!dfs(curr_vertice.second, colors, graph)) {
                return false;
            }
        }
    }
    return true;
}


int main() {
    freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);
    
    int pastures, cows;
    cin >> pastures >> cows;

    /*
    every disconnected multiply by 2
    check if it is possible and how many disconnected

    */

    vector<vector<pair<char, int>>> graph(pastures);
    for (int i = 0; i < cows; i++) {
        char type;
        int from, to;
        cin >> type >> from >> to;

        from--; to--;
        graph[from].push_back({type, to});
        graph[to].push_back({type, from});
    }

    vector<int> colors(pastures);

    int zeros = 0;
    for (int i = 0; i < pastures; i++) {
        if (colors[i] == 0) {
            colors[i] = 1;
            if (!dfs(i, colors, graph)) {
                cout << 0 << endl;
                return 0;
            } else {
                zeros++;
            }
        }
    }

    cout << '1';
    for (int i = 0; i < zeros; i++) {
        cout << '0';
    }
    cout << endl;
}