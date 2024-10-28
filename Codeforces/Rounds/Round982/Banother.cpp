#include <bits/stdc++.h>
using namespace std;

/*
stalin sort -> just one element

first element that wont be removed
->
apply ss
->

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
        // first element not removed
        
        int curr_max = arr[i];
        int curr_removed = i;
        for (int j = i + 1; j < n; j++) {
            // apply ss from it
            if (curr_max <= arr[j] && arr[j] != arr[i]) {
                curr_max = arr[j];
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