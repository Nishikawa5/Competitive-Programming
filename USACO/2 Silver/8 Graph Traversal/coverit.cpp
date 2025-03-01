#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    /*
    take only odd or even distances
    to get the intuition of how the conditions are meet this way
    see the graph as waves, paint the odd/even distances
    */

    vector<bool> visited(n);
    vector<int> distances(n, 2e5 + 1);
    queue<int> q;

    // no need to do more bfs's since the graph is connected
    // 0 is initial
    distances[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int vertice = q.front();
        q.pop();


        visited[vertice] = true;

        for (auto &curr_vertice: graph[vertice]) {
            if (!visited[curr_vertice]) {
                q.push(curr_vertice);
                distances[curr_vertice] = distances[vertice] + 1;
            }
        }
    }

    int odd = 0;
    int even = 0;
    for (int i = 0; i < n; i++) {
        odd += (distances[i] % 2);
        even += (distances[i] % 2 == 0); 
    }

    if (odd < even) {
        cout << odd << endl;
        for (int i = 0; i < n; i++) {
            if (distances[i] % 2) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    } else {
        cout << even << endl;
        for (int i = 0; i < n; i++) {
            if (distances[i] % 2 == 0) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
    return 0;
}
