#include <bits/stdc++.h>
using namespace std;

/*
N cows N locations

hard to interpret to me

42:00 wrong on case 5, 9/10
*/
bool checkMissing(vector<bool> indexes_missing) {
    for (int i = 1; i < indexes_missing.size(); i++) {
        if (indexes_missing[i] == true) {
            // some index is missing
            return false;
        }
    }
    return true;
}

int main() {
    freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);

    int n, m;

    cin >> n >> m;
    vector<int> cow_places(n);
    for (int i = 0; i < n; i++) {
        cin >> cow_places[i];
    }

    vector<pair<int, pair<int, int>>> wormhole(m);
    for (int i = 0; i < m; i++) {
        cin >> wormhole[i].second.first >> wormhole[i].second.second >> wormhole[i].first;
    }
    sort(wormhole.begin(), wormhole.end(), std::greater<>());

    // check which indexes we want of wormholes
    vector<bool> indexes_missing(n + 1, true);
    indexes_missing[0] = false;
    for (int i = 1; i <= n; i++) {
        indexes_missing[i] = cow_places[i - 1] != i;
    }

    // go through wormholes searching for those indexes
    int ans = -1;
    if (!checkMissing(indexes_missing)) {
        for (int i = 0; i < m; i++) {
            indexes_missing[wormhole[i].second.first] = false;
            indexes_missing[wormhole[i].second.second] = false;

            if (checkMissing(indexes_missing)) {
                ans = wormhole[i].first;
                break; 
            }
        }
    }
    cout << ans << endl;
}