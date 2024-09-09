#include <bits/stdc++.h>
using namespace std;

/*
There is a point (not start) that is closer to the final point =>
not possible since both moves at same speed

The starting point is the closest to the final point => is possible
Proof:
We can see the starting point as increasing circle as the other points. So
to prove with contradiction assume the starting point goes through a circle
... (triangle ineq)

~40
*/
long long calc_distance(pair<int, int> start, pair<int, int> end) {
    return 1LL * (start.first - end.first) * (start.first - end.first) +
           1LL * (start.second - end.second) * (start.second - end.second);
}

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> increasing_circles(n);
    for (pair<int, int> &ic: increasing_circles) {
        cin >> ic.first >> ic.second;
    }
    pair<int, int> start, end;
    cin >> start.first >> start.second >> end.first >> end.second;
    long long distance = calc_distance(start, end);

    for (int i = 0; i < n; i++) {
        if (distance >= calc_distance(increasing_circles[i], end)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}