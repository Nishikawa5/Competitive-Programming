#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> movies(n);
    for (auto &mv: movies) {
        cin >> mv.second >> mv.first;
    }

    sort(movies.begin(), movies.end());
    // the second are also ordered, so we dont need multiset here
    vector<int> ms(k, 0);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        // pick the first movie that ends after the current start
        auto it = upper_bound(ms.begin(), ms.end(), movies[i].second);

        if (it == ms.begin()) {
            continue;
        }
        ans++;
        ms.erase(--it);
        ms.push_back(movies[i].first);
    }
    cout << ans << endl;
}