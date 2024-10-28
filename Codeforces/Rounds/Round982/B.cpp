#include <bits/stdc++.h>
using namespace std;

/*
select a element

get the longest decreasing subsequence less than this element
remove the rest

*/
void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }

    int min_removed = n - 1;
    for (int i = 0; i < n; i++) {
        // select a number
        
        int curr_removed = i;
        for (int j = i + 1; j < n; j++) {
            // apply ss from it
            if (arr[i] < arr[j]) {
                // remove this element
                curr_removed++;
            }
        }
        min_removed = min(min_removed, curr_removed);
    }
    cout << min_removed << endl;
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