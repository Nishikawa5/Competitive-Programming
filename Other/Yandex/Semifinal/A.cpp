#include <bits/stdc++.h>
using namespace std;

long long get_closest(vector<int> &v) {
    long long ans = 0;

    vector<int> zeros;
    vector<int> gtone;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0) {
            zeros.push_back(i);
        } else if (v[i] > 1) {
            gtone.push_back(i);
        }
    }

    int last_gtone = 0;
    for (int i = 0; i < zeros.size(); i++) {
        ans += (long long)abs(zeros[i] - gtone[last_gtone]);

        if (--v[gtone[last_gtone]] <= 1) {
            last_gtone++;
        }
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;

    // separe in rows => separe in columns
    vector<int> columns(n);
    vector<int> rows(n);

    while (n--) {
        int col, row;
        cin >> row >> col;

        columns[col - 1]++;
        rows[row - 1]++;
    }
    long long ans = get_closest(rows) + get_closest(columns);

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;

    while (tc--) {
        solve();
    }
    return 0;
}
