#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int xc, yc, k;
        cin >> xc >> yc >> k;

        if (k % 2) {
            cout << xc << " " << yc << endl;
            k--;
        }

        for (int i = 1; i <= k / 2; i++) {
            cout << xc + i << " " << yc + i << endl;
            cout << xc - i << " " << yc - i << endl;
        }
    }
}