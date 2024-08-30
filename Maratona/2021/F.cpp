#include <bits/stdc++.h>
using namespace std;

void dfs(int x, vector<bool> &visited, vector<vector<int>> &field) {
    if (x == field.size() - 1 || visited[x]) {
        // n - 1 e da ana
        return;
    }
    visited[x] = true;

    for (int next: field[x]) {
        dfs(next, visited, field);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> field(n);
    vector<bool> visited(n, false);
    
    for (int i = 0; i < m; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        p1--;
        p2--;
        field[p1].push_back(p2);
        field[p2].push_back(p1);
    }

    // n - 2 e todos que forem possivel tocar sem passar pelo n - 1 e do bob
    dfs(n - 2, visited, field);
    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            cout << "B";
        } else {
            cout << "A";
        }
    }
    cout << "\n";
}