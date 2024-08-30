#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> rst(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int t;
            cin >> t;
            rst[i] |= t;
            rst[j] |= t;
        }
    }

    cout << rst[0];
    for (int i = 1; i < n; i++) {
        cout << " " << rst[i];
    }
    cout << endl;
}