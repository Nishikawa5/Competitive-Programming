#include <bits/stdc++.h>
using namespace std;

void solve() {
    // up -> down
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }

    int curr_placement = 1;
    for (int left = 0, right = n-1; left <= right;) {
        int minimal = min(arr[left], arr[right]);

        while (left <= right && min(arr[left], arr[right]) != 0) {
            curr_placement = min(arr[left], arr[right]) + 1;
            left++;
            right--;
        }

        if (arr[left] == 0) {
            arr[left]
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    solve();
}