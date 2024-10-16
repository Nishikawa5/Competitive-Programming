#include <bits/stdc++.h>
using namespace std;

struct LazySum {
    vector<int> difference_array;
    LazySum(int n) : difference_array(n, 0) {}

    void add(int l, int r, int val) {
        if (l > r) return;
        difference_array[l] += val;
        difference_array[r + 1] -= val;
    }

    void pushToAndClear(vector<int> &dp) {
        int sum = 0;
        for (int i = 0; i < difference_array.size(); i++) {
            sum += difference_array[i];

            if (i < dp.size()) {
                // add the sum according to the points
                dp[i] += sum;
            }

            difference_array[i] = 0;
        }
    }
};

void solve() {
    int records, points;
    cin >> records >> points;

    vector<int> dp(points + 1, -1e9);      // consider 0
    LazySum ls(points + 2);                // the last is just to add -1
    dp[0] = 0;

    int P = 0;
    for (int i = 0; i < records; i++) {
        int r;
        cin >> r;

        if (r == 0) {
            ls.pushToAndClear(dp);

            for (int k = points; k > 0; k--) {
                // update max
                dp[k] = max(dp[k], dp[k - 1]);
            }
            
            P++;
        } else if (r < 0) {
            // strength
            // add one to diff array where P + r <= I (P - S = I)
            ls.add(0, P + r, 1);
        } else {
            // intelligence
            // add one to diff array where I >= r
            ls.add(r, points, 1);
        }
    }
    ls.pushToAndClear(dp);
	cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;
    while (tc--) {
        solve();
    }
}
