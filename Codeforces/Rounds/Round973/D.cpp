#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    // make the min closer to the max and vice-versa
    vector<int> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }

    for (int i = 0; i < n - 1; i++) {
        int difference = arr[i] - arr[i + 1];
        
        if (difference > 0) {
            // make them as equal as possible
            arr[i]     -= difference / 2 - (difference % 2);
            arr[i + 1] += difference / 2 + (difference % 2);
        }
    }

    int min_num = arr[0];
    int max_num = arr[0];
    for (int i = 1; i < n; i++) {
        min_num = min(min_num, arr[i]);
        max_num = max(max_num, arr[i]);
    }
    cout << max_num - min_num << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}