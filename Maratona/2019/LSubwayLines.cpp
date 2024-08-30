#include <bits/stdc++.h>
using namespace std;

// if is possible to go from s1 to s2, return the path
vector<int> 

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int s1, s2;
        cin >> s1 >> s2;
        graph[s1].push_back(s2);
        graph[s2].push_back(s1);
    }

    
}