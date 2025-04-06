#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }

    int min_x = 0;
    int max_x = 1e9;
    for (int i = 1; i < n; i++) {

        if (arr[i - 1] == arr[i]) {
            // ai-1 == ai => x any
        } else if (arr[i - 1] < arr[i]) {
            // ai-1 < ai =>     x < ai-1 + (ai - ai-1) / 2
            max_x = min(max_x, arr[i - 1] + (arr[i] - arr[i - 1]) / 2);
        } else {
            // arr[i - 1] > arr[i]
            // ai-1 > ai =>     x >= ceil((ai - ai-1) / 2) + ai
            min_x = max(min_x, arr[i] + (arr[i - 1] - arr[i] + 1) / 2);
        }
    }

    if (min_x > max_x) {
        cout << -1 << endl;
    } else {
        cout << min_x << endl;
    }
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
