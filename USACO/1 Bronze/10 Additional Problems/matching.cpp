#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    // i - j = ai - aj => ai - i = aj - j
    // so we can store  k - ak  and calculate

    unordered_map<int, vector<int>> can_connect;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        can_connect[i - a].push_back(a);
    }

    long long ans = 0;
    for (auto &p: can_connect) {
        vector<int> &edges = p.second;

        sort(edges.begin(), edges.end());
        
        for (int i = edges.size() - 1; i-1 >= 0; i -= 2) {
            int weight = edges[i] + edges[i - 1];

            if (weight <= 0) {
                break;
            }
            ans += weight;
        }
    }
    cout << ans << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}