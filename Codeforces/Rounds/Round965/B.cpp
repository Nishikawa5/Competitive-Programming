#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        int p;
        for (int i = 0; i < n; i++) {
            cin >> p;
            cout << (p % n) + 1 << " ";
        }
        cout << endl;
    }
}