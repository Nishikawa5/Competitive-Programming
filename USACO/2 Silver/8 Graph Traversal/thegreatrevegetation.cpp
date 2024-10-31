#include <bits/stdc++.h>
using namespace std;

/*

1 1 2
2 2 1
*/
bool dfs(int vertice, vector<int> &colors, vector<vector<pair<bool, int>>> &graph) {
    int curr_color = colors[vertice];

    for (auto curr_vertice: graph[vertice]) {
        if (colors[curr_vertice.second] != 0) {
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

    vector<vector<pair<bool, int>>> graph(pastures);
    for (int i = 0; i < cows; i++) {
        char type;
        int from, to;
        cin >> type >> from >> to;

        from--; to--;
        graph[from].push_back({type, to});
        graph[to].push_back({type, from});
    }

    vector<int> colors(pastures);

    string ans = "1";
    for (int i = 0; i < pastures; i++) {
        if (colors[i] == 0) {
            if (!dfs(i, colors, graph)) {
                cout << 0 << endl;
                return 0;
            } else {
                ans += '0';
            }
        }
    }
    cout << ans << endl;
}