#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);
    for (int e1 = 2; e1 <= n; e1++) {
        int e2;
        cin >> e2;

        graph[e1].push_back(e2);
        graph[e2].push_back(e1);
    }


}