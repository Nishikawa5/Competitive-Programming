#include <bits/stdc++.h>
using namespace std;

/*
First try: 19 min
*/
int main() {
    freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);

    vector<vector<int>> graph(101, vector(101, 0));
    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        // fill the graph with direct connections
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }

    for (int i = 1; i <= n; i++) {
        // fill the graph with indirect connections
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == 1) {
                for (int k = 1; k <= n; k++) {
                    graph[i][k] |= graph[j][k];
                }
            }
        }
    }

    // check if some node is connected to every node
    for (int j = 1; j <= n; j++) {
        bool isThis = true;
        for (int i = 1; i <= n; i++) {
            if (!graph[i][j] && i != j) {
                isThis = false;
                break;
            }
        }
        if (isThis) {
            cout << j << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}