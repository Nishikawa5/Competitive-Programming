#include <bits/stdc++.h>
using namespace std;

int main() {
    long long mod = 1e9 + 7;
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    // consider dp[visited subset][end at]
    vector<vector<long long>> dp(1 << n, vector<long long>(n));
    while (m--) {
        int a, b;
        cin >> a >> b;
        // to verify if there is a path from a to b
        graph[b - 1].push_back(a - 1);
    }

    // start at 1 visited
    dp[1][0] = 1;
    for (int s = 2; s < (1 << n); s++) {
        // calculate the number of ways we can get
        // this subset s

        // the first city has to be the first to be visited
        if (!(s & 1)) continue;

        // the last city has to be the last to be visited
        if ((s & (1 << (n - 1))) && (s != (1 << n) - 1)) continue;

        for (int end = 1; end < n; end++) {
            // assume this city is not visited yet
            // cant assume city 0 is not visited yet (i = 0)
            if (!(s & (1 << end))) continue;

            int not_visited_subset = s ^ (1 << end);
            for (auto from: graph[end]) {
                // verify if that has been visited
                if ((s & (1 << from))) {
                    // visit this city coming from
                    // assume the last visited city was from
                    dp[s][end] += dp[not_visited_subset][from];
                    dp[s][end] %= mod;
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1] << endl;
}