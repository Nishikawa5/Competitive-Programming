#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }

    int curr_a = arr[0];
    int max_arr = 1;
    for (int i = 1; i < n; i++) {

        while (i < n && arr[i] <= curr_a + 1) {
            i++;
        }
        if (i < n) {
            curr_a = arr[i];
            max_arr++;
        }
    }
    cout << max_arr << endl;
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
