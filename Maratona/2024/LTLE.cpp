#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int change = arr[i] ^ arr[j];
            arr[i] |= arr[j];

            // deactivate every change
            change = ~change;
            arr[j] &= change;
        }
        cout << arr[i] << " ";
    }
    cout << endl;
}