#include <bits/stdc++.h>
using namespace std;

int last_true(int lo, int hi, function<bool(int)> f) {
	lo--;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;
		if (f(mid)) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}
	return lo;
}
void dfs(int vertice, int curr_comp, int min_width, vector<vector<pair<int, int>>> &graph, vector<int> &conn_comp) {
    conn_comp[vertice] = curr_comp;

    for (auto &v: graph[vertice]) {
        // add to the component only if is lower than max_weight
        if (conn_comp[v.first] == -1 && v.second >= min_width) {
            dfs(v.first, curr_comp, min_width, graph, conn_comp);            
        }
    }
}

int main() {
    freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);

    int cow_num, wormhole_num;
    cin >> cow_num >> wormhole_num;

    vector<vector<pair<int, int>>> graph(cow_num);
    vector<int> cows(cow_num);

    for (int &c: cows) {
        cin >> c;
        c--;
    }

    int greatest_width = 0;
    for (int i = 0; i < wormhole_num; i++) {
        int from, to, width;
        cin >> from >> to >> width;

        from--; to--;
        graph[from].push_back({to, width});
        graph[to].push_back({from, width});
        greatest_width = max(width, greatest_width);
    }

    // max path from n to m
    int max_width = last_true(0, greatest_width + 1, [&](int min_width) {
        vector<int> conn_comp(cow_num, -1);
        // connect the components
        for (int i = 0; i < cow_num; i++) {
            if (conn_comp[i] == -1) {
                dfs(i, i, min_width, graph, conn_comp);
            }
        }

        // verify if the component is connected
        for (int i = 0; i < cow_num; i++) {
            if (conn_comp[i] != conn_comp[cows[i]]) {
                return false;
            }
        }

        return true;
    });

    cout << (max_width == greatest_width + 1 ? -1 : max_width) << endl; 
}