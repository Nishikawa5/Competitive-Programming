#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n - 1; i++) {
            cin >> b[i];
        }
        a[0] = b[0];
        for (int i = 1; i < n; i++) {
            a[i] = (b[i] | b[i - 1]);
        }
        a[n - 1] = b[n - 2];


        // check
        bool isPossible = true;
        for (int i = 0; i < n - 1; i++) {
            if ((a[i] & a[i + 1]) != b[i]) {
                cout << -1 << endl;
                isPossible = false;
                break;
            }
        }
        if (isPossible) {
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
}