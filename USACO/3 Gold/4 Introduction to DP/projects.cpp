#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
    int n;
    cin >> n;
    
    vector<int> start(n), end(n), money(n);
    map<int, int> compressed;
    for (int i = 0; i < n; i++) {
        cin >> start[i] >> end[i] >> money[i];
        end[i]++;    // available only after this day

        // to use in 
        compressed[start[i]];
        compressed[end[i]];
    }

    int coords = 0;
    for (auto &c: compressed) {
        c.second = coords++;
    }

    // projects[end day] == {{start day, reward}}
    vector<vector<pair<int, int>>> projects(coords);
    for (int i = 0; i < n; i++) {
        projects[compressed[end[i]]].push_back({compressed[start[i]], money[i]});
    }

    // the max amount of money you can earn at day i
    vector<long long> dp(coords);
    dp[0] = 0;

    for (int i = 1; i < coords; i++) {
        dp[i] = dp[i - 1];
        for (auto project: projects[i]) {
            // a project that ended in this day
            dp[i] = max(dp[i], dp[project.first] + project.second);
        }
    }
    cout << dp[coords - 1] << endl;
}