#include <bits/stdc++.h>
using namespace std;


/*
Since we can eliminate 3 points (cows), by picking 4 of the extremes, 1 is guaranteed to stay and we are using this
point. So try every combination of the 4 extremes of every side (pick one of min x, max x, min y, max y), see if
the rectangle is valid (only 3 points outside) and calculate the minimum area 
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

    vector<int> x_min(4);
    vector<int> x_max(4);
    vector<int> y_min(4);
    vector<int> y_max(4);
    // get the every extreme of x and y
    sort(cows.begin(), cows.end());
    for (int i = 0; i < 4; i++) {
        x_min[i] = cows[i].first;
        x_max[i] = cows[n - 1 - i].first;
    }

    sort(cows.begin(), cows.end(), 
    [&] (pair<int, int> a, pair<int, int> b) { 
        if (a.second == b.second) {
            return a.first < b.first;
        } else {
            return a.second < b.second;
        }
    });
    for (int i = 0; i < 4; i++) {
        y_min[i] = cows[i].second;
        y_max[i] = cows[n - 1 - i].second;
    }

    int min_area = INT_MAX;
    // every combination
    for (int a = 0; a < x_min.size(); a++) {
        for (int b = 0; b < x_max.size(); b++) {
            for (int c = 0; c < y_min.size(); c++) {
                for (int d = 0; d < y_max.size(); d++) {
                    // check if there are at most 3 points outside
                    int outside_points = 0;
                    for (int i = 0; i < n && outside_points <= 3; i++) {
                        if (!(x_min[a] <= cows[i].first && cows[i].first <= x_max[b]) ||
                            !(y_min[c] <= cows[i].second && cows[i].second <= y_max[d])) {
                            outside_points++;
                        }
                    }
                    if (outside_points <= 3) {
                        min_area = min(min_area, (x_max[b] - x_min[a]) * (y_max[d] - y_min[c]));
                    }
                }
            }
        }
    }
    cout << min_area << endl;
}