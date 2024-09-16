#include <bits/stdc++.h>
using namespace std;

void dfs(int vertice, int curr_component, vector<int> &components, string &cows_type, vector<vector<int>> &graph) {
    // connect every vertice that has the same color
    components[vertice] = curr_component;

    for (auto &curr_vertice: graph[vertice]) {
        if (components[curr_vertice] == -1 && cows_type[curr_vertice] == cows_type[vertice]) {
            // not visited yet and same color, so make this component the current
            dfs(curr_vertice, curr_component, components, cows_type, graph);
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

    vector<int> components(num_farms, -1);
    for (int i = 0; i < num_farms; i++) {
        // component for each farm
        if (components[i] != -1) continue;

        // new component
        dfs(i, i, components, cows_type, graph);
    }

    for (int i = 0; i < num_friends; i++) {
        int from, to;
        char type;
        cin >> from >> to >> type;
        from--; to--;

        if (components[from] == components[to]) {
            cout << (type == cows_type[from]);
        } else {
            // different
            cout << 1;
        }
    }
    cout << endl;
}