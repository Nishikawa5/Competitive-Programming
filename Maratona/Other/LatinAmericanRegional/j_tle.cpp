#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265358979323

void solve() {
    int theta, n;
    cin >> theta >> n;

    vector<pair<double, double>> intervals(n);
    
    double const_tan = tan(PI * theta / 180);
    for (int i = 0; i < n; i++) {
        double pos, h;
        cin >> pos >> h;

        // can we just use tan?
        double x = h / const_tan;
        intervals[i] = {pos, pos + x};
    }
    sort(intervals.begin(), intervals.end());

    double ans = 0;
    for (int i = 0; i < n; i++) {
        double start = intervals[i].first;
        double max_shadow = intervals[i].second;
        while (i < n-1 && max_shadow > intervals[i+1].first) {
            i++;
            max_shadow = max(max_shadow, intervals[i].second);
        }
        ans += max_shadow - start;
    }
    cout << fixed << setprecision(13) << ans << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();
}