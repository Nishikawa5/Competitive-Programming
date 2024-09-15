#include <bits/stdc++.h>
using namespace std;

void dfs(int vertice, bool found, bool &ans, 
         char desired_milk, int desired_vertice, bool &stop_dfs, 
         string &cows_type, vector<bool> &visited, vector<vector<int>> &graph) {

    visited[vertice] = true;
    if (vertice == desired_vertice) {
        ans = found || cows_type[vertice] == desired_milk;
        stop_dfs = true;
    }
    if (stop_dfs) {
        return;
    }

    for (auto &curr_vertice: graph[vertice]) {
        if (!visited[curr_vertice]) {
            dfs(curr_vertice, found || cows_type[curr_vertice] == desired_milk, ans, 
                desired_milk, desired_vertice, stop_dfs, cows_type, visited, graph);
        }
    }

}

int main() {
    freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);

    int num_farms, num_friends;
    string cows_type;
    cin >> num_farms >> num_friends >> cows_type;

    vector<vector<int>> graph(num_farms);
    for (int i = 1; i < num_farms; i++) {
        int f1, f2;
        cin >> f1 >> f2;
        f1--; f2--;
        graph[f1].push_back(f2);
        graph[f2].push_back(f1);
    }

    for (int i = 0; i < num_friends; i++) {
        int from, to;
        char desired_milk;
        cin >> from >> to >> desired_milk;
        from--; to--;

        bool ans = false;
        bool stop_bfs = false;
        vector<bool> visited(num_farms, false);
        dfs(from, false, ans, desired_milk, to, stop_bfs, cows_type, visited, graph);
        cout << ans;
    }
    cout << endl;
}