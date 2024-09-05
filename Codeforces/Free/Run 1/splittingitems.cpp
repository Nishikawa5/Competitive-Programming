#include <bits/stdc++.h>
using namespace std;

/*
pairs of closest elements
~25 min
very easy but misinterpreted the problem
*/
int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n, k;
        cin >> n >> k;

        vector<long long> costs(n);
        for (long long &c: costs) {
            cin >> c;
        }

        sort(costs.begin(), costs.end());
        long long max_cost = 0;
        for (int alice = n - 1, bob = n - 2; bob >= 0; alice -= 2, bob -= 2) {
            if (costs[alice] <= costs[bob] + k) {
                // can make it equal
                k -= costs[alice] - costs[bob];
                max_cost += 0;
            } else {
                max_cost += costs[alice] - (costs[bob] + k);
                k = 0;
            }
        }
        if (n % 2) {
            // alice take the last
            max_cost += costs[0];
        }
        cout << max_cost << endl;
    }
}