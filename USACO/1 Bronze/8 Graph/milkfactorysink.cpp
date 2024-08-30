#include <bits/stdc++.h>
using namespace std;

/*
"Walkways are expensive, so Farmer John has elected to use the minimum number of walkways 
so that one can eventually reach any station starting from any other station"

so the sink is the answer

if we have two sink is impossible
*/
int main() {
    freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> graph[n + 1];
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
    }

    // try to find a sink
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        if (graph[i].size() == 0) {
            if (ans != -1) {
                ans = -1;
                break;
            }
            ans = i;
        }
    }
    cout << ans << endl;
}