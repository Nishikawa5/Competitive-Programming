#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int a, b;
        cin >> a >> b;

        if (a % 2) {
            cout << "NO\n";
        } else {
            b %= 2;
            if ((b == 1 && a >= 2) || (b == 0)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}