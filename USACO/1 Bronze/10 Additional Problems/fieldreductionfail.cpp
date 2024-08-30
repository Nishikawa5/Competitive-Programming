#include <bits/stdc++.h>
using namespace std;

/*
consider removing just the 12 extreme cows

Don't know why it don't work.
*/
int main() {
    freopen("reduce.in", "r", stdin);
	freopen("reduce.out", "w", stdout);

    int n;
    cin >> n;

    vector<pair<int, int>> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    // stores the addresses to make it unique
    vector<pair<int, int>*> extreme_cows;

    sort(cows.begin(), cows.end());
    for (int i = 0; i < 3; i++) {
        extreme_cows.push_back(&cows[i]);
        extreme_cows.push_back(&cows[cows.size() - 1 - i]);
    }

    sort(cows.begin(), cows.end(), 
    [&] (pair<int, int> a, pair<int, int> b) { 
        if (a.second == b.second) {
            return a.first < b.first;
        } else {
            return a.second < b.second;
        }
    });
    for (int i = 0; i < 3; i++) {
        extreme_cows.push_back(&cows[i]);
        extreme_cows.push_back(&cows[cows.size() - 1 - i]);
    }

    int min_area = INT_MAX;
    for (int i = 0; i < extreme_cows.size(); i++) {
        for (int j = i + 1; j < extreme_cows.size(); j++) {
            for (int k = j + 1; k < extreme_cows.size(); k++) {
                int ml = INT_MAX;
                int mr = INT_MIN;
                int md = INT_MAX;
                int mu = INT_MIN;
                for (int l = 0; l < cows.size(); l++) {
                    if (&cows[l] == extreme_cows[i] || 
                        &cows[l] == extreme_cows[j] || 
                        &cows[l] == extreme_cows[k]) {
                        continue;
                    }
                    ml = min(ml, cows[l].first);
                    mr = max(mr, cows[l].first);
                    md = min(md, cows[l].second);
                    mu = max(mu, cows[l].second);
                }
                min_area = min(min_area, (mr - ml) * (mu - md));
            }
        }
    }
    cout << min_area << endl;
}