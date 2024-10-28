#include <bits/stdc++.h>
using namespace std;

/*
count the number of hills
*/
void solve() {
    int num_heights;
    cin >> num_heights;

    vector<int> heights(num_heights);

    for (auto &h: heights) {
        cin >> h;
    }

    int mid = 0;
    long long total_hills = 0;
    for (int l = 0, r = 1; r < num_heights; r++) {

        if (heights[r] > heights[mid]) {
            mid = r;
        } else if (heights[r] < heights[mid]) {
            // start decreasing
            int left_heights = mid - l;
            int right_heights = 1;
            while (r + 1 < num_heights && heights[r] > heights[r + 1]) {
                r++;
                right_heights++;
            }

            // update left
            l = r;
            mid = r;

            // calculate the hills combinations
            total_hills += 1LL * left_heights * right_heights;
        } else {
            l = r;
            mid = r;
        }
    }
    cout << total_hills << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
    return 0;
}