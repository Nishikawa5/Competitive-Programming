#include <bits/stdc++.h>
using namespace std;

bool dfs(int pupil, vector<int> &colors, vector<vector<int>> &graph) {
    // cant be the same color as the pupil
    int friend_color = colors[pupil] == 1 ? 2 : 1;

    for (int &f: graph[pupil]) {
        if (colors[f] == 0) {
            // just change it
            colors[f] = friend_color;
            if (!dfs(f, colors, graph)) {
                return false;
            }
        } else if (colors[f] != friend_color) {
            // can't have
            return false;
        }
    }
    return true;
}

int main() {
    int n, friendships;
    cin >> n >> friendships;

    vector<int> colors(n);
    vector<vector<int>> graph(n);
    for (int i = 0; i < friendships; i++) {
        int f1, f2;
        cin >> f1 >> f2;
        graph[f1 - 1].push_back(f2 - 1);
        graph[f2 - 1].push_back(f1 - 1);
    }

    for (int i = 0; i < n; i++) {
        if (colors[i] == 0) {
            // put in the group 1
            colors[i] = 1;
            if (!dfs(i, colors, graph)) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    for (int c: colors) {
        cout << c << " ";
    }
    cout << "\n";
}