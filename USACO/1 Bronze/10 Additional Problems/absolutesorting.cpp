#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }

    for (int i = 1; i < n; i++) {

        if (arr[i - 1] == arr[i]) {
            // ai-1 == ai => x any
        } else if (arr[i - 1] < arr[i]) {
            // ai-1 < ai =>     any x <= ai-1
        }
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
